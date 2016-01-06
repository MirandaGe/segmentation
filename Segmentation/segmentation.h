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
	bool hasDir;
	
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
	void on_rgbImageAction_triggered();
	void on_depthImageAction_triggered();
	void on_rgbFileAction_triggered();
	void on_depthFileAction_triggered();
	void on_imageList_currentItemChanged();

	void showImageOnLabel(QLabel *label, const QString &imgPath, QImage &objImage);
	bool needDepth() { return method != "gb" && method != "gc" && method != "mgc"; }
	void setDir(QString &path);
	void clearDir();
};

#endif // SEGMENTATION_H
