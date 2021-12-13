/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "../etape1/board.h"
#include "../etape1/board_view.h"
#include <SDL.h>
#include <assert.h>
#include <stdbool.h>

#if defined CONFIG_PLAYER_MANAGER_SDL

extern bool TemoinFinPartie;
PieceType thisPlayer;

void PlayerManager_init(void)
{
	thisPlayer = CROSS;
	assert(SDL_WasInit(SDL_INIT_VIDEO) != 0);
}

void PlayerManager_free(void) {}


static bool tryMove(int x, int y)
{
	if (x < 3 && x >= 0 && y < 3 && y >= 0) {
		if (Board_putPiece(x, y, thisPlayer) == PIECE_IN_PLACE) {
			return true;
		} else {
			BoardView_sayCannotPutPiece();
			return false;
		}
	}
}

void PlayerManager_oneTurn(void)
{
	int error;
	SDL_Event event;
	bool validMove;
	int xMouse, yMouse;

	BoardView_displayPlayersTurn(thisPlayer);
	BoardView_displayAll();

	do {

		validMove = false;
		error = SDL_WaitEvent(&event);
		assert(error == 1);

		switch (event.type) {
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
					validMove = true;
					TemoinFinPartie = true;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				SDL_GetMouseState(&xMouse, &yMouse);
				xMouse = xMouse / 158;
				yMouse = yMouse / 158;
				validMove = tryMove(xMouse, yMouse);
				BoardView_displayAll();
				break;
		}
	} while (!validMove);

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

#endif// defined CONFIG_PLAYER_MANAGER_SCANF
