//
// Created by VsDev on 10/30/2019.
//

#ifndef NXENG_AUDIOMANAGER_H
#define NXENG_AUDIOMANAGER_H


class AudioManager {
public:
  AudioManager();
  void AudioManager::LoadMusicFromFile(std::string name, std::string path);
  void AudioManager::LoadSFXFromFile(std::string name, std::string path);
private:
  std::map<std::string,Mix_Music*> music_list;
  std::map<std::string,Mix_Chunk> sfx_list;
};


#endif //NXENG_AUDIOMANAGER_H
