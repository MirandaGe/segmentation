#include "segmentation.h"

Segmentation::Segmentation(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	openRGB = new QAction(QIcon(":/images/file-open"), tr("Open RGB Image"), this);
	openRGB->setStatusTip("Open an RGB image.");

	openDepth = new QAction(QIcon(":/images/file-open"), tr("open Depth Image"), this);
	openDepth->setStatusTip("Open a depth image.");

	QMenu *file = menuBar()->addMenu(tr("File"));
	file->addAction(openRGB);
	file->addAction(openDepth);
}

Segmentation::~Segmentation()
{

}