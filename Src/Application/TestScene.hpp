#pragma once

#include "stdafx.hpp"
#include "SceneBase.hpp"
#include "Model.hpp"
#include "Cube.hpp"
#include "PerspectiveCamera.hpp"

class TestScene : public Kaleid::Game::SceneBase
{
public:
	TestScene(Kaleid::Game::App* app);
	void Load();
	void Update();
	void Render();
	void Dispose();
private:
	void BuildShaderProgram();
	void BuildMesh();

	Kaleid::Graphics::ShaderProgram* _shader_program;
	Kaleid::Graphics::Mesh* _mesh;
	Kaleid::Math::PerspectiveCamera _camera;
	Kaleid::Math::Transform _transform;
};