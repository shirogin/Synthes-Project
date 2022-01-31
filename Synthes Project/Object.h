#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include <glm/gtx/string_cast.hpp>

class Object
{
private:
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
public:
	glm::mat4 model = glm::mat4(1.0f);
	Object();
	Object(glm::vec3 vec);
	void Translate(glm::vec3 vec);
	void SetPosition(glm::vec3 vec);
	glm::vec3 GetPosition();
};

