#pragma once
#include <iostream>
#include <QDialog>
#include <vector>
#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include "Board.h"
#include "Chess.h"
#include "Viewer.h"
using namespace std;
class GameManager :public QWidget{
	Q_OBJECT
private:
	QPoint now;
	Board temp_board;
	int now_value;
	int temp_x, temp_y;
	int now_where; // 0���� 1�i�J�C��
	bool isEnd;
	bool pick;//true ����ۤv���Ѥl
	bool current_player;//true �¤�Ffalse ����
public:
	Board board;
	vector<Chess>chess;
	//Viewer viewer;
	GameManager(QWidget* parent = 0);
	void newGame(QPainter& ptr);
	void drawChess(QPainter& ptr, int x, int y, int value, bool whoose);
	void drawBoard(QPainter& ptr, const Board& board);
	void paintEvent(QPaintEvent*);
	void mouseReleaseEvent(QMouseEvent* event);
	bool cantmove(const Board& board, bool player);
	bool kingDie(const Board& board, bool player);

	void playGameManger();
	bool getNowplayer();
	bool getisEnd();
};