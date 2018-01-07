#pragma once

#include "RenderableShape.hpp"

namespace Jagerts::Kaleid::Graphics
{
	class Mesh;
	class ShaderProgram;
	class Renderer;
	class GraphicsFactory;
}

namespace Jagerts::Kaleid::Game
{
	class JAGERTS_KALEID_GAME_API Cube : public Jagerts::Kaleid::Game::RenderableShape
	{
	public:
		Cube();
		~Cube();
		jkgUsingRenderableShape;
		jkmUsingTransformableObject;
		jkgRenderableShapeStaticHeader;
	};
}