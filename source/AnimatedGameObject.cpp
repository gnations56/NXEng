//
// Created by VsDev on 10/31/2019.
//

#include "AnimatedGameObject.h"

AnimatedGameObject(std::string animation_name, int max_frames, int frame_width, int frame_height, GameObject g)
{
  this->max_frames = max_frames;
  this->frame_width = frame_width;
  this->frame_height = frame_height;
  this->game_object = g;
  this->current_frame = 1;
}
void AnimatedGameObject::Animate()
{
  TextureManager::DrawFullTexture(animation.find(frame_number)->first);
}
void AnimatedGameObject::UpdateSheet(SDL_Texture* sheet)
{
  SDL_Rect source;
  SDL_Rect dest;
  SDL_Texture* frame; 
  this->texture_render_target = SDL_CreateTexture(this->game_object->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->frame_width, this->frame_height);
  SDL_SetRenderTarget(this->game_object->renderer);
  for (int i = 1; i < max_frames, i++) {
    SDL_QueryTexture(sheet,NULL,NULL,&source.w,&source.h);
    source.x = frame_width*i;
    source.y = frame_height;
    source.w = frame_width;
    source.h = source_height;
    dest.x = x_offset;
    dest.y = y_offset;
    dest.w = dest_width;
    dest.h = dest_height;
    SDL_RenderCopy(this->game_object->renderer,this->texture_render_target,source,dest);
    SDL_RenderClear(this->game_object->renderer);
    this->animation.insert(new std::pair<int,SDL_Texture*>(i,frame));
  }
  SDL_DestroyTexture(frame);
}
void AnimatedGameObject::SetFrameNumber(int frame_number)
{
  this->current_frame = frame_number;
}