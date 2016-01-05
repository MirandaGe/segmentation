#include <QtWidgets>
#include "scribblearea.h"

ScribbleArea::ScribbleArea(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_StaticContents);
	modified = false;
	scribbling = false;
	myPenWidth = 8;
	myPenColor = Qt::red;
}

ScribbleArea::~ScribbleArea()
{

}

// initialize the shown image and seed on widget
bool ScribbleArea::openImage(const QString &fileName) {
	QImage loadedImage;
	if (!loadedImage.load(fileName))
		return false;

	this->setFixedSize(loadedImage.size());
	image = loadedImage;
	imagePath = fileName;
	modified = false;
	update();

	seedImage = QImage(loadedImage.size(), QImage::Format_RGB888);
	seedImage.fill(qRgb(128, 128, 128));
	return true;
}

bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat, const QImage &img) {
	if (img.save(fileName, fileFormat)) {
		modified = false;
		//cout << "success" << endl;
		return true;
	}
	else {
		//cout << "fail" << endl;
		return false;
	}
}

void ScribbleArea::setPenColor(const QColor &newColor) {
	myPenColor = newColor;
}

void ScribbleArea::setPenWidth(int newWidth) {
	myPenWidth = newWidth;
}

void ScribbleArea::clearImage() {
	openImage(imagePath);
	seedImage.fill(qRgb(128, 128, 128));
}

void ScribbleArea::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		lastPoint = event->pos();
		scribbling = true;
	}
}

void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::LeftButton) && scribbling)
		drawLineTo(event->pos());
}

void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && scribbling) {
		drawLineTo(event->pos());
		scribbling = false;
	}
}

void ScribbleArea::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	QRect dirtyRect = event->rect();
	painter.drawImage(dirtyRect, image, dirtyRect);
}

void ScribbleArea::drawLineTo(const QPoint &endPoint) {
	QPainter painter(&image);
	painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
		Qt::RoundJoin));
	painter.drawLine(lastPoint, endPoint);
	modified = true;

	QPainter seedPainter(&seedImage);
	QColor seedPenColor = myPenColor == Qt::red ? Qt::white : Qt::black;
	seedPainter.setPen(QPen(seedPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	seedPainter.drawLine(lastPoint, endPoint);

	int rad = (myPenWidth / 2) + 2;
	update(QRect(lastPoint, endPoint).normalized()
		.adjusted(-rad, -rad, +rad, +rad));
	lastPoint = endPoint;
}

void ScribbleArea::setMethod(const QString &str) {
	//cout << "method type is " << str.toStdString() << endl;
	method = str;
}

void ScribbleArea::setDepthPath(const QString &path) {
	depthPath = path;
}

void ScribbleArea::segment() {
	segAlgorithm seg;
	seg.setImgPath(imagePath.toStdString());
	seg.setDepthPath(depthPath.toStdString());
	seg.setMethodType(method.toStdString());
	seg.setSeedImage(QImage2CvMat(seedImage));

	seg.segmentation();

	segTime += seg.getSegTime();
	++count;
	segImage = cvMat2QImage(seg.getSegImage()).convertToFormat(QImage::Format_RGB32);
	image = cvMat2QImage(seg.getShowImage());
	update();
}

QImage ScribbleArea::cvMat2QImage(const cv::Mat &inMat) {
	switch (inMat.type()) {
		// 8-bit, 4 channel
		case CV_8UC4: {
			QImage img(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32);
			return img;
		}

		// 8-bit, 3 channel
		case CV_8UC3: {
			QImage img(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888);
			return img.rgbSwapped();
		}

		// 8-bit, 1 channel
		case CV_8UC1: {
			static QVector<QRgb>  sColorTable;

			// only create our color table once
			if (sColorTable.isEmpty()) {
				for (int i = 0; i < 256; ++i)
					sColorTable.push_back(qRgb(i, i, i));
			}

			QImage img(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8);
			img.setColorTable(sColorTable);
			return img;
		}

		default:
			qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
			break;
	}
	return QImage();
}

cv::Mat ScribbleArea::QImage2CvMat(const QImage &inImage, bool inCloneImageData) {
	switch (inImage.format()) {
		// 8-bit, 4 channel
		case QImage::Format_RGB32: {
			cv::Mat mat(inImage.height(), inImage.width(), CV_8UC4, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine());
			return (inCloneImageData ? mat.clone() : mat);
		}

		// 8-bit, 3 channel
		case QImage::Format_RGB888: {
			if (!inCloneImageData)
				qWarning() << "ASM::QImageToCvMat() - Conversion requires cloning since we use a temporary QImage";

			QImage swapped = inImage.rgbSwapped();
			return cv::Mat(swapped.height(), swapped.width(), CV_8UC3, const_cast<uchar*>(swapped.bits()), swapped.bytesPerLine()).clone();
		}

		// 8-bit, 1 channel
		case QImage::Format_Indexed8: {
			cv::Mat mat(inImage.height(), inImage.width(), CV_8UC1, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine());
			return (inCloneImageData ? mat.clone() : mat);
		}

		default:
			qWarning() << "ASM::QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
			break;
	}
	return cv::Mat();
}