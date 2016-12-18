#include"GamePage.h"

#include<QtGui\qimage.h>
#include<QtGui\qevent.h>

// top apis

void GamePage::SetScene()
{
	scene->setupUi(window);

	connect(scene->labelGame, &LabelGame::leftClick, this, &GamePage::LeftClick);
	connect(scene->labelGame, &LabelGame::rightClick, this, &GamePage::RightClick);
	connect(scene->labelGame, &LabelGame::dbClick, this, &GamePage::DbClick);
	connect(scene->labelGame, &LabelGame::mClick, this, &GamePage::MClick);
}
void GamePage::Init() {
	srand((unsigned)time(0));
	Map = new mineMap();
}
void GamePage::Load(QString lastPage, void* params) {
	int mapWidth, mapHeight;

	if (window->gameLevel == 1) { mapWidth = 10; mapHeight = 10; mineNumber = 10; }
	else if (window->gameLevel == 2) { mapWidth = 16; mapHeight = 16; mineNumber = 40; }
	else if (window->gameLevel == 3) { mapWidth = 30; mapHeight = 16; mineNumber = 99; }

	Map->Set(mapWidth, mapHeight, mineNumber);
	solver = new solveMap();
	drawer = new mapDrawer();
	drawer->Bind(Map, window->drawStyle, window->showLabel);
	window->gameTime = 0;
	window->gameState = 0;
	clickTimes = 0;

	if (myPagePos.isEmpty())
		window->resize(Map->m_width * 30 + 10, Map->m_height * 30 + 55);
	else {
		window->move(myPagePos.topLeft());
		window->resize(myPagePos.size());
	}

}
void GamePage::Exit() {
	killTimer(myTimerId);
	window->gameState = Map->GameState();
	Map->Clear();

	myPagePos.setTopLeft(window->pos());
	myPagePos.setSize(window->size());
	delete drawer;
	delete solver;
}
void GamePage::Release() {
	delete Map;
}

// events

void GamePage::timerEvent(QTimerEvent* e) {
	DisplayTime();
	clickTimes++;
}
void GamePage::LeftClick(double x, double y) {

	//have win
	if (Map->GameState() == M_WIN || Map->GameState() == M_LOSE) {
		window->clickTimes = clickTimes;
		window->ChangePage(tr("EndPage"));
		return;
	}

	//haven't click before, open
	if (clickTimes == 0) {
		Map->Generate(x * Map->m_width, y * Map->m_height);
		myTimerId = startTimer(1000);
		solver->Bind(Map);
	}
	Map->Open(x * Map->m_width, y * Map->m_height);
	clickTimes++;
	DisplayBoard();
	DisplayMines();
}
void GamePage::RightClick(double x, double y) {

	//have win
	if (Map->GameState() == M_WIN || Map->GameState() == M_LOSE) {
		window->clickTimes = clickTimes;
		window->ChangePage(tr("EndPage"));
		return;
	}

	if (clickTimes > 0)Map->Mark(x * Map->m_width, y * Map->m_height);
	clickTimes++;
	DisplayBoard();
	DisplayMines();
}

void GamePage::DbClick(double x, double y) {

	if (clickTimes > 0)Map->FastOpen(x * Map->m_width, y * Map->m_height);
	clickTimes += 2;
	DisplayBoard();
	DisplayMines();
}

void GamePage::MClick() {
	if (clickTimes > 0)solver->Solve(1);
	DisplayBoard();
	DisplayMines();
}

void GamePage::Resize(int width, int height) {
	scene->labelGame->resize(width - 10, height - 55);
	scene->labelGame->move(5, 5);
	scene->labelTime->move(width * 0.1, height - 40);
	scene->labelMines->move(width * 0.6, height - 40);
	DisplayBoard();
	DisplayMines();
	DisplayTime();
}

// bottom apis

void GamePage::DisplayTime() {
	string display_tmp = "Time: " + toString<int>(window->gameTime);
	scene->labelTime->setText(tr(display_tmp.c_str()));
	window->gameTime++;
}

void GamePage::DisplayMines() {
	string display_tmp = "Mines: " + toString<int>(Map->m_mineleft);
	scene->labelMines->setText(tr(display_tmp.c_str()));
}

void GamePage::DisplayBoard() {
	Mat image(scene->labelGame->height(), scene->labelGame->width(), CV_8UC3, cvBlack);
	drawer->Draw(image);
	cvtColor(image, image, CV_BGR2RGB);
	QImage img_to_draw =
		QImage((const unsigned char*)image.data, image.cols, image.rows, image.cols*image.channels(), QImage::Format_RGB888);
	scene->labelGame->setPixmap(QPixmap::fromImage(img_to_draw));
}