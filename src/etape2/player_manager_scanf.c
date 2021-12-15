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

PieceType thisPlayer;
void PlayerManager_interaction(int* x, int* y);

void PlayerManager_init (void)
{
	thisPlayer = CROSS;
	BoardView_displayAll(); // Display a first time the board
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{

	BoardView_displayPlayersTurn(thisPlayer);

	int x = 0;
	int y = 0;

	PlayerManager_interaction(&x, &y);

	//Put piece on boardgi
	bool is_put = false;
	do{
		PutPieceResult PieceResult = Board_putPiece(x,y,thisPlayer);
		if(PieceResult == SQUARE_IS_NOT_EMPTY){
			BoardView_sayCannotPutPiece();
			PlayerManager_interaction(&x, &y);
		}else if(PieceResult == PIECE_IN_PLACE){
			is_put = true;
		}

	}while(!is_put);

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

	//comparaison avec le code ASCII
	do{
		printf("Which row ? ");
		error = scanf("%c", &row);
		getchar();
	}while(error != 1 || row > 50 || row < 48);

	*x = row - 48; //on retrouve le nombre entier

	//comparaison avec le code ASCII
	do{
		printf("Which column ? ");
		error = scanf("%c", &col);
		getchar();
	}while(error != 1 || col > 50 || col < 48);

	*y = col - 48;

}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF