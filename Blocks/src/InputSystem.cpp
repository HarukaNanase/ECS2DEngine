#include "InputSystem.h"
#include "TransformComponent.h"
#include <iostream>
#include <World.h>
using namespace std::placeholders;

bool InputSystem::IsClickOnObject(const Vector2& _mousePosition, GameObject* _obj)
{
	if (_obj->HasComponent<TransformComponent>()) {
		auto transform = _obj->GetComponent<TransformComponent>();
		Vector2 objectCenter = transform.GetPosition();
		auto objectSize = transform.GetSize();
		auto objectBoundTop = objectCenter.y + objectSize.y / 2;
		auto objectBoundBottom = objectCenter.y - objectSize.y / 2;
		auto objectBoundRight = objectCenter.x + objectSize.x / 2;
		auto objectBoundLeft = objectCenter.x - objectSize.x / 2;
		if (_mousePosition.x <= objectBoundRight && _mousePosition.x >= objectBoundLeft
			&& _mousePosition.y >= objectBoundBottom && _mousePosition.y <= objectBoundTop) {

			return true;
		}
	}


	return false;
}

bool InputSystem::IsClickOnGame(const Vector2& _mousePosition, const Vector2& _gameRes)
{
	return !(_mousePosition.x < (-_gameRes.x / 2) || _mousePosition.x >(_gameRes.x / 2) || _mousePosition.y < (-_gameRes.y / 2) || _mousePosition.y >(_gameRes.y / 2));
}

void InputSystem::Update(float _deltaTime)
{	
	//std::vector<GameObject*> objects = GetGameObjects();
	SDL_PumpEvents();
	TheMouse.MouseMask = SDL_GetMouseState(&TheMouse.x, &TheMouse.y);
	auto objects = this->GetGameObjects();
	for (auto object : objects) {
		auto& inputComp = object->GetComponent<InputComponent>();
		if(inputComp.IsEnabled()){
			auto bindings = inputComp.GetBindings();
			for (auto& entry : bindings) {
				if (TheMouse.MouseMask && SDL_BUTTON(entry.first) && entry.first == SDL_BUTTON_LEFT) {
					auto camera = GetWorld()->GetCamera2D();
					auto inWorldMouse = camera.ScreenToWorldRaycast(TheMouse.x, TheMouse.y);
					if (!IsClickOnGame(inWorldMouse, camera.Size))
						continue;
					if (IsClickOnObject(inWorldMouse, object)) {
						auto callback = std::bind(entry.second, *object);
						callback();
					}
				}
				else if (TheKeyboard.Keys[entry.first]) {
					auto callback = std::bind(entry.second, *object);
					callback();
				}

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



void InputSystem::RegisterWorldEvent(World* _world, SDL_EventType _sdlEventType, std::function<void(World* _world, const SDL_Event& _event)> _callback)
{
	auto& eventsForEventType = WorldEvents[_sdlEventType];
	auto bindedMethod = std::bind(_callback, _world, _1);
	WorldEventBinding _worldBinding = WorldEventBinding{ _world, bindedMethod, _sdlEventType };
	eventsForEventType.push_back(_worldBinding);
}

void InputSystem::OnObjectAdded(GameObject& _object)
{

}




void InputSystem::OnObjectRemoved(GameObject& _object)
{

}

void InputSystem::OnInitialize()
{
	TheKeyboard.Keys = SDL_GetKeyboardState(NULL);
	TheMouse.MouseMask = SDL_GetMouseState(&TheMouse.x, &TheMouse.y);
}


