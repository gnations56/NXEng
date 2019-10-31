//
// Created by VsDev on 10/31/2019.
//

#ifndef NXENG_ANIMATEDGAMEOBJECT_H
#define NXENG_ANIMATEDGAMEOBJECT_H

#include "GameObject.h"
#include "master.h"

class AnimatedGameObject : GameObject{
public:
    AnimatedGameObject(std::string animation_name, int max_frames, int frame_width, int frame_height, GameObject g);
    void AnimatedGameObject::Animate();
    void AnimatedGameObject::UpdateSheet(SDL_Texture* sheet);
    void AnimatedGameObject::SetFrameNumber(int frame_number);
protected:
    std::map<int,SDL_Texture*> animation;
    int frame_number;
    int total_frames;
    GameObject game_object;
};


#endif //NXENG_ANIMATEDGAMEOBJECT_H
