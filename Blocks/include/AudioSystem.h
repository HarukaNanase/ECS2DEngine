#pragma once
#include <string>
#include "AudioManager.h"
#include "System.h"
#include "irrKlang.h"
using namespace irrklang;
class AudioSystem : public System
{
private:
	ISoundEngine* SoundEngine;

public:
	void Play2DSound(const std::string& _assetPath, bool loop = false);
	void Play2DSoundFromMemory(AudioManager& _manager, const std::string& _assetName, bool loop = false);
	AudioSystem();
	ISoundEngine* GetSoundEngine();
	// Inherited via ISystem
	virtual void Initialize() override;
	virtual void Update(float _deltaTime) override;
	virtual void Destroy() override;
};

