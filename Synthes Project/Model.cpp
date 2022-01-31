
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

void Model::SetTexture(const char* imageDiffuse, const char* imageSpecular)
{
	mesh->textures[0] = Texture(imageDiffuse, "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE);
	mesh->textures[1] = Texture(imageSpecular, "specular", 1, GL_RED, GL_UNSIGNED_BYTE);
}
