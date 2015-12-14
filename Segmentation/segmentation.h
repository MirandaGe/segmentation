#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <QtWidgets/QMainWindow>
#include "ui_segmentation.h"

#include <iostream>
#include <string>
#include <QFileDialog>
#include <qmenubar.h>
using namespace std;

class Segmentation : public QMainWindow
{
	Q_OBJECT

public:
	Segmentation(QWidget *parent = 0);
	~Segmentation();

private:
	Ui::SegmentationClass ui;
	QString RGBPath;
	QString DepthPath;
	QString SeedPath;
	QString ResultPath;
	QAction *openRGB;
	QAction *openDepth;
};

#endif // SEGMENTATION_H
