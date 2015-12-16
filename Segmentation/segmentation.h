#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <QtWidgets/QMainWindow>
#include "ui_segmentation.h"

#include <iostream>
#include <QFileDialog>
#include <QMenubar>
#include <QMessageBox>
using namespace std;

class Segmentation : public QMainWindow
{
	Q_OBJECT

public:
	Segmentation(QWidget *parent = 0);
	~Segmentation();
	void openDepthPath();
	void openRGBPath();
	void openDepthImage();
	void openRGBImage();
	void showImageOnLabel(QLabel *label, QString imgPath);

private:
	Ui::SegmentationClass ui;
	QString rgbPath;
	QString depthPath;
	QString seedPath;
	QString resultPath;
	QString curRGBName;
	QString curDepthName;

private slots:
	void on_seedButton_clicked();
	void on_resultButton_clicked();
	void on_segmentButton_clicked();
};

#endif // SEGMENTATION_H
