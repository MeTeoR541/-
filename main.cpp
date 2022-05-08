#include <QtWidgets>
#include <QApplication>
#include "Viewer.h"
#include "GameManager.h"
//#include "Viewer.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    GameManager b;
    b.show();
    return a.exec();
}