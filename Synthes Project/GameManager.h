#pragma once
#include"Cube.h"
#include"LightCube.h"
class GameManager
{
public: 

	static const unsigned int width = 800;
	static const unsigned int height = 600;
	int currentMoving = 0;
	float speed = 0.01f;
	GLFWwindow* window;
	Camera *mainCamera;
	bool switchable=true;
	std::vector <Cube*>* models = new std::vector <Cube*>();
		LightCube *light;

	GameManager( Camera *camera);
	void SetLight( LightCube* light);
	void AddModel(Cube* model);
	void Update();
	void Activate();
	void Delete();
	void Terminate();
	void Input();
};

