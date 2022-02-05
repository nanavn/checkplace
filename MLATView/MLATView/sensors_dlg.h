#ifndef SENSORS_DLG_H
#define SENSORS_DLG_H

#include <QStandardItemModel>
#include <QStandardItem>
#include <QDialog>
#include <vector>
#include "sensors_positions_parser.h"


namespace Ui {
class sensors_dlg;
}

class sensors_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit sensors_dlg(QWidget *parent = nullptr);
    ~sensors_dlg();

private slots:
    void table_item_changed(QStandardItem *item);
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    void update();
    Ui::sensors_dlg *ui;
    QStandardItemModel *model;
    std::vector<coord> m_cs;
    // Путь к файлу с координатами
    QString m_file_path;
    int m_selected_row;
};

#endif // SENSORS_DLG_H
