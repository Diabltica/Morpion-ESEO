#include "board.h"
#include <stdbool.h>

//define the size of the board
#define LIGNES 3
#define COLONNES 3

PieceType boardSquares[LIGNES][COLONNES]; //declare the board
SquareChangeCallback boardOnSquareChange; //declare OnSquareChange callback
EndOfGameCallback boardOnEndOfGame;//declare EndOfGame Callback
GameResult boardGameResult; //declare the gameresult variable


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
 * @pre boardGameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 *
 */
static bool isGameFinished(const PieceType boardSquares[3][3],
                           Coordinate lastChangeX, Coordinate lastChangeY,
                           GameResult *gameResult)
{

	//check if the board is full
	bool stop = true;
	for (int i = 0; (i < LIGNES) && stop; i++) {
		for (int j = 0; (j < COLONNES) && stop; j++) {
			if (boardSquares[i][j] == NONE) {
				stop = false;
			}
		}
	}
	if (stop) { //if the board is full return DRAW
		*gameResult = DRAW;
		return true;
	}

	// Check if the last piece played win the game
	//Check for columns
	if (boardSquares[lastChangeY][0] == boardSquares[lastChangeY][1] &&
	            boardSquares[lastChangeY][1] == boardSquares[lastChangeY][2] &&
	            boardSquares[lastChangeY][2] != NONE ||
	    //Check for row
	    boardSquares[0][lastChangeX] == boardSquares[1][lastChangeX] &&
	            boardSquares[1][lastChangeX] == boardSquares[2][lastChangeX] &&
	            boardSquares[2][lastChangeX] != NONE ||
	    //Check for diagonal (top left to bottom right)
	    lastChangeX == lastChangeY &&
	            boardSquares[0][0] == boardSquares[1][1] &&
	            boardSquares[1][1] == boardSquares[2][2] &&
	            boardSquares[2][2] != NONE ||
	    //Check for the other diagonal (bottom left to top right)
	    lastChangeX + lastChangeY == 2 &&
	            boardSquares[0][2] == boardSquares[1][1] &&
	            boardSquares[1][1] == boardSquares[2][0] &&
	            boardSquares[2][0] != NONE) {
		//Check who's the winner and change *gameResult
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
		*gameResult = DRAW;//return Draw if the game is not ended
		return false;
	}
}


void Board_init(SquareChangeCallback onSquareChange,
                EndOfGameCallback onEndOfGame)//init the board
{
	for (int i = 0; i < LIGNES; ++i) {
		for (int j = 0; j < COLONNES; ++j) { boardSquares[i][j] = NONE; }
	}                                    // initialize all square to NONE
	boardOnSquareChange = onSquareChange;//init the OnSquareChange callback
	boardOnEndOfGame = onEndOfGame;      // init the EndOfGame callback
}

void Board_free()
{
	for (int i = 0; i < LIGNES; ++i) {
		for (int j = 0; j < COLONNES; ++j) { boardSquares[i][j] = NONE; }
	}// Free the board by putting all square to None
}

PutPieceResult Board_putPiece(Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	PutPieceResult Is_empty;

	if (Board_getSquareContent(x, y) == NONE) { //check if the square is empty
		boardSquares[y][x] = kindOfPiece; // Put the piece
		boardOnSquareChange(x, y, kindOfPiece);//Call OnSquareChange callback
		//Check if the game is win
		if (isGameFinished(boardSquares, x, y, &boardGameResult))
			boardOnEndOfGame(boardGameResult);//Call EndOfGame callback
		Is_empty = PIECE_IN_PLACE; //save that the piece is in place
	} else {
		Is_empty = SQUARE_IS_NOT_EMPTY; //save that the square is occupied
	}
	return Is_empty; //return the value saved
}

PieceType Board_getSquareContent(Coordinate x, Coordinate y)
{
	return boardSquares[y][x]; // return the content of the square
}
