#include "Player.h"
#include "Keys.h"
#include "Engine.h"
#include <bitset>
#include <cmath>
#include <complex>

using namespace std;
using namespace glm;

extern bitset<5> keys; //Using extern to access the global keys variable from main.cpp

Player::Player(glm::vec2 initPosition, 
			   float initOrientation, 
			   glm::vec2 initSize, 
			   GLuint initTextureID, 
			   float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;

	velocity = vec2(0.0f, 0.0f); //Initial velocity is zero
}

void Player::update(double tDelta) {

	ScreenBounds();
	//cout << position.x << "," << position.y << "\n";

	vec2 F = vec2(0.0f, 0.0f);

#pragma region Player Movement

	if (keys.test(Key::W) == true) {

		vec2 forward(cos(Player::orientation),
					sin(Player::orientation));

		F += forward * thrust;
	}
	if (keys.test(Key::S) == true) {

		vec2 backward(cos(Player::orientation),
					  sin(Player::orientation));

		F -= backward * thrust;
	}
	if (keys.test(Key::A) == true) {
	
		Player::orientation += playerRotationSpeed * (float)tDelta;
	}
	if (keys.test(Key::D) == true) {

		Player::orientation -= playerRotationSpeed * (float)tDelta;
	}

	vec2 a = F * (1.0f / mass); //Calculate acceleration
	velocity = velocity + (a * (float)tDelta); //Update velocity
	Player::position += (velocity * (float)tDelta); //Update position
#pragma endregion

}

void Player::ScreenBounds() {

	float halfHieght = getViewplaneHeight() / 2.0f;
	float halfWidth = getViewplaneWidth() / 2.0f;

	if (Player::position.x >= halfWidth) {
		position.x = -halfWidth + 0.1f;
	}
	if (Player::position.x <= -halfWidth) {
		position.x = halfWidth - 0.1f;
	}
	if (position.y >= halfHieght) {
		position.y = -halfWidth + 0.1f;
	}
	if (position.y <= -halfWidth) {
		position.y = halfWidth + 0.1f;
	}
}
