#pragma once

#include "GameObject2D.h"

using namespace glm;

class Player : public GameObject2D {
	private:
		float mass;
		vec2 velocity;
		float playerRotationSpeed = 1.8f;
		float screenBounce = 25.0f;
		const float thrust = 2.0f;

	public:
		Player(vec2 initialPosition, float initOrientation, vec2 initSize, GLuint initTextureID, float mass);

		void update(double tDelta) override;

};