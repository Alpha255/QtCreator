#include "qtools.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTools w;
    w.setWindowIcon(QIcon(":/Icons/qt.ico"));
    w.show();
    return a.exec();
}
