#include <QtWidgets>
#include "scribblearea.h"

ScribbleArea::ScribbleArea(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_StaticContents);
	modified = false;
	scribbling = false;
	myPenWidth = 8;
	myPenColor = Qt::blue;
}

ScribbleArea::~ScribbleArea()
{

}

bool ScribbleArea::openImage(const QString &fileName) {
	QImage loadedImage;
	if (!loadedImage.load(fileName))
		return false;

	QSize newSize = loadedImage.size().expandedTo(size());
	resizeImage(&loadedImage, newSize);
	image = loadedImage;
	modified = false;
	update();
	return true;
}

bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat) {
	QImage visibleImage = image;
	resizeImage(&visibleImage, size());

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
	image.fill(qRgb(255, 255, 255));
	modified = true;
	update();
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

void ScribbleArea::resizeEvent(QResizeEvent *event)
//! [15] //! [16]
// 是否需要保留？
{
	if (width() > image.width() || height() > image.height()) {
		int newWidth = qMax(width() + 128, image.width());
		int newHeight = qMax(height() + 128, image.height());
		resizeImage(&image, QSize(newWidth, newHeight));
		update();
	}
	QWidget::resizeEvent(event);
}
//! [16]

void ScribbleArea::resizeImage(QImage *image, const QSize &newSize)
// 同上
{
	if (image->size() == newSize)
		return;

	QImage newImage(newSize, QImage::Format_RGB32);
	newImage.fill(qRgb(255, 255, 255));
	QPainter painter(&newImage);
	painter.drawImage(QPoint(0, 0), *image);
	*image = newImage;
}

void ScribbleArea::drawLineTo(const QPoint &endPoint) {
	QPainter painter(&image);
	painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
		Qt::RoundJoin));
	painter.drawLine(lastPoint, endPoint);
	modified = true;

	int rad = (myPenWidth / 2) + 2;
	update(QRect(lastPoint, endPoint).normalized()
		.adjusted(-rad, -rad, +rad, +rad));
	lastPoint = endPoint;
}

