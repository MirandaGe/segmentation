#include "segmentation.h"

Segmentation::Segmentation(QWidget *parent)
	: QMainWindow(parent),
	hasDir(false)
{
	ui.setupUi(this);
	
	segDialog = new InteractionSegment(this);
}

Segmentation::~Segmentation()
{

}

void Segmentation::on_depthImageAction_triggered() {
	QString imgName = QFileDialog::getOpenFileName(this, tr("Open Depth Image"), "E:\\Image\\NJU-DS400\\depth", tr("Images (*.png *.xpm *.jpg)"));
	if (curDepthName.isEmpty() && imgName.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any image."));
		return;
	}
	else {
		int splitIndex = imgName.lastIndexOf("/");
		curDepthName = imgName.right(imgName.length() - splitIndex - 1);
		depthPath = imgName.left(splitIndex + 1);
		showImageOnLabel(ui.depthImage, imgName, depthImage);
		//cout << curDepthName.toStdString() << endl;
		//cout << depthPath.toStdString() << endl;
	}
	if (!curRGBName.isEmpty()) {
		if (curDepthName != curRGBName)
			QMessageBox::warning(this, tr("Name Match"), tr("The RGB image name is not matched with depth image name."));
	}
}

void Segmentation::on_rgbImageAction_triggered() {
	QString imgName = QFileDialog::getOpenFileName(this, tr("Open RGB Image"), "E:\\Image\\NJU-DS400\\image", tr("Images (*.png *.xpm *.jpg)"));
	if (curRGBName.isEmpty() && imgName.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any image."));
		return;
	}
	else {
		int splitIndex = imgName.lastIndexOf("/");
		curRGBName = imgName.right(imgName.length() - splitIndex - 1);
		rgbPath = imgName.left(splitIndex + 1);
		showImageOnLabel(ui.RGBImage, imgName, rgbImage);
		//cout << curRGBName.toStdString() << endl;
		//cout << rgbPath.toStdString() << endl;
	}
	if (!curDepthName.isEmpty()) {
		if (curDepthName != curRGBName)
			QMessageBox::warning(this, tr("Name Match"), tr("The RGB image name is not matched with depth image name."));
	}
}

