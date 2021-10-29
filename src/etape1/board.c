#include "board.h"
#include <stdbool.h>
#include <assert.h>

/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is not set if
 * the game is not finished)
 *
 * @pre lastChangeX must be in [0..1]
 * @pre lastChangeY must be in [0..1]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */
static bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
	bool win = false;
	// look at the diagonale, ligne and colomne of the last change to check a win condition
	if(boardSquares[lastChangeX][0] == boardSquares[lastChangeX][1] == boardSquares[lastChangeX][2]){
		win = true;
	}
	else if(boardSquares[0][lastChangeY] == boardSquares[1][lastChangeY] == boardSquares[2][lastChangeY]){
		win = true;
	}
	else if(lastChangeX == lastChangeY){
		if(boardSquares[0][0] == boardSquares[1][1] == boardSquares[2][2]){
			win = true;
		}
	}
	else if(lastChangeX + lastChangeY == 2){
		if(boardSquares[0][2] == boardSquares[1][1] == boardSquares[2][0]){
			win = true;
		}
	}

	if(win == true){
		switch(boardSquares[lastChangeX][lastChangeY]){
			case CROSS:
				*gameResult = CROSS_WINS;
			case CIRCLE:
				*gameResult = CIRCLE_WINS;
			default:
				*gameResult = NONE;
		}
	}else{
		*gameResult = DRAW;
	}




}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{
  // TODO: à compléter
}

void Board_free ()
{
  // TODO: à compléter
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
  // TODO: à compléter
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
  // TODO: à compléter
}
