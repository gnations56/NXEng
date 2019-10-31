//
// Created by VsDev on 10/30/2019.
//

#include "TextureManager.h"

/**
 * Load a texture from a Bitmap
 * @param renderer the SDL_Renderer instance to use
 * @param path the path to the texture
 * @return SDL_Texture instance containing the Bitmap
 */
void TextureManager::LoadTexture(std::string name, std::string path)
{
    SDL_Surface* pTempSurface = IMG_LOAD(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->render,pTempSurface);
    SDL_FreeSurface(pTempSurface);
    this->textures.insert(std::pair<std::string,SDL_Texture*>(name,texture);
}

/**
 * Creates an SDL Renderer
 * @param win The SDL_Window instance to use;
 * @param driver_number the driver number to use. should use -1 in most cases
 * @param sdl_render_flags
 * @return
 */
void TextureManager::CreateRenderer(int driver_number, int sdl_render_flags)
{
    this->render = SDL_CreateRenderer(this->window,driver,sdl_render_flags);
}

/**
 * Creates an SDL Window
 * @param title The title of the window
 * @param xpos the x offset of the window
 * @param ypos the y offset of the window
 * @param width the width of the window in pixels
 * @param height the height of the window in pixels
 * @param window_flags the SDL_WINDOW_ flags to apply
 * @return pointer to SDL_Renderer instance
 */
void TextureManager::CreateWindow(std::string title, int xpos, int ypos,int width, int height, int window_flags)
{
    this-window = >SDL_CreateWindow(title,xpos,ypos,width,height,window_flags);
}

/**
 * Draws an entire texture
 * @param renderer the SDL_Renderer to use
 * @param texture the texture returned by loadTexture
 * @param x_offset the x offset for the texture
 * @param y_offset the y offset for the texture
 */
void TextureManager::DrawFullTexture(std::string texture_name, int x_offset, int y_offset)
{
    SDL_Rect source;
    SDL_Rect dest;
    SDL_QueryTexture(this->textures.find(texture_name),NULL,NULL,&source.w,&source.h);
    dest.x = x_offset;
    dest.y = y_offset;
    dest.w = source.w;
    dest.h = source.h;
    SDL_RenderCopy(this->render,this->textures.find(texture_name),source,dest);
}

/**
* Draw a portion of a texture
* @param renderer the SDL_Renderer to use
* @param texture the texture returned by loadTextureFromBMP
* @param x_offset the x offset for the texture
* @param y_offset the y offset for the texture
* @param source_width the width of the texture snip
* @param source_height the height of the texture snip
* @param dest_width the width of the sprite on the window
* @param dest_height the height of the sprite on the window
*/
void TextureManager::DrawPartialTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x_offset, int y_offset,int source_width, int source_height,int dest_width,int dest_height)
{
SDL_Rect source;
SDL_Rect dest;
SDL_QueryTexture(texture,NULL,NULL,&source.w,&source.h);
source.w = source_width;
source.h = source_height;
dest.x = x_offset;
dest.y = y_offset;
dest.w = dest_width;
dest.h = dest_height;
SDL_RenderCopy(renderer,texture,source,dest);
}

void TextureManager::DrawTextureRotatedOrFlipped(std::string texture_name, int x_offset, int y_offset, int angle, int center_of_rotation, int flip_flag) {
    SDL_Rect source;
    SDL_Rect dest;
    SDL_QueryTexture(this->textures.find(texture_name),NULL,NULL,&source.w,&source.h);
    dest.x = x_offset;
    dest.y = y_offset;
    dest.w = source.w;
    dest.h = source.h;
    SDL_RenderCopyEx(this->render,this->textures.find(texture_name),source,dest,angle,center_of_rotation,flip_flag);
}

void TextureManager::DrawPartialTextureRotatedOrFlipped(std::string texture_name, int x_offset, int y_offset,int source_width, int source_height,int dest_width,int dest_height,int angle, int center_of_rotation, int flip_flag) {
    SDL_Rect source;
    SDL_Rect dest;
    SDL_QueryTexture(this->textures.find(texture_name),NULL,NULL,&source.w,&source.h);
    source.w = source_width;
    source.h = source_height;
    dest.x = x_offset;
    dest.y = y_offset;
    dest.w = dest_width;
    dest.h = dest_height;
    SDL_RenderCopyEx(this->render,this->textures.find(texture_name),source,dest,angle,center_of_rotation,flip_flag);
}


/**
 * Draws all queued objects on screen
 * @details Should be run after all draw calls.
 * @param renderer
 */

void TextureManager::drawFrame()
{
    SDL_RenderPresent(this->render);
}

/**
 * Set the default render color
 * @param renderer The SDL_Renderer instance
 * @param r the red value from 0-255
 * @param g the green value from 0-255
 * @param b the blue value from 0-255
 * @param a the alpha(opacity) value from 0-255
 */
void TextureManager::SetBackgroundColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(this->render,r,g,b,a);
}

/**
 * Clears the screen
 * @details Should be run once per frame at the beginning of the frame
 * @param renderer A pointer to an SDL_Renderer
 */
void TextureManager::ClearFrame(
{
    SDL_RenderClear(this->render);
}

SDL_Texture* TextureManager::GetTexture(std::string name)
{
    return this->textures.find(name);
}

