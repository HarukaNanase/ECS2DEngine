#pragma once
#include "Event.h"
#include "Component.h"
#include <functional>


class InputComponent : public Component
{

private:
	std::unordered_map<int16_t, std::function<void(GameObject&)>> bindings;

public:
	void AddBinding(const std::string& _input, std::function<void(GameObject&)> _callback);
	std::unordered_map < int16_t, std::function<void(GameObject&)>> GetBindings();
};

