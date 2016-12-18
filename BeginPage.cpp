#include"BeginPage.h"
#include"QtWidgets\qpushbutton.h"
/*
using namespace std;
#include"filenamehandler.h"*/
#include<QtCore\qfile.h>

// protected apis

void BeginPage::SetScene()
{
	scene->setupUi(window);
//	window->setStyleSheet(tr("background-color:white"));
	connect(scene->buttonGo, &QPushButton::clicked, this, &BeginPage::ButtonGoClick);
	connect(scene->buttonCancel, &QPushButton::clicked, window, &PageHostWindow::Exit);
}
void BeginPage::Load(QString lastPage, void* params) {
	QFile recordFile(tr("record.txt"));
	recordFile.open(QFile::ReadOnly);

	for (auto i = 0; i < 3; i++)
		window->record[i] = 2048;
	auto line = recordFile.readLine();
	while (!line.isNull()) {
		line.replace(tr("\r\n"), "\t");
		auto linesplit = line.split('\t');
		if (linesplit[2].toInt() < window->record[linesplit[1].toInt() - 1])
			window->record[linesplit[1].toInt() - 1] = linesplit[2].toInt();
		line = recordFile.readLine();
	}

	recordFile.close();
	if(window->record[0] != 2048)scene->labelRecordEasy->setText(QString::number(window->record[0]));
	if (window->record[1] != 2048)scene->labelRecordNormal->setText(QString::number(window->record[1]));
	if (window->record[2] != 2048)scene->labelRecordHard->setText(QString::number(window->record[2]));

}
void BeginPage::Exit() {
	if (scene->actionEasy->isChecked()) window->gameLevel = 1;
	else if (scene->actionNormal->isChecked()) window->gameLevel = 2;
	else if (scene->actionHard->isChecked()) window->gameLevel = 3;

	if (scene->actionPlain->isChecked()) window->drawStyle = 0;
	else if (scene->actionCircular->isChecked()) window->drawStyle = 1;
	else if (scene->actionBlack->isChecked()) window->drawStyle = 2;

	window->showLabel = 1;
}

// events

void BeginPage::ButtonGoClick() {
	window->ChangePage(tr("GamePage"));
}