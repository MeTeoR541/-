#pragma once
#include <iostream>
#include <vector>
#include "Board.h"
#include "Chess.h"
using namespace std;
class GameManager {
private:
	bool isEnd;
	bool current_player;//true �¤�Ffalse ����
public:
	Board board;
	GameManager();
	void playGameManger();
	bool getNowplayer();
	bool getisEnd();
};