void Segmentation::on_depthFileAction_triggered() {
	QString curPath = QFileDialog::getExistingDirectory(this, tr("Select Depth Image Path"), "E:\\Image\\NJU-DS400\\depth", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (depthPath.isEmpty() && curPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		if (rgbPath.isEmpty())
			setDir(curPath);
		depthPath = curPath + "/";
		//cout << depthPath.toStdString() << endl;
	}
}

void Segmentation::on_rgbFileAction_triggered() {
	QString curPath = QFileDialog::getExistingDirectory(this, tr("Select RGB Image Path"), "E:\\Image\\NJU-DS400\\image", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	if (rgbPath.isEmpty() && curPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		if (!rgbPath.isEmpty()) {
			clearDir();
			depthPath.clear();
			rgbPath.clear();
			curDepthName.clear();
			curRGBName.clear();
		}
		setDir(curPath);
		rgbPath = curPath + "/";
		//cout << rgbPath.toStdString() << endl;
	}
}

/* according to the given path, show image name list on ui.imageList*/
void Segmentation::setDir(QString &path) {
	QDir dir(path);
	QStringList filter;
	filter << "*.jpg" << "*.png";
	dir.setNameFilters(filter);
	QList<QFileInfo> fileInfo(dir.entryInfoList(filter));
	for (int i = 0; i < fileInfo.length(); ++i) {
		QString str = fileInfo.at(i).fileName();
		QListWidgetItem *item = new QListWidgetItem(str, ui.imageList);
	}
	//ui.imageList->setCurrentRow(0);

	hasDir = static_cast<bool>(fileInfo.length());
}

/* clear the image name list on ui.imageList */
void Segmentation::clearDir() {
	ui.imageList->clear();
	hasDir = false;
}

void Segmentation::on_imageList_currentItemChanged() {
	QListWidgetItem *curItem = ui.imageList->currentItem();

	if (curItem) {
		curRGBName = curItem->text();
		if (!rgbPath.isEmpty())
			showImageOnLabel(ui.RGBImage, rgbPath + curRGBName, rgbImage);
		if (!depthPath.isEmpty()) {
			curDepthName = curRGBName;
			showImageOnLabel(ui.depthImage, depthPath + curDepthName, depthImage);
		}
	}
}

void Segmentation::on_seedButton_clicked() {
	QString curPath = QFileDialog::getExistingDirectory(this, tr("Select Depth Image Path"), "E:\\Image\\NJU-DS400\\seed", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (seedPath.isEmpty() && curPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		seedPath = curPath + "/";
		ui.seedPathEdit->setText(seedPath);
		//cout << seedPath.toStdString() << endl;
	}
}

void Segmentation::on_resultButton_clicked() {
	QString curPath = QFileDialog::getExistingDirectory(this, tr("Select Result Path"), "E:\\Image\\NJU-DS400", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (resultPath.isEmpty() && curPath.isEmpty()) {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any path."));
	}
	else {
		resultPath = curPath + "/";
		ui.resultPathEdit->setText(resultPath);
		//cout << resultPath.toStdString() << endl;
	}
}

/* show image on the label and initialize objImage using given imagePath. if imagePath is empty, using data of objImage*/
void Segmentation::showImageOnLabel(QLabel *label, const QString &imgPath, QImage &objImage) {
	if (!imgPath.isEmpty())
		objImage = QImage(imgPath);
	double wRatio(label->width() / (double)objImage.width()), hRatio(label->height() / (double)objImage.height());
	double ratio(wRatio < hRatio ? wRatio : hRatio);
	label->setPixmap(QPixmap::fromImage(objImage.scaled(objImage.width()*ratio, objImage.height()*ratio)));
	label->setAlignment(Qt::AlignCenter);
	label->show();
}

void Segmentation::on_segmentButton_clicked() {
	segDialog->ui.ScribbleWidget->clearTime();

	getMethod();
	if(method.isEmpty()) {
		QMessageBox::warning(this, tr("Method"), tr("Please select a method first!"));
		return;
	}

	initializeDialog();
	segDialog->exec();

	ui.timeLineEdit->setText(QString::number(segDialog->ui.ScribbleWidget->getSegTime()));
	showImageOnLabel(ui.seedImage, QString(), segDialog->ui.ScribbleWidget->seedImage);
	showImageOnLabel(ui.resultImage, QString(), segDialog->ui.ScribbleWidget->segImage);
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
	if (segDialog->saveImage(segDialog->ui.ScribbleWidget->seedImage, seedPath + curRGBName) && segDialog->saveImage(segDialog->ui.ScribbleWidget->segImage, resultPath + curRGBName))
		QMessageBox::information(this, tr("success"), tr("Save succeed."));
}

void Segmentation::getMethod() {
	if (ui.gbRadio->isChecked()) {
		//cout << "Grabcut is selected." << endl;
		method = "gb";
	}
	else if (ui.gcRadio->isChecked()) {
		//cout << "graphcut is selected." << endl;
		method = "gc";
	}
	else if (ui.gddRadio->isChecked()) {
		//cout << "gdd is selected." << endl;
		method = "gdd";
	}
	else if (ui.ggRadio->isChecked()) {
		//cout << "GG is selected." << endl;
		method = "gg";
	}
	else if (ui.hggRadio->isChecked()) {
		//cout << "HGG is selected." << endl;
		method = "hgg";
	}
	else if (ui.mgcRadio->isChecked()) {
		//cout << "MGC is selected." << endl;
		method = "mgc";
	}
	else if (ui.rgbdRadio->isChecked()) {
		//cout << "RGBD is selected." << endl;
		method = "rgbd";
	}
}

/* send RGB image name, depth image name and method to segDialog */
void Segmentation::initializeDialog() {
	segDialog->ui.ScribbleWidget->openImage(rgbPath + curRGBName);
	segDialog->ui.ScribbleWidget->setMethod(method);
	if (needDepth()) {
		segDialog->ui.ScribbleWidget->setDepthPath(depthPath + curDepthName);
	}
}