#include "hunting_squares.hpp"

HuntingSquares::HuntingSquares(int screenWidth, int screenHeight)
{
    // Initialize vector of goal points.
    for (int i=0; i < n; i++)
    {
        SDL_Rect sp = {rand()%(screenWidth-200)+100, rand()%(screenHeight-200)+100, 20, 20};
        setPoints.push_back(sp);
    }

    setPoint = setPoints.back();
    pIndex += 1;

}

void HuntingSquares::logic()
{
    float distance = sqrt(square(setPoint.x - player.x - pw/2) + square(setPoint.y - player.y - ph/2));
    std::cout << setPoint.x - player.x << ' ' << distance << std::endl;
    if (distance < 20 && pIndex < n)
    {
        pIndex += 1;
        setPoints.pop_back();
        setPoint = setPoints.back();
    }

    player.x += (int) pidX.compute((float) setPoint.x, (float) player.x + pw/2, 0.016f);
    player.y += (int) pidY.compute((float) setPoint.y, (float) player.y + ph/2, 0.016f);
    // std::cout << pX << ' ' << pY << std::endl;
}

void handleEvents(SDL_Event &event)
{
}

void HuntingSquares::render(SDL_Renderer* pRenderer)
{
    SDL_Event event;

    SDL_SetRenderDrawColor(pRenderer, 0, 100, 0, 255);
    SDL_RenderFillRect(pRenderer, &player);
    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(pRenderer, &setPoint);

    // std::cout << setPoint.x << ' ' << setPoint.y << std::endl;
    // std::cout << player.x << ' ' << player.y << std::endl;
}

float HuntingSquares::square(float x)
{
    return x * x;
}
