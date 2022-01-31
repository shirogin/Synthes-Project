#include "Cube.h"


Cube::Cube(Shader *sh) 
	: MeshedObject(sh) { 
		InitMesh(); 
	};
Cube::Cube(Shader* sh, glm::vec3 position)
	: MeshedObject(sh, position) {
		InitMesh();
	};
Cube::Cube(Shader* sh, glm::vec3 position, glm::vec4 color)
	: MeshedObject(sh, position, color) {
		InitMesh();
	};

void Cube::InitMesh() {
	const Vertex CubeVertices[]
	{ //               COORDINATES           /            NORMALS          /           COLORS         /        TexCoord        //
		// ToP
		Vertex{glm::vec3(-1.0f, 1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, 1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
		//Bottom
		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

	};
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

	// Texture data
	const Texture CubeTextures[]
	{
		Texture("default.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("default.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	SetMesh(CubeVertices, CubeIndices, CubeTextures);
};

void Cube::Activate(MeshedObject *light)
{
	shader->Activate();
	MeshedObject::Activate(light->Color);
	glUniform3f(glGetUniformLocation(shader->ID, "lightPos"), light->GetPosition().x, light->GetPosition().y, light->GetPosition().z);
};

