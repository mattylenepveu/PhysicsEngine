#include "FixedTimestepTutorialApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Plane.h"
#include "Sphere.h"
#include "Box.h"
#include <glm\ext.hpp>
#include <Gizmos.h>


FixedTimestepTutorialApp::FixedTimestepTutorialApp() {

}

FixedTimestepTutorialApp::~FixedTimestepTutorialApp() {

}

bool FixedTimestepTutorialApp::startup() 
{
	// increase the 2d line count to maximize the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0, 0));
	m_physicsScene->setTimeStep(0.003f);

	Sphere* ball1 = new Sphere(glm::vec2(-4, 0), glm::vec2(0, 0), 3.0f, 1.0f, glm::vec4(1, 0, 0, 1));
	Sphere* ball2 = new Sphere(glm::vec2(4, 0), glm::vec2(0, 0), 3.0f, 1.0f, glm::vec4(0, 1, 0, 1));
	Sphere* ball3 = new Sphere(glm::vec2(8, 4), glm::vec2(0, 0), 3.0f, 1.0f, glm::vec4(0, 1, 1, 1));

	Box* box1 = new Box(glm::vec2(-4, 8), glm::vec2(0, 0), 3.0f, 1.0f, 1.0f, glm::vec4(0, 0, 1, 1));
	Box* box2 = new Box(glm::vec2(4, 8), glm::vec2(0, 0), 3.0f, 1.0f, 1.0f, glm::vec4(1, 1, 0, 1));
	Box* box3 = new Box(glm::vec2(-8, 4), glm::vec2(0, 0), 3.0f, 1.0f, 1.0f, glm::vec4(1, 0, 1, 1));

	Plane* plane = new Plane(glm::vec2(-1, 1), 0);

	m_physicsScene->addActor(ball1);
	m_physicsScene->addActor(ball2);
	m_physicsScene->addActor(ball3);

	m_physicsScene->addActor(box1);
	m_physicsScene->addActor(box2);
	m_physicsScene->addActor(box3);

	m_physicsScene->addActor(plane);

	ball1->applyForce(glm::vec2(30, 0));
	ball2->applyForce(glm::vec2(-30, 0));
	ball3->applyForce(glm::vec2(0, -15));

	box1->applyForce(glm::vec2(30, 0));
	box2->applyForce(glm::vec2(-30, 0));
	box3->applyForce(glm::vec2(0, -15));

	return true;
}

void FixedTimestepTutorialApp::shutdown() 
{
	delete m_font;
	delete m_2dRenderer;
}

void FixedTimestepTutorialApp::update(float deltaTime) 
{
	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void FixedTimestepTutorialApp::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100,
						-100 / aspectRatio, 100 / aspectRatio, 
						-1.0f, 1.0f));


	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}