// Paged window


#pragma once
#include<QtWidgets\qmainwindow.h>

#include<map>

#ifndef WINDOWPAGE_H
#define WINDOWPAGE_H

class PageHostWindow;

	// A page in the window
class WindowPage : public QWidget {
	Q_OBJECT
public:
	WindowPage(QWidget* parent = 0) : QWidget(parent){}
	~WindowPage() {}

	// execute on application init
	virtual void Init(){}

	// execute on application quit
	virtual void Release(){}

	// execute before page start. doing things of scene.
	virtual void SetScene(){}

	// execute on page start
	virtual void Load(QString lastPage, void* params){}

	// execute on change page
	virtual void Exit(){}

	// execute on resize
	virtual void Resize(int width, int height){}
};

	// The host window for pages
class PageHostWindow : public QMainWindow {
	Q_OBJECT
	
public:
	explicit PageHostWindow(QWidget* parent = 0);

	~PageHostWindow();

	void LoadPage(QString name, WindowPage* page) { pages[name] = page; }

	void InitSelf();

	// add initself in it
	virtual void Init(){}

	// execute in the last
	virtual void Release(){}

	void ChangePage(QString nextPage, void* params = 0);

signals:
	void Resize(int width, int height);

public slots:
	void Exit();

protected:
	std::map<QString, WindowPage*> pages;
	QString currentPage;
	int state;
	void* startParams;

	void resizeEvent(QResizeEvent* e);
};

#endif