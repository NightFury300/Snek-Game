#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	:
	gfx( gfx )
{
}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < Width);
	assert(loc.y >= 0);
	assert(loc.y < Height);
	gfx.DrawRectDim(loc.x * Dimension, loc.y * Dimension, Dimension, Dimension, c);
}

int Board::GetGridWidth() const
{
	return Width;
}

int Board::GetGridHeight() const
{
	return Height;
}

Location Board::GetBoardTopLeftPoint()
{
	return top_left;
}

bool Board::isInsideBoard(const Location & loc)
{
	return loc.x >= top_left.x && loc.x < Width &&
		loc.y >= top_left.y && loc.y < Height;
}

void Board::DrawBorder()
{
	Color c = Color(107, 90, 139);
	static constexpr int girth = 6;
	//TOP:
	gfx.DrawRect(top_left.x * 20, top_left.y * 20, GetGridWidth() * 20, top_left.y * 20 + girth, c);
	//LEFT:
	gfx.DrawRect(top_left.x * 20, top_left.y * 20, top_left.x * 20 + girth, GetGridHeight() * 20, c);
	//RIGHT:
	gfx.DrawRect(GetGridWidth() * 20 - girth, top_left.y * 20, GetGridWidth() * 20, GetGridHeight() * 20, c);
	//BOTTOM:
	gfx.DrawRect(top_left.x * 20, GetGridHeight() * 20 - girth, GetGridWidth() * 20, GetGridHeight() * 20, c);
}
