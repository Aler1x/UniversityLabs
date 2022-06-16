/*
 * icon taked from:
 * https://www.flaticon.com/
 */

#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication	a(argc, argv);
	Widget			w;

	try {
	w.				setWindowIcon(QIcon(":/math.png"));
	w.				setWindowTitle("Calculator");
	w.				show();
	}
	catch(...){
		qDebug() << "Undefined error";
	}

	return			a.exec();
}
