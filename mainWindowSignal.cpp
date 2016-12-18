#include"mainWindowSignals.h"
#include<QtGui\qevent.h>


void LabelGame::mousePressEvent(QMouseEvent* e) {
	if (e->buttons() == Qt::LeftButton)emit leftClick(e->x() / (double)width(), e->y() / (double)height());
	else if (e->buttons() == Qt::RightButton)emit rightClick(e->x() / (double)width(), e->y() / (double)height());
	else if (e->buttons() == Qt::MiddleButton)emit mClick();
	else if (e->buttons() == Qt::LeftButton | Qt::RightButton)emit dbClick(e->x() / (double)width(), e->y() / (double)height());
}

void LabelGame::mouseDoubleClickEvent(QMouseEvent * e)
{
	if (e->button() == Qt::RightButton)emit mClick();
}