#pragma once
#ifndef INIT_H
#define INIT_H

#include<iostream>
#include <SDL.h>
//#include <SDL_image.h>
#include <string>

using namespace std;

void logSDLError(ostream& os, const string& msg, bool fatal)
{
	os << msg << " error: " << SDL_GetError() << endl;//tương đương cout << "-----" << endl;
	if (fatal)
	{
		SDL_Quit();
		exit(1);
	}
};

void renderTexture(SDL_Renderer* ren, SDL_Texture *text, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.h = h;
	dst.w = w;
	SDL_RenderCopy(ren, text, NULL, &dst);
};
void initSDL(SDL_Window* &win, SDL_Renderer* &ren, int w, int h, const string& title)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		logSDLError(cout, "SDL_Init", true);
	}

	win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		logSDLError(cout, "SDL_CreateWindow", true);
	}
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
	{
		logSDLError(cout, "SDL_CreateRenderer", true);
		SDL_DestroyWindow(win);
	}
};
void quitSDL(SDL_Window* win, SDL_Renderer* ren)
{
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
};
void waitUntilKeyPressed()
{
	SDL_Event e;
	while (true) {
		if (SDL_WaitEvent(&e) != 0 &&
			(e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
			return;
		SDL_Delay(100);
	}
}
#endif
//tạo cửa sổ chơi