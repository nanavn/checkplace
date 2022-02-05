#ifndef SENSORS_POSITIONS_PARSER_H
#define SENSORS_POSITIONS_PARSER_H

#include <QString>
#include <QFile>
#include <vector>

using namespace std;

struct coord {
    coord()
    {

    }
    coord(double latitude, double longitude, double altitude, int Type)
    {
        lat = latitude;
        lon = longitude;
        alt = altitude;
        type = Type;
    }
    double lat, lon, alt;
    // сенсор - 1, приёмо-передающий сенсор  - 2, ответчик  - 3.
    int type;
};

class parser {
public:
    parser(QString file_name)
    {
        m_file_name = file_name;
        m_obj_valid = true;

        if (m_file_name == "") {
            m_obj_valid = false;
            return;
        }
        mp_f = new QFile(m_file_name);
        if (!mp_f->open(QIODevice::ReadOnly | QIODevice::Text))
            m_obj_valid = false;
    }
    ~parser() {
        mp_f->close();
        delete mp_f;
    }
    // Заполняет вектор структур данными из файла,
    // путь к которому задаётся в параметре
    // конструктора. Возвращает -1 в случае ошибки
    // и 0 в случае успешного завершения.
    int parse_file(std::vector<struct coord> & ar);

private:
    /* Если чтение прошло без ошибок, то: возвращает 0,
     * если достигнут конец файла, 1 в случае, если он
     * не достигнут. В случае если чтение не удалось или
     * завершилось ошибкой возвращает -1. */
    int parse_line(coord &c);

    QString m_file_name;
    bool m_obj_valid;
    QFile *mp_f;
};

#endif // SENSORS_POSITIONS_PARSER_H
