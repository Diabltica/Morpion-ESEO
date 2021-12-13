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
	//Circle Win test set
	int test_x[6] = {0, 1, 0, 1, 2, 1};
	int test_y[6] = {0, 0, 1, 1, 2, 2};
	//Draw Test set
//	int test_x[9] = {0,0,1,2,1,0,2,1,2};
//	int test_y[9] = {1,0,0,1,1,2,0,2,2};


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
