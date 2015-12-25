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

bool ScribbleArea::openImage(const QString &fileName) {
	QImage loadedImage;
	if (!loadedImage.load(fileName))
		return false;

	this->setFixedSize(loadedImage.size());
	image = loadedImage;
	if(imagePath.isEmpty())
		imagePath = fileName;
	modified = false;
	update();
	seedImage = QImage(loadedImage.size(), QImage::Format_RGB32);
	seedImage.fill(qRgb(128, 128, 128));
	return true;
}

bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat) {
	QImage visibleImage = seedImage;

	if (visibleImage.save(fileName, fileFormat)) {
		modified = false;
		return true;
	}
	else {
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

void ScribbleArea::setMethod(QString &str) {
	cout << "method type is " << str.toStdString() << endl;
	method = str;
}

void ScribbleArea::setDepthImage(QImage &img) {
	depthImage = img;
}