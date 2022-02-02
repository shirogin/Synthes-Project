#pragma once
#include "Model.h"


class Cube : public Model
{
public:
	
	Cube(Shader* sh);
	Cube(Shader* sh, glm::vec3 position);
	Cube(Shader* sh, glm::vec3 position, glm::vec4 color);
	void Activate(Model* light);
	void InitMesh();
};

