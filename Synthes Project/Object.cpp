#include "Object.h"
#include <iostream>
Object::Object() {
	model = glm::translate(model, position);
}
Object::Object(glm::vec3 vec) {
	SetPosition(vec);
}

void Object::Translate(glm::vec3 vec) {
	SetPosition(position + vec);
}
void Object::SetPosition(glm::vec3 vec) {
	position = vec;
	model = glm::translate(model, vec);
}

glm::vec3 Object::GetPosition() {
	return position;
}