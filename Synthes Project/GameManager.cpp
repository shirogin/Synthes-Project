#include "GameManager.h"

GameManager::GameManager(Camera *camera)
{
	// Initialize GLFW
	glfwInit();

	// Version of OpenGL 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GameManager::window = glfwCreateWindow(width, height, "Synthes Project", NULL, NULL) ;
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	mainCamera = camera;

	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	glViewport(0, 0, width, height);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

}

void GameManager::SetLight(LightCube* light)
{
	GameManager::light = light;
}

void GameManager::AddModel(Cube* model)
{
	GameManager::models->push_back(model);
}

void GameManager::Update()
{

	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Handles Models inputs
	Input();
	// Handles camera inputs
	mainCamera->Inputs(window);
	// Updates and exports the camera matrix to the Vertex Shader
	mainCamera->updateMatrix(45.0f, 0.1f, 100.0f);

	light->Draw(*mainCamera);
	// Draw Models
	for (Cube* m : *models) {
		m->Draw(*mainCamera);
	}


	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);
	// Take care of all GLFW events
	glfwPollEvents();

}

void GameManager::Activate()
{
	light->Activate();
	for (Cube* m : *models) {
		m->Activate(light);
	}
}

void GameManager::Delete()
{
	light->Delete();
	for (Cube* m : *models) {
		m->Delete();
	}
}

void GameManager::Terminate()
{
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}

void GameManager::Input() {
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		(*models)[currentMoving]->Translate( glm::vec3(-speed,0.0f,0.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		(*models)[currentMoving]->Translate(glm::vec3(speed, 0.0f, 0.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		(*models)[currentMoving]->Translate(glm::vec3(0.0f, 0.0f, -speed));
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		(*models)[currentMoving]->Translate(glm::vec3(0.0f, 0.0f, speed));
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
	{
		(*models)[currentMoving]->Translate(glm::vec3(0.0f, speed, 0.0f ));
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
	{
		(*models)[currentMoving]->Translate(glm::vec3(0.0f, -speed, 0.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		if (switchable) {
			std::cout << currentMoving << " ID :  "<< (*models)[currentMoving]->shader->ID << std::endl;
			currentMoving = (currentMoving + 1) % models->size(); 
			switchable = false;
		}
	}
	else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_RELEASE) {
		switchable = true;
	}
}