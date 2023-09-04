#include "Game.hpp"

Game *game = nullptr;

int main(int argc, const char* argv[])
{
    const Uint8 FPS = 60;
    const Uint8 FRAME_DELAY = 1000 / FPS;
    
    Uint32 frameStart;
    Uint16 frameTime;
    
    game = new Game;

    game->init("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768, false);

    while(game->running())
    {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if(FRAME_DELAY > frameTime)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    game->clean();

    return 0;
}
