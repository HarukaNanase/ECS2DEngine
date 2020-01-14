#include "InputComponent.h"
#include "GameObject.h"
//
//void InputComponent::AddBinding(int16_t _key, std::function<void()> _callback)
//{
//	bindings.push_back(InputEventBinding{_callback, _key });
//}

void InputComponent::AddBinding(int16_t key, std::function<void(GameObject&)> _callback)
{
	this->bindings.emplace(key, _callback);
}

std::unordered_map<int16_t, std::function<void(GameObject&)>> InputComponent::GetBindings()
{
	return bindings;
}
