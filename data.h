#ifndef DATA_H
#define DATA_H

#include <QMainWindow>
#include <QDialog>
#include <QLineEdit>
#include <QSignalMapper>
#include <QTextEdit>
#include <QString>
using std::tolower, std::toupper;

struct Node{
    QString val = "";
    Node *next;
};

class Queue{
public:
    Queue();
    ~Queue();

    void add_elem(const QString &elem);

    void delete_elem();

    QString get_all();

protected:
    Node *first;
    Node *cur;
    Node *next;
    Node *tmp;
};

class Data: public QDialog
{
     Q_OBJECT
    public:
     Data( QWidget * parent = 0);
     virtual ~Data(){};
    protected:
     QTextEdit * m_pTextEdit;
     QSignalMapper * m_pSignalMapper;
//     QLineEdit * m_pLineEdit;

     void setNumEdit( double ); ///< Отобразить текст в m_pTextEdit

     QString strip;
     QLineEdit * line;
     QTextEdit * text;
     Queue sample;

     private slots:
     /// Слот для обработки нажатий всех кнопок
     void clicked(int id);
//     void edit(QString inp);

//     double m_Val; ///< Значение, с которым будет выполнена операция
//     int m_Op; ///< Код нажатой операции
//     bool m_bPerf;///< Операция была выполнена. Надо очистить поле ввода
//     void initNum();///< Инициализировать переменные, связанные с вычислениями
//     double getNumEdit(); ///< Получить число из m_pLineEdit

//     /// Вычислить предыдущую операцию
//     ///(в бинарных операциях был введен второй операнд)
//     void calcPrevOp( int curOp );

//     /// Проверить, была ли выполнена операция при нажатии на цифровую клавишу
//     /// Если операция выполнена, значит m_pLineEdit необходимо очистить
//     void checkOpPerf();
};

#endif // DATA_H
