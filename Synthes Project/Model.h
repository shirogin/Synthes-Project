#pragma once
#include "Object.h"
#include"Mesh.h"
class Model : public Object
{
public:
	static std::vector <Texture> *textures;
	static void LoadTextures();
	Mesh* mesh = NULL;
	Shader* shader;
	glm::vec4 Color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	Model();
	Model( glm::vec3 position);
	Model(glm::vec3 position, glm::vec4 color);
	void Draw(Camera& camera);
	void Activate(glm::vec4 lightColor);
	void Delete();
	
	virtual void InitMesh(); // abstract
	void SetMesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices);
	void SetTexture(std::vector <Texture> *Textures);
};

