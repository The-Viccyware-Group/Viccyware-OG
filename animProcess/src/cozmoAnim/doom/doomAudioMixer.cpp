#include "cozmoAnim/doom/doomAudioMixer.h"
#include "audioEngine/audioTools/standardWaveDataContainer.h"
#include "audioEngine/audioTypeTranslator.h"
#include "audioEngine/plugins/ankiPluginInterface.h"

// Simplified implementation that logs but doesn't attempt to play audio
// This preserves the interface but removes the problematic implementation

namespace {
  // Remove the problematic constants
  // Constants will be defined within functions if needed
}

void DoomAudioMixer::Play(const Anki::AudioEngine::StandardWaveDataContainer* container, bool looping)
{
  PRINT_NAMED_WARNING("DOOM", "DoomAudioMixer::Play called but audio functionality is disabled");
  std::lock_guard<std::mutex> lock(_mutex);
  _playQueue.emplace(QueueEntry{ container, looping });
}

void DoomAudioMixer::FlushPlayQueue()
{
  std::lock_guard<std::mutex> lock(_mutex);
  while (!_playQueue.empty()) {
    // Just log instead of trying to play
    PRINT_NAMED_WARNING("DOOM", "DoomAudioMixer::FlushPlayQueue - skipping audio playback");
    _playQueue.pop();
  }
}

void DoomAudioMixer::PlayInternal(const Anki::AudioEngine::StandardWaveDataContainer* container, bool looping)
{
  // Simply store the last container and log
  _lastContainer = container;
  PRINT_NAMED_WARNING("DOOM", "DoomAudioMixer::PlayInternal - audio playback disabled");
  
  // No actual audio playback is attempted
}