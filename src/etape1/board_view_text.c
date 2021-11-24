#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#define CONFIG_TEXTUI 1

#if defined CONFIG_TEXTUI

void BoardView_init (void)
{
}

void BoardView_free (void)
{
}

void BoardView_displayAll (void)
{
	for (int i = 0; i < LIGNES; ++i) {
		for (int j = 0; j < COLONNES; ++j) {

		}
	}
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
  printf('The game is finished : %c', result);
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
}

void BoardView_sayCannotPutPiece (void)
{
  printf('You can\'t put any piece in this case. Please, choose another.');
}

#endif // defined CONFIG_TEXTUI
