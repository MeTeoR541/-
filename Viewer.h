#pragma once
#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include "Board.h"
using namespace std;
class Viewer :public QDialog{
	Q_OBJECT
public:
	explicit Viewer(QWidget *parent = nullptr);
	void drawChess(QPainter& ptr, int x,int y, int value,bool whoose);
	void drawBoard(QPainter& ptr, const Board& board);
	void paintEvent(QPaintEvent *);
private:
	bool start;
	bool load;
	bool left;
};