#include "Box.h"
#include <Gizmos.h>

Box::Box(glm::vec2 position, glm::vec2 velocity, float mass, 
		 float width, float height, glm::vec4 colour) :
		 RigidBody(ShapeType::BOX, position, velocity, 0, mass, 0.2f, 0.2f, 0.8f)
{
	m_width = width;
	m_height = height;

	m_dimensions = glm::vec2(m_width, m_height);

	m_colour = colour;
}

Box::~Box()
{
}

void Box::makeGizmo()
{
	aie::Gizmos::add2DAABBFilled(m_position, m_dimensions, m_colour);
}
