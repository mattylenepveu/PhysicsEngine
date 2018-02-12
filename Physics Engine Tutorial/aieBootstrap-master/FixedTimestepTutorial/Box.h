#pragma once
#include "RigidBody.h"

class Box : public RigidBody
{
public:
	Box() = delete;
	Box(glm::vec2 position, glm::vec2 velocity, float mass, 
		float width, float height, glm::vec4 colour);
	~Box();

	virtual void makeGizmo();

	float getWidth() { return m_width; }
	float getHeight() { return m_height; }

	glm::vec2 getDimensions() { return m_dimensions; }
	glm::vec2 getMin() { return m_min; }
	glm::vec2 getMax() { return m_max; }

	glm::vec4 getColour() { return m_colour; }

protected:
	float m_width;
	float m_height;

	glm::vec2 m_dimensions;
	glm::vec2 m_min;
	glm::vec2 m_max;

	glm::vec4 m_colour;
};

