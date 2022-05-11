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
	int now_where; // 0���� 1�i�J�C��	2�N�x�e��	3�ӧQ�e��(isEnd����true�N��)
	bool isEnd;
	bool pick;//true ����ۤv���Ѥl
	bool current_player;//true �¤�Ffalse ����
	bool winner;
public:
	Board board;
	vector<Chess>chess;
	Viewer viewer;
	GameManager(QWidget* parent = 0);
	void newGame();

	void paintEvent(QPaintEvent*);
	void mouseReleaseEvent(QMouseEvent* event);
	
	Board nextmove(const Board& board, bool player);
	bool Check(const Board& board, bool player);
	bool cantmove(const Board& board, bool player);
	bool movewillDie(const Board& board, bool player);
	bool kingDie(const Board& board, bool player);
	
	void playGameManger();

};