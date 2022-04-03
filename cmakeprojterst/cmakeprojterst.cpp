// cmakeprojterst.cpp : Defines the entry point for the application.
//

#include "cmakeprojterst.h"
#include "util.h"
#include "SDL/SDL.h"
#include <iostream>
#include <vector>
#include <functional>
#include <stdio.h>
#include <string>
#include "Game.h"

bool playing = false;


SDL_Window* createWindow(const char *title, int x, int y, int w, int h, Uint32 flags) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_init error: " << SDL_GetError() << std::endl;
	}

	SDL_Window* win = SDL_CreateWindow("hellworld", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	if (win == nullptr) {
		std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
	return win;
}

SDL_Renderer* createRenderer(SDL_Window * win,int index, Uint32 flags) {
	SDL_Renderer* ren = SDL_CreateRenderer(win, index, flags);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
	return ren;
}

void handleWindowEvents(SDL_Event &e) {
	if (e.type == SDL_WINDOWEVENT) {
		switch (e.window.event) {
		case SDL_WINDOWEVENT_CLOSE:
			SDL_Log("window %d closed", e.window.windowID);
			playing = false;
			break;
		//default:
		//	SDL_Log("window %d got unkown event %d", e.window.windowID, e.window.event);
		//	break;
		}
	}
}

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;

int tet_square[3 * 3] = {
	0,1,0,
	0,1,0,
	1,1,0,
};

Matrix squarePiece{ 3, 3, tet_square }; 


void drawRectanlge(SDL_Renderer *renderer, SDL_Rect *rect) { 
}



void draw() {

	//SDL_Rect rect {
	//	50,//x
	//	50,//y
	//	50,//w
	//	50,//h
	//};

	//setBackgroundColor(255,255,0,255);
	//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	//renderPiece(&squarePiece);
	//SDL_RenderPresent(renderer);
}


int main(int argc, char* argv[]) 
{
	window = createWindow("tetris", 100,100, 640, 480, SDL_WINDOW_SHOWN);
	renderer = createRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Game game{ window, renderer };

	SDL_Event event;
	playing = true;

	while (playing) {
		while (SDL_PollEvent(&event)) {
			handleWindowEvents(event);
			game.handleKeypresses(event);
		}
		game.update();
		game.draw();
	};

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return 0;
}
