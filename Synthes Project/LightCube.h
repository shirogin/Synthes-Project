#pragma once
#include"Model.h"

class LightCube : public Model
{
public:
	static Shader* defaultLightShader;
	LightCube();
	LightCube( glm::vec3 position);
	LightCube( glm::vec3 position, glm::vec4 color);
	void Activate();
	void InitMesh();
	static Shader* DefaultShader();
};

