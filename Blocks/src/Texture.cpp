#include "Texture.h"
#include "SDL_image.h"
#include <iostream>
Texture::Texture(SDL_Renderer* _renderer, const std::string& _texturePath, Uint32 _texId)
{
	auto surface = IMG_Load(_texturePath.c_str());
	Tex = SDL_CreateTextureFromSurface(_renderer, surface);
	TexId = _texId;
	SDL_FreeSurface(surface);
}

Texture::~Texture()
{
	SDL_DestroyTexture(Tex);
	Tex = nullptr;
	std::cout << "Deleted texture with id: " << TexId << std::endl;

}

SDL_Texture* Texture::GetTex()
{
	return Tex;
}
