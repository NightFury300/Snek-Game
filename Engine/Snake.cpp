#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	segments[0].initHead(loc);
}

void Snake::moveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].moveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].initBody(Pattern);
		++nSegments;
		Pattern += 1;
		if (Pattern == 3)
		{
			Pattern = 0;
		}
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::getNextHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

bool Snake::isInTileExceptEnd(const Location & target) const
{
	for (int i = 0; i < nSegments - 1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::isInTile(const Location & target) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

int Snake::GetLength() const
{
	return nSegments;
}

void Snake::SnakeSegment::initHead(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::SnakeSegment::initBody(int Pattern)
{
	c = Snake::bodyColorPattern[Pattern];
}

void Snake::SnakeSegment::Follow(const SnakeSegment & next)
{
	loc = next.loc;
}

void Snake::SnakeSegment::moveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
    loc.Add(delta_loc);
}

void Snake::SnakeSegment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::SnakeSegment::GetLocation() const
{
	return loc;
}
