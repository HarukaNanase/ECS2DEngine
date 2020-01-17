#pragma once
#include "SDL.h"
#include "GameObject.h"
#include "System.h"
class EventSystem : public System
{
private:

public:
	void Update(SDL_Event& _event, GameObject* _object);
	EventSystem();



	// Inherited via System
	virtual void Initialize() override;

};

