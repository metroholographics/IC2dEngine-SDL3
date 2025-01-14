#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	const int screen_width = 1920;
	const int screen_height = 1080;

	const SDL_Color bg_color = {
		.r = 100,
		.g = 149,
		.b = 237,
		.a = 255
	};

	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD)) {
		SDL_LogError(SDL_LOG_CATEGORY_CUSTOM, "SDL could not be initialized: %s\n", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow("Engine", screen_width, screen_height, 0);
	if (!window) {
		SDL_LogError(SDL_LOG_CATEGORY_CUSTOM, "SDL window could not be created: %s\n", SDL_GetError());
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer) {
		SDL_LogError(SDL_LOG_CATEGORY_CUSTOM, "SDL renderer could not be created: %s\n", SDL_GetError());
	}

	SDL_Event evt;
	bool running = true;
	const double performance_frequency_inverse = 1.0 / (double)SDL_GetPerformanceFrequency();
	uint64_t last_time = SDL_GetPerformanceCounter();

	while (running) {
		const uint64_t current_time = SDL_GetPerformanceCounter();
		const float delta_time = (float)((double)(current_time - last_time) * performance_frequency_inverse);

		while (SDL_PollEvent(&evt)) {
			if (evt.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, bg_color.r, bg_color.g, bg_color.b, bg_color.a);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

		last_time = current_time;
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

}
