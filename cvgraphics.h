#pragma once

#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>

class cvwindow {
public:
	int m_width, m_height;
private:
	string m_title;	
	Mat* showImg, *drawImg;

public:
	cvwindow() {
	}
	cvwindow(int width, int height, const string title) {
		m_width = width;
		m_height = height;
		m_title = title;
		showImg = new Mat(m_height, m_width, CV_8UC3, Scalar(0, 0, 0));
		drawImg = new Mat(m_height, m_width, CV_8UC3, Scalar(0, 0, 0));
	}
	~cvwindow() {
		Release();
	}
	// show the window
	void Show() {
		namedWindow(m_title, WINDOW_NORMAL);
		resizeWindow(m_title, m_width, m_height);
		imshow(m_title, *showImg);
	}
	// close window
	void Close() {
		destroyWindow(m_title);
	}
	// paint the image into the window, used in draw callback
	void Draw() {
		imshow(m_title, *showImg);
	}
	// update the draw result into show image, used in gameloop callback
	void Update() {
		auto t = drawImg;
		drawImg = showImg;
		showImg = t;
		drawImg->setTo(cvBlack);
	}
	// clear window
	void Clear(Scalar color = cvBlack) {
		drawImg->setTo(color);
	}
	// resize
	void Resize(int width, int height) {
		m_width = width;
		m_height = height;
		resizeWindow(m_title, width, height);
		resize(*drawImg, *showImg, Size(height, width));
		Draw();
		*drawImg = Mat(m_width, m_height, CV_8UC3, cvBlack);
		Update();
	}
	const string GetTitle() { return m_title; }
	// paint picture from source
	void Paint(const Mat& sourceImg) {
		*drawImg = sourceImg;
	}
	// paint rectangle
	void Rectangle(int x1, int y1, int x2, int y2, Scalar color = cvBlack, int border = 1, Scalar borderColor = cvWhite) {
		rectangle(*drawImg, Rect(x1, y1, x2 - x1, y2 - y1), color);
		if (border > 0) {
			line(*drawImg, Point(x1, y1), Point(x2, y1), borderColor, border);
			line(*drawImg, Point(x2, y1), Point(x2, y2), borderColor, border);
			line(*drawImg, Point(x1, y2), Point(x2, y2), borderColor, border);
			line(*drawImg, Point(x1, y2), Point(x1, y1), borderColor, border);
		}
	}
	// write text
	void Write(const string& text, int x, int y, Scalar color = cvWhite) {
		putText(*drawImg, text, Point(x, y), CV_FONT_HERSHEY_DUPLEX, 0.8, color);
	}
	void Release() {
		Close();
		delete showImg;
		delete drawImg;
	}
};