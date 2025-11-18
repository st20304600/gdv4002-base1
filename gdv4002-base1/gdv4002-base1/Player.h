#pragma once

#include "GameObject2D.h"

using namespace glm;

class Player : public GameObject2D {
	private:
		float mass;
		vec2 velocity;


	public:
		Player(vec2 initialPosition, float initOrientation, vec2 initSize, GLuint initTextureID, float mass);

		void update(double tDelta) override;

		const float thrust = 2.0f;
};