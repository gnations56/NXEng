//
// Created by VsDev on 10/30/2019.
//

#ifndef NXENG_TEXTUREMANAGER_H
#define NXENG_TEXTUREMANAGER_H

#include "master.h"
class TextureManager {
public:
    void TextureManager::LoadTexture(std::string name, std::string path);
    void TextureManager::CreateRenderer(int driver_number, int sdl_render_flags);
    void TextureManager::CreateWindow(std::string title, int xpos, int ypos,int width, int height, int window_flags);
    void TextureManager::DrawFullTexture(std::string texture_name, int x_offset, int y_offset);
    SDL_Texture* TextureManager::GetTexture(std::string name);
private:
    std::map<std::string, SDL_Texture* texture> textures;
    TextureManager();
    SDL_Renderer* render;
    SDL_Window* window;
};


#endif //NXENG_TEXTUREMANAGER_H
