#pragma once

#include <SDL2/SDL.h>
#include "iostream"
#include "hunting_squares.hpp"

class Game
{
    public:
        Game(const char* title, int dimX, int dimY);
        ~Game();
        void play();
        bool isRunning() {return m_bRunning;}

    private:
        SDL_Renderer* m_pRenderer;
        SDL_Window* m_pWindow;
        HuntingSquares* huntingTriangles;
        bool m_bRunning = false;

        bool init(const char* title, int dimX, int dimY);
        void handleEvents(SDL_Event& event);
        void render();
};