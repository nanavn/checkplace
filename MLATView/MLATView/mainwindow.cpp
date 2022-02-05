#include <vector>
#include <iterator>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sensors_positions_parser.h"
#include "bancroft_original.h"
#include <QMessageBox>

//using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->action, SIGNAL(toggled(bool)), this, SLOT(on_action_triggered()));
    m_sd = NULL;
    this->setFixedWidth(this->width());
    this->setFixedHeight(this->height());
    ui->action_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete m_sd;
    delete ui;
}


void MainWindow::on_action_6_triggered()
{

}

void MainWindow::on_action_triggered()
{
    if (m_sd == NULL) {
        m_sd = new sensors_dlg();
        m_sd->setFixedWidth(m_sd->width());
        m_sd->setFixedHeight(m_sd->height());        
    }
    ui->action->setEnabled(false);
    ui->action_2->setEnabled(true);
    m_sd->show();
}

void MainWindow::on_action_triggered(bool checked)
{

}

void MainWindow::on_action_toggled(bool arg1)
{

}

void MainWindow::on_action_12_triggered()
{
    mat sens_pos(4, 3);
    sens_pos(0, 0) = -1318.130;
    sens_pos(0, 1) = -85.100;
    sens_pos(0, 2) = 1.560;
    sens_pos(1, 0) = -489.310;
    sens_pos(1, 1) = 155.230;
    sens_pos(1, 2) = 6.680;
    sens_pos(2, 0) = -21.480;
    sens_pos(2, 1) = 401.060;
    sens_pos(2, 2) = 4.690;
    sens_pos(3, 0) = -149.540;
    sens_pos(3, 1) = -53.010;
    sens_pos(3, 2) = 23.700;

    mat toa(4, 4);
    toa(0, 0) = 0.00000687000000;// первая подозрительная на ошибку цель
    toa(0, 1) = 0.00000402000000;
    toa(0, 2) = 0.00000247000000;
    toa(0, 3) = 0.00000315000000;
    toa(1, 0) = 0.00000545000000;
    toa(1, 1) = 0.00000267000000;
    toa(1, 2) = 0.00000180000000;
    toa(1, 3) = 0.00000168000000;
    toa(2, 0) = 0.00000550000000;
    toa(2, 1) = 0.00000266000000;
    toa(2, 2) = 0.00000151000000;
    toa(2, 3) = 0.00000188000000;
    toa(3, 0) = 0.00000681000000;// вторая подозрительная на ошибку цель
    toa(3, 1) = 0.00000399000000;
    toa(3, 2) = 0.00000256000000;
    toa(3, 3) = 0.00000301000000;
//    bancroft_original bo(sens_pos, toa);
//    vec r = bo.exec_alg();
//    QMessageBox(QMessageBox::Information, QString("MLATView"),
//                QString("x = ")+QString::number(r[0], 'g', 6)+QString(", y = ")+
//                QString::number(r[1], 'g', 6)+QString(", z = ")+QString::number(r[2], 'g', 6),
//                QMessageBox::Ok, this, Qt::Dialog);
}

// Меню "Файл-Закрыть список сенсоров"
void MainWindow::on_action_2_triggered()
{
    if (m_sd != NULL) {
        delete m_sd;
        m_sd = NULL;
    }
    ui->action->setEnabled(true);
    ui->action_2->setEnabled(false);
}


void MainWindow::on_action_13_triggered()
{
    this->close();
}

