#pragma once
#include"Model.h"

class LightCube : public Model
{
public:
	LightCube(Shader* sh);
	LightCube(Shader* sh, glm::vec3 position);
	LightCube(Shader* sh, glm::vec3 position, glm::vec4 color);
	void Activate();
	void InitMesh();
};

