#include "Chess.h"
Chess::Chess(int value) {
	Chess_value = value;
}
int Chess::getValue() {
	return Chess_value;
}
Board Chess::change(const Board board, int from_x, int from_y, int to_x, int to_y,bool nowplayer) {
	Board temp = board;
	temp.map[from_x][from_y] = 0;
	temp.map[to_x][to_y] = this->Chess_value;
	if (nowplayer == true) {
		temp.map[to_x][to_y] = true;
		return temp;
	}
	temp.map[to_x][to_y] = false;
	return temp;
}
void Chess::move(Board& board, int x, int y, bool nowplayer) {
	return;
}
Soldier::Soldier() :Chess(1) {
	return;
}
void Soldier::move(Board& board, int x, int y, bool nowplayer){
	if (nowplayer == true) {
		if (x >= 5) {
			if (x + 1 < 10)
				board.map[x + 1][y] += 10;
			if (y + 1 < 9)
				board.map[x][y + 1] += 10;
			if (y - 1 >= 0)
				board.map[x][y - 1] += 10;
			return;
		}
		if (x + 1 < 10)
			board.map[x + 1][y] += 10;
		return;
	}
	if (x <= 4) {
		if (x - 1 >= 0)
			board.map[x - 1][y] += 10;
		if (y + 1 < 9)
			board.map[x][y + 1] += 10;
		if (y - 1 >= 0)
			board.map[x][y - 1] += 10;
		return;
	}
	if (x - 1 >= 0)
		board.map[x - 1][y] = 8;
	return;
}
Cannon::Cannon() : Chess(2) {
	return;
}
void Cannon::move(Board& board, int x, int y, bool nowplayer) {
	bool check = false;
	for (int i = 1; x + i < 10; i++) {
		if (board.map[x + i][y] % 10 != 0) {
			if (check == true) {
				if (board.BorR[x + i][y] != nowplayer)
					board.map[x + i][y] += 10;
				break;
			}
			check == true;
		}
		else if (check == false)
			board.map[x + i][y] += 10;
	}
	check = false;
	for (int i = 1; x - i >= 0; i++) {
		if (board.map[x - i][y] % 10 != 0) {
			if (check == true) {
				if (board.BorR[x - i][y] != nowplayer)
					board.map[x - i][y] += 10;
				break;
			}
			check == true;
		}
		else if (check == false)
			board.map[x - i][y] += 10;
	}
	check = false;
	for (int i = 1; y + i < 9; i++) {
		if (board.map[x][y + i] % 10 != 0) {
			if (check == true) {
				if (board.BorR[x][y + i] != nowplayer)
					board.map[x][y + i] += 10;
				break;
			}
			check == true;
		}
		else if (check == false)
			board.map[x][y + i] += 10;
	}
	check = false;
	for (int i = 1; y - i >= 0; i++) {
		if (board.map[x][y - i] % 10 != 0) {
			if (check == true) {
				if (board.BorR[x][y - i] != nowplayer)
					board.map[x][y - i] += 10;
				break;
			}
			check == true;
		}
		else if (check == false)
			board.map[x][y - i] += 10;
	}
}
Rook::Rook() : Chess(3) {
	return;
}
void Rook::move(Board& board, int x, int y, bool nowplayer) {
	for (int i = 1; x + i < 10; i++) {
		if (board.map[x + i][y] % 10 != 0) {
			if (board.BorR[x + i][y] != nowplayer)
				board.map[x + i][y] += 10;
			break;
		}
		board.map[x + i][y] += 10;
	}
	for (int i = 1; x - i >= 0; i++) {
		if (board.map[x - i][y] % 10 != 0) {
			if (board.BorR[x - i][y] != nowplayer)
				board.map[x - i][y] += 10;
			break;
		}
		board.map[x - i][y] += 10;
	}
	for (int i = 1; y + i < 9; i++) {
		if (board.map[x][y + i] % 10 != 0) {
			if (board.BorR[x][y + i] != nowplayer)
				board.map[x][y + i] += 10;
			break;
		}
		board.map[x][y + i] += 10;
	}
	for (int i = 1; y - i >= 0; i++) {
		if (board.map[x][y - i] % 10 != 0) {
			if (board.BorR[x][y - i] != nowplayer)
				board.map[x][y - i] += 10;
			break;
		}
		board.map[x][y - i] += 10;
	}
}
Horse::Horse() : Chess(4) {
	return;
}
void Horse::move(Board& board, int x, int y, bool nowplayer) {

}
Elephant::Elephant() : Chess(5) {
	return;
}
Advisor::Advisor() : Chess(6) {
	return;
}
General::General() : Chess(7) {
	return;
}