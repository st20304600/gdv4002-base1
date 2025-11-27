#include "Asteroid.h"
#include "Engine.h"

using namespace glm;
using namespace std;

Asteroid::Asteroid(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, glm::vec2 initVelocity, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {
	
	velocity = initVelocity;
	rotationSpeed = 3.0f;

	this->mass = mass;

}

void Asteroid::update(double tDelta) {
	ScreenBounce();

	//SpawnAsteroids();

	orientation += rotationSpeed * (float)tDelta;

	position += (velocity / mass * (float)tDelta);

}

void Asteroid::RandomPosition(float* x, float* y)
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

void Asteroid::ScreenBounce() {

	float halfHeight = getViewplaneHeight() / 2.0f;
	float halfWidth = getViewplaneWidth() / 2.0f;

	if (position.x <= -halfWidth || position.x >= halfWidth) {
		velocity.x = -velocity.x;
	}
	if (position.y <= -halfHeight || position.y >= halfHeight) {
		velocity.y = -velocity.y;
	}

}

void Asteroid::SpawnAsteroids() {

	GLuint asteroidTexture = loadTexture("Resources\\Textures\\Asteroid.png");

	while (currentAsteroids < maxAsteroids) {

		float x, y;
		RandomPosition(&x, &y);
		Asteroid* asteroid = new Asteroid(vec2(0.0f, 2.0f), 1.0f, vec2(0.5f, 0.5f), asteroidTexture, vec2(0.5f, -0.2f), 1.0f);
		addObject("asteroid", asteroid);
		currentAsteroids++;
	}

}