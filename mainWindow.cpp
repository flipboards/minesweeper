#include"BeginPage.h"
#include"GamePage.h"
#include"EndPage.h"

// construct functions
myWindow::myWindow(QMainWindow* parent) : PageHostWindow(parent){
	LoadPage(tr("BeginPage"), new BeginPage(this));
	LoadPage(tr("GamePage"), new GamePage(this));
	LoadPage(tr("EndPage"), new EndPage(this));
	currentPage = tr("BeginPage");
	Init();
}

void myWindow::Init() {

	InitSelf();
}