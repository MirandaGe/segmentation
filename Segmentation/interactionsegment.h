#ifndef INTERACTIONSEGMENT_H
#define INTERACTIONSEGMENT_H

#include <QDialog>
#include "ui_interactionsegment.h"

class InteractionSegment : public QDialog
{
	Q_OBJECT

public:
	InteractionSegment(QWidget *parent = 0);
	~InteractionSegment();

	Ui::InteractionSegment ui;
private:
	
};

#endif // INTERACTIONSEGMENT_H
