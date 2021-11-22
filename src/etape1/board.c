#include "board.h"
#include <assert.h>

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
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 *
 */
static bool isGameFinished(const PieceType boardSquares[3][3],
                           Coordinate lastChangeX, Coordinate lastChangeY,
                           GameResult *gameResult) {
  // TODO: à compléter
}

void Board_free() {
  // TODO: à compléter
}

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