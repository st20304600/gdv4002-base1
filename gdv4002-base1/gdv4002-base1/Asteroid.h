#pragma once

#include "GameObject2D.h"

using namespace glm;

class Asteroid : public GameObject2D {
private:
	float mass;
	float rotationSpeed;
	vec2 velocity;

public:
	Asteroid(glm::vec2 initialPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, glm::vec2 initVelocity, float mass);

	void update(double tDelta) override;

	void SpawnAsteroid();
};
