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

LightCube::LightCube()
	: Model() {
	InitMesh();
};
LightCube::LightCube(glm::vec3 position)
	: Model( position) {
	InitMesh();
};
LightCube::LightCube( glm::vec3 position, glm::vec4 color)
	: Model( position, color) {
	InitMesh();
}
void LightCube::Activate()
{
	Model::Activate(Color);
}


void LightCube::InitMesh() {
	shader = LightCube::DefaultShader();
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
}
Shader* LightCube::DefaultShader()
{
	if (defaultLightShader == NULL) defaultLightShader = new Shader("light.vert", "light.frag");
	return defaultLightShader;
};
Shader* LightCube::defaultLightShader=NULL;
