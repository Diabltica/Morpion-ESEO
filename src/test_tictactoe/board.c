#include "../etape1/board.h"
#include <stdbool.h>

#define LIGNES 3
#define COLONNES 3


static bool isGameFinished(const PieceType boardSquares[3][3],
                           Coordinate lastChangeX, Coordinate lastChangeY,
                           GameResult *gameResult)
{

	//check if the board is full
	bool stop = false;

	for (int i = 0; (i < LIGNES) && !stop; i++) {
		for (int j = 0; (j < COLONNES) && !stop; j++) {
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
