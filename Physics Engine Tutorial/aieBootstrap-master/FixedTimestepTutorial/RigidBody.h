#pragma once
#include "PhysicsObject.h"

class RigidBody : public PhysicsObject
{
public:
	RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, 
			  float rotation, float mass, float linearDrag, 
			  float angularDrag, float elasticity);
	~RigidBody();

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void debug() {}

	void applyForce(glm::vec2 force);
	void applyForceToActor(RigidBody* actor2, glm::vec2 force);
	void resolveCollision(RigidBody* actor2);

	void setPosition(glm::vec2 pos) { m_position = pos; }
	glm::vec2 getPosition() { return m_position; }

	float getRotation() { return m_rotation; }
	float getMass() { return m_mass; }
	glm::vec2 getVelocity() { return m_velocity; }
	float getLinearDrag() { return m_linearDrag; }
	float getAngularDrag() { return m_angularDrag; }
	float getElasticity() { return m_elasticity; }

protected:
	glm::vec2 m_position;
	glm::vec2 m_velocity;

	float m_mass;
	float m_rotation; // 2D so we only need a single float to represent our rotation
	float m_angularVelocity;
	float m_linearDrag;
	float m_angularDrag;
	float m_elasticity;
};
