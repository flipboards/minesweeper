#include "windowpage.h"
#include<iostream>

PageHostWindow::PageHostWindow(QWidget* parent) : 
	QMainWindow(parent), state(0), startParams(nullptr) {
}

PageHostWindow::~PageHostWindow() {
	state = 0;
	for (const auto& page : pages) {
		page.second->Release();
		delete page.second;
	}
	Release();
}

void PageHostWindow::InitSelf()
{
	currentPage = tr("");
	for (const auto& page : pages) {
		page.second->Init();
	}
	if (pages.empty()) {
		std::cerr << "Cannot find any pages. Exiting...";
		Exit();
		return;
	}
	if (currentPage.isEmpty())currentPage = pages.begin()->first;
	pages[currentPage]->SetScene();
	pages[currentPage]->Load(tr(""), startParams);
	connect(this, &PageHostWindow::Resize, pages[currentPage], &WindowPage::Resize);
	state = 1;
}

void PageHostWindow::ChangePage(QString nextPage, void* params) {
	if (pages.find(nextPage) == pages.end()) {
		std::cerr << "Cannot find page " << nextPage.toStdString() << std::endl;
		std::cerr << "Current page is " << currentPage.toStdString() << std::endl;
		return;
	}
	state = 0;
	disconnect(this, &PageHostWindow::Resize, pages[currentPage], &WindowPage::Resize);
	pages[currentPage]->Exit();
	QString lastPage = currentPage;
	currentPage = nextPage;
	pages[currentPage]->SetScene();
	state = 1;
	connect(this, &PageHostWindow::Resize, pages[currentPage], &WindowPage::Resize);
	pages[currentPage]->Load(lastPage, params);
}

void PageHostWindow::resizeEvent(QResizeEvent* e) {
/*	if (state == 1) {
		pages[currentPage]->Resize(width(), height());
		pages[currentPage]->SetScene();
	}*/
	emit Resize(width(), height());
}

void PageHostWindow::Exit() {
	pages[currentPage]->Exit();
	close();
}