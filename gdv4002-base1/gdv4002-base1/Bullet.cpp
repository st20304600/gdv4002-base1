#include "Bullet.h"
#include "Keys.h"
#include "Engine.h"
#include "Player.h"
#include <bitset>
#include <cmath>

using namespace std;
using namespace glm;

extern bitset<5> keys;

Bullet::Bullet(vec2 initalPosition, 
			   float initOrientation,
			   vec2 initSize, 
			   GLuint initTextureID,
			   vec2 initVelocity,
			   float mass)
	: GameObject2D(initalPosition, initOrientation, initSize, initTextureID) // initialize base
{
	this->mass = mass;

	velocoity = initVelocity; // use provided initial velocity
}

void Bullet::update(double tDelta) {
	// simple movement
	position += velocoity * (float)tDelta;
}

void Bullet::Shoot() {

	GLuint bulletTexture = loadTexture("Resources\\Textures\\Bullet.png");

	// get the player instance from the engine (position is not static)
	GameObject2D* playerObj = getObject("player");
	if (playerObj == nullptr) {
		// player not found, bail out
		return;
	}

	vec2 playerPos = playerObj->position;
	float playerOri = playerObj->orientation;

	// create bullet in front of player
	Bullet* bullet = new Bullet(
		vec2(playerPos.x, playerPos.y),
		playerOri,
		vec2(0.2f, 0.2f),
		bulletTexture,
		vec2(0.0f, 0.0f),
		0.5f
	);

	// give bullet an initial velocity in player's facing direction
	float speed = 5.0f;
	bullet->velocoity = vec2(cos(playerOri), sin(playerOri)) * speed;

	// add the new bullet into the engine object list so it updates/renders
	addObject("bullet", bullet);
}