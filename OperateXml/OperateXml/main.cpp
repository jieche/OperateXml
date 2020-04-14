#include "operatexml.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OperateXml w;
	w.show();
	return a.exec();
}
