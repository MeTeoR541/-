#pragma once
#include <iostream>
#include <vector>
using namespace std;
class GameManager {
private:
	bool isEnd;
	bool current_player;
public:
	GameManager();
	void playGameManger();
	bool getNowplayer();
	bool getisEnd();
};