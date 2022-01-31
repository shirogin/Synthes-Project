#include "Object.h"


Object::Object() :Object(glm::vec3(0.0f, 0.0f, 0.0f)) {}
Object::Object(glm::vec3 vec) {
	Position = vec;
	model = glm::translate(model, vec);
}

void Object::Translate(glm::vec3 vec) {
	model= glm::translate(model, vec);
}