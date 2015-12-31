#include "interactionsegment.h"

InteractionSegment::InteractionSegment(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

InteractionSegment::~InteractionSegment()
{

}

void InteractionSegment::on_foreButton_clicked() {
	ui.ScribbleWidget->setPenColor(Qt::red);
}

void InteractionSegment::on_backButton_clicked() {
	ui.ScribbleWidget->setPenColor(Qt::blue);
}

void InteractionSegment::on_clearButton_clicked() {
	ui.ScribbleWidget->clearImage();
}

void InteractionSegment::on_brushSpinBox_valueChanged(int i) {
	ui.ScribbleWidget->setPenWidth(i);
}

void InteractionSegment::on_segmentButton_clicked() {
	ui.ScribbleWidget->segment();
}

void InteractionSegment::on_okButton_clicked() {
	QDialog::accept();
}

void InteractionSegment::saveImage(const QImage &img) {
	QString initialPath = QDir::currentPath() + "/untitled.jpg";

	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
		initialPath,
		tr("Images (*.png *.xpm *.jpg)"));

	if (!fileName.isEmpty()) {
		ui.ScribbleWidget->saveImage(fileName, "JPG", img);
	}
}