/********************************************************************************
** Form generated from reading UI file 'BeginScene.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BEGINSCENE_H
#define BEGINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BeginScene
{
public:
    QAction *actionEasy;
    QAction *actionNormal;
    QAction *actionHard;
    QAction *actionPlain;
    QAction *actionCircular;
    QAction *actionBlack;
    QAction *actionExit;
    QAction *actionExit_2;
    QAction *actionNumber;
    QAction *actionColor;
    QWidget *centralwidget;
    QLabel *labelStart;
    QFrame *line;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelRecord_2;
    QLabel *labelRecord_3;
    QLabel *labelRecord_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *buttonGo;
    QPushButton *buttonCancel;
    QLabel *labelRecord;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelRecordEasy;
    QLabel *labelRecordNormal;
    QLabel *labelRecordHard;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuLevel;
    QMenu *menuStyle;
    QMenu *menuLabelStyle;

    void setupUi(QMainWindow *BeginScene)
    {
        if (BeginScene->objectName().isEmpty())
            BeginScene->setObjectName(QStringLiteral("BeginScene"));
        BeginScene->resize(960, 540);
        actionEasy = new QAction(BeginScene);
        actionEasy->setObjectName(QStringLiteral("actionEasy"));
        actionEasy->setCheckable(true);
        actionNormal = new QAction(BeginScene);
        actionNormal->setObjectName(QStringLiteral("actionNormal"));
        actionNormal->setCheckable(true);
        actionHard = new QAction(BeginScene);
        actionHard->setObjectName(QStringLiteral("actionHard"));
        actionHard->setCheckable(true);
        actionHard->setChecked(true);
        actionPlain = new QAction(BeginScene);
        actionPlain->setObjectName(QStringLiteral("actionPlain"));
        actionPlain->setCheckable(true);
        actionPlain->setChecked(true);
        actionCircular = new QAction(BeginScene);
        actionCircular->setObjectName(QStringLiteral("actionCircular"));
        actionCircular->setCheckable(true);
        actionBlack = new QAction(BeginScene);
        actionBlack->setObjectName(QStringLiteral("actionBlack"));
        actionBlack->setCheckable(true);
        actionExit = new QAction(BeginScene);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit_2 = new QAction(BeginScene);
        actionExit_2->setObjectName(QStringLiteral("actionExit_2"));
        actionNumber = new QAction(BeginScene);
        actionNumber->setObjectName(QStringLiteral("actionNumber"));
        actionNumber->setCheckable(true);
        actionNumber->setChecked(true);
        actionColor = new QAction(BeginScene);
        actionColor->setObjectName(QStringLiteral("actionColor"));
        actionColor->setCheckable(true);
        centralwidget = new QWidget(BeginScene);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        labelStart = new QLabel(centralwidget);
        labelStart->setObjectName(QStringLiteral("labelStart"));
        labelStart->setGeometry(QRect(60, 30, 401, 81));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font.setPointSize(10);
        labelStart->setFont(font);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(60, 210, 411, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 250, 231, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelRecord_2 = new QLabel(verticalLayoutWidget);
        labelRecord_2->setObjectName(QStringLiteral("labelRecord_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setPointSize(13);
        labelRecord_2->setFont(font1);

        verticalLayout->addWidget(labelRecord_2);

        labelRecord_3 = new QLabel(verticalLayoutWidget);
        labelRecord_3->setObjectName(QStringLiteral("labelRecord_3"));
        labelRecord_3->setFont(font1);

        verticalLayout->addWidget(labelRecord_3);

        labelRecord_4 = new QLabel(verticalLayoutWidget);
        labelRecord_4->setObjectName(QStringLiteral("labelRecord_4"));
        labelRecord_4->setFont(font1);

        verticalLayout->addWidget(labelRecord_4);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(590, 270, 151, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        buttonGo = new QPushButton(verticalLayoutWidget_2);
        buttonGo->setObjectName(QStringLiteral("buttonGo"));
        QFont font2;
        font2.setPointSize(14);
        buttonGo->setFont(font2);
        buttonGo->setFlat(true);

        verticalLayout_2->addWidget(buttonGo);

        buttonCancel = new QPushButton(verticalLayoutWidget_2);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setFont(font2);
        buttonCancel->setFlat(true);

        verticalLayout_2->addWidget(buttonCancel);

        labelRecord = new QLabel(centralwidget);
        labelRecord->setObjectName(QStringLiteral("labelRecord"));
        labelRecord->setGeometry(QRect(60, 160, 181, 51));
        labelRecord->setFont(font1);
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(320, 250, 133, 141));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelRecordEasy = new QLabel(verticalLayoutWidget_3);
        labelRecordEasy->setObjectName(QStringLiteral("labelRecordEasy"));
        labelRecordEasy->setFont(font1);

        verticalLayout_3->addWidget(labelRecordEasy);

        labelRecordNormal = new QLabel(verticalLayoutWidget_3);
        labelRecordNormal->setObjectName(QStringLiteral("labelRecordNormal"));
        labelRecordNormal->setFont(font1);

        verticalLayout_3->addWidget(labelRecordNormal);

        labelRecordHard = new QLabel(verticalLayoutWidget_3);
        labelRecordHard->setObjectName(QStringLiteral("labelRecordHard"));
        labelRecordHard->setFont(font1);

        verticalLayout_3->addWidget(labelRecordHard);

        BeginScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BeginScene);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 21));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        menuLevel = new QMenu(menuGame);
        menuLevel->setObjectName(QStringLiteral("menuLevel"));
        menuLevel->setAutoFillBackground(false);
        menuStyle = new QMenu(menuGame);
        menuStyle->setObjectName(QStringLiteral("menuStyle"));
        menuLabelStyle = new QMenu(menuGame);
        menuLabelStyle->setObjectName(QStringLiteral("menuLabelStyle"));
        BeginScene->setMenuBar(menubar);

        menubar->addAction(menuGame->menuAction());
        menuGame->addAction(menuLevel->menuAction());
        menuGame->addAction(menuStyle->menuAction());
        menuGame->addAction(menuLabelStyle->menuAction());
        menuGame->addSeparator();
        menuGame->addAction(actionExit_2);
        menuLevel->addAction(actionEasy);
        menuLevel->addAction(actionNormal);
        menuLevel->addAction(actionHard);
        menuStyle->addAction(actionPlain);
        menuStyle->addAction(actionCircular);
        menuStyle->addAction(actionBlack);
        menuLabelStyle->addSeparator();
        menuLabelStyle->addAction(actionNumber);
        menuLabelStyle->addAction(actionColor);

        retranslateUi(BeginScene);

        QMetaObject::connectSlotsByName(BeginScene);
    } // setupUi

    void retranslateUi(QMainWindow *BeginScene)
    {
        BeginScene->setWindowTitle(QApplication::translate("BeginScene", "Minesweeper", 0));
        actionEasy->setText(QApplication::translate("BeginScene", "Easy", 0));
        actionNormal->setText(QApplication::translate("BeginScene", "Normal", 0));
        actionHard->setText(QApplication::translate("BeginScene", "Hard", 0));
        actionPlain->setText(QApplication::translate("BeginScene", "Plain", 0));
        actionCircular->setText(QApplication::translate("BeginScene", "Circular", 0));
        actionBlack->setText(QApplication::translate("BeginScene", "Black", 0));
        actionExit->setText(QApplication::translate("BeginScene", "New", 0));
        actionExit_2->setText(QApplication::translate("BeginScene", "Exit", 0));
        actionNumber->setText(QApplication::translate("BeginScene", "Number", 0));
        actionColor->setText(QApplication::translate("BeginScene", "Color", 0));
        labelStart->setText(QApplication::translate("BeginScene", "<h1>Desktop Minesweeper</h1>", 0));
        labelRecord_2->setText(QApplication::translate("BeginScene", "Easy (10x10):", 0));
        labelRecord_3->setText(QApplication::translate("BeginScene", "Normal (30x16):", 0));
        labelRecord_4->setText(QApplication::translate("BeginScene", "Hard (30x30):", 0));
        buttonGo->setText(QApplication::translate("BeginScene", "Go", 0));
        buttonCancel->setText(QApplication::translate("BeginScene", "Exit", 0));
        labelRecord->setText(QApplication::translate("BeginScene", "Your Record: ", 0));
        labelRecordEasy->setText(QApplication::translate("BeginScene", "0", 0));
        labelRecordNormal->setText(QApplication::translate("BeginScene", "0", 0));
        labelRecordHard->setText(QApplication::translate("BeginScene", "0", 0));
        menuGame->setTitle(QApplication::translate("BeginScene", "Game", 0));
        menuLevel->setTitle(QApplication::translate("BeginScene", "Level", 0));
        menuStyle->setTitle(QApplication::translate("BeginScene", "PaintStyle", 0));
        menuLabelStyle->setTitle(QApplication::translate("BeginScene", "LabelStyle", 0));
    } // retranslateUi

};

namespace Ui {
    class BeginScene: public Ui_BeginScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BEGINSCENE_H
