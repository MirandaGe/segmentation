#include "segmentation.h"

Segmentation::Segmentation(QWidget *parent)
	: QMainWindow(parent)
{
	QAction *openRGB = new QAction(QIcon(":/images/file-open"), tr("Open RGB Image"), this);
	openRGB->setStatusTip("Open an RGB image.");

	QAction *openDepth = new QAction(QIcon(":/images/file-open"), tr("open Depth Image"), this);
	openDepth->setStatusTip("Open a depth image.");

	QAction *openRGBFile = new QAction(QIcon(":/images/file-open"), tr("Open RGB Image File"), this);
	openRGBFile->setStatusTip("Open an RGB image File Path.");

	QAction *openDepthFile = new QAction(QIcon(":/images/file-open"), tr("Open Depth Image File"), this);
	openDepthFile->setStatusTip("Open a depth image File Path.");

	QMenu *file = menuBar()->addMenu(tr("File"));
	file->addAction(openRGB);
	file->addAction(openDepth);
	file->addAction(openDepthFile);
	file->addAction(openRGBFile);

	connect(openDepth, &QAction::triggered, this, &Segmentation::openDepthImage);
	connect(openRGB, &QAction::triggered, this, &Segmentation::openRGBImage);
	connect(openDepthFile, &QAction::triggered, this, &Segmentation::openDepthPath);
	connect(openRGBFile, &QAction::triggered, this, &Segmentation::openRGBPath);

	ui.setupUi(this);
}

Segmentation::~Segmentation()
{

}

void Segmentation::openDepthImage() {
	curDepthName = QFileDialog::getOpenFileName(this, tr("Open Depth Image"), "E:\\Image", tr("Images (*.png *.xpm *.jpg)"));
	if (curDepthName.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any image."));
	}
	else {
		showImageOnLabel(ui.depthImage, curDepthName);
		cout << curDepthName.toStdString() << endl;
	}
}

void Segmentation::openRGBImage() {
	curRGBName = QFileDialog::getOpenFileName(this, tr("Open RGB Image"), "E:\\Image", tr("Images (*.png *.xpm *.jpg)"));
	if (curRGBName.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any image."));
	}
	else {
		showImageOnLabel(ui.RGBImage, curRGBName);
		cout << curRGBName.toStdString() << endl;
	}
}

void Segmentation::openDepthPath() {
	depthPath = QFileDialog::getExistingDirectory(this, tr("Select Seed Path"), "E:\\Image", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (depthPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		cout << depthPath.toStdString() << endl;
	}
}

void Segmentation::openRGBPath() {
	rgbPath = QFileDialog::getExistingDirectory(this, tr("Select Seed Path"), "E:\\Image", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (rgbPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		cout << rgbPath.toStdString() << endl;
	}
}

void Segmentation::on_seedButton_clicked() {
	seedPath = QFileDialog::getExistingDirectory(this, tr("Select Seed Path"), "E:\\Image", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (seedPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		ui.seedPathEdit->setText(seedPath);
		cout << seedPath.toStdString() << endl;
	}
}

void Segmentation::on_resultButton_clicked() {
	resultPath = QFileDialog::getExistingDirectory(this, tr("Select Result Path"), "E:\\Image", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (resultPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		ui.resultPathEdit->setText(resultPath);
		cout << resultPath.toStdString() << endl;
	}
}

void Segmentation::showImageOnLabel(QLabel *label, QString imgPath) {
	QImage imgObj(imgPath);
	double wRatio(252 / (double)imgObj.width()), hRatio(179 / (double)imgObj.height());
	double ratio(wRatio < hRatio ? wRatio : hRatio);
	imgObj = imgObj.scaled(imgObj.width()*ratio, imgObj.height()*ratio);
	label->setPixmap(QPixmap::fromImage(imgObj));
	label->setAlignment(Qt::AlignCenter);
	label->show();
}

void Segmentation::on_segmentButton_clicked() {
	if (ui.gbRadio->isChecked()) {
		cout << "Grabcut is selected." << endl;
	}
	else if (ui.gcRadio->isChecked()) {
		cout << "graphcut is selected." << endl;
	}
	else if (ui.gddRadio->isChecked()) {
		cout << "gdd is selected." << endl;
	}
	else if (ui.ggRadio->isChecked()) {
		cout << "GG is selected." << endl;
	}
	else if (ui.hggRadio->isChecked()) {
		cout << "HGG is selected." << endl;
	}
	else if (ui.mgcRadio->isChecked()) {
		cout << "MGC is selected." << endl;
	}
	else if (ui.rgbdRadio->isChecked()) {
		cout << "RGBD is selected." << endl;
	}
	else {
		QMessageBox::warning(this, tr("Method"), tr("Please select a method first!"));
	}
}