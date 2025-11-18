#pragma once

#include "GameObject2D.h"

using namespace glm;

class Player : public GameObject2D {
	private:
		float playerSpeed;


	public:
		Player(vec2 initialPosition, float initOrientation, vec2 initSize, GLuint initTextureID, float initalPlayerspeed);

		void update(double tDelta) override;
};