#include "board.h"
#include <stdbool.h>
PieceType boardSquares[3][3];
GameResult gameResult;


/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is
 * not set if the game is not finished)
 *
 * @pre lastChangeX must be in [0..1]
 * @pre lastChangeY must be in [0..1]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 *
 */
static bool isGameFinished(const PieceType boardSquares[3][3],
                           Coordinate lastChangeX, Coordinate lastChangeY,
                           GameResult *gameResult)
{

	//check if the board is full
	bool stop = false;
	for (int i = 0; (i < 3) && !stop; i++) {
		for (int j = 0; (j < 3) && !stop; j++) {
			if (boardSquares[i][j] == NONE) { stop = true; }
		}
	}
	if (!stop) {
		*gameResult = DRAW;
		return true;
	}

	// look at the diagonale, ligne and colomne of the last change to check a win condition
	if (boardSquares[lastChangeY][0] == boardSquares[lastChangeY][1] &&
	            boardSquares[lastChangeY][1] == boardSquares[lastChangeY][2] &&
	            boardSquares[lastChangeY][2] != NONE ||
	    boardSquares[0][lastChangeX] == boardSquares[1][lastChangeX] &&
	            boardSquares[1][lastChangeX] == boardSquares[2][lastChangeX] &&
	            boardSquares[2][lastChangeX] != NONE ||
	    lastChangeX == lastChangeY &&
	            boardSquares[0][0] == boardSquares[1][1] &&
	            boardSquares[1][1] == boardSquares[2][2] &&
	            boardSquares[2][2] != NONE ||
	    lastChangeX + lastChangeY == 2 &&
	            boardSquares[0][2] == boardSquares[1][1] &&
	            boardSquares[1][1] == boardSquares[2][0] &&
	            boardSquares[2][0] != NONE) {
		switch (boardSquares[lastChangeY][lastChangeX]) {
			case CROSS:
				*gameResult = CROSS_WINS;
				break;
			case CIRCLE:
				*gameResult = CIRCLE_WINS;
				break;
			default:
				*gameResult = DRAW;
				break;
		}
		return true;
	} else {
		*gameResult = DRAW;
		return false;
	}
}

// void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
// {
//   // TODO: à compléter
// }

// void Board_free ()
// {
//   // TODO: à compléter
// }

PutPieceResult Board_putPiece(Coordinate x, Coordinate y, PieceType kindOfPiece,
                              SquareChangeCallback squareCallback,
                              EndOfGameCallback endCallback) {
  PutPieceResult Is_empty;

  if (Board_getSquareContent(x, y) == NONE) {
    squareCallback(x, y, kindOfPiece);
    boardSquares[y][x] = kindOfPiece;
    if (isGameFinished(boardSquares, x, y, &gameResult))
      endCallback(gameResult);
    Is_empty = PIECE_IN_PLACE;
  } else {
    Is_empty = SQUARE_IS_NOT_EMPTY;
  }
  return Is_empty;
}

PieceType Board_getSquareContent(Coordinate x, Coordinate y) {
  return boardSquares[y][x];
}
