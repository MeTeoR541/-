#pragma once
#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QMessageBox>
#include <QPoint>
#include <QDialog>
#include <QMouseEvent>
#include <QVBoxLayout>
#include "Board.h"

using namespace std;
class Viewer :public QDialog{
	Q_OBJECT
public:
	explicit Viewer(QWidget *parent = nullptr);
	void choose1Slot();
	void btn2();
	void btn3();
private:
	bool start;
	bool load;
	bool left;
};