#include "Player.h"
#include "Keys.h"
#include <bitset>

using namespace std;

extern bitset<5> keys; //Using extern to access the global keys variable from main.cpp

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialPlayerSpeed) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	playerSpeed = initialPlayerSpeed;
}

void Player::update(double tDelta) {

	// Unlike our myUpdate function, we're already 'in' the player object, so no need to call getObject as we did before :)

	if (keys.test(Key::W) == true) {

		position.y += playerSpeed * (float)tDelta;
	}
	if (keys.test(Key::S) == true) {

		position.y -= playerSpeed * (float)tDelta;
	}
	if (keys.test(Key::A) == true) {

		position.x -= playerSpeed * (float)tDelta;
	}
	if (keys.test(Key::D) == true) {

		position.x += playerSpeed * (float)tDelta;
	}
}
