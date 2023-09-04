#pragma once

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component {
public:
	TransformComponent *transform;

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
		SDL_EventState(SDL_MOUSEMOTION,SDL_IGNORE);
	}

	void update() override {
		while(SDL_PollEvent(&Game::event)) {
			if (Game::event.type == SDL_KEYDOWN) {
				switch (Game::event.key.keysym.sym) {
				case SDLK_w:
					transform->velocity.y = -1;
					break;
				case SDLK_s:
					transform->velocity.y = 1;
					break;
				case SDLK_a:
					transform->velocity.x = -1;
					break;
				case SDLK_d:
					transform->velocity.x = 1;
					break;
				default: break;
				}
			}
			if (Game::event.type == SDL_KEYUP) {
				switch (Game::event.key.keysym.sym) {
				case SDLK_w:
					transform->velocity.y = 0;
					break;
				case SDLK_s:
					transform->velocity.y = 0;
					break;
				case SDLK_a:
					transform->velocity.x = 0;
					break;
				case SDLK_d:
					transform->velocity.x = 0;
					break;
				default: break;
				}
			}
			switch (Game::event.type) {
			case SDL_QUIT:
				SDL_Quit();
				std::cout << "Game Cleaned!" << std::endl;
				break;
			default:
				break;
			}

		}
	}
};
