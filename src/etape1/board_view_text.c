#include "board_view.h"
#include <stdio.h>
#include <stdlib.h>

int isPlayerMock = 0;

#if defined CONFIG_TEXTUI

extern PieceType boardSquares[3][3];
void clear();

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
	#ifndef CONFIG_PLAYER_MANAGER_MOCK
		clear();
	#endif
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

	#ifndef CONFIG_PLAYER_MANAGER_MOCK
		clear();
	#endif

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 5; j++) { printf("%c", boardDisplay[i][j]); }
		printf("\n");
	}
	printf("\n\n");
}

void BoardView_displaySquare(Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	char sym;
	sym = kindOfPiece == CIRCLE ? 'O' : 'X';// choose symbol
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

	#ifndef CONFIG_PLAYER_MANAGER_MOCK
		clear();
	#endif
	BoardView_displayAll();
	bool is_draw = false;
	if (result == CIRCLE_WINS) {
		printf("Circle Wins\n");
	} else if (result == CROSS_WINS) {
		printf("Cross Wins\n");
	}else{
		is_draw = true;
		printf("________ __________    _____  __      __ \n"
		       "\\______ \\\\______   \\  /  _  \\/  \\    /  \\\n"
		       " |    |  \\|       _/ /  /_\\  \\   \\/\\/   /\n"
		       " |    `   \\    |   \\/    |    \\        / \n"
		       "/_______  /____|_  /\\____|__  /\\__/\\  /  \n"
		       "        \\/       \\/         \\/      \\/ \n  ");
	}
	if(!is_draw){

		printf("  ________  ________                                .__        \n"
		       " /  _____/ /  _____/   ___.__. ____  __ __  __  _  _|__| ____  \n"
		       "/   \\  ___/   \\  ___  <   |  |/  _ \\|  |  \\ \\ \\/ \\/ /  |/   "
		       " \\ \n"
		       "\\    \\_\\  \\    \\_\\  \\  \\___  (  <_> )  |  /  \\     /|  |  "
		       " |  \\\n"
		       " \\______  /\\______  /  / ____|\\____/|____/    \\/\\_/ |__|___|  "
		       "/\n"
		       "        \\/        \\/   \\/                                   "

		       "\\/ \n");
	}
}

void BoardView_displayPlayersTurn(PieceType thisPlayer)
{
	switch (thisPlayer) {
		case CROSS:
			printf("It's cross turn \n");
			break;
		case CIRCLE:
			printf("It's circle turn \n");
			break;
	}
}

void BoardView_sayCannotPutPiece(void)
{
	printf("Square occupied try again.\n");
}

void clear(){ //Clear screen
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	                                                                  // Check OS
		system("clear");
	#endif

	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

#endif// defined CONFIG_TEXTUI
