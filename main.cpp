#include "menu.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Menu * dialog = new Menu();

    dialog->show(); // отображаем окно
    return app.exec(); // запускаем цикл обработки сообщений
}
