
#include "Model.h"
Model::Model(Shader* shaderIn) : Object() {
	shader = shaderIn;
};
Model::Model(Shader* shaderIn, glm::vec3 position)
	: Model(shaderIn) {
	Position = position;
	Translate(Position);
};
Model::Model(Shader* shaderIn, glm::vec3 position, glm::vec4 color)
	:Model(shaderIn, position) {
	Color = color;
};
void Model::Draw(Camera& camera) {
	mesh->Draw(*shader, camera);
}
void Model::Activate(glm::vec4 lightColor) {
	shader->Activate();
	std::cout << glm::to_string(model) << std::endl;
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniform4f(glGetUniformLocation(shader->ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
};

void Model::Delete()
{
	shader->Delete();
}

void Model::Translate(glm::vec3 vec)
{
	Object::Translate(vec);
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

void Model::InitMesh()
{
	printf("Base InitMesh");
}



void Model::SetMesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures)
{
	mesh = new Mesh(vertices, indices, textures);
}
