//
// Created by VsDev on 10/31/2019.
//

#include "GameObject.h"

GameObject(std::string texture_name, int xpos, int ypos, int width, int height, SDL_Renderer* renderer)
{
    this->renderer = renderer;
    this->xpos = xpos;
    this->ypos = ypos;
    this->width = width;
    this->height = height;
    this->texture = TextureManager::GetTexture(texture_name);
}
GameObject::SetRenderTarget(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}
GameObject::Draw()
{
    TextureManager::DrawFullTexture();

}
GameObject::UpdateTexture(std::string texture_name)
{
    this->texture = TextureManager::GetTexture();
}