#include "Plane.h"
#include "PhysicsObject.h"
#include "Gizmos.h"
#include <glm\ext.hpp>

Plane::Plane(glm::vec2 normal,  float distance) : PhysicsObject(ShapeType::PLANE)
{
	m_distanceToOrigin = -20.0f;
	m_normal = glm::vec2(0, 1);

	m_centrePoint = m_normal * m_distanceToOrigin;
}

Plane::~Plane()
{
}

void Plane::fixedUpdate(glm::vec2 gravity, float timeStep) {}

void Plane::makeGizmo()
{
	float lineSegmentLength = 300;
	glm::vec2 parallel(m_normal.y, -m_normal.x);

	glm::vec4 colour(1, 1, 1, 1);
	glm::vec2 start = m_centrePoint + (parallel * lineSegmentLength);
	glm::vec2 end = m_centrePoint - (parallel * lineSegmentLength);

	aie::Gizmos::add2DLine(start, end, colour);
}

void Plane::resetPosition()
{

}
