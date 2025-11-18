#include "Engine.h"
#include "stdlib.h"
#include "Keys.h"

#include <complex>
#include <bitset>
#include <ctime>
#include <cmath>

using namespace std;
using namespace glm;

//global variables
bitset<5> keys{ 0x0 };
//keys bitset to hold key states
static float playerSpeed = 1.0f;
static float playerRotationSpeed = radians(100.0f);
float pi = 3.14159265359f;
const float PI_2 = 1.57079632679f;

// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta);
//set prototype for update function
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
//set prototype for keyboard handler function

void RandomPosition(float* x, float* y)
{
	float v1 = (float)rand() / (float)RAND_MAX;
	*x = v1 * 5.0f - 2.5f;
	//rand() generates a pseudo-random integer between 0 and RAND_MAX
	//Dividing rand() by RAND_MAX gives a float between 0.0 and 1.0
	//then
	//Multiplying by 5.0f gives a range of 0.0 to 5.0
	//Subtracting 2.5f shifts the range to - 2.5 to + 2.5

	float v2 = (float)rand() / (float)RAND_MAX;
	*y = v2 * 2.5f;
}
void SpawnAsteroid()
{
	//addObject("Asteroid", glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.3f, 0.3f), "Resources\\Textures\\Asteroid.png", TextureProperties::NearestFilterTexture());
	//Function to spawn asteroids at random positions at the top of the screen
	int maxAsteroids = 5;
	int currentAsteroids = 0;

	while (currentAsteroids < maxAsteroids) {

		float x, y;
		RandomPosition(&x, &y);
		addObject("Asteroid", glm::vec2(x, y), 0.0f, glm::vec2(0.3f, 0.3f), "Resources\\Textures\\Asteroid.png", TextureProperties::NearestFilterTexture());
		currentAsteroids++;
	}
}

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024, 5.0f);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	std::srand(std::time({}));


	//float anglesPerSecond = glm::radians(45.0f);

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	//
	// Setup game scene objects here
	//
	
	//Background
	
	//addObject("Background", glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(4.0f, 4.0f), "Resources\\Textures\\Background_Space.png", TextureProperties::NearestFilterTexture());
	//asteroids
	//addObject("Asteroid", glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.3f, 0.3f), "Resources\\Textures\\Asteroid.png", TextureProperties::NearestFilterTexture());

	//Player Ship
	addObject("Player", glm::vec2(0.0f, -1.0f), 0.0f, glm::vec2(0.4f, 0.5f), "Resources\\Textures\\Player_Ship.png", TextureProperties::NearestFilterTexture());
	
	GameObject2D* player = getObject("Player");
	//GameObject2D* Asteroid = getObject("Asteroid");


	if (player != nullptr)
	{
		cout << "Player Found \n";
		//player code here

	}
	else 
	{
		cout << "Player Not Found";
	}

	/*
	if (Asteroid != nullptr)
	{
		cout << "Asteroid Found";
		//asteroid code here
		float x, y;
		RandomPosition(&x, &y);
		//take the random pos
		Asteroid->position = glm::vec2(x, y);
		//set the asteroid to that pos
	}
	else
	{
		cout << "Asteroid Not Found";
	}
	*/
	SpawnAsteroid();
	listGameObjectKeys();

	setUpdateFunction(myUpdate);
	//Sets it and gets it ready.
	setKeyboardHandler(myKeyboardHandler);
	//Sets it and gets it ready.


	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

void myUpdate(GLFWwindow* window, double tDelta) {

	//SpawnAsteroid();
	/*
	float asteroidRotationSpeed = glm::radians(45.0f); // 45 degrees per second
	GameObject2D* Asteroid = getObject("Asteroid");
	Asteroid->orientation += asteroidRotationSpeed * (float)tDelta;
	*/

	//Asteroids
	GameObjectCollection asteroids = getObjectCollection("Asteroid"); //get all asteroids and add them to a collection called "asteroids"
	//float asteroidRotationSpeed = glm::radians(45.0f); // 45 degrees per second
	float asteroidRotationSpeed[5] = {
		glm::radians(20.0f),
		glm::radians(40.0f),
		glm::radians(60.0f),
		glm::radians(80.0f),
		glm::radians(100.0f)
	}; //different rotation speeds for each asteroid
	for (int i = 0; i < asteroids.objectCount; i++) {
		GameObject2D* asteroid = asteroids.objectArray[i];
		asteroid->orientation += asteroidRotationSpeed[i] * (float)tDelta;
	}

	//Player
	GameObject2D* player = getObject("Player");
	if (keys.test(Key::W) == true) {
		//V.1
		//player->position.y += playerSpeed * (float)tDelta;

		//V.2
		complex<float> i(0.0f, 1.0f);
		complex<float> r = exp(i * (player->orientation + PI_2)); // e^(i*theta) gives us a unit vector in the direction of theta
		vec2 forward(r.real(), r.imag());

		player->position += forward * playerSpeed * (float)tDelta;

		cout << i << "\n";
		cout << r << "\n";

		
	}

	if (keys.test(Key::S) == true) {
		player->position.y -= playerSpeed * (float)tDelta;
	}

	if (keys.test(Key::D) == true) {
		//player->position.x += playerSpeed * (float)tDelta;
		player->orientation -= playerRotationSpeed * (float)tDelta;
	}

	if (keys.test(Key::A) == true) {
		//player->position.x -= playerSpeed * (float)tDelta;
		player->orientation += playerRotationSpeed * (float)tDelta;
	}
}
//Called every frame, input and animations go here

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
		}
	}
}

