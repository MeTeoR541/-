#pragma once
#include <iostream>
#include <QMouseEvent>
#include <QPoint>
#include <vector>
#include "Board.h"
#include "Chess.h"
#include "Viewer.h"
using namespace std;
class GameManager {
private:
	bool isEnd;
	bool current_player;//true ¶Â¤è¡Ffalse ¬õ¤è
public:
	Board board;
	Viewer viewer;
	GameManager();
	void newGame(QPainter& ptr);
	QPoint turnMsPoint(QPoint pt);
	void mouseReleaseEvent(QMouseEvent* ev);
	bool click(QPoint pt);


	void playGameManger();
	bool getNowplayer();
	bool getisEnd();
};