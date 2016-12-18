#include"mainWindow.h"
#include<QtWidgets\qapplication.h>

#include<QtCore\qfile.h>

int main(int argc, char** argv){
	
	QApplication app(argc, argv);
	QFile stylesheet("style.qss");
	stylesheet.open(QFile::ReadOnly);
	QString style = stylesheet.readAll();
	app.setStyleSheet(style);
	stylesheet.close();

	myWindow window;
	window.show();

	return app.exec();
}