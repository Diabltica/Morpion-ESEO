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
int i;

void PlayerManager_init(void)
{
	thisPlayer = CROSS;
	i = 0;
}

void PlayerManager_free(void) {}

void PlayerManager_oneTurn(void)
{
	//Coordinates choices
	int test_x[5] = {1, 0, 1, 0, 1};
	int test_y[5] = {0, 0, 1, 1, 2};


	Board_putPiece(test_x[i], test_y[i], thisPlayer);

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
	i++;
}

#endif//  #if defined CONFIG_PLAYER_MANAGER_MOCK
