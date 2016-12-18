#include"EndPage.h"
#include"mine.h"

// top apis

void EndPage::SetScene()
{
	scene->setupUi(window);
	connect(((Ui::EndScene*)scene)->buttonGo, &QPushButton::clicked, this, &EndPage::ButtonGoClick);
	connect(((Ui::EndScene*)scene)->buttonCancel, &QPushButton::clicked, window, &PageHostWindow::Exit);
}
void EndPage::Load(QString lastPage, void* params) {

	if (window->gameState == M_WIN) {	// write win time and score.
		if (window->gameTime >= window->record[window->gameLevel - 1])
			((Ui::EndScene*)scene)->labelStart->setText(tr("<h2>Congratulations, you win!</h2>"));
		else
			scene->labelStart->setText(tr("<h2>Amazing! You break the record!</h2>"));
		time_t timer;	tm date;
		time(&timer);	localtime_s(&date, &timer);

		ofstream file("record.txt", ios::app);
		file << date.tm_year + 1900 << '/' << (date.tm_mon + 1) << '/' << date.tm_mday << '\t' << window->gameLevel << '\t' << window->gameTime << endl;
		file.close();

	}
	else if (window->gameState == M_LOSE) {
		((Ui::EndScene*)scene)->labelStart->setText(tr("<h2>Sorry, you lose. Again?</h2>"));
	}
	string label_times = "Time: " + toString<int>(window->gameTime) + "/" + toString<int>(window->record[window->gameLevel - 1]);
	string label_clicktimes = "Clicktimes: " + toString<int>(window->clickTimes);
	scene->labelTime->setText(tr(label_times.c_str()));
	scene->labelClicktimes->setText(tr(label_clicktimes.c_str()));
}

void EndPage::ButtonGoClick() {
	window->ChangePage(tr("GamePage"));
}