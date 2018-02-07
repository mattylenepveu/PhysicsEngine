#include "Sphere.h"
#include <Gizmos.h>

Sphere::Sphere(glm::vec2 position, glm::vec2 velocity,
	float mass, float radius, glm::vec4 colour) :
	RigidBody(SPHERE, position, velocity, 0, mass)
{
	m_radius = radius;
	m_colour = colour;
}

Sphere::~Sphere()
{
}

void Sphere::makeGizmo()
{
	aie::Gizmos::add2DCircle(m_position, m_radius, 12, m_colour);
}

bool Sphere::checkCollision(PhysicsObject* pOther)
{
	Sphere* other = dynamic_cast<Sphere*>(pOther);

	if (other)
	{
		return ((other->m_radius + m_radius) > glm::distance(other->m_position, m_position));
	}

	return false;
}
