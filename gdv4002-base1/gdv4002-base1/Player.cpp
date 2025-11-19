#include "Player.h"
#include "Keys.h"
#include "Engine.h"
#include <bitset>

using namespace std;
using namespace glm;

extern bitset<5> keys; //Using extern to access the global keys variable from main.cpp

float screenBounce = 15.0f;

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;

	velocity = vec2(0.0f, 0.0f); //Initial velocity is zero
}

void Player::update(double tDelta) {

	vec2 F = vec2(0.0f, 0.0f); //Initialize force vector

	// Corrected screen boundary checks
	if (position.y < -getViewplaneHeight() / 2.0f) {
		F += glm::vec2(0.0f, screenBounce);
		//position.y = -getViewplaneHeight() / 2.0f; // Prevent going out of bounds

	}
	if (position.y > getViewplaneHeight() / 2.0f) {
		F += glm::vec2(0.0f, -screenBounce);
		//position.y = getViewplaneHeight() / 2.0f; // Prevent going out of bounds

	}
	if (position.x < -getViewplaneWidth() / 2.0f) {
		F += glm::vec2(screenBounce, 0.0f);
		//position.x = -getViewplaneWidth() / 2.0f; // Prevent going out of bounds

	}
	if (position.x > getViewplaneWidth() / 2.0f) {
		F += glm::vec2(-screenBounce, 0.0f);
		//position.x = getViewplaneWidth() / 2.0f; // Prevent going out of bounds

	}

	// 1. accumulate forces
	if (keys.test(Key::W)) {
		F += glm::vec2(0.0f, thrust);
	}
	if (keys.test(Key::S)) {
		F += glm::vec2(0.0f, -thrust);
	}
	if (keys.test(Key::A)) {
		F += glm::vec2(-thrust, 0.0f);
	}
	if (keys.test(Key::D)) {
		F += glm::vec2(thrust, 0.0f);
	}

	// 2. calculate acceleration. If f=ma, a=f/m
	vec2 a = F * (1.0f / mass);

	// 3. integrate to get new velocity
	velocity = velocity + (a * (float)tDelta);

	// 4. integrate to get new position
	position = position + (velocity * (float)tDelta);

}
