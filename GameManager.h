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
	int now_where; // 0首頁 1進入遊戲	2將軍畫面	3勝利畫面(isEnd等於true代替)
	bool isEnd;
	bool pick;//true 拿到自己的棋子
	bool current_player;//true 黑方；false 紅方
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