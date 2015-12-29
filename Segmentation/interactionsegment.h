#ifndef INTERACTIONSEGMENT_H
#define INTERACTIONSEGMENT_H

#include <QDialog>
#include <qdir.h>
#include <qfiledialog.h>
#include "ui_interactionsegment.h"
#include <iostream>

using namespace std;

class InteractionSegment : public QDialog
{
	Q_OBJECT

public:
	InteractionSegment(QWidget *parent = 0);
	~InteractionSegment();

	Ui::InteractionSegment ui;

	void saveImage(const QImage &img);

private slots:
	void on_foreButton_clicked();
	void on_backButton_clicked();
	void on_clearButton_clicked();
	void on_brushSpinBox_valueChanged(int i);
	void on_segmentButton_clicked();
	void on_okButton_clicked();
};

#endif // INTERACTIONSEGMENT_H
