#include "Goal.h"

Goal::Goal(std::mt19937 & rng, Board & brd, Snake & snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937 & rng, Board & brd, Snake & snake)
{
	std::uniform_int_distribution<int> xDist(brd.GetBoardTopLeftPoint().x, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(brd.GetBoardTopLeftPoint().y, brd.GetGridHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} 
	while (snake.isInTile(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board & brd)
{
	g += c;
	b += c;
	if (g == 252 && b == 252)
	{
		c = -4;
	}
	if (g == 0 && b == 0)
	{
		c = 4;
	}
	Color C = Color(r, g, b);
	brd.DrawCell(loc, C);
}

const Location & Goal::GetLocation() const
{
	return loc;
}
