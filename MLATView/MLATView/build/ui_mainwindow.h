/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *action_T_SVD;
    QAction *action_9;
    QAction *action_10;
    QAction *action_11;
    QAction *action_13;
    QAction *action_4;
    QAction *action_12;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menu_2;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QString::fromUtf8("action_7"));
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QString::fromUtf8("action_8"));
        action_T_SVD = new QAction(MainWindow);
        action_T_SVD->setObjectName(QString::fromUtf8("action_T_SVD"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QString::fromUtf8("action_9"));
        action_10 = new QAction(MainWindow);
        action_10->setObjectName(QString::fromUtf8("action_10"));
        action_11 = new QAction(MainWindow);
        action_11->setObjectName(QString::fromUtf8("action_11"));
        action_13 = new QAction(MainWindow);
        action_13->setObjectName(QString::fromUtf8("action_13"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_12 = new QAction(MainWindow);
        action_12->setObjectName(QString::fromUtf8("action_12"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menuMenu->addAction(action_4);
        menuMenu->addSeparator();
        menuMenu->addAction(action);
        menuMenu->addAction(action_2);
        menuMenu->addSeparator();
        menuMenu->addAction(action_5);
        menuMenu->addSeparator();
        menuMenu->addAction(action_13);
        menu_2->addAction(action_11);
        menu->addAction(action_12);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MLATView", nullptr));
        action->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \321\201\320\265\320\275\321\201\320\276\321\200\320\276\320\262", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \321\201\320\265\320\275\321\201\320\276\321\200\320\276\320\262", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\201\320\265\320\275\321\201\320\276\321\200\320\276\320\262 \320\262\321\200\321\203\321\207\320\275\321\203\321\216", nullptr));
        action_5->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\201\320\265\320\275\321\201\320\276\321\200\320\276\320\262 \320\262\321\200\321\203\321\207\320\275\321\203\321\216", nullptr));
        action_6->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\221\321\215\320\275\320\272\321\200\320\276\321\204\321\202\320\260 \320\276\321\200\320\270\320\263\320\270\320\275\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        action_7->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\221\321\215\320\275\320\272\321\200\320\276\321\204\321\202\320\260 \320\242\320\260\320\274\320\270\320\273\320\276\320\262\320\260", nullptr));
        action_8->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\235\321\214\321\216\321\202\320\276\320\275\320\260 \320\240\321\215\321\204\321\201\320\276\320\275\320\260", nullptr));
        action_T_SVD->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 T-SVD", nullptr));
        action_9->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\242\320\270\321\205\320\276\320\275\320\276\320\262\320\260", nullptr));
        action_10->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\321\202\320\270\321\202\320\274 \320\242\320\270\321\205\320\276\320\275\320\276\320\262\320\260 2", nullptr));
        action_11->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        action_13->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        action_4->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\272\320\260\321\200\321\202\321\203", nullptr));
        action_12->setText(QApplication::translate("MainWindow", "\320\221\321\215\320\275\320\272\321\200\320\276\321\204\321\202 \320\276\321\200\320\270\320\263\320\270\320\275\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        menuMenu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
