#include "segmentation.h"
#include <QFileDialog>

Segmentation::Segmentation(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Segmentation::~Segmentation()
{

}

void Segmentation::on_OpenRGB_clicked() {
	QString filePath = QFileDialog::getOpenFileName(this, "open");
	RGBPath = filePath.toLocal8Bit().constData();
}