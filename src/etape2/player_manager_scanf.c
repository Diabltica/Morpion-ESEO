/**
* @file player_manager_scanf.c
*
* @date 7 oct. 2016
* @author jilias
*/

#include "../etape1/board.h"
#include "../etape1/board_view.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_PLAYER_MANAGER_SCANF

PieceType thisPlayer; //declare variable to know who play
void PlayerManager_interaction(int* x, int* y); //definition function who
// handle interaction with players

void PlayerManager_init (void)
{
	thisPlayer = CROSS; //Choose the first player
	BoardView_displayAll(); // Display a first time the board
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{

	BoardView_displayPlayersTurn(thisPlayer); //display who need to play

	//declare buffer for coordinate
	int x = 0;
	int y = 0;

	PlayerManager_interaction(&x, &y); //ask player coordinate to put his piece

	//Put piece on board
	bool is_put = false; // to know if the piece is placed
	do{
		//try to put the piece
		PutPieceResult PieceResult = Board_putPiece(x,y,thisPlayer);
		if(PieceResult == SQUARE_IS_NOT_EMPTY){ // If the square is not empty
			BoardView_sayCannotPutPiece();//display msg
			PlayerManager_interaction(&x, &y);//ask new coordinate
		}else if(PieceResult == PIECE_IN_PLACE){// If the square is empty
			is_put = true;//Piece placed
		}

	}while(!is_put); //while the piece is not placed

	//next player
	switch (thisPlayer) {
		case CROSS:
			thisPlayer = CIRCLE;
			break;
		case CIRCLE:
			thisPlayer = CROSS;
			break;
		default:
			printf("Error during change of player.");
	}


}

void PlayerManager_interaction(int* x, int* y){
	int error;
	char row;
	char col;

	//Compare with ASCII Code
	do{
		printf("Which row ? ");
		error = scanf("%c", &row);
		getchar();
	}while(error != 1 || row > 50 || row < 48); //While the input is wrong

	*x = row - 48; //get correct coordinate

	//Compare with ASCII Code
	do{
		printf("Which column ? ");
		error = scanf("%c", &col);
		getchar();
	}while(error != 1 || col > 50 || col < 48);//While the input is wrong

	*y = col - 48;//get correct coordinate

}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF