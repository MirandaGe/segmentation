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

bool InteractionSegment::saveImage(const QImage &img, const QString &pathName) {
	if (!pathName.isEmpty()) {
		return ui.ScribbleWidget->saveImage(pathName, "JPG", img);
	}
	else {
		return false;
	}
}