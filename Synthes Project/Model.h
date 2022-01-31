#pragma once
#include "Object.h"
#include"Mesh.h"
class Model : public Object
{
public:
	Mesh* mesh = NULL;
	Shader* shader;
	glm::vec4 Color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	Model(Shader* shaderIn);
	Model(Shader* shaderIn, glm::vec3 position);
	Model(Shader* shaderIn, glm::vec3 position, glm::vec4 color);
	void Draw(Camera& camera);
	void Activate(glm::vec4 lightColor);
	void Delete();
	void Translate(glm::vec3 vec);
	virtual void InitMesh(); // abstract
	void SetMesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures);
};

