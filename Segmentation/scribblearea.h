#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <iostream>
#include "segAlgorithm.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"

using namespace std;

class ScribbleArea : public QWidget
{
	Q_OBJECT

public:
	ScribbleArea(QWidget *parent = 0);
	~ScribbleArea();

	bool openImage(const QString &fileName);
	bool saveImage(const QString &fileName, const char *fileFormat, const QImage &img);
	void setPenColor(const QColor &newColor);
	void setPenWidth(int newWidth);
	void setMethod(QString &str);
	void setDepthPath(QString &path);
	void segment();

	bool isModified() const { return modified; }
	QColor penColor() const { return myPenColor; }
	int penWidth() const { return myPenWidth; }

	QImage seedImage; // seed image
	QImage segImage; // segment image

public slots:
	void clearImage();

protected:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
	void drawLineTo(const QPoint &endPoint);
	void updateAfterSeg(QImage &newImage);
	QImage cvMat2QImage(const cv::Mat &inMat);
	cv::Mat QImage2CvMat(const QImage &inImage, bool inCloneImageData = true);

	bool modified;
	bool scribbling;
	int myPenWidth;
	QColor myPenColor;
	QImage image; // show image
	QPoint lastPoint;
	QString imagePath; // path of initial image
	QString depthPath;
	QString method;
};

#endif // SCRIBBLEAREA_H
