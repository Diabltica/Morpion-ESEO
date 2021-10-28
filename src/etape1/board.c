#include "board.h"
#include <bool.h>
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
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */
static bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
  // TODO: à compléter
	//test every ligne and colomne to check one complete
	for(int i = 1; i < 3; i++){
		if(boardSquares[i][1] == boardSquares[lastChangeX][lastChangeY] && boardSquares[i][2] == boardSquares[lastChangeX][lastChangeY] && boardSquares[i][3] == boardSquares[lastChangeX][lastChangeY]){
			return true;
		}
	}
	for(int j = 1; j < 3; j++){
		if(boardSquares[1][j] == boardSquares[lastChangeX][lastChangeY] && boardSquares[2][j] == boardSquares[lastChangeX][lastChangeY] && boardSquares[3][j] == boardSquares[lastChangeX][lastChangeY]){
			return true;
		}
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
