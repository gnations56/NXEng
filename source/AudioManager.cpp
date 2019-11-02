//
// Created by VsDev on 10/30/2019.
//

#include "AudioManager.h"

  AudioManager(int frequency = 44100, int channels = 2, int chunk_size = 2048)
  {
    Mix_OpenAudio(frequency,MIX_DEFAULT_FORMAT,channels,chunk_size);
  }
  void AudioManager::LoadMusicFromFile(std::string name, std::string path)
  {
    Mix_Music* tempMusic = Mix_LoadMUS(path);
    this->music_list.insert(new std::pair<std:string,Mix_Music*>(name,tempMusic));
    Mix_FreeMusic(tempMusic);
  }
  void AudioManager::LoadSFXFromFile(std::string name, std::string path)
  {
    Mix_Chunk* tempSFX = Mix_LoadWAV(path);
    this->sfx_list.insert(new std::pair<std::string,Mix_Chunk*>(name,tempSFX));
    Mix_FreeChunk(tempSFX);
  }
  void AudioManager::PlaySFX(std::string name, int channel_number)
  {
    Mix_PlayChannel(-1,this->music_list.find(name)->first,channel_number);
  }
  void AudioManager::PlayMusic(std::string name, int channel_number)
  {
    
  }

void AudioManager::PauseMusic(std::string name);
{
  Mix_PauseMusic();
}
  void AudioManager::StopMusic(std::string name)
{
    
}