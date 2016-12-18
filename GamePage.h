// Game Page (main functions of game)

#pragma once
#include "mainWindow.h"
#include "GameScene.h"
#include "mine.h"

class GamePage : public WindowPage {
	Q_OBJECT
public:

	myWindow* window;
	Ui::GameScene* scene;

	explicit GamePage::GamePage(myWindow* parent = 0) : 
		WindowPage(parent), window(parent), scene(new Ui::GameScene) {
	}
	~GamePage() {
		delete scene;
	}

	void SetScene();
	void Init();
	void Load(QString lastPage, void* params);
	void Exit();
	void Release();

private:

	mineMap* Map;
	solveMap* solver;
	mapDrawer* drawer;

	int myTimerId;
	int clickTimes;
	int mineNumber;

	QRect myPagePos;

	void timerEvent(QTimerEvent* e);

	void DisplayTime();
	void DisplayMines();
	void DisplayBoard();

private slots:

	void LeftClick(double x, double y);
	void RightClick(double x, double y);
	void DbClick(double x, double y);
	void MClick();
	void Resize(int width, int height);
};