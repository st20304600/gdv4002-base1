#include "Snowflake.h"
#include "Engine.h"

using namespace glm;
using namespace std;

extern vec2 gravity;

Snowflake::Snowflake(vec2 initPosition, float initOrientation, vec2 initSize, GLuint initTextureID, float mass, float angleChangePerSecond)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;
	velocity = vec2(0.0f, 0.0f);

	this->angleChangePerSecond = angleChangePerSecond;
}

Snowflake::~Snowflake() {
	cout << "Obj Deleted";
}


void Snowflake::update(double tDelta) {

	// 1. Physics bit for movement

	// 1.1. Sum forces - only add gravity for now
	vec2 F = gravity;

	// 1.2. Calculate acceleration
	vec2 accel = F * (1.0f / mass);

	// 1.3. Update velocity
	velocity = velocity + accel * (float)tDelta;

	// 1.4. Update position
	position = position + velocity * (float)tDelta;



	// 2. Non-physics bit for rotation
	orientation += angleChangePerSecond * (float)tDelta;
}

