/********************************************************************************
** Form generated from reading UI file 'EndScene.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ENDSCENE_H
#define ENDSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndScene
{
public:
    QWidget *centralwidget;
    QLabel *labelStart;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonGo;
    QPushButton *buttonCancel;
    QLabel *labelData;
    QFrame *line;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelTime;
    QLabel *labelClicktimes;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EndScene)
    {
        if (EndScene->objectName().isEmpty())
            EndScene->setObjectName(QStringLiteral("EndScene"));
        EndScene->resize(960, 540);
        centralwidget = new QWidget(EndScene);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        labelStart = new QLabel(centralwidget);
        labelStart->setObjectName(QStringLiteral("labelStart"));
        labelStart->setGeometry(QRect(50, 90, 411, 41));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        labelStart->setFont(font);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(590, 240, 160, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        buttonGo = new QPushButton(verticalLayoutWidget);
        buttonGo->setObjectName(QStringLiteral("buttonGo"));
        QFont font1;
        font1.setPointSize(14);
        buttonGo->setFont(font1);
        buttonGo->setFlat(true);

        verticalLayout->addWidget(buttonGo);

        buttonCancel = new QPushButton(verticalLayoutWidget);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setFont(font1);
        buttonCancel->setFlat(true);

        verticalLayout->addWidget(buttonCancel);

        labelData = new QLabel(centralwidget);
        labelData->setObjectName(QStringLiteral("labelData"));
        labelData->setGeometry(QRect(60, 220, 111, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font2.setPointSize(14);
        labelData->setFont(font2);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(50, 260, 411, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(150, 280, 251, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelTime = new QLabel(verticalLayoutWidget_2);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setFont(font2);

        verticalLayout_2->addWidget(labelTime);

        labelClicktimes = new QLabel(verticalLayoutWidget_2);
        labelClicktimes->setObjectName(QStringLiteral("labelClicktimes"));
        labelClicktimes->setFont(font2);

        verticalLayout_2->addWidget(labelClicktimes);

        EndScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EndScene);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 21));
        EndScene->setMenuBar(menubar);
        statusbar = new QStatusBar(EndScene);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        EndScene->setStatusBar(statusbar);

        retranslateUi(EndScene);

        QMetaObject::connectSlotsByName(EndScene);
    } // setupUi

    void retranslateUi(QMainWindow *EndScene)
    {
        EndScene->setWindowTitle(QApplication::translate("EndScene", "MainWindow", 0));
        labelStart->setText(QApplication::translate("EndScene", "<h1>Congratulations, you win! Try again?</h1>", 0));
        buttonGo->setText(QApplication::translate("EndScene", "Go", 0));
        buttonCancel->setText(QApplication::translate("EndScene", "Cancel", 0));
        labelData->setText(QApplication::translate("EndScene", "Game Data", 0));
        labelTime->setText(QApplication::translate("EndScene", "Time:0/0", 0));
        labelClicktimes->setText(QApplication::translate("EndScene", "Click Times: 0", 0));
    } // retranslateUi

};

namespace Ui {
    class EndScene: public Ui_EndScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ENDSCENE_H
