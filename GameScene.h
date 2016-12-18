/********************************************************************************
** Form generated from reading UI file 'GameScene.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "mainWindowSignals.h"

QT_BEGIN_NAMESPACE

class Ui_GameScene
{
public:
    QWidget *centralwidget;
    QLabel *labelTime;
    QLabel *labelMines;
    LabelGame *labelGame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameScene)
    {
        if (GameScene->objectName().isEmpty())
            GameScene->setObjectName(QStringLiteral("GameScene"));
        GameScene->resize(905, 464);
        GameScene->setStyleSheet(QStringLiteral("background-color:black;"));
        centralwidget = new QWidget(GameScene);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        labelTime = new QLabel(centralwidget);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setGeometry(QRect(30, 400, 221, 16));
        QFont font;
        font.setPointSize(12);
        labelTime->setFont(font);
        labelTime->setStyleSheet(QStringLiteral("color:white;"));
        labelMines = new QLabel(centralwidget);
        labelMines->setObjectName(QStringLiteral("labelMines"));
        labelMines->setGeometry(QRect(470, 400, 151, 16));
        labelMines->setFont(font);
        labelMines->setStyleSheet(QStringLiteral("color:white"));
        labelGame = new LabelGame(centralwidget);
        labelGame->setObjectName(QStringLiteral("labelGame"));
        labelGame->setGeometry(QRect(0, 0, 701, 341));
        labelGame->setStyleSheet(QStringLiteral("background-color:black;"));
        GameScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameScene);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 905, 21));
        GameScene->setMenuBar(menubar);
        statusbar = new QStatusBar(GameScene);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        GameScene->setStatusBar(statusbar);

        retranslateUi(GameScene);

        QMetaObject::connectSlotsByName(GameScene);
    } // setupUi

    void retranslateUi(QMainWindow *GameScene)
    {
        GameScene->setWindowTitle(QApplication::translate("GameScene", "MainWindow", 0));
        labelTime->setText(QApplication::translate("GameScene", "Time:", 0));
        labelMines->setText(QApplication::translate("GameScene", "Mines:", 0));
    } // retranslateUi

};

namespace Ui {
    class GameScene: public Ui_GameScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GAMESCENE_H
