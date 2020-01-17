#pragma once
#include "SDL.h"
#include <string>
class Texture
{
private:
	SDL_Texture* Tex;
	Uint32 TexId;
public:
	Texture(SDL_Renderer* _renderer, const std::string& _texturePath, Uint32 _texId);
	~Texture();
	SDL_Texture* GetTex();
};

