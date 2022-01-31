#include "LightCube.h"

LightCube::LightCube(Shader* sh)
	: MeshedObject( sh) {
	InitMesh();
};
LightCube::LightCube(Shader* sh, glm::vec3 position)
	: MeshedObject(sh, position) {
	InitMesh();
};
LightCube::LightCube(Shader* sh, glm::vec3 position, glm::vec4 color)
	: MeshedObject(sh, position, color) { 
	InitMesh();
}
void LightCube::Activate()
{
	MeshedObject::Activate(Color);
}


void LightCube::InitMesh() {
	Vertex LightCubeVertices[] =
	{ //     COORDINATES     //
		Vertex{glm::vec3(-0.1f, 3.0f,  0.1f)},
		Vertex{glm::vec3(-0.1f, 3.0f, -0.1f)},
		Vertex{glm::vec3(0.1f, 3.0f, -0.1f)},
		Vertex{glm::vec3(0.1f, 3.0f,  0.1f)},
		Vertex{glm::vec3(-0.1f,  3.2f,  0.1f)},
		Vertex{glm::vec3(-0.1f,  3.2f, -0.1f)},
		Vertex{glm::vec3(0.1f,  3.2f, -0.1f)},
		Vertex{glm::vec3(0.1f,  3.2f,  0.1f)}
	};
	// Indices for vertices order
	GLuint LightCubeIndices[]
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
	// Texture data
	Texture LightCubeTextures[]
	{
		Texture("default.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("default.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	SetMesh(LightCubeVertices, LightCubeIndices, LightCubeTextures);
};