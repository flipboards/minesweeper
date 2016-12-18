// End Page

#pragma once
#include"mainWindow.h"
#include"EndScene.h"

class EndPage : public WindowPage {
	Q_OBJECT
public:
	myWindow* window;
	Ui::EndScene* scene;

	explicit EndPage::EndPage(myWindow* parent = 0) : 
		WindowPage(parent), window(parent), scene(new Ui::EndScene) {
	}
	~EndPage() {
		delete scene;
	}
	void Load(QString lastPage, void* params);
	void SetScene();

public slots:
	void ButtonGoClick();
};