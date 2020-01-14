#pragma once
#include "ResourceManager.h"
#include "irrKlang.h"
#include "SDL_stdinc.h"
using namespace irrklang;

struct AudioSource {
	ISoundSource* SoundSource;
	Uint32 SoundId;
	ISoundSource* GetSoundSource() { return SoundSource; }
	AudioSource(ISoundSource* _soundSource, Uint32 _id) : SoundSource(_soundSource), SoundId(_id) {}
};

class AudioManager : public ResourceManager<AudioManager, AudioSource>
{
	ISoundEngine* SoundEngine;

private:

public:
	AudioManager();
	AudioManager(ISoundEngine* _engine);
	// Inherited via ResourceManager
	virtual void DestroyResource(const std::string& _assetName) override;
	virtual AudioSource* LoadResource(const std::string& _assetName, const std::string& _assetPath) override;


};

