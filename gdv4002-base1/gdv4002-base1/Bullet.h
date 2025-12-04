#pragma once

#include "GameObject2D.h"

using namespace glm;

class Bullet : public GameObject2D {
	private:
		float mass;
		vec2 velocoity;

	public:
		Bullet(vec2 initalPosition, float initOrientation, vec2 initSize, GLuint initTextureID, vec2 initVelocity, float mass);

		void update(double tDelta) override;

		// Make Shoot static so it can be called from Player without an instance
		static void Shoot();
};