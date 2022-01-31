#pragma once
#include "Object.h"
#include"Mesh.h"
class MeshedObject : public Object
{
public:
	Mesh* mesh=NULL;
	Shader* shader;
	glm::vec4 Color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	MeshedObject( Shader* shaderIn);
	MeshedObject( Shader* shaderIn,glm::vec3 position);
	MeshedObject( Shader* shaderIn,glm::vec3 position, glm::vec4 color);
	void Draw(Camera *camera);
	void Activate(glm::vec4 lightColor);
	void Delete();
	virtual void InitMesh(); // abstract
	void SetMesh(const Vertex Vertices[], const  GLuint Indices[], const Texture Textures[]);
};

