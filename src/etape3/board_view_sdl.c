/**
 * @file board_view_text.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "../etape1/board_view.h"
#include "../etape1/tictactoe_errors.h"
#include <SDL.h>
#include <SDL_image.h>
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_SDLUI

static SDL_Window *MainWindow;
static SDL_Renderer *MainRenderer;
static SDL_Surface *BackgroundImage;
static SDL_Surface *SpriteO;
static SDL_Surface *SpriteX;
static SDL_Surface *SpriteWin;
static SDL_Surface *SpriteNo;
static SDL_Surface *SpriteOturn;
static SDL_Surface *SpriteXturn;
static SDL_Surface *SpriteDraw;

static void renderImage(SDL_Surface *image, int x, int y)
{
	SDL_Texture *aTexture;
	aTexture = SDL_CreateTextureFromSurface(MainRenderer, image);
	assert(aTexture != NULL);
	SDL_Rect pos = {x, y, image->w, image->h};
	SDL_RenderCopy(MainRenderer, aTexture, 0, &pos);
	SDL_RenderPresent(MainRenderer);
	SDL_DestroyTexture(aTexture);
}

void BoardView_init(void)
{
	int result;

	// Initialize SDL
	result = SDL_Init(SDL_INIT_VIDEO);
	if (result != 0) { fatalError(SDL_GetError()); }
	atexit(SDL_Quit);

	// Initialize SDL_image
	int initted = IMG_Init(IMG_INIT_PNG);
	if (initted != IMG_INIT_PNG) { fatalError(IMG_GetError()); }

	// Loads images
	BackgroundImage = IMG_Load("../src/etape3/background.png");
	if (BackgroundImage == NULL) fatalError(IMG_GetError());
	SpriteO = IMG_Load("../src/etape3/sprite_O.png");
	if (SpriteO == NULL) fatalError(IMG_GetError());
	SpriteX = IMG_Load("../src/etape3/sprite_X.png");
	if (SpriteX == NULL) fatalError(IMG_GetError());
	SpriteWin = IMG_Load("../src/etape3/win.png");
	if (SpriteWin == NULL) fatalError(IMG_GetError());
	SpriteNo = IMG_Load("../src/etape3/no.png");
	if (SpriteNo == NULL) fatalError(IMG_GetError());
	SpriteOturn = IMG_Load("../src/etape3/Circle_turn.png");
	if (SpriteOturn == NULL) fatalError(IMG_GetError());
	SpriteXturn = IMG_Load("../src/etape3/Cross_turn.png");
	if (SpriteXturn == NULL) fatalError(IMG_GetError());
	SpriteDraw = IMG_Load("../src/etape3/draw.png");
	if (SpriteDraw == NULL) fatalError(IMG_GetError());
	// Creates the window
	MainWindow = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED,
	                              SDL_WINDOWPOS_UNDEFINED, 480, 480, 0);
	if (MainWindow == NULL) { fatalError(SDL_GetError()); }

	// Creates the main renderer
	MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
	if (MainRenderer == NULL) { fatalError(SDL_GetError()); }
}

void BoardView_free(void)
{
	SDL_DestroyRenderer(MainRenderer);
	SDL_DestroyWindow(MainWindow);
	SDL_FreeSurface(SpriteX);
	SDL_FreeSurface(SpriteO);
	SDL_FreeSurface(SpriteWin);
	SDL_FreeSurface(SpriteNo);
	SDL_FreeSurface(SpriteOturn);
	SDL_FreeSurface(SpriteXturn);
	SDL_FreeSurface(SpriteDraw);
	SDL_FreeSurface(BackgroundImage);
	IMG_Quit();
	SDL_Quit();
}

void BoardView_displayAll(void)
{
	/* utiliser "renderImage" pour afficher l'image de fond "BackgroundImage",
	 * puis afficher l'ensemble des cases à l'aide de la fonction BoardView_displaySquare
	 */
	PieceType toDisplay = NONE;        // by default display none
	renderImage(BackgroundImage, 0, 0);//display background

	//loop to display all square
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			toDisplay = Board_getSquareContent(i, j);// get the piece type
			BoardView_displaySquare(j, i, toDisplay);// Display the piece
			SDL_Delay(1);//little delay avoiding blinking
		}
	}
}

void BoardView_displaySquare(Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	/* utiliser "renderImage" pour afficher le sprite correspondant à kindOfPiece à
	 * l'endroit correspondant aux coordonnées logiques "x" et "y".
	 */
	int displayed_x = x * 158;//display to the right coordinate
	int displayed_y = y * 158;//display to the right coordinate

	if (kindOfPiece == CROSS) {                        //if it's a cross
		renderImage(SpriteX, displayed_y, displayed_x);//display cross
	} else if (kindOfPiece == CIRCLE) {                //if it's a circle
		renderImage(SpriteO, displayed_y, displayed_x);//display circle
	}
}

void BoardView_displayEndOfGame(GameResult result)
{
	if (result == DRAW) {
		renderImage(SpriteDraw, 0, 0);//display draw image
	} else {
		renderImage(SpriteWin, 0, 0);//display win image
	}
	SDL_Delay(2000);//delay to see the image
}

void BoardView_displayPlayersTurn(PieceType thisPlayer)
{
	if (thisPlayer == CROSS) {
		renderImage(SpriteXturn, 0, 0);//display cross turn image
	} else {
		renderImage(SpriteOturn, 0, 0);//display circle turn image
	}
	SDL_Delay(200);//delay to see the image
}

void BoardView_sayCannotPutPiece(void)
{
	renderImage(SpriteNo, 0, 0);
	SDL_Delay(200);
}

#endif// defined CONFIG_SDLUI
