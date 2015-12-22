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