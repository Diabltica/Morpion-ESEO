#include "board_view.h"
#include <stdio.h>
#include <stdlib.h>

#if defined CONFIG_TEXTUI//This code will be executed if CONFIG_TEXTUI = 1

extern PieceType boardSquares[3][3];//call the variable boardsquare from board

void clear();//declare the function clear that will clean the console

//declare and initialize the board that will be display
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
#ifndef CONFIG_PLAYER_MANAGER_MOCK//If we don't use the mock
	clear();                      // clear the console
#endif
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			boardSquares[i][j] = Board_getSquareContent(i, j);//init the board
		}
	}
}

void BoardView_free(void)
{
	for (int i = 0; i < 10; ++i) {//remove pieces displayed
		boardDisplay[1][i * 2] = ' ';
		boardDisplay[4][i * 2] = ' ';
		boardDisplay[7][i * 2] = ' ';
	}
}

void BoardView_displayAll(void)
{

#ifndef CONFIG_PLAYER_MANAGER_MOCK//If we don't use the mock
	clear();                      // clear the console
#endif

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%c", boardDisplay[i][j]);//Display all the piece
		}
		printf("\n");//line break
	}
	printf("\n\n");//line break
}

void BoardView_displaySquare(Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	char sym;
	sym = kindOfPiece == CIRCLE ? 'O' : 'X';// choose symbol
	switch (x) {                            //put the symbol to the right square
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
	BoardView_displayAll();//re display the board
}

void BoardView_displayEndOfGame(GameResult result)
{

#ifndef CONFIG_PLAYER_MANAGER_MOCK//If we don't use the mock
	clear();                      // clear the console
#endif
	BoardView_displayAll();//display the board
	bool is_draw = false;
	if (result == CIRCLE_WINS) {// Circle wins
		printf("Circle Wins\n");
	} else if (result == CROSS_WINS) {// If cross wins
		printf("Cross Wins\n");
	} else {
		is_draw = true;//save that is a draw
		printf("________ __________    _____  __      __ \n"
		       "\\______ \\\\______   \\  /  _  \\/  \\    /  \\\n"
		       " |    |  \\|       _/ /  /_\\  \\   \\/\\/   /\n"
		       " |    `   \\    |   \\/    |    \\        / \n"
		       "/_______  /____|_  /\\____|__  /\\__/\\  /  \n"
		       "        \\/       \\/         \\/      \\/ \n  ");
		//display a message
	}
	if (!is_draw) {//if it's not a draw

		printf("  ________  ________                                .__        "
		       "\n"
		       " /  _____/ /  _____/   ___.__. ____  __ __  __  _  _|__| ____  "
		       "\n"
		       "/   \\  ___/   \\  ___  <   |  |/  _ \\|  |  \\ \\ \\/ \\/ /  "
		       "|/   "
		       " \\ \n"
		       "\\    \\_\\  \\    \\_\\  \\  \\___  (  <_> )  |  /  \\     /| "
		       " |  "
		       " |  \\\n"
		       " \\______  /\\______  /  / ____|\\____/|____/    \\/\\_/ "
		       "|__|___|  "
		       "/\n"
		       "        \\/        \\/   \\/                                   "

		       "\\/ \n");//display a message
	}
}

void BoardView_displayPlayersTurn(PieceType thisPlayer)//display the
													  // players turns
{
	switch (thisPlayer) {
		case CROSS: //if it's the turn of cross player
			printf("It's cross turn \n");
			break;
		case CIRCLE://if it's the turn of circle player
			printf("It's circle turn \n");
			break;
	}
}

void BoardView_sayCannotPutPiece(void)//display that the square is occupied
{
	printf("Square occupied try again.\n");
}

void clear()
{//Clear screen
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	// Check OS
	system("clear");// send the command clear
#endif

#if defined(_WIN32) || defined(_WIN64)
	system("cls");//send the command cls
#endif
}

#endif// defined CONFIG_TEXTUI
