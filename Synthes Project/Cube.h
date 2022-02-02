#pragma once
#include "Model.h"


class Cube : public Model
{
public:
	
	Cube();
	Cube( glm::vec3 position);
	Cube( glm::vec3 position, glm::vec4 color);
	void Activate(Model* light);
	void InitMesh();
};

