#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, Board& brd, Snake& snake);
	void Respawn(std::mt19937& rng, Board& brd, Snake& snake);
	void Draw(Board& brd);
	const Location& GetLocation() const;
private:
	Location loc;
    Color C;
	int r = 255;
	int g = 0;
	int b = 0;
	int c = 4;
};