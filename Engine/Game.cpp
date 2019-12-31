/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng( std::random_device()() ),
	snek( {7,7} ),
	goal(rng,brd,snek),
	meter({ 0,0 })
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	if (isStarted)
	{
		if (!gameIsOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				if (delta_loc.y != 1 || snek.GetLength() <= 1)
				{
					delta_loc = { 0,-1 };
				}
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				if (delta_loc.y != -1 || snek.GetLength() <= 1)
				{
					delta_loc = { 0,1 };
				}
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				if (delta_loc.x != -1 || snek.GetLength() <= 1)
				{
					delta_loc = { 1,0 };
				}
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				if (delta_loc.x != 1 || snek.GetLength() <= 1)
				{
					delta_loc = { -1,0 };
				}
			}

			snekMoveCounter += dt;
			if (snekMoveCounter >= snekMovePeriod)
			{
				snekMoveCounter -= snekMovePeriod;
				const Location next = snek.getNextHeadLocation(delta_loc);
				if (!brd.isInsideBoard(next) ||
					snek.isInTileExceptEnd(next))
				{
					gameIsOver = true;
				}
				else
				{
					
					const bool eating = next == goal.GetLocation();
					if (eating)
					{
						snek.Grow();
						meter.IncreaseScore();
					}
					snek.moveBy(delta_loc);
					if (eating)
					{
						goal.Respawn(rng, brd, snek);
					}
				}
			}

			snekMovePeriod = std::max(snekMovePeriod - dt * snekSpeedUpFactor,snekMovePeriodMin);
		}
	}
}

void Game::ComposeFrame()
{
	
	if (gameIsOver)
	{	
		SpriteCodex::DrawGameOver(350, 250, gfx);
	}
	if (!isStarted)
	{
		SpriteCodex::DrawTitle(275, 200, gfx);
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			isStarted = true;
		}
	}
	if (isStarted)
	{
		meter.Draw(gfx,brd);
		snek.Draw(brd);
		goal.Draw(brd);
		brd.DrawBorder();
	}
}
