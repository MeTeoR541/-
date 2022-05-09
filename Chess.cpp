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
		temp.BorR[to_x][to_y] = true;
		return temp;
	}
	temp.BorR[to_x][to_y] = false;
	return temp;
}
void Chess::move(Board& board, int x, int y, bool nowplayer) {
	return;
}
void Chess::kingWking(Board& board, int x, int y, bool player) {
	Board temp = board;
	int from_x = x;
	int from_y = y;
	if (player == true) {
		for (int i = from_x + 1; i < 10; i++) {
			if (temp.map[i][from_y] % 10 != 0 && temp.map[i][from_y] % 10 != 7) 
				return;
			else if (temp.map[i][from_y] % 10 == 7) {
				board.map[i][from_y] += 10;
				return;
			}
		}
		return;
	}
	for (int i = from_x - 1; i >= 0; i--) {
		if (temp.map[i][from_y] % 10 != 0 && temp.map[i][from_y] % 10 != 7)
			return;
		else if (temp.map[i][from_y] % 10 == 7) {
			board.map[i][from_y] += 10;
			return;
		}
	}
	return;
}
Soldier::Soldier() :Chess(1) {
	return;
}
void Soldier::move(Board& board, int x, int y, bool nowplayer) {
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
		board.map[x - 1][y] += 10;
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
			check = true;
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
			check = true;
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
			check = true;
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
			check = true;
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
	if (x + 2 < 10 && y + 1 < 9) {
		if (board.map[x + 1][y] % 10 == 0) {
			if (board.map[x + 2][y + 1] % 10 == 0 || board.BorR[x + 2][y + 1] != nowplayer)
				board.map[x + 2][y + 1] += 10;
		}
	}
	if (x + 2 < 10 && y - 1 >= 0) {
		if (board.map[x + 1][y] % 10 == 0) {
			if (board.map[x + 2][y - 1] % 10 == 0 || board.BorR[x + 2][y - 1] != nowplayer)
				board.map[x + 2][y - 1] += 10;
		}
	}
	if (x - 2 >= 0 && y + 1 < 9) {
		if (board.map[x - 1][y] % 10 == 0) {
			if (board.map[x - 2][y + 1] % 10 == 0 || board.BorR[x - 2][y + 1] != nowplayer)
				board.map[x - 2][y + 1] += 10;
		}
	}
	if (x - 2 >= 0 && y - 1 >= 0) {
		if (board.map[x - 1][y] % 10 == 0) {
			if (board.map[x - 2][y - 1] % 10 == 0 || board.BorR[x - 2][y - 1] != nowplayer)
				board.map[x - 2][y - 1] += 10;
		}
	}
	if (x + 1 < 10 && y + 2 < 9) {
		if (board.map[x][y + 1] % 10 == 0) {
			if (board.map[x + 1][y + 2] % 10 == 0 || board.BorR[x + 1][y + 2] != nowplayer)
				board.map[x + 1][y + 2] += 10;
		}
	}
	if (x - 1 >= 0 && y + 2 < 9) {
		if (board.map[x][y - 1] % 10 == 0) {
			if (board.map[x - 1][y + 2] % 10 == 0 || board.BorR[x - 1][y + 2] != nowplayer)
				board.map[x - 1][y + 2] += 10;
		}
	}
	if (x + 1 < 10 && y - 2 >= 0) {
		if (board.map[x][y - 1] % 10 == 0) {
			if (board.map[x + 1][y - 2] % 10 == 0 || board.BorR[x + 1][y - 2] != nowplayer)
				board.map[x + 1][y - 2] += 10;
		}
	}
	if (x - 1 >= 0 && y - 2 >= 0) {
		if (board.map[x][y - 1] % 10 == 0) {
			if (board.map[x - 1][y - 2] % 10 == 0 || board.BorR[x - 1][y - 2] != nowplayer)
				board.map[x - 1][y - 2] += 10;
		}
	}
}
Elephant::Elephant() : Chess(5) {
	return;
}
void Elephant::move(Board& board, int x, int y, bool nowplayer) {
	if (nowplayer == true) {
		if (x + 2 < 5 && y + 2 < 9) {
			if (board.map[x + 1][y + 1] % 10 == 0) {
				if (board.map[x + 2][y + 2] % 10 == 0 || board.BorR[x + 2][y + 2] != nowplayer)
					board.map[x + 2][y + 2] += 10;
			}
		}
		if (x + 2 < 5 && y - 2 >= 0) {
			if (board.map[x + 1][y - 1] % 10 == 0) {
				if (board.map[x + 2][y - 2] % 10 == 0 || board.BorR[x + 2][y - 2] != nowplayer)
					board.map[x + 2][y - 2] += 10;
			}
		}
		if (x - 2 >= 0 && y + 2 < 9) {
			if (board.map[x - 1][y + 1] % 10 == 0) {
				if (board.map[x - 2][y + 2] % 10 == 0 || board.BorR[x - 2][y + 2] != nowplayer)
					board.map[x - 2][y + 2] += 10;
			}
		}
		if (x - 2 >= 0 && y - 2 >= 0) {
			if (board.map[x - 1][y - 1] % 10 == 0) {
				if (board.map[x - 2][y - 2] % 10 == 0 || board.BorR[x - 2][y - 2] != nowplayer)
					board.map[x - 2][y - 2] += 10;
			}
		}
	}
	else {
		if (x + 2 < 10 && y + 2 < 9) {
			if (board.map[x + 1][y + 1] % 10 == 0) {
				if (board.map[x + 2][y + 2] % 10 == 0 || board.BorR[x + 2][y + 2] != nowplayer)
					board.map[x + 2][y + 2] += 10;
			}
		}
		if (x + 2 < 10 && y - 2 >= 0) {
			if (board.map[x + 1][y - 1] % 10 == 0) {
				if (board.map[x + 2][y - 2] % 10 == 0 || board.BorR[x + 2][y - 2] != nowplayer)
					board.map[x + 2][y - 2] += 10;
			}
		}
		if (x - 2 >= 5 && y + 2 < 9) {
			if (board.map[x - 1][y + 1] % 10 == 0) {
				if (board.map[x - 2][y + 2] % 10 == 0 || board.BorR[x - 2][y + 2] != nowplayer)
					board.map[x - 2][y + 2] += 10;
			}
		}
		if (x - 2 >= 5 && y - 2 >= 0) {
			if (board.map[x - 1][y - 1] % 10 == 0) {
				if (board.map[x - 2][y - 2] % 10 == 0 || board.BorR[x - 2][y - 2] != nowplayer)
					board.map[x - 2][y - 2] += 10;
			}
		}
	}
}
Advisor::Advisor() : Chess(6) {
	return;
}
void Advisor::move(Board& board, int x, int y, bool nowplayer) {
	if (nowplayer == true) {
		if (x + 1 < 3 && y + 1 < 6) {
			if (board.map[x + 1][y + 1] % 10 == 0 || board.BorR[x + 1][y + 1] != nowplayer)
				board.map[x + 1][y + 1] += 10;
		}
		if (x + 1 < 3 && y - 1 >= 3) {
			if (board.map[x + 1][y - 1] % 10 == 0 || board.BorR[x + 1][y - 1] != nowplayer)
				board.map[x + 1][y - 1] += 10;
		}
		if (x - 1 >= 0 && y + 1 < 6) {
			if (board.map[x - 1][y + 1] % 10 == 0 || board.BorR[x - 1][y + 1] != nowplayer)
				board.map[x - 1][y + 1] += 10;
		}
		if (x - 1 >= 0 && y - 1 >= 3) {
			if (board.map[x - 1][y - 1] % 10 == 0 || board.BorR[x - 1][y - 1] != nowplayer)
				board.map[x - 1][y - 1] += 10;
		}
	}
	else {
		if (x + 1 < 10 && y + 1 < 6) {
			if (board.map[x + 1][y + 1] % 10 == 0 || board.BorR[x + 1][y + 1] != nowplayer)
				board.map[x + 1][y + 1] += 10;
		}
		if (x + 1 < 10 && y - 1 >= 3) {
			if (board.map[x + 1][y - 1] % 10 == 0 || board.BorR[x + 1][y - 1] != nowplayer)
				board.map[x + 1][y - 1] += 10;
		}
		if (x - 1 >= 7 && y + 1 < 6) {
			if (board.map[x - 1][y + 1] % 10 == 0 || board.BorR[x - 1][y + 1] != nowplayer)
				board.map[x - 1][y + 1] += 10;
		}
		if (x - 1 >= 7 && y - 1 >= 3) {
			if (board.map[x - 1][y - 1] % 10 == 0 || board.BorR[x - 1][y - 1] != nowplayer)
				board.map[x - 1][y - 1] += 10;
		}
	}
}
General::General() : Chess(7) {
	return;
}
void General::move(Board& board, int x, int y, bool nowplayer) {
	if (nowplayer == true) {
		kingWking(board, x, y, nowplayer);
		if (x + 1 < 3) {
			if (board.map[x + 1][y] % 10 == 0 || board.BorR[x + 1][y] != nowplayer)
				board.map[x + 1][y] += 10;
		}
		if (x - 1 >= 0) {
			if (board.map[x - 1][y] % 10 == 0 || board.BorR[x - 1][y] != nowplayer)
				board.map[x - 1][y] += 10;
		}
		if (y + 1 < 6) {
			if (board.map[x][y + 1] % 10 == 0 || board.BorR[x][y + 1] != nowplayer)
				board.map[x][y + 1] += 10;
		}
		if (y - 1 >= 3) {
			if (board.map[x][y - 1] % 10 == 0 || board.BorR[x][y - 1] != nowplayer)
				board.map[x][y - 1] += 10;
		}
	}
	else {
		kingWking(board, x, y, nowplayer);
		if (x + 1 < 10) {
			if (board.map[x + 1][y] % 10 == 0 || board.BorR[x + 1][y] != nowplayer)
				board.map[x + 1][y] += 10;
		}
		if (x - 1 >= 7) {
			if (board.map[x - 1][y] % 10 == 0 || board.BorR[x - 1][y] != nowplayer)
				board.map[x - 1][y] += 10;
		}
		if (y + 1 < 6) {
			if (board.map[x][y + 1] % 10 == 0 || board.BorR[x][y + 1] != nowplayer)
				board.map[x][y + 1] += 10;
		}
		if (y - 1 >= 3) {
			if (board.map[x][y - 1] % 10 == 0 || board.BorR[x][y - 1] != nowplayer)
				board.map[x][y - 1] += 10;
		}
	}
}