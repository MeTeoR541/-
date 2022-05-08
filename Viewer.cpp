#include "Viewer.h"
Viewer::Viewer() {
	return;
}
void Viewer::draw() {
    QWidget* window = new QWidget();
    QPushButton* choose1 = new QPushButton(QObject::tr("START"), window);
    QPushButton* choose2 = new QPushButton(QObject::tr("LOAD"), window);
    QPushButton* choose3 = new QPushButton(QObject::tr("END"), window);
    choose1->setFixedHeight(50);
    choose1->setFixedWidth(150);
    choose2->setFixedHeight(50);
    choose2->setFixedWidth(150);
    choose3->setFixedHeight(50);
    choose3->setFixedWidth(150);
    QVBoxLayout* group = new QVBoxLayout;
    group->addWidget(choose1);
    group->addWidget(choose2);
    group->addWidget(choose3);
    group->setContentsMargins(50, 350, 200, 25);
    window->setLayout(group);
    window->setMinimumHeight(600);
    window->setMinimumWidth(750);
    window->show();
}