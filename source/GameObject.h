//
// Created by VsDev on 10/31/2019.
//

#ifndef NXENG_GAMEOBJECT_H
#define NXENG_GAMEOBJECT_H

#include "master.h"
#include "TextureManager.h"
class GameObject {
public:
    GameObject(std::string texture_name, int xpos, int ypos, int width, int height, SDL_Renderer* renderer);
    GameObject::SetRenderTarget(SDL_Renderer* renderer);
    GameObject::Draw();
    GameObject::UpdateTexture(std::string texture_name);
protected:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    int width;
    int height;
    int xpos;
    int ypos;
};


#endif //NXENG_GAMEOBJECT_H
