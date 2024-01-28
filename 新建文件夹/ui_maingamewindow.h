#ifndef UI_MAINGAMEWINDOW_H
#define UI_MAINGAMEWINDOW_H

#include <QtCore/QCoreApplication>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGameWindow
{
public:
    QAction *actionStart;
    QAction *actionBasic;
    QAction *actionMedium;
    QAction *actionHard;
    QAction *actionQuit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuLevel;

    void setupUi(QMainWindow *MainGameWindow)
    {
        if (MainGameWindow->objectName().isEmpty())
            MainGameWindow->setObjectName(QStringLiteral("MainGameWindow"));
        MainGameWindow->resize(400, 300);
        actionStart = new QAction(MainGameWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionBasic = new QAction(MainGameWindow);
        actionBasic->setObjectName(QStringLiteral("actionBasic"));
        actionMedium = new QAction(MainGameWindow);
        actionMedium->setObjectName(QStringLiteral("actionMedium"));
        actionHard = new QAction(MainGameWindow);
        actionHard->setObjectName(QStringLiteral("actionHard"));
        actionQuit = new QAction(MainGameWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainGameWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainGameWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainGameWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuLevel = new QMenu(menu);
        menuLevel->setObjectName(QStringLiteral("menuLevel"));
        MainGameWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionStart);
        menu->addAction(menuLevel->menuAction());
        menu->addAction(actionQuit);
        menuLevel->addAction(actionBasic);
        menuLevel->addAction(actionMedium);
        menuLevel->addAction(actionHard);

        retranslateUi(MainGameWindow);

        QMetaObject::connectSlotsByName(MainGameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainGameWindow)
    {
        MainGameWindow->setWindowTitle(QCoreApplication::translate("MainGameWindow", "MainGameWindow", nullptr));
        actionStart->setText(QCoreApplication::translate("MainGameWindow", "start", nullptr));
        actionBasic->setText(QCoreApplication::translate("MainGameWindow", "basic", nullptr));
        actionMedium->setText(QCoreApplication::translate("MainGameWindow", "medium", nullptr));
        actionHard->setText(QCoreApplication::translate("MainGameWindow", "hard", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainGameWindow", "quit", nullptr));
        menu->setTitle(QCoreApplication::translate("MainGameWindow", "Game", nullptr));
        menuLevel->setTitle(QCoreApplication::translate("MainGameWindow", "level", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainGameWindow: public Ui_MainGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAMEWINDOW_H
