#pragma once
#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QMessageBox>
#include <QPoint>
#include <QDialog>
#include <QVBoxLayout>
#include "Board.h"

using namespace std;
class Viewer{
public:
	Viewer();
	void drawhomepage(QPainter& ptr);
	void drawChess(QPainter& ptr, int x, int y, int value, bool whoose);
	void drawBoard(QPainter& ptr, const Board& board);
private:
	bool start;
	bool load;
	bool left;
};