#include "Archer.h"

Archer::Archer(float _x, float _y) {
	ChangePosition(_x, _y);
}

void Archer::AddArms() {
	m_Arms.setSize(sf::Vector2f(80.0f, 3.0f));
	m_Arms.setPosition(m_Pos.x + 40.0f, m_Pos.y);
	m_Arms.setOrigin(40.0f, 1.5f);
	m_Arms.setFillColor(sf::Color::Black);
	
	m_Arc.setRadius(50.0f);
	m_Arc.setPointCount(3);
	m_Arc.setPosition(m_Pos.x + 40.0f, m_Pos.y);
	m_Arc.setOutlineThickness(2);
	m_Arc.setOrigin(50.0f, 37.5f);
	m_Arc.setOutlineColor(sf::Color::Black);
	m_Arc.setFillColor(sf::Color::Transparent);
}

void Archer::UpdateArms(float angle) {
    m_Arms.setRotation(angle);
	m_Arc.setRotation(angle - 90.0f);
}