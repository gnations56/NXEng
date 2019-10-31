//
// Created by VsDev on 10/30/2019.
//

#include "master.h"


/**
 * Initialoze SDL with the specified features
 * @param sdl_features
 * @return
 */
bool InitSDL(int sdl_features)
{
    if (SDL_Init(sdl_features))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Checks if a SDL feature is enabled
 * @param feature The SDL feature to check if enabled
 * @return true if active, false otherwise
 */
bool CheckFeatureActive(int feature)
{
    if (SDL_WasInit(feature) != 0)
    {
        return true;
    }
    else
        {
        return false;
        }
}

