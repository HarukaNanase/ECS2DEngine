#include "InputSystem.h"
#include "TransformComponent.h"
#include <iostream>
#include <World.h>
using namespace std::placeholders;
void InputSystem::Update(float _deltaTime)
{	
	SDL_PumpEvents();
	TheMouse.MouseMask = SDL_GetMouseState(&TheMouse.x, &TheMouse.y);
	
	for (auto& keysAndEvents : RegisteredEvents) {
		if ((TheMouse.MouseMask & SDL_BUTTON(keysAndEvents.first))) {

			auto& events = keysAndEvents.second;
			for (auto& _event : events) {
				auto object = _event.Object;
				if (object.HasComponent<TransformComponent>() && (_event.Action == SDL_BUTTON_LEFT)) {
					auto transform = object.GetComponent<TransformComponent>();
					auto camera = GetWorld()->GetCamera2D();
					auto objectPosition = transform.GetPosition();
					auto inWorldMouse = camera.ScreenToGameRaycast(TheMouse.x, TheMouse.y);
					auto objectSize = transform.GetSize();
					objectSize.x = objectSize.x * ((float) camera.Resolution.x / camera.Size.x);
					objectSize.y = objectSize.y * ((float) camera.Resolution.y / camera.Size.y);
					auto objectBoundLeft = objectPosition.x - objectSize.x / 2;
					auto objectBoundRight = objectPosition.x + objectSize.x / 2;
					auto objectBoundTop = objectPosition.y - objectSize.y / 2;
					auto objectBoundBottom = objectPosition.y + objectSize.y / 2;
					
					if (inWorldMouse.x >= objectBoundLeft && inWorldMouse.x <= objectBoundRight
						&& inWorldMouse.y >= objectBoundTop && inWorldMouse.y <= objectBoundBottom) {
					
						_event.CallbackMethod();
					}

				}
				
			
			}
		}
		else if (TheKeyboard.Keys[keysAndEvents.first]) {
			auto& events = keysAndEvents.second;
			for (auto& _event : events) {
				_event.CallbackMethod();
			}
		
		}
		
		
	}
	

	for (auto& typesAndEvents : WorldEvents) {
		if (SDL_HasEvent(typesAndEvents.first)) {
			SDL_Event event;
			int count = SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT);
			auto& worldEvents = typesAndEvents.second;
			for (auto& _event : worldEvents) {
				_event.CallbackMethod(event);
			}
		}
	}
	
	
	
}

InputSystem::InputSystem()
{
}

void InputSystem::RegisterObjectEvent(GameObject& _gameObject, int16_t _sdlEventCode, std::function<void(GameObject& _objectToCall)> _callback)
{
	auto& eventsForKey = RegisteredEvents[_sdlEventCode];
	eventsForKey.push_back(InputEventBinding{ _gameObject, std::bind(_callback, _gameObject) , _sdlEventCode});
	
}


void InputSystem::RegisterWorldEvent(World* _world, SDL_EventType _sdlEventType, std::function<void(World* _world, const SDL_Event& _event)> _callback)
{
	auto& eventsForEventType = WorldEvents[_sdlEventType];
	auto bindedMethod = std::bind(_callback, _world, _1);
	WorldEventBinding _worldBinding = WorldEventBinding{ _world, bindedMethod, _sdlEventType };
	eventsForEventType.push_back(_worldBinding);
}

void InputSystem::OnObjectAdded(GameObject& _object)
{
	auto& objectInputComponent = _object.GetComponent<InputComponent>();
	auto objectBindings = objectInputComponent.GetBindings();
	// create input events for this component
	for (auto& binding : objectInputComponent.GetBindings()) {
		auto key = binding.first;
		auto callback = binding.second;
		//get existing events for this key
		auto& eventsForKey = RegisteredEvents[key];
		InputEventBinding newEvent{ _object, std::bind(callback, _object), key };
		eventsForKey.push_back(newEvent);
	}
}




void InputSystem::OnInitialize()
{
	TheKeyboard.Keys = SDL_GetKeyboardState(NULL);
	TheMouse.MouseMask = SDL_GetMouseState(&TheMouse.x, &TheMouse.y);
}


