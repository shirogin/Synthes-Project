// Synthes Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include"GameManager.h"

int main()
{
	
	
	GameManager gameManager( new Camera(GameManager::width, GameManager::height, glm::vec3(0.0f, 3.0f, 4.0f)) );
	gameManager.SetLight(new LightCube(new Shader("light.vert", "light.frag"), glm::vec3(0.0f, 5.0f, -5.0f)));
	
	Cube cube(new Shader("default.vert", "default.frag"), glm::vec3(1.5f, 0.0f, 0.0f));
	
	gameManager.AddModel(new Cube(new Shader("default.vert", "default.frag")));
	gameManager.AddModel(&cube);
	

	cube.SetTexture("abdou.png", "abdou.png");
	
	gameManager.Activate();




	// Main while loop
	while (!glfwWindowShouldClose(gameManager.window))
	{	
		gameManager.Update();
	}



	// Delete all the objects we've created
	gameManager.Delete();
	
	
	return 0;
}