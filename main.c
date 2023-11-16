#include <SDL.h>
#include <math.h>
#include <time.h>
#include "base.h"  
#include <stdbool.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Blinking Light", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 50, 50, 0);
    if (!window) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    clock_t startTime = clock();
    float frequency = 2.5f; // Start at 2.5Hz

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        clock_t currentTime = clock();
        float elapsed = (float)(currentTime - startTime) / (float)CLOCKS_PER_SEC;
        float minutesPassed = elapsed / 60.0f;

        // interpolate from 2.5hz to 1hz over the course of 60 minutes
        frequency = ClampBottom(1.0f, 2.5f - (minutesPassed / 60.0f) * (2.5f - 1.0f));

        // Calculate color based on sine wave for smooth transition
        float sine = sinf(SDL_GetTicks() * 0.001f * frequency * 3.14159f * 2.0f);
        int colorValue = (int)((sine + 1.0f) / 2.0f * 255);

        SDL_SetRenderDrawColor(renderer, colorValue, colorValue, 0, 255); // Yellow to Black transition
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(10); // A short delay to limit the update rate
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
