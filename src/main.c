#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD)) {
		SDL_LogError(SDL_LOG_CATEGORY_CUSTOM, "SDL could not be initialized: %s\n", SDL_GetError());
	}

	printf("H W\n");

	SDL_Quit();

	return 0;
}
