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

	Asteroid::orientation += rotationSpeed * (float)tDelta;

}