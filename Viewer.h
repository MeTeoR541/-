#pragma once
#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QMessageBox>
#include <QPoint>
#include "Board.h"
#include <QPixmap>

using namespace std;
class Viewer{
private:
	QPixmap blackS;
	QPixmap blackC;
	QPixmap blackR;
	QPixmap blackH;
	QPixmap blackE;
	QPixmap blackA;
	QPixmap blackG;
	QPixmap redS;
	QPixmap redC;
	QPixmap redR;
	QPixmap redH;
	QPixmap redE;
	QPixmap redA;
	QPixmap redG;

	QPixmap start;
	QPixmap read;
	QPixmap end;
	QPixmap lose;
public:
	Viewer();
	void drawWinMessage(QPainter& ptr,bool winner);
	void drawCheckMessage(QPainter& ptr, bool winner);

	void drawhomepage(QPainter& ptr);
	void drawChess(QPainter& ptr, int x, int y, int value, bool whoose);
	void drawBoard(QPainter& ptr, const Board& board);
};