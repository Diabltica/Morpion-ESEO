/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include <SDL.h>
#include <assert.h>
#include <stdbool.h>

#if defined CONFIG_PLAYER_MANAGER_SDL

extern bool TemoinFinPartie;

void PlayerManager_init(void) { assert(SDL_WasInit(SDL_INIT_VIDEO) != 0); }

void PlayerManager_free(void) {}


static bool tryMove(int x, int y)
{

	// TODO: à compléter
}

void PlayerManager_oneTurn(void)
{
	int error;
	SDL_Event event;
	bool validMove;

	do {
		BoardView_displayAll();

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
				Board_putPiece(1,1,CROSS);
//				printf("Bonjour");
				break;
		}
	} while (!validMove);
}

#endif// defined CONFIG_PLAYER_MANAGER_SCANF
