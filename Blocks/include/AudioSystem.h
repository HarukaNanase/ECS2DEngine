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
	AudioManager SoundManager;
	void Play2DSoundFromMemory(ISoundSource* _source, bool _loop = false);
	void Play2DSoundStream(const std::string& _assetName, bool _loop = false);
public:
	~AudioSystem();
	void Play2DSound(const std::string& _assetPath, bool _loop = false);
	AudioSystem();
	ISoundEngine* GetSoundEngine();
	AudioManager& GetSoundManager();
	// Inherited via ISystem
	virtual void Initialize() override;
	virtual void Update(float _deltaTime) override;
	virtual void Destroy() override;
};

