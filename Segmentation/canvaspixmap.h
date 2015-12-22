#ifndef CANVASPIXMAP_H
#define CANVASPIXMAP_H

#include <QPixmap>

class canvasPixmap : public QPixmap
{
	Q_OBJECT

public:
	canvasPixmap(QObject *parent);
	~canvasPixmap();

private:
	
};

#endif // CANVASPIXMAP_H
