#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	int statut = EXIT_FAILURE;

	if(0 != SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
		goto Quit;
	}
	window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480, SDL_WINDOW_SHOWN);
	if(NULL == window)
	{
		fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
		goto Quit;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(NULL == renderer)
	{
		fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
		goto Quit;
	}

	statut = EXIT_SUCCESS;
	SDL_Delay(3000);

Quit:
	if(NULL != renderer)
		SDL_DestroyRenderer(renderer);
	if(NULL != window)
		SDL_DestroyWindow(window);
	SDL_Quit();
	return statut;
}
