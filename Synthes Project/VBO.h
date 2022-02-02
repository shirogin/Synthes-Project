#pragma once

#include<glm/glm.hpp>
#include<glad/glad.h>
#include<vector>

// Structure to standardize the vertices used in the meshes
struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;

	Vertex(glm::vec3 p);
	Vertex(glm::vec3 p,glm::vec3 n,glm::vec3 c,glm::vec2 t);
	Vertex* VertexCopy();
};
// Copy the VBO
void Copy();


class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(std::vector<Vertex>& vertices);

	// Binds the VBO
	void Bind();
	// Unbinds the VBO
	void Unbind();
	// Deletes the VBO
	void Delete();
};