#pragma once
#include "Graphics.h"
#include "Board.h"
#include "Location.h"
#include "Colors.h"

class ScoreMeter
{
public:
	ScoreMeter(const Location& in_loc);
	void IncreaseScore();
	void Draw(Graphics& gfx,const Board& brd);
private:
	Location loc;
	int score = 0;
	static constexpr int Width = 20;
	static constexpr int increaseScore = 4;
	static constexpr Color c = Colors::Blue;
};