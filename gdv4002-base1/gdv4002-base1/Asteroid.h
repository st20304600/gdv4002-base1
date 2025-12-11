#pragma once

#include "GameObject2D.h"
#include "Engine.h"

using namespace glm;

class Asteroid : public GameObject2D {

private:
	float mass;
	float rotationSpeed;
	vec2 velocity;
	float bounceForce = 0.0f; // Initialize to default value

	int maxAsteroids = 5;
	

public:
	float halfHeight = getViewplaneHeight() / 1.8f;
	float halfWidth = getViewplaneWidth() / 1.8f;

	Asteroid(glm::vec2 initialPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, glm::vec2 initVelocity, float mass);

	void update(double tDelta) override;

	//void RandomPosition(float* y, fl);

	void ScreenBounce();

	void SpawnAsteroids();

	void SpawnPoint(float* x, float* y);

};
