#pragma once
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <vector>

class PhysicsObject;

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);
	void update(float dt);
	void updateGizmos();
	void debugScene();

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	glm::vec2 getGravity() const { return m_gravity; }

	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	float getTimeStep() const { return m_timeStep; }

	void checkForCollision();

	static bool plane2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool plane2Sphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool plane2aabb(PhysicsObject* obj1, PhysicsObject* obj2);

	static bool sphere2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool sphere2aabb(PhysicsObject* obj1, PhysicsObject* obj2);

	static bool aabb2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool aabb2Sphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool aabb2aabb(PhysicsObject* obj1, PhysicsObject* obj2);

protected:
	glm::vec2 m_gravity;
	float m_timeStep;
	std::vector<PhysicsObject*> m_actors;
};

