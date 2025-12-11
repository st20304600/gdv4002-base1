#include "Asteroid.h"
#include "Engine.h"

using namespace glm;
using namespace std;

float counter = 5.0f;
float timeInterval;

static int currentAsteroids = 0;

Asteroid::Asteroid(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, glm::vec2 initVelocity, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {
	
	velocity = initVelocity;
	rotationSpeed = glm::radians(90.0f);

	this->mass = mass;


	timeInterval = counter;

}

void Asteroid::update(double tDelta) {
	ScreenBounce();

	//SpawnPoint(&position.x, &position.y);

	orientation += rotationSpeed * (float)tDelta;

	position += ((velocity / mass) * (float)tDelta);

	counter += (float)tDelta;

}

//void Asteroid::RandomPosition(float* y)
//{
//	//float v1 = (float)rand() / (float)RAND_MAX;
//	//*x = v1 * 5.0f - 2.5f;
//
//	float v2 = (float)rand() / (float)RAND_MAX;
//	*y = v2 * 2.5f;
//
//}

void Asteroid::SpawnPoint(float* x, float* y) {

	float rightEdge = halfWidth - 0.1f;
	float leftEdge  = -halfWidth + 0.1f;

	float maxY = getViewplaneHeight() / 2.0f;
	float minY = -maxY;

	// Choose left or right edge
	if ((rand() % 2) == 0) {
		*x = leftEdge;
	} else {
		*x = rightEdge;
	}

	// Random Y between minY and maxY
	float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	float randY = t * (maxY - minY) + minY;

	*y = randY;
}

void Asteroid::ScreenBounce() {

	if (position.x <= -halfWidth || position.x >= halfWidth) {
		velocity.x = -velocity.x;
	}
	if (position.y <= -halfHeight || position.y >= halfHeight) {
		velocity.y = -velocity.y;
	}

}

void Asteroid::SpawnAsteroids() {

	GLuint asteroidTexture = loadTexture("Resources\\Textures\\Asteroid.png");

	while (currentAsteroids <= maxAsteroids && counter >= timeInterval) {

			counter -= timeInterval;

			float sizeXY = ((float)rand() / (float)RAND_MAX) * 0.4f + 0.1f;
			float x, y;
			SpawnPoint(&y, &x);

			Asteroid* asteroid = new Asteroid(vec2(x, y), 1.0f, vec2(sizeXY, sizeXY), asteroidTexture, vec2(1.0f, -0.2f), 1.0f);

			if (position.x > 0) {
				asteroid->velocity.x = -1.0f;// -asteroid->velocity.x;
			}
			else {
				asteroid->velocity.x = 1.0f;// -asteroid->velocity.x;
			}

			addObject("asteroid", asteroid);

			currentAsteroids++;
	}
}