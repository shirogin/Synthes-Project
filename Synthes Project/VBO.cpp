#include "VBO.h"

#include <iostream>

Vertex::Vertex(glm::vec3 p)
{
	position = p;
}

Vertex::Vertex(glm::vec3 p, glm::vec3 n, glm::vec3 c, glm::vec2 t)
{
	position=p;
	normal=n;
	color=c;
	texUV=t;
}

// Copy the Vertex
Vertex* Vertex::VertexCopy() {
	return  new Vertex(position, normal, color, texUV);
}
// Constructor that generates a Vertex Buffer Object and links it to vertices
VBO::VBO(std::vector<Vertex>& vertices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

// Binds the VBO
void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbinds the VBO
void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Deletes the VBO
void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}