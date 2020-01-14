#include "AudioManager.h"
#include "AudioSystem.h"

using namespace irrklang;

AudioManager::AudioManager()
{
}

AudioManager::AudioManager(ISoundEngine* _engine)
{
	SoundEngine = _engine;
}

void AudioManager::DestroyResource(const std::string& _assetName)
{
}

AudioSource* AudioManager::LoadResource(const std::string& _assetName, const std::string& _assetPath)
{
	if (SoundEngine) {
		ISoundSource* soundSource = SoundEngine->addSoundSourceFromFile(_assetPath.c_str(), ESM_AUTO_DETECT, true);
		auto sound = std::make_unique<AudioSource>(soundSource, CurrentId);
		CurrentId++;
		this->AddResource(_assetName, sound);
		return sound.get();
	}


	return nullptr;

	
}

