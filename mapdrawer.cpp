#include"mine.h"

Scalar mapDrawer::getColor(int num, int flag) {
	if (flag == STATE_OPENED) {
		if (num == 1)return Scalar(255, 128, 0);
		else if (num == 2)return Scalar(0, 255, 128);
		else if (num == 3)return Scalar(0, 255, 255);
		else if (num == 4)return Scalar(0, 188, 249);
		else if (num == 5)return Scalar(255, 0, 255);
		else if (num == 6)return Scalar(191, 0, 191);
		else if (num == 7)return Scalar(128, 0, 255);
		else if (num == 8)return Scalar(0, 0, 255);
		else return Scalar(0, 0, 0);
	}
	else if (flag == STATE_CLOSED) {
		return Scalar(13, 219, 249);
	}
	else if (flag == STATE_KILLED) {
		return Scalar(28, 11, 232);
	}
	else if (flag == STATE_MARKED) {
		return cvRed;
	}
	else return Scalar(0, 0, 0);
}
void mapDrawer::paint(Mat& img, Point point, int lengthx, int lengthy, const Scalar &color, int flag) {
	if (flag == DRAW_NORMAL)rectangle(img, point, Point(point.x + lengthx, point.y + lengthy), color, -1);
	else if (flag == DRAW_ROUND)circle(img, Point(point.x + 0.5*lengthx, point.y + 0.5*lengthy), Min(lengthx / 2, lengthy / 2), color, -1);
}
void mapDrawer::Bind(mineMap* map, int drawflag, int label) {
	this->map = map;
	this->drawflag = drawflag;
	this->drawLabel = label;
}
void mapDrawer::Draw(Mat& pic) {

	//	Mat pic(height,width,CV_8UC3,cvBlack);
	const int cellW = pic.cols / map->m_width, cellH = pic.rows / map->m_height;

	if (map->GameState() == M_UNSTART) {
		pic = Mat(pic.rows, pic.cols, CV_8UC3, getColor(0, STATE_CLOSED));
		for (int x = 1; x<map->m_width; x++) {
			line(pic, Point(x*cellW, 0), Point(x*cellW, pic.rows), cvWhite);
		}
		for (int y = 1; y<map->m_height; y++) {
			line(pic, Point(0, y*cellH), Point(pic.cols, y*cellH), cvWhite);
		}
		//		imshow(window,pic);
		return;
	}

	for (int x = 0; x<map->m_width; x++)
		for (int y = 0; y<map->m_height; y++) {
			if (map->getLattice(x, y)->state != STATE_OPENED) {
				if (drawflag != DRAW_DARK)
					paint(pic, Point(cellW*x, cellH*y), cellW, cellH, getColor(0, map->getLattice(x, y)->state), drawflag);
				else {
					if (map->getLattice(x, y)->state == STATE_MARKED || map->getLattice(x, y)->state == STATE_KILLED)
						paint(pic, Point(cellW*x, cellH*y), cellW, cellH, getColor(0, map->getLattice(x, y)->state), 0);
				}
				if (drawflag == DRAW_NORMAL) {
					rectangle(pic, Point(cellW*x, cellH*y), Point(cellW*(x + 1), cellH*(y + 1)), cvWhite, 1);
				}

			}
			else {
				if (drawLabel) {
					if (map->getLattice(x, y)->getlabel()>0)
						putText(pic, toString(map->getLattice(x, y)->getlabel()), Point(cellW*(x + 0.2), cellH*(y + 0.8)), CV_FONT_HERSHEY_DUPLEX, 0.8,
							getColor(map->getLattice(x, y)->getlabel(), STATE_OPENED));
				}
				else {
					paint(pic, Point(cellW*x, cellH*y), cellW, cellH, getColor(map->getLattice(x, y)->getlabel(), STATE_OPENED), 0);
				}

			}
		}
	//imshow(window,pic);
}