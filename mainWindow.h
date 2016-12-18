// definition of main window class
// entry point of whole window

#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "windowpage.h"

class myWindow : public PageHostWindow {
	Q_OBJECT
public:
	explicit myWindow(QMainWindow *parent = 0);
	int gameTime;
	int gameState;
	int gameLevel;
	int drawStyle;
	int showLabel;
	int clickTimes;
	int record[3];
	double winRate[3];

private:
	void Init();
};

#endif // !MAINWINDOW_H