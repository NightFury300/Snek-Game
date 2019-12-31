#pragma once
#include "Board.h"

class Snake
{
private:
	class SnakeSegment
	{
	public:
		void initHead(const Location& loc);
		void initBody(int Pattern);
		void Follow(const SnakeSegment& next);
		void moveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
		int ColorCounter = 0;
	};
public:
	Snake(const Location& loc);
	void moveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;
	Location getNextHeadLocation(const Location& delta_loc) const;
	bool isInTileExceptEnd(const Location& loc) const;
	bool isInTile(const Location& loc) const;
	int GetLength() const;
private:
	static constexpr Color headColor = Colors::Yellow;
	int Pattern = 0;
	static constexpr Color bodyColorPattern[3] = { Color(0,104,0),Color(0,128,0),Color(0,166,0) };
	static constexpr int nSegmentsMax = 100;
	SnakeSegment segments[nSegmentsMax];
	int nSegments = 1;

};