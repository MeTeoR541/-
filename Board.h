#pragma once
#include <iostream>
using namespace std;
class Board {
public:
	//車 3，馬 4，象 5，士 6，將 7 ，砲 2，兵 1，紅點:判斷能走的位置 +=10
	Board() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				map[i][j] = 0;
				BorR[i][j] = false;
			}
		}
		for (int i = 0; i < 4; i++) {
			map[0][i] = i + 3;
			map[0][8 - i] = i + 3;
			BorR[0][i] = true;
			BorR[0][8 - i] = true;
			map[9][i] = i + 3;
			map[9][8 - i] = i + 3;
			BorR[9][i] = false;
			BorR[9][8 - i] = false;
			if (i % 2 == 0) {
				map[3][i] = 1;
				map[3][8 - i] = 1;
				BorR[3][i] = true;
				BorR[3][8 - i] = true;
				map[6][i] = 1;
				map[6][8 - i] = 1;
				BorR[6][i] = false;
				BorR[6][8 - i] = false;
			}
		}
		map[0][4] = 7;
		map[3][4] = 1;
		map[2][1] = 2;
		map[2][7] = 2;
		BorR[0][4] = true;
		BorR[3][4] = true;
		BorR[2][1] = true;
		BorR[2][7] = true;
		map[9][4] = 7;
		map[6][4] = 1;
		map[7][1] = 2;
		map[7][7] = 2;
		BorR[9][4] = false;
		BorR[6][4] = false;
		BorR[7][1] = false;
		BorR[7][7] = false;
	}
	Board& operator=(const Board& copy) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				map[i][j] = copy.map[i][j];
				BorR[i][j] = copy.BorR[i][j];
			}
		}
		return *this;
	}
	Board operator+(const Board& add) {
		Board temp = *this;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (temp.map[i][j] != add.map[i][j])
					temp.map[i][j] = temp.map[i][j] + add.map[i][j] / 10 * 10;
			}
		}
		return temp;
	}
	int findKingValue(bool player) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				if (map[i][j] % 10 == 7 && BorR[i][j] == player)
					return map[i][j];
			}
		}
		return 0;
	}
	int map[10][9];
	bool BorR[10][9];//true代表黑方；false代表紅方
};