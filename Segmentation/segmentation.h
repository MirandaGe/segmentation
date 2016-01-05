#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <QtWidgets/QMainWindow>
#include "ui_segmentation.h"
#include "interactionsegment.h"

//#include <iostream>
#include <QFileDialog>
#include <QMenubar>
#include <QMessageBox>
//using namespace std;

class Segmentation : public QMainWindow
{
	Q_OBJECT

public:
	Segmentation(QWidget *parent = 0);
	~Segmentation();

private:
	Ui::SegmentationClass ui;
	QString rgbPath;
	QString depthPath;
	QString seedPath;
	QString resultPath;
	QString curRGBName;
	QString curDepthName;
	QString method;
	QImage rgbImage;
	QImage seedImage;
	QImage resultImage;
	QImage depthImage;
	
	InteractionSegment *segDialog;

	void getMethod();
	void initializeDialog();
	void openDepthPath();
	void openRGBPath();
	void openDepthImage();
	void openRGBImage();

private slots:
	void on_seedButton_clicked();
	void on_resultButton_clicked();
	void on_segmentButton_clicked();
	void on_saveButton_clicked();
	void showImageOnLabel(QLabel *label, const QString &imgPath, QImage &objImage);
	void on_imageList_currentItemChanged();
	bool needDepth() { return method != "gb" && method != "gc" && method != "mgc"; }
};

#endif // SEGMENTATION_H
