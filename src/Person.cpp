#include "Person.h"

Person::Person(float _x, float _y) 
	: m_Pos(_x, _y)
{
	Create();
}

void Person::Create() {
	m_Floor.setSize(sf::Vector2f(80.0f, 5.0f));
	m_Floor.setPosition(m_Pos.x, m_Pos.y + 70.0f);
	m_Floor.setFillColor(sf::Color::Black);
	
	m_LegLeft.setSize(sf::Vector2f(40.0f, 3.0f));
	m_LegLeft.setRotation(-60);
	m_LegLeft.setPosition(m_Pos.x + 18.0f, m_Pos.y + 70.0f);
	m_LegLeft.setFillColor(sf::Color::Black);
	
	m_LegRight.setSize(sf::Vector2f(40.0f, 3.0f));
	m_LegRight.setRotation(-120);
	m_LegRight.setPosition(m_Pos.x + 57.0f, m_Pos.y + 72.0f);
	m_LegRight.setFillColor(sf::Color::Black);
	
	m_Stomach.setSize(sf::Vector2f(40.0f, 3.0f));
	m_Stomach.setPosition(m_Pos.x+40, m_Pos.y);
	m_Stomach.setRotation(90);
	m_Stomach.setFillColor(sf::Color::Black);
	
	m_Head.setRadius(15);
	m_Head.setPosition(m_Pos.x + 23.0f, m_Pos.y - 30.0f);
	m_Head.setFillColor(sf::Color::Black);

	AddArms();
}

void Person::Draw(sf::RenderWindow& win) {
	win.draw(m_Floor);
	win.draw(m_LegLeft);
	win.draw(m_LegRight);
	win.draw(m_Stomach);
	win.draw(m_Arms);
	win.draw(m_Head);
	win.draw(m_Arc);
}

void Person::Init(float _x, float _y) {
	m_Pos = sf::Vector2f(_x, _y);
	Create();
}