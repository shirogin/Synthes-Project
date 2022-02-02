// Synthes Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include"GameManager.h"
void CreateTree(GameManager *gameManager, glm::vec3 p0) {
	gameManager->AddModel(new Cube(new Shader("default.vert", "default.frag"), glm::vec3(0.0f+p0.x, 0.0f+p0.y, 0.0f+p0.z)));
	gameManager->AddModel(new Cube(new Shader("default.vert", "default.frag"), glm::vec3(0.0f + p0.x, 1.0f + p0.y, 0.0f + p0.z)));
	gameManager->AddModel(new Cube(new Shader("default.vert", "default.frag"), glm::vec3(0.0f + p0.x, 2.0f + p0.y, 0.0f + p0.z)));
	gameManager->AddModel(new Cube(new Shader("default.vert", "default.frag"), glm::vec3(0.0f + p0.x, 3.0f + p0.y, 0.0f + p0.z)));

	Cube* grass[] = {
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(1.0f + p0.x, 4.0f + p0.y, -1.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(1.0f + p0.x, 4.0f + p0.y, 0.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(1.0f + p0.x, 4.0f + p0.y, 1.0f + p0.z)),

		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(0.0f + p0.x, 4.0f + p0.y, 1.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(0.0f + p0.x, 4.0f + p0.y, -1.0f + p0.z)),

		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(-1.0f + p0.x, 4.0f + p0.y, -1.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(-1.0f + p0.x, 4.0f + p0.y, 0.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(-1.0f + p0.x, 4.0f + p0.y, 1.0f + p0.z)),

		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(1.0f + p0.x, 5.0f + p0.y, -1.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(1.0f + p0.x, 5.0f + p0.y, 0.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(1.0f + p0.x, 5.0f + p0.y, 1.0f + p0.z)),

		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(0.0f + p0.x, 5.0f + p0.y, 1.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(0.0f + p0.x, 5.0f + p0.y, -1.0f + p0.z)),

		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(-1.0f + p0.x, 5.0f + p0.y, -1.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(-1.0f + p0.x, 5.0f + p0.y, 0.0f + p0.z)),
		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(-1.0f + p0.x, 5.0f + p0.y, 1.0f + p0.z)),

		new Cube(new Shader("default2.vert", "default2.frag"), glm::vec3(0.0f + p0.x, 5.0f + p0.y, 0.0f + p0.z)),
	};
	for (Cube* c : grass) {
		c->SetTexture("Grass.png", "Grass.png");
		gameManager->AddModel(c);
	}
}

int main()
{
	
	GameManager gameManager( new Camera(GameManager::width, GameManager::height, glm::vec3(0.0f, 3.0f, 4.0f)) );

	gameManager.SetLight(new LightCube(new Shader("light.vert", "light.frag"), glm::vec3(0.0f, 5.0f, -5.0f)));
	
	CreateTree(&gameManager, glm::vec3(0.0f, 0.0f, 0.0f));
	CreateTree(&gameManager, glm::vec3(0.0f, 0.0f, 5.0f));
	CreateTree(&gameManager, glm::vec3(0.0f, 0.0f, 10.0f));
	CreateTree(&gameManager, glm::vec3(0.0f, 0.0f, 15.0f));

	CreateTree(&gameManager, glm::vec3(5.0f, 0.0f, 0.0f));
	CreateTree(&gameManager, glm::vec3(5.0f, 0.0f, 5.0f));
	CreateTree(&gameManager, glm::vec3(5.0f, 0.0f, 10.0f));
	CreateTree(&gameManager, glm::vec3(5.0f, 0.0f, 15.0f));
	
		
	
	
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