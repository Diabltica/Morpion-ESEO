/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_PLAYER_MANAGER_SCANF

PieceType thisPlayer;

void PlayerManager_init (void)
{
	thisPlayer = CROSS;
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
	int error;
	char row;
	char col;

	//comparaison avec le code ASCII
	do{
		printf("Wich row ? ");
		error = scanf("%c", &row);
		getchar();
	}while(error != 1 || row > 50 || row < 48);

	//comparaison avec le code ASCII
	do{
		printf("Wich columne ? ");
		error = scanf("%c", &col);
		getchar();
	}while(error != 1 || col > 50 || col < 48);

	//Put piece on board
	Board_putPiece(row,col,thisPlayer);

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

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
