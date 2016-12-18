#pragma once

#include<QtWidgets\qlabel.h>

class LabelGame : public QLabel {
	Q_OBJECT
public:
	explicit LabelGame(QWidget* parent = 0): QLabel(parent){}
signals:
	void leftClick(double x, double y);
	void rightClick(double x, double y);
	void dbClick(double x, double y);
	void mClick();
private:
	void mousePressEvent(QMouseEvent* e);
	void mouseDoubleClickEvent(QMouseEvent* e);
};
