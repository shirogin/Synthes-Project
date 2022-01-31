#pragma once
#include"Object.h"

#include"shaderClass.h"
#define Speed 0.01f
#define MouseClamp 85.0f


class Camera : public Object
{
public:
	// Stores the main vectors of the camera
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

	bool mouseLock = true,firstTime=true;

	// Stores the width and height of the window
	int width;
	int height;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed = Speed;
	float sensitivity = 100.0f;

	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);

	// Updates the camera matrix to the Vertex Shader
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	// Exports the camera matrix to a shader
	void Matrix(Shader* shader, const char* uniform);
	// Handles camera inputs
	void Inputs(GLFWwindow* window);
};

