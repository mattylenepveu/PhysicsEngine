#pragma once
#include <glm\glm.hpp>
#include <glm\ext.hpp>

enum ShapeType : unsigned short int
{
	PLANE = 0,
	SPHERE,
	BOX,
	SHAPE_COUNT
};

class PhysicsObject
{
protected:
	PhysicsObject(ShapeType a_shapeID) : m_shapeID(a_shapeID) {}

public:
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
	virtual void debug() = 0;
	virtual void makeGizmo() = 0;
	virtual void resetPosition() {};

	ShapeType getShapeID() { return m_shapeID; }

protected:
	ShapeType m_shapeID;
};