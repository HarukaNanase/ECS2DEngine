#include "AudioSystem.h"
#include "SDL.h"
#include <iostream>


void AudioSystem::Play2DSound(const std::string& _assetPath, bool loop)
{
	SoundEngine->play2D(_assetPath.c_str(), loop);
}


void AudioSystem::Play2DSoundFromMemory(AudioManager& _manager, const std::string& _assetName, bool loop)
{
	SoundEngine->play2D(_manager.Get(_assetName)->GetSoundSource(), loop);
}

AudioSystem::AudioSystem()
{
	Initialize();
}

ISoundEngine* AudioSystem::GetSoundEngine()
{
	return SoundEngine;
}

void AudioSystem::Initialize()
{
	SoundEngine = createIrrKlangDevice();
	SoundEngine->setSoundVolume(0.1f);
}

void AudioSystem::Update(float _deltaTime)
{
}

void AudioSystem::Destroy()
{
}
