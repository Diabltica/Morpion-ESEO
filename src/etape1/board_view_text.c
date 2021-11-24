#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_TEXTUI

PieceType boardSquares[3][3];
char boardDisplay[5][5];

void BoardView_init(void)
{


void BoardView_free(void) {}

void BoardView_displayAll(void)
{
	//TODO
}

void BoardView_displaySquare(Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	BoardView_displayAll();
}

void BoardView_displayEndOfGame(GameResult result)
{
	// TODO: à compléter
}

void BoardView_displayPlayersTurn(PieceType thisPlayer)
{
	switch (thisPlayer) {
		case CROSS:
			printf("It's the turn of cross");
			break;
		case CIRCLE:
			printf("It's the turn of circle");
			break;
		case NONE:
			break;
	}
}

void BoardView_sayCannotPutPiece(void)
{
	// TODO: à compléter
}

#endif// defined CONFIG_TEXTUI
