#pragma once
#include <iostream>
#include "Board.h"
using namespace std;
class Viewer {
public:
	Viewer();
	void draw(const Board& board);
};