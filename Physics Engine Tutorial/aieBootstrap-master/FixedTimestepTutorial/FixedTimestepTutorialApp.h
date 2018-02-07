#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <glm\glm.hpp>
#include "PhysicsScene.h"

class FixedTimestepTutorialApp : public aie::Application 
{
public:
	FixedTimestepTutorialApp();
	virtual ~FixedTimestepTutorialApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	PhysicsScene* m_physicsScene;
};