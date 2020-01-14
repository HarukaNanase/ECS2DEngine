#pragma once

#include "System.h"
#include "SDL.h"
#include <unordered_map>
#include <functional>
#include "GameObject.h"
#include "InputComponent.h"
class InputSystem : public System
{	
	struct InputEventBinding {
		GameObject& Object;
		std::function<void()> CallbackMethod;
		int16_t Action;
	};
	struct WorldEventBinding {
		World* TheWorld;
		std::function<void(const SDL_Event& _event)> CallbackMethod;
		SDL_EventType EventType;
	};

	struct Mouse {
		Uint32 MouseMask;
		int x;
		int y;
	};
	struct Keyboard {
		const Uint8* Keys;
	};

private:
	std::unordered_map<int16_t, std::vector<InputEventBinding>> RegisteredEvents; // game objects can register to receive certain specific input events
	std::unordered_map<SDL_EventType, std::vector<WorldEventBinding>> WorldEvents;
	Mouse TheMouse;
	Keyboard TheKeyboard;
public:

	void Update(float _deltaTime) override;
	InputSystem();
	void RegisterObjectEvent(GameObject& _gameObject, int16_t _sdlKey, std::function<void(GameObject& _objectToCall)> _callback);
	void RegisterWorldEvent(World* _world, SDL_EventType _sdlEventType, std::function<void(World* _world, const SDL_Event & _event)> _callback);
	void OnObjectAdded(GameObject& _object) override;
	void OnInitialize() override;

};

