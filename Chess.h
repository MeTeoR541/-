#pragma once
#include <iostream>
#include "Board.h"
using namespace std;
class Chess {
private:
	int Chess_value;
public:
	Chess(int value);
	int getValue();
	Board change(const Board board, int from_x, int from_y, int to_x, int y, bool nowplayer);
	void kingWking(Board& board, int x, int y, bool player);
	virtual void move(Board& board, int x, int y, bool nowplayer);
};
class Soldier:public Chess{
public:
	Soldier();
	virtual void move(Board& board, int x, int y, bool nowplayer)override;
};
class Cannon :public Chess {
public:
	Cannon();
	virtual void move(Board& board, int x, int y, bool nowplayer)override;
};
class Rook :public Chess {
public:
	Rook();
	virtual void move(Board& board, int x, int y, bool nowplayer)override;
};
class Horse :public Chess {
public:
	Horse();
	virtual void move(Board& board, int x, int y, bool nowplayer)override;
};
class Elephant :public Chess {
public:
	Elephant();
	virtual void move(Board& board, int x, int y, bool nowplayer)override;
};
class Advisor :public Chess {
public:
	Advisor();
	virtual void move(Board& board, int x, int y, bool nowplayer)override;
};
class General :public Chess {
public:
	General();
	virtual void move(Board& board, int x, int y, bool nowplayer)override;
};