#include "sensors_positions_parser.h"
#include <iostream>
#include <QDebug>
#include <QStringList>

int parser::parse_line(coord &c)
{
    if (!m_obj_valid)
        return -1;

    QByteArray ba_line = mp_f->readLine();
    QString line(ba_line);
    // Убираем '\n' из конца строки.
    line = line.left(line.size()-1);

    QStringList sl = line.split(QChar(' '), QString::SkipEmptyParts);
    if (sl.size() != 4)
        return -1;

    c.lat = sl.at(0).toDouble();
    c.lon = sl.at(1).toDouble();
    c.alt = sl.at(2).toDouble();
    c.type = sl.at(3).toInt();
    if (mp_f->atEnd())
        return 0;
    return 1;
}

int parser::parse_file(std::vector<struct coord> & ar)
{
    coord c;
    int r;
    do {
        r = parse_line(c);
        if (r != -1)
            ar.push_back(c);
    } while (r == 1);
    if (r == -1)
        return -1;
    return 0;
}
