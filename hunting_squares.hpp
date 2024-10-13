#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include <cmath>
#include "pid_controller.hpp"


class HuntingSquares
{
    public:
        HuntingSquares(int screenWidth, int screenHeight);
        void render(SDL_Renderer* pRenderer);
        void logic();
        void handleEvents(SDL_Event &event);


    private:
        float square(float x);
        std::vector<SDL_Rect> setPoints;
        unsigned int pIndex = 0;
        SDL_Rect setPoint; 

        int n = 100;
        int pw = 100, ph = 100;
        SDL_Rect player = {50, 50, pw, ph};

        PID pidX = {0.04f, 0.08f, 0.01f, 10.0f, -10.0f};
        PID pidY = {0.04f, 0.08f, 0.01f, 10.0f, -10.0f};
};