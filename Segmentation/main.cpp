#include "segmentation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Segmentation w;
	w.setFixedSize(w.width(), w.height());
	w.show();
	return a.exec();
}
