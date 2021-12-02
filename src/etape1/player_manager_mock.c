/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_PLAYER_MANAGER_MOCK

PieceType thisPlayer;

void PlayerManager_init(void) { thisPlayer = CROSS; }

void PlayerManager_free(void) {}

void PlayerManager_oneTurn(void)
{
	//Coordinates choices
	char x;
	int y;
	printf("x ?");
	scanf("%d", &x);
	printf("y ?");
	scanf("%d", &y);
	//Put piece on board
	Board_putPiece(x, y, thisPlayer);

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

#endif//  #if defined CONFIG_PLAYER_MANAGER_MOCK
