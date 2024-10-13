#include "game.hpp"

Game::Game(const char* title, int dimX, int dimY)
{
    if (!init(title, dimX, dimY))
    {
        std::cout << "Error! could not initialize SDL\n";
    }
    else
    {
        srand(time(NULL));
        m_bRunning = true;
        huntingTriangles = new HuntingSquares(dimX, dimY);
    }
}

Game::~Game()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

bool Game::init(const char* title, int dimX, int dimY)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimX, dimY, SDL_WINDOW_SHOWN);

    if (!m_pWindow)
    {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    
    if (!m_pRenderer)
    {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

    return true;
}

void Game::play()
{
    SDL_Event event;

    while (m_bRunning)
    {
        SDL_Delay(16);
        render();
        huntingTriangles->logic();
        handleEvents(event);        
    }
}

void Game::handleEvents(SDL_Event& event)
{
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            m_bRunning = false;
        }
        // huntingTriangles->handleEvents(event);
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(m_pRenderer, 180, 220, 255, 255);
    SDL_RenderClear(m_pRenderer);
    huntingTriangles->render(m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}
