#include "LightCube.h"
GLuint LightCubeIndices[] =
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

LightCube::LightCube(Shader* sh)
	: Model(sh) {
	InitMesh();
};
LightCube::LightCube(Shader* sh, glm::vec3 position)
	: Model(sh, position) {
	
	InitMesh();
};
LightCube::LightCube(Shader* sh, glm::vec3 position, glm::vec4 color)
	: Model(sh, position, color) {
	InitMesh();
}
void LightCube::Activate()
{
	Model::Activate(Color);
}


void LightCube::InitMesh() {
	
	Vertex LightCubeVertices[] =
	{ //     COORDINATES     //
		Vertex(glm::vec3(-0.1f, 0.0f,  0.1f)),
		Vertex(glm::vec3(-0.1f, 0.0f, -0.1f)),
		Vertex(glm::vec3(0.1f, 0.0f, -0.1f)),
		Vertex(glm::vec3(0.1f, 0.0f,  0.1f)),
		Vertex(glm::vec3(-0.1f,  0.2f,  0.1f)),
		Vertex(glm::vec3(-0.1f,  0.2f, -0.1f)),
		Vertex(glm::vec3(0.1f,  0.2f, -0.1f)),
		Vertex(glm::vec3(0.1f,  0.2f,  0.1f))
	};

	

	std::vector <Vertex> verts(LightCubeVertices, LightCubeVertices + sizeof(LightCubeVertices) / sizeof(Vertex));
	std::vector <GLuint> ind(LightCubeIndices, LightCubeIndices + sizeof(LightCubeIndices) / sizeof(GLuint));
	SetMesh(verts, ind);
};
