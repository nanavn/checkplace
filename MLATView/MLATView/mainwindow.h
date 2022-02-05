#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sensors_dlg.h"
#include <armadillo>
using namespace arma;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_6_triggered();

    void on_action_triggered();

    void on_action_triggered(bool checked);

    void on_action_toggled(bool arg1);

    void on_action_12_triggered();

    void on_action_2_triggered();

    void on_action_13_triggered();

private:
    Ui::MainWindow *ui;
    sensors_dlg *m_sd;
};
#endif // MAINWINDOW_H
