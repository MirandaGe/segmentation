#include "segmentation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Segmentation w;
	w.show();
	return a.exec();
}
