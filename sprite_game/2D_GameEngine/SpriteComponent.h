#pragma once
#include"Components.h"
#include"SDL.h"

class SpriteComponent :public Component
{
private:
	TransformComponent  *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;
public:

	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}

	void setTex(const char* path)
    {
		texture = TextureManager::LoadTexture(path);
	}
	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 64;
		destRect.w = destRect.h = 128;
	}
    
	void update() override
	{
		destRect.x = position->x();
		destRect.y = position->y();


	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};