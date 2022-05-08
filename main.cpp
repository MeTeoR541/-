#include <QtWidgets>
#include <QApplication>
#include "GameManager.h"
//#include "Viewer.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    GameManager b;
    return a.exec();
}