/********************************************************************************
** Form generated from reading UI file 'plotwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTWINDOW_H
#define UI_PLOTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plotindow
{
public:
    QAction *action_PostScript;
    QAction *actionPfrhsnm;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuAfqk;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *plotwindow)
    {
        if (plotwindow->objectName().isEmpty())
            plotwindow->setObjectName(QString::fromUtf8("plotwindow"));
        plotwindow->resize(800, 600);
        action_PostScript = new QAction(plotwindow);
        action_PostScript->setObjectName(QString::fromUtf8("action_PostScript"));
        actionPfrhsnm = new QAction(plotwindow);
        actionPfrhsnm->setObjectName(QString::fromUtf8("actionPfrhsnm"));
        centralwidget = new QWidget(plotwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plotwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(plotwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuAfqk = new QMenu(menubar);
        menuAfqk->setObjectName(QString::fromUtf8("menuAfqk"));
        plotwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(plotwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        plotwindow->setStatusBar(statusbar);

        menubar->addAction(menuAfqk->menuAction());
        menuAfqk->addAction(action_PostScript);
        menuAfqk->addSeparator();
        menuAfqk->addAction(actionPfrhsnm);

        retranslateUi(plotwindow);

        QMetaObject::connectSlotsByName(plotwindow);
    } // setupUi

    void retranslateUi(QMainWindow *plotwindow)
    {
        plotwindow->setWindowTitle(QApplication::translate("plotindow", "MainWindow", nullptr));
        action_PostScript->setText(QApplication::translate("plotindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\321\202\321\214 \320\262 PostScript", nullptr));
        actionPfrhsnm->setText(QApplication::translate("plotindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        menuAfqk->setTitle(QApplication::translate("plotindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plotindow: public Ui_plotindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTWINDOW_H
