#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <QtWidgets/QMainWindow>
#include "ui_segmentation.h"

#include <iostream>
#include <string>
using namespace std;

class Segmentation : public QMainWindow
{
	Q_OBJECT

public:
	Segmentation(QWidget *parent = 0);
	~Segmentation();

private:
	Ui::SegmentationClass ui;
	string RGBPath;
	string DepthPath;
	string SeedPath;
	string ResultPath;

private slots:;
	void on_OpenRGB_clicked();
};

#endif // SEGMENTATION_H
