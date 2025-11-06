#include "Engine.h"
#include "stdlib.h"
#include <ctime>

using namespace std;

// Function prototypes
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

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024, 5.0f);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	std::srand(std::time({}));

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	//
	// Setup game scene objects here
	//
	
	//Background
	//addObject("Background", glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(4.0f, 4.0f), "Resources\\Textures\\Background_Space.png", TextureProperties::NearestFilterTexture());
	//asteroids
	addObject("Asteroid", glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.3f, 0.3f), "Resources\\Textures\\Asteroid.png", TextureProperties::NearestFilterTexture());
	//Player Ship
	addObject("Player", glm::vec2(0.0f, -1.0f), 0.0f, glm::vec2(0.4f, 0.5f), "Resources\\Textures\\Player_Ship.png", TextureProperties::NearestFilterTexture());
	
	GameObject2D* player = getObject("Player");
	GameObject2D* Asteroid = getObject("Asteroid");


	if (player != nullptr)
	{
		cout << "Player Found";
		//player code here

	}
	else 
	{
		cout << "Player Not Found";
	}

	if (Asteroid != nullptr)
	{
		cout << "Asteroid Found";
		//asteroid code here
		float x, y;
		RandomPosition(&x, &y);
		Asteroid->position = glm::vec2(x, y);
	}
	else
	{
		cout << "Asteroid Not Found";
	}
	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


