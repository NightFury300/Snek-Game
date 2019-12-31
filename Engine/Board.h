#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc,Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
	Location GetBoardTopLeftPoint();
	bool isInsideBoard(const Location& loc);
	void DrawBorder();
private:
	static constexpr int Dimension = 20;
	static constexpr int Width = 39;
	static constexpr int Height = 29;
	static constexpr Location top_left = { 1,1 };
	Graphics& gfx;
};