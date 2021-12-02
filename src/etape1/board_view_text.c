#include "board_view.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#if defined CONFIG_TEXTUI

extern PieceType boardSquares[3][3];


char boardDisplay[9][5] = {
        {' ', '|', ' ', '|', ' '}, {' ', '|', ' ', '|', ' '},// data
        {'_', '|', '_', '|', '_'}, {' ', '|', ' ', '|', ' '},
        {' ', '|', ' ', '|', ' '},// data
        {'_', '|', '_', '|', '_'}, {' ', '|', ' ', '|', ' '},
        {' ', '|', ' ', '|', ' '},// data
        {' ', '|', ' ', '|', ' '},
};

void BoardView_init(void)
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			boardSquares[i][j] = Board_getSquareContent(i, j);
		}
	}
}

void BoardView_free(void)
{
	for (int i = 0; i < 10; ++i) {

		boardDisplay[1][i * 2] = ' ';

		boardDisplay[4][i * 2] = ' ';

		boardDisplay[7][i * 2] = ' ';
	}
}

void BoardView_displayAll(void)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 5; j++) { printf("%c", boardDisplay[i][j]); }
		printf("\n");
	}
	printf("\n\n");
}

void BoardView_displaySquare(Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	char sym = ' ';
	sym = kindOfPiece == CIRCLE ? 'O' : 'X';// choose symbole
	switch (x) {
		case 0:
			boardDisplay[1][y * 2] = sym;
			break;
		case 1:
			boardDisplay[4][y * 2] = sym;
			break;
		case 2:
			boardDisplay[7][y * 2] = sym;
			break;
	}
	BoardView_displayAll();
}

void BoardView_displayEndOfGame(GameResult result)
{
	if (result == CIRCLE_WINS) {
		printf("Circle Wins\n");
	} else {
		printf("Cross Wins\n");
	}
	printf("  ________  ________                                .__        \n"
	       " /  _____/ /  _____/   ___.__. ____  __ __  __  _  _|__| ____  \n"
	       "/   \\  ___/   \\  ___  <   |  |/  _ \\|  |  \\ \\ \\/ \\/ /  |/   "
	       " \\ \n"
	       "\\    \\_\\  \\    \\_\\  \\  \\___  (  <_> )  |  /  \\     /|  |  "
	       " |  \\\n"
	       " \\______  /\\______  /  / ____|\\____/|____/    \\/\\_/ |__|___|  "
	       "/\n"
	       "        \\/        \\/   \\/                                   "
	       "\\/ ");
}

void BoardView_displayPlayersTurn(PieceType thisPlayer)
{
	switch (thisPlayer) {
		case CROSS:
			printf("It's the turn of cross \n");
			break;
		case CIRCLE:
			printf("It's the turn of circle \n");
			break;
	}
}

void BoardView_sayCannotPutPiece(void)
{
	printf("Square occupied; try again.\n");
}

#endif// defined CONFIG_TEXTUI
