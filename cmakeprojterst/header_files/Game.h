#include "cmakeprojterst.h"
#include "util.h"
#include "SDL/SDL.h"
#include <iostream>
#include <vector>
#include <functional>
#include <stdio.h>
#include <string>


SDL_Window* createWindow(const char* title, int x, int y, int w, int h, Uint32 flags);

SDL_Renderer* createRenderer(SDL_Window* win, int index, Uint32 flags);


 class Game {
private: 
	bool playing = true;
	SDL_Renderer* renderer = NULL;
	SDL_Window* window = NULL;
	int gridH = 20;
	int gridW = 10;
	Matrix grid;
	

	int tet_square[3 * 3] = {
		0,1,0,
		0,1,0,
		1,1,0,
	};
	Matrix *controlPiece;
	Matrix squarePiece{ 3, 3, tet_square }; 
public:
	//Game(SDL_Window* window) :
	//	window{ window },
	//	renderer{ createRenderer(window,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) }
	//{};

	Game(SDL_Window* window, SDL_Renderer* renderer) :
		window{ window },
		renderer{ renderer },
		grid{gridH, gridW}
	{
	};

	inline void setBackgroundColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a ) {
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
		SDL_RenderClear(renderer);
	}

	inline void handleKeypresses(SDL_Event &e) {
		switch (e.type) {
			case SDL_KEYDOWN: 
				switch (e.key.keysym.sym) {
					case SDLK_LEFT:
						rotateMatrix(&squarePiece, ROT_DIR::COUNTERCLOCKWISE);
						break;
					case SDLK_RIGHT:
						rotateMatrix(&squarePiece, ROT_DIR::CLOCKWISE);
						break;
					case SDLK_UP:
						break;
					case SDLK_DOWN:
						break;
				}
		}
	}

	inline void renderPiece(Matrix* mat) {
		int x = 50;
		int y = 50;
		
		SDL_Rect rect {
			50,//x
			50,//y
			50,//w
			50,//h
		};

		for (int row = 0; row < mat->height; row++) {
			for (int col = 0; col < mat->width; col++) {
				int idx = mat->getIndex(col, row);
				int color = mat->data.at(idx);
				if (color == 1) {
					SDL_Rect rect {
						50 * col,//x
						50 * row,//y
						50,//w
						50,//h
					};
					SDL_RenderFillRect(renderer, &rect);
				}
			}
		}
	}

	inline void update() {}

	inline void draw() {
		setBackgroundColor(255,255,0,255);
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		renderPiece(&squarePiece);
		SDL_RenderPresent(renderer);
	}
	
};

