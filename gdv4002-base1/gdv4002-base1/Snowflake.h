#pragma once

#include "GameObject2D.h"

using namespace glm;

class Snowflake : public GameObject2D {

	private:
		float mass;
		vec2 velocity;

		float angleChangePerSecond;
		// ... but we also want the snowflakes to rotate as they fall, so we'll change the orientation attribute but without the physics.  
		// We already inherit the orientation attribute from GameObject2D, so we just need to add the 'change in orientation per second' here;

	public:

		Snowflake(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, float angleChangePerSecond);
		~Snowflake();

		void update(double tDelta) override;

};
