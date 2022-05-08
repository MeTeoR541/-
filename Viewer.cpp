#include "Viewer.h"
Viewer::Viewer(QWidget *parent) :QDialog(parent){
    start = true;
    
    QPushButton* choose1 = new QPushButton("START");
    QPushButton* choose2 = new QPushButton("LOAD");
    QPushButton* choose3 = new QPushButton("END");
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
    this->setLayout(group);
    this->setMinimumHeight(460);
    this->setMinimumWidth(510);
    
    connect(choose3, SIGNAL(clicked()), this, SLOT(close()));
    choose1Slot();
}
void Viewer::choose1Slot() {

}
void Viewer::btn2() {

}
void Viewer::btn3() {


}