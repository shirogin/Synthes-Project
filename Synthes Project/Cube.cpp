#include "Cube.h"


// Indices for vertices order
const GLuint CubeIndices[]
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};
Cube::Cube() : Model() {
	InitMesh();
}

Cube::Cube( glm::vec3 position) : Model( position) {
	InitMesh();
};
Cube::Cube( glm::vec3 position, glm::vec4 color) : Model( position, color) {
	InitMesh();
};

void Cube::InitMesh() {
	
	Vertex CubeVertices[8]
	{ //               COORDINATES           /            NORMALS          /           COLORS         /        TexCoord        //
		// ToP
		Vertex(glm::vec3(-0.5f, 0.5f,  0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f,  0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),
		//Bottom
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),

	};
	std::vector <Vertex> verts(CubeVertices, CubeVertices + sizeof(CubeVertices) / sizeof(Vertex));
	std::vector <GLuint> ind(CubeIndices, CubeIndices + sizeof(CubeIndices) / sizeof(GLuint));
	SetMesh(verts, ind);
};

void Cube::Activate(Model* light)
{
	shader->Activate();
	Model::Activate(light->Color);
	glUniform3f(glGetUniformLocation(shader->ID, "lightPos"), light->Position.x, light->Position.y, light->Position.z);
};

