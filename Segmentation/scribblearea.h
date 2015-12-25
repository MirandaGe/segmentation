#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <iostream>

using namespace std;

class ScribbleArea : public QWidget
{
	Q_OBJECT

public:
	ScribbleArea(QWidget *parent = 0);
	~ScribbleArea();

	bool openImage(const QString &fileName);
	bool saveImage(const QString &fileName, const char *fileFormat);
	void setPenColor(const QColor &newColor);
	void setPenWidth(int newWidth);
	void setMethod(QString &str);
	void setDepthImage(QImage &img);

	bool isModified() const { return modified; }
	QColor penColor() const { return myPenColor; }
	int penWidth() const { return myPenWidth; }

public slots:
	void clearImage();

protected:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
	void drawLineTo(const QPoint &endPoint);

	bool modified;
	bool scribbling;
	int myPenWidth;
	QColor myPenColor;
	QImage image; // show image
	QImage depthImage;
	QImage seedImage; // seed image
	QImage segImage; // segment image
	QPoint lastPoint;
	QString imagePath; // path of initial image
	QString method;
};

#endif // SCRIBBLEAREA_H
