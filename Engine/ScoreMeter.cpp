#include"ScoreMeter.h"
#include"Graphics.h"

ScoreMeter::ScoreMeter(const Location& in_loc)
{
	loc = in_loc;
}

void ScoreMeter::IncreaseScore()
{
	score++;
}

void ScoreMeter::Draw(Graphics & gfx,const Board& brd)
{
	gfx.DrawRect(loc.x * 20, brd.GetGridHeight() * 20 - (increaseScore * score), loc.x * 20 + Width, brd.GetGridHeight() * 20, c);
}
