#pragma once

#include "stdafx.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include "GraphicsFactory.hpp"

API_BEGIN
namespace Kaleid::Game
{
	class SceneBase;

	class App sealed
	{
	public:
		KALEID_GAME_API App();
		KALEID_GAME_API void Load();
		KALEID_GAME_API void Dispose();
		KALEID_GAME_API void Run();

		KALEID_GAME_API void SetRenderer(Kaleid::Graphics::Renderer* renderer);
		KALEID_GAME_API Kaleid::Graphics::Renderer* GetRenderer();

		KALEID_GAME_API void SetGraphicsFactory(Kaleid::Graphics::GraphicsFactory* graphics_factory);
		KALEID_GAME_API Kaleid::Graphics::GraphicsFactory* GetGraphicsFactory();

		KALEID_GAME_API void SetScene(SceneBase* current_scene);
		KALEID_GAME_API SceneBase* GetScene();

		KALEID_GAME_API Kaleid::Graphics::Window* GetWindow();
#ifdef KALEID_GAME_DLL
	private:
		SceneBase* _current_scene;
		Kaleid::Graphics::Renderer* _renderer;
		Kaleid::Graphics::GraphicsFactory* _graphics_factory;
		Kaleid::Graphics::Window* _window;
#endif
	};
}
API_END