#include <iostream>
#include <SDL.h>
#include <math.h>
#include <deque>

using namespace std;

SDL_Renderer *ren;


struct Square{
	SDL_Rect rect;
	short red, green, blue, alpha, weight;
	int h, g, x, y;
	Square *parent;
	deque<Square> openList, closedList;

	bool isStart, isTarget, isObstacle;

	Square() {
		rect.x = 0;
		rect.y = 0;
		rect.w = 10;
		rect.h = 10;
		red = 255;
		green = 255;
		blue = 255;
		alpha = 255;
		//parent = NULL;
		h = 0;
		g = 0;
		weight = 1;
	}

	Square(int x, int y) {
		rect.x = x;
		rect.y = y;
		rect.w = 25;
		rect.h = 25;
		red = 0;
		green = 0;
		blue = 0;
		alpha = 255;
		//parent = -1;
		h = 0;
		g = 0;
		weight = 1;
	}

	void draw() {
		SDL_SetRenderDrawColor(ren, red, green, blue, alpha);
		SDL_RenderFillRect(ren, &rect);
	}

	int getF() {
		return (h + g);
	}

	void AStarPath(Square *start, Square *target) {
		Square *curr = start;

		openList.push_back(*curr);

		
		
		for (auto a = openList.begin(); a != openList.end(); a++) {
		}
	}
	
};









int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow("A* Algorithm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 960, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);




	Square *square[20][20];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			square[i][j] = new Square(i * 30 + 300, j * 30 + 200);
			square[i][j]->x = i;
			square[i][j]->y = j;
			if ((int)sqrt(i*i + j*j) % 3 == 0 && (i) % 3 != 2)
			{
				square[i][j]->blue = 127;
				square[i][j]->isObstacle = true;
			}
		}
	}

	Square *start = square[1][17];
	start->green = 127;
	start->isStart = true;

	Square *target = square[18][9];
	target->red = 127;
	target->isTarget = true;


	SDL_Event e;
	bool quit = 0;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = 1;
			}
		}

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				square[i][j]->draw();
			}
		}

		SDL_RenderPresent(ren);
		SDL_SetRenderDrawColor(ren, 40, 40, 40, 25);
		SDL_RenderClear(ren);
	}

	return 0;
}