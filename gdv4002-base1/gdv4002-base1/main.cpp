#include "Engine.h"
#include "stdlib.h"
#include "Keys.h"
#include "Player.h"
#include "Asteroid.h"
#include "Emitter.h"

#include <bitset>

using namespace std;
using namespace glm;

//global variables
bitset<6> keys{ 0x0 };
vec2 gravity = vec2(0.0f, -0.005f);

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

//set prototype for keyboard handler function

void myRender(GLFWwindow* window);

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024, 5.0f);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_ALWAYS);

	srand(std::time({}));


	//Background
	GLuint backgroundTexture = loadTexture("Resources\\Textures\\BackGround.png");

	GameObject2D* background = new GameObject2D(vec2(0.0f, 0.0f), 0.0f, vec2(5.0f, 5.0f), backgroundTexture);
	addObject("background", background);

	//Player
	GLuint playerTexture = loadTexture("Resources\\Textures\\player1_ship.png");

	Player* mainPlayer = new Player(vec2(0.0f, 0.0f), 0.0f, vec2(0.5f, 0.5f), playerTexture, 2.5f);

	addObject("player", mainPlayer);

	//Asteroid
	GLuint asteroidTexture = loadTexture("Resources\\Textures\\Asteroid.png");
	Asteroid* asteroid = new Asteroid(vec2(0.0f, 2.0f), 1.0f, vec2(0.5f, 0.5f), asteroidTexture, vec2(0.5f, -0.2f), 1.0f);
	asteroid->SpawnAsteroids();

	////Emitter
	//Emitter* emitter = new Emitter(
	//	glm::vec2(0.0f, getViewplaneHeight() / 2.0f * 1.2f),
	//	glm::vec2(getViewplaneWidth() / 2.0f, 0.0f),
	//	0.05f);

	//addObject("emitter", emitter);

	setKeyboardHandler(myKeyboardHandler);
	setRenderFunction(myRender);
	//setUpdateFunction(deleteSnowflakes, false);

	//Sets it and gets it ready.

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	listGameObjectKeys();

	// return success :)
	return 0;
}

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Check if the key was just pressed
	if (action == GLFW_PRESS) {

		// now check which key was pressed...
		switch (key)
		{
		case GLFW_KEY_W:
			keys[Key::W] = true;
			break;
		case GLFW_KEY_S:
			keys[Key::S] = true;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = true;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = true;
			break;
		case GLFW_KEY_SPACE:
			keys[Key::SPACE] = true;
			break;
		case GLFW_KEY_F:
			keys[Key::F] = true;
			break;
		}
	}
	// If not pressed, check the key has just been released
	else if (action == GLFW_RELEASE) {

		// handle key release events
		switch (key)
		{
		case GLFW_KEY_W:
			keys[Key::W] = false;
			break;
		case GLFW_KEY_S:
			keys[Key::S] = false;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = false;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = false;
			break;
		case GLFW_KEY_SPACE:
			keys[Key::SPACE] = false;
			break;
		case GLFW_KEY_F:
			keys[Key::F] = false;
			break;
		}
	}
}

void myRender(GLFWwindow* window) {

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_ALWAYS);

	GameObject2D* background = getObject("background");
	background->render();

	GameObjectCollection asteroids = getObjectCollection("asteroid");
	for (int i = 0; i < asteroids.objectCount; i++) {
		asteroids.objectArray[i]->render();
	}
	GameObject2D* player = getObject("player");
	player->render();

	GameObjectCollection bullets = getObjectCollection("bullet");
	for (int i = 0; i < bullets.objectCount; ++i) {
		if (bullets.objectArray[i]) bullets.objectArray[i]->render();
	}

}