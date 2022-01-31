// Synthes Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include"Cube.h"
#include"LightCube.h"
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------


const unsigned int width = 800;
const unsigned int height = 600;



int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object 
	GLFWwindow* window = glfwCreateWindow(width, height, "Synthes Project", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	glViewport(0, 0, width, height);

	Cube cube(new Shader("default.vert", "default.frag")),
		cube2(new Shader("default.vert", "default.frag"), glm::vec3(1.5f, 0.0f, 0.0f));
	LightCube lc(new Shader("light.vert", "light.frag"), glm::vec3(0.0f, 5.0f, -5.0f));

	cube2.SetTexture("abdou.png", "abdou.png");
	
	lc.Activate();
	cube.Activate(&lc);
	cube2.Activate(&lc);


	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 3.0f, 4.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);


		// Draws different Model
		lc.Draw(camera);
		cube.Draw(camera);
		cube2.Draw(camera);

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created	
	cube.Delete();
	cube2.Delete();
	lc.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}