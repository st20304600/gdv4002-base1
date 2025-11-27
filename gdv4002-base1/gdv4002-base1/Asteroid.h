#pragma once

#include "GameObject2D.h"

using namespace glm;

class Asteroid : public GameObject2D {
private:
	float mass;
	float rotationSpeed;
	vec2 velocity;
	float bounceForce = 0.0f; // Initialize to default value

	int maxAsteroids = 5;
	int currentAsteroids = 0; // Initialize to default value

public:
	Asteroid(glm::vec2 initialPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, glm::vec2 initVelocity, float mass);

	void update(double tDelta) override;

	void RandomPosition(float* x, float* y);

	void ScreenBounce();

	void SpawnAsteroids();

};
