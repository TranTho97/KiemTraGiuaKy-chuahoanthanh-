#include "Display.h"
#include "Game.h"
#include "Media.h"
#include "Player.h"
#include "utils.h"

#include <SDL.h>
#include <iostream>

int main(int argc, char* args[])
{
	Display display;
	Game game;
	Media media;
	Player player;
	SDL_Window* win = NULL;
	SDL_Renderer* ren = NULL;


	game.start(display, media, player);

	printf("\n\n\nYou Win!");
	SDL_Delay(3000);

	return 0;
}
void begin(SDL_Window* &win, SDL_Renderer* &ren, const int screen_height, const int screen_width)

{
	SDL_Texture *texb = loadTexture("image/begin.bmp", ren);
	renderTexture(texb, ren, 0, 0, screen_height, screen_width);

	SDL_Texture *texp = loadTexture("image/play.png", ren);
	renderTexture(texp, ren, 600, 10, 50, 160);

	SDL_Texture *texe = loadTexture("image/exit.png", ren);
	renderTexture(texe, ren, 600, 70, 50, 160);

	SDL_RenderPresent(ren);
	SDL_Event e;
	if (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
		{
			//exit
			quitSDL(win, ren);
			exit(1);
		}
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int x = e.button.x;
			int y = e.button.y;
			if (600 <= x && x <= 760)
			{
				if (10 <= y && y <= 60)
				{
					//play
				}
				if (70 <= y && y <= 120)
				{
					//exit
					quitSDL(win, ren);
					exit(1);
				}
			}
		}
	}

}