/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include "player_manager.h"
#include <stdio.h>
bool TemoinFinPartie;

void Game_SquareChangeCallback(Coordinate x, Coordinate y,
                               PieceType kindOfPiece)
{
	BoardView_displaySquare(x, y, kindOfPiece);
}

void Game_EndOfGameCallback(GameResult result)
{
	TemoinFinPartie = true;
	BoardView_displayEndOfGame(result);
}

void Game_init(void)
{
	TemoinFinPartie = false;
	Board_init(Game_SquareChangeCallback, Game_EndOfGameCallback);
	BoardView_init();
	PlayerManager_init();
}

void Game_free(void)
{
	BoardView_free();
	PlayerManager_free();
	Board_free();
}

void Game_loop(void)
{
	do {
		PlayerManager_oneTurn();

	} while (!TemoinFinPartie);

}
