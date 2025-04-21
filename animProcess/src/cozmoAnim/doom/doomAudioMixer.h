#pragma once

#include <mutex>
#include <queue>

namespace Anki{
  namespace AudioEngine {
    struct StandardWaveDataContainer;
  }
  namespace Vector { // Changed from Cozmo to Vector
    namespace Audio {
      class CozmoAudioController; // Keep the name CozmoAudioController for compatibility
    }
  }
}

class DoomAudioMixer {
public:
  
  using WaveContainer = Anki::AudioEngine::StandardWaveDataContainer;
  
  // clears whatever is playing and plays something new
  void Play(const WaveContainer* container, bool looping);
  
  using AudioController = Anki::Vector::Audio::CozmoAudioController; // Changed from Cozmo to Vector
  void SetAudioController(AudioController* audioController) { _audioController = audioController; }
  
  void FlushPlayQueue();
private:
  
  void PlayInternal(const WaveContainer* container, bool looping);
  
  struct QueueEntry {
    const Anki::AudioEngine::StandardWaveDataContainer* container;
    bool looping;
  };
  std::mutex _mutex;
  std::queue<QueueEntry> _playQueue;
  
  AudioController* _audioController = nullptr;
  const WaveContainer* _lastContainer = nullptr;
};