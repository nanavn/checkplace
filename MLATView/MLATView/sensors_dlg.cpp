#include "sensors_dlg.h"
#include "ui_sensors_dlg.h"
#include "mainwindow.h"

#include <QModelIndex>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QList>
#include <QFileDialog>

#define PRECISION 6


void sensors_dlg::table_item_changed(QStandardItem *item)
{
    update();
}

void sensors_dlg::update()
{
    QFile f(m_file_path);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox(QMessageBox::Warning, QString("MLATView"),
                    QString("Ошибка записи в файл ")+m_file_path+QString("."),
                    QMessageBox::Ok, this, Qt::Dialog);
        return;
    }
    QTextStream out(&f);
    if (m_cs.size() == 0) {
        out << "";
        f.close();
    }
    for (int i = 0; i < m_cs.size(); i++) {
        for (int j = 0; j<4; j++) {
            if (j < 3)
                out << QString("%1").arg(model->item(i, j)->data(0).toDouble(), 0, 'g', 6).toStdString().c_str() << " ";
            else if (j == 3) {
                QString str = model->item(i, j)->data(0).toString();
                if (str == QString("Сенсор")) {
                    out << "1";
                } else if (str == QString("Приёмо-передающий сенсор")) {
                    out << "2";
                } else if (str == QString("Ответчик")) {
                    out << "3";
                } else if (str == QString("Тип не задан")) {
                    out << "0";
                } else {
                    out << "0";
                }
            }
        }
        out << "\n";
    }
    f.close();
}

sensors_dlg::sensors_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sensors_dlg)
{
    ui->setupUi(this);
    m_selected_row = -1;
    m_file_path = QFileDialog::getOpenFileName(this,
         tr("Открыть файл с координатами сенсоров"), "/home/", tr("Text files (* *.txt)"));
    parser p(m_file_path);
    p.parse_file(m_cs);

    model = new QStandardItemModel(m_cs.size(),3,this);
    ui->tableView->setModel(model);
    QStringList labels;
    labels.append(QString("Широта"));
    labels.append(QString("Долгота"));
    labels.append(QString("Высота"));
    labels.append(QString("Тип сенсора"));
    model->setHorizontalHeaderLabels(labels);

    std::vector<coord>::iterator it = m_cs.begin();
    for (int  i = 0; it != m_cs.end(); it++, i++) {
        QList<QStandardItem *> l;
        QString s;
        QStandardItem *si1 = new QStandardItem(s.setNum(it->lat, 'g', PRECISION));
        l.append(si1);
        QStandardItem *si2 = new QStandardItem(s.setNum(it->lon, 'g', PRECISION));
        l.append(si2);
        QStandardItem *si3 = new QStandardItem(s.setNum(it->alt, 'g', PRECISION));
        l.append(si3);

        QStandardItem *si4;
        switch (it->type) {
        case 1:
            si4 = new QStandardItem(QString("Сенсор"));
            break;

        case 2:
            si4 = new QStandardItem(QString("Приёмо-передающий сенсор"));
            break;

        case 3:
            si4 = new QStandardItem(QString("Ответчик"));
            break;

        default:
            si4 = new QStandardItem(QString("Тип не задан"));
            break;
        }
        si4->setEditable(false);
        l.append(si4);

        model->insertRow(i, l);
    }
    model->setRowCount(m_cs.size());
    QObject::connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(table_item_changed(QStandardItem*)));
    ui->comboBox->addItem(QString("Тип не задан"));
    ui->comboBox->addItem(QString("Сенсор"));
    ui->comboBox->addItem(QString("Приёмо-передающий сенсор"));
    ui->comboBox->addItem(QString("Ответчик"));
}


sensors_dlg::~sensors_dlg()
{
    delete model;
    delete ui;
}

void sensors_dlg::on_pushButton_clicked()
{
    if (ui->lineEdit_3->text() == QString("") || ui->lineEdit_2->text() == QString("") ||
            ui->lineEdit->text() == QString("")) {
        QMessageBox msgBox;
        msgBox.setText("Все поля должны быть заполнены.");
        msgBox.exec();
        return;
    }
    QList<QStandardItem *> row;
    row.append(new QStandardItem(ui->lineEdit_3->text()));
    row.append(new QStandardItem(ui->lineEdit_2->text()));
    row.append(new QStandardItem(ui->lineEdit->text()));
    int ind = ui->comboBox->currentIndex();
    if (ind == 0)
        row.append(new QStandardItem(QString("Тип не задан")));
    else if (ind == 1)
        row.append(new QStandardItem(QString("Сенсор")));
    else if (ind == 2)
        row.append(new QStandardItem(QString("Приёмо-передающий сенсор")));
    else if (ind == 3)
        row.append(new QStandardItem(QString("Ответчик")));
    else
        row.append(new QStandardItem(QString("Тип не задан")));
    row[row.size()-1]->setEditable(false);

    model->insertRow(model->rowCount(), row);
    QFile f(m_file_path);
    if (!f.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox(QMessageBox::Warning, QString("MLATView"),
                    QString("Ошибка открытия на запись файла ")+m_file_path+QString("."),
                    QMessageBox::Ok, this, Qt::Dialog);
        return;
    }

    QTextStream out(&f);
    out.readAll();

    int type;
    for (int j = 0; j<4; j++) {
        if (j < 3)
            out << QString("%1").arg(model->item(model->rowCount()-1, j)->data(0).toDouble(), 0, 'g', 6).toStdString().c_str() << " ";
        else if (j == 3) {
            QString str = model->item(model->rowCount()-1, j)->data(0).toString();
            if (str == QString("Сенсор")) {
                out << "1";
                type = 1;
            } else if (str == QString("Приёмо-передающий сенсор")) {
                out << "2";
                type = 2;
            } else if (str == QString("Ответчик")) {
                out << "3";
                type = 3;
            } else if (str == QString("Тип не задан")) {
                out << "0";
                type = 0;
            } else {
                out << "0";
                type = 0;
            }
        }
    }
    out << "\n";

    f.close();
    m_cs.push_back(coord(model->item(model->rowCount()-1, 0)->data(0).toDouble(),
                   model->item(model->rowCount()-1, 1)->data(0).toDouble(),
                   model->item(model->rowCount()-1, 2)->data(0).toDouble(), type));
    ui->lineEdit_3->setText(QString());
    ui->lineEdit_2->setText(QString());
    ui->lineEdit->setText(QString());
}

void sensors_dlg::on_tableView_clicked(const QModelIndex &index)
{
    m_selected_row = index.row();
}


void sensors_dlg::on_pushButton_2_clicked()
{
    if (m_selected_row != -1) {
        model->removeRows(m_selected_row, 1);

        vector<coord>::iterator iter = m_cs.begin();
        //for (int i = 0; i != m_selected_row; i++, iter++);
        int i = 0;
        while (i != m_selected_row) {
            iter++;
            i++;
        }
        m_cs.erase(iter);

        update();
        if (m_selected_row == model->rowCount())
            m_selected_row--;
    }
}

