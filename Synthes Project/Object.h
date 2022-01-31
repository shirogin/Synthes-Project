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

public:
	glm::vec3 Position;
	glm::mat4 model = glm::mat4(1.0f);
	Object();
	Object(glm::vec3 vec);
	void Translate(glm::vec3 vec);
};

