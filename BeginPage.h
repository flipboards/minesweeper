#pragma once
#include"mainWindow.h"
#include"BeginScene.h"

class BeginPage : public WindowPage {
	Q_OBJECT
	
public:
	myWindow* window;
	Ui::BeginScene* scene;

	explicit BeginPage(myWindow* parent = 0) :
		WindowPage(parent), scene(new Ui::BeginScene) {
		window = parent;
	}
	~BeginPage() {
		delete scene;
	}
	void SetScene();
	void Load(QString lastPage, void* params);
	void Exit();

public slots:
	void ButtonGoClick();
};