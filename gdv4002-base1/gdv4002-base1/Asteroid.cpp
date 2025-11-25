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

	orientation += rotationSpeed * (float)tDelta;

	position += (velocity * (float)tDelta);

}

void Asteroid::ScreenBounce() {

	float halfHeight = getViewplaneHeight() / 2.0f;
	float halfWidth = getViewplaneWidth() / 2.0f;

	if (position.x <= 0 || position.x >= halfWidth) {
		velocity.x = -velocity.x;
	}
	if (position.y <= 0 || position.y >= halfHeight) {
		velocity.y = -velocity.y;
	}

}