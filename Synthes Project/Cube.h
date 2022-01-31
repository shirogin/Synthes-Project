#pragma once
#include "MeshedObject.h"


class Cube : public MeshedObject
{
public:
	Cube(Shader *sh);
	Cube(Shader *sh,glm::vec3 position);
	Cube(Shader *sh,glm::vec3 position, glm::vec4 color);
	void Activate(MeshedObject *light);
	void InitMesh();
};

