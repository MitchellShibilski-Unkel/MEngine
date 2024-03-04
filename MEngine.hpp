#include "SDL.h"
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
#include "py.c"

using namespace std;

class MEngine {
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	PyFuncs m_pyf;
	bool running = true;

	void end() {
		SDL_DestroyWindowSurface(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

public:
	void createWindow(const char* caption, int width, int height, bool fullscreen, bool resizable) {
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
			if (fullscreen == true) {
				m_window = SDL_CreateWindow(caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN);
			} else if (resizable == true) {
				m_window = SDL_CreateWindow(caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
			} else {
				m_window = SDL_CreateWindow(caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		    }

			m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		} else {
			printf("ERROR :: Window Could Not Be Created :(");
			printf(SDL_GetError());
		}
	}

	void drawRectangle(int pos[2], int width, int height, int r, int g, int b, bool onlyShowOutline) {
		SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);

		SDL_Rect rect;

		rect.x = pos[0];
		rect.y = pos[1];
		rect.w = width;
		rect.h = height;

		if (!onlyShowOutline == true) {
			SDL_RenderFillRect(m_renderer, &rect);
		} else {
			SDL_RenderDrawRect(m_renderer, &rect);
		}
	}

	void drawLine(int pointOne[2], int pointTwo[2], int r, int g, int b) {
		SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
		SDL_RenderDrawLine(m_renderer, pointOne[0], pointOne[1], pointTwo[0], pointOne[1]);
	}

	void restRender() {
		SDL_RenderClear(m_renderer);
	}

	void showRender() {
		SDL_UpdateWindowSurface(m_window);
		SDL_RenderPresent(m_renderer);
	}

	int gravity(int ground, int acceleration, int objectY, int mass) {
		int distance = y - ground;
		int force = (acceleration * mass) / distance
		
		return round(force);
	}

	void update(bool runVar) {	
		SDL_Event event;

		while (runVar == true) {
			while (SDL_PollEvent(&event) > 0) {
				if (event.type == SDL_QUIT) {
					runVar = false;
					break;
				}
			}
		}

		if (runVar == false) {
			end();
		}
	}
};
