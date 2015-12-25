#include "segmentation.h"

Segmentation::Segmentation(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

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
	
	segDialog = new InteractionSegment(this);

	connect(openDepth, &QAction::triggered, this, &Segmentation::openDepthImage);
	connect(openRGB, &QAction::triggered, this, &Segmentation::openRGBImage);
	connect(openDepthFile, &QAction::triggered, this, &Segmentation::openDepthPath);
	connect(openRGBFile, &QAction::triggered, this, &Segmentation::openRGBPath);
}

Segmentation::~Segmentation()
{

}

void Segmentation::openDepthImage() {
	QString imgName = QFileDialog::getOpenFileName(this, tr("Open Depth Image"), "E:\\Image\\NJU-DS400\\depth", tr("Images (*.png *.xpm *.jpg)"));
	if (curDepthName.isEmpty() && imgName.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any image."));
	}
	else {
		curDepthName = imgName;
		showImageOnLabel(ui.depthImage, curDepthName, depthImage);
		cout << curDepthName.toStdString() << endl;
	}
}

void Segmentation::openRGBImage() {
	QString imgName = QFileDialog::getOpenFileName(this, tr("Open RGB Image"), "E:\\Image\\NJU-DS400\\image", tr("Images (*.png *.xpm *.jpg)"));
	if (curRGBName.isEmpty() && imgName.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any image."));
	}
	else {
		curRGBName = imgName;
		showImageOnLabel(ui.RGBImage, curRGBName, rgbImage);
		cout << curRGBName.toStdString() << endl;
	}
}

void Segmentation::openDepthPath() {
	QString curPath = QFileDialog::getExistingDirectory(this, tr("Select Depth Image Path"), "E:\\Image\\NJU-DS400\\depth", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (depthPath.isEmpty() && curPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		depthPath = curPath;
		cout << depthPath.toStdString() << endl;
	}
}

void Segmentation::openRGBPath() {
	QString curPath = QFileDialog::getExistingDirectory(this, tr("Select RGB Image Path"), "E:\\Image\\NJU-DS400\\image", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (rgbPath.isEmpty() && curPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		rgbPath = curPath;
		cout << rgbPath.toStdString() << endl;
	}
}

void Segmentation::on_seedButton_clicked() {
	QString curPath = QFileDialog::getExistingDirectory(this, tr("Select Depth Image Path"), "E:\\Image\\NJU-DS400\\seed", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (seedPath.isEmpty() && curPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		seedPath = curPath;
		ui.seedPathEdit->setText(seedPath);
		cout << seedPath.toStdString() << endl;
	}
}

void Segmentation::on_resultButton_clicked() {
	QString curPath = QFileDialog::getExistingDirectory(this, tr("Select Result Path"), "E:\\Image\\NJU-DS400", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (resultPath.isEmpty() && curPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		resultPath = curPath;
		ui.resultPathEdit->setText(resultPath);
		cout << resultPath.toStdString() << endl;
	}
}

void Segmentation::showImageOnLabel(QLabel *label, QString &imgPath, QImage &objImage) {
	objImage = QImage(imgPath);
	double wRatio(label->width() / (double)objImage.width()), hRatio(label->height() / (double)objImage.height());
	double ratio(wRatio < hRatio ? wRatio : hRatio);
	label->setPixmap(QPixmap::fromImage(objImage.scaled(objImage.width()*ratio, objImage.height()*ratio)));
	label->setAlignment(Qt::AlignCenter);
	label->show();
}

void Segmentation::on_segmentButton_clicked() {
	getMethod();
	if(method.isEmpty()) {
		QMessageBox::warning(this, tr("Method"), tr("Please select a method first!"));
		return;
	}

	initializeDialog();
	segDialog->exec();
}

void Segmentation::on_saveButton_clicked() {
	if (seedPath.isEmpty()) {
		QMessageBox::warning(this, tr("Seed Path"), tr("Please select a seed path first!"));
		return;
	}
	if (resultPath.isEmpty()) {
		QMessageBox::warning(this, tr("Result Path"), tr("Please select a result path first!"));
		return;
	}
}

void Segmentation::getMethod() {
	if (ui.gbRadio->isChecked()) {
		cout << "Grabcut is selected." << endl;
		method = "gb";
	}
	else if (ui.gcRadio->isChecked()) {
		cout << "graphcut is selected." << endl;
		method = "gc";
	}
	else if (ui.gddRadio->isChecked()) {
		cout << "gdd is selected." << endl;
		method = "gdd";
	}
	else if (ui.ggRadio->isChecked()) {
		cout << "GG is selected." << endl;
		method = "gg";
	}
	else if (ui.hggRadio->isChecked()) {
		cout << "HGG is selected." << endl;
		method = "hgg";
	}
	else if (ui.mgcRadio->isChecked()) {
		cout << "MGC is selected." << endl;
		method = "mgc";
	}
	else if (ui.rgbdRadio->isChecked()) {
		cout << "RGBD is selected." << endl;
		method = "rgbd";
	}
}

void Segmentation::initializeDialog() {
	segDialog->ui.ScribbleWidget->openImage(curRGBName);
	segDialog->ui.ScribbleWidget->setMethod(method);
	if (method != "gb" && method != "gc" && method != "mgc") {
		segDialog->ui.ScribbleWidget->setDepthImage(depthImage);
	}
}