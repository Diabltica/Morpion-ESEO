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
	bool played = false;
	while (!played) {
		//The player choose a case to play
		int x;
		scanf("Which line ? : %d", &x);
		int y;
		scanf("Which columne ? : %d", &y);

		//Condition to validate the choice
		if (!Board_getSquareContent(x, y)) {
			printf("Error : the case is out. Choose again !");
		} else if (Board_getSquareContent(x, y) != NONE) {
			printf("Error : the case is already taken. Choose again !");
		} else {
			Board_putPiece(x, y, thisPlayer);
			played = true;
		}
	}
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
