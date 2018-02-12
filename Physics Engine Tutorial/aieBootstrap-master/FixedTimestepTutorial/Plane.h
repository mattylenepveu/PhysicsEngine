#pragma once
#include "PhysicsObject.h"
#include <glm\glm.hpp>

class Plane : public PhysicsObject
{
public:
	Plane() = delete;
	Plane(glm::vec2 normal, float distance);
	~Plane();

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void debug() {}
	virtual void makeGizmo();
	virtual void resetPosition();

	glm::vec2 getNormal() { return m_normal; }
	glm::vec2 getCentre() { return m_centrePoint; }
	float getDistance() { return m_distanceToOrigin; }

protected:
	glm::vec2 m_normal;
	glm::vec2 m_centrePoint;

	float m_distanceToOrigin;
};

