#include "Mouse.hpp"
#include "MouseMoveBinding.hpp"
#include "Jagerts.Kaleid.Graphics/Window.hpp"

using namespace Jagerts::Kaleid::Input;

MouseMoveBinding::MouseMoveBinding(const MouseMoveType type, const std::function<void(double, double)> action)
{
	this->_type = type;
	this->_action = action;
}

void MouseMoveBinding::Poll(Jagerts::Kaleid::Graphics::Window*& window, Mouse* mouse)
{
	double x, y;
	switch (this->_type)
	{
	case MouseMoveType::Normal:
		x = mouse->_xpos;
		y = mouse->_ypos;
		break;
	case MouseMoveType::Delta:
		x = mouse->_delta_xpos;
		y = mouse->_delta_ypos;
		break;
	case MouseMoveType::CenteredDelta:
		x = mouse->_center_delta_xpos;
		y = mouse->_center_delta_ypos;
		break;
	default:
		break;
	}

	this->_action(x, y);
}