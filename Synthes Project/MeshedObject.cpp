#include "MeshedObject.h"
MeshedObject::MeshedObject(Shader* shaderIn) : Object() {
	shader = shaderIn;
};
MeshedObject::MeshedObject( Shader* shaderIn, glm::vec3 position) 
	: MeshedObject(shaderIn)  {
		SetPosition(position);
	};
MeshedObject::MeshedObject( Shader* shaderIn,glm::vec3 position, glm::vec4 color) 
	:MeshedObject(shaderIn,position) {
		Color = color;
	};
void MeshedObject::Draw(Camera* camera) {
	this->mesh->Draw(shader, camera);
}
void MeshedObject::Activate(glm::vec4 lightColor) {
	shader->Activate();
	std::cout << shader << std::endl;
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniform4f(glGetUniformLocation(shader->ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
};

void MeshedObject::Delete()
{
	shader->Delete();
}

void MeshedObject::InitMesh()
{
	printf("Base InitMesh");
}



void MeshedObject::SetMesh(const Vertex Vertices[], const GLuint Indices[], const Texture Textures[])
{
	this->mesh = new Mesh(
		*(new std::vector <Vertex>(Vertices, Vertices + sizeof(Vertices) / sizeof(Vertex))),
		*(new std::vector <GLuint>(Indices, Indices + sizeof(Indices) / sizeof(GLuint))),
		*(new std::vector <Texture>(Textures, Textures + sizeof(Textures) / sizeof(Texture)))
	);
}
