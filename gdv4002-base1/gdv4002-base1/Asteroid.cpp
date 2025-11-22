#include "Asteroid.h"
#include "Engine.h"

using namespace glm;
using namespace std;

Asteroid::Asteroid(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, glm::vec2 initVelocity, float rotSpeed, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {
	
	velocity = initVelocity;
	rotationSpeed = rotSpeed;

	this->mass = mass;

}

void Asteroid::update(double tDelta) {



}