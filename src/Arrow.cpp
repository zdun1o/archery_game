#include "Arrow.h"

Arrow::Arrow()
	:arrowSpeed(50.0f), arrowVelocity(sf::Vector2f(0.0f, 0.0f))
{
}

void Arrow::Init(float _x, float _y) {
	m_Pos = sf::Vector2f(_x, _y);
	m_Stem.setSize(sf::Vector2f(50.0f, 2.0f));
	m_Stem.setFillColor(sf::Color::Red);
	m_Stem.setOrigin(0.0f, 1.0f);
	m_Stem.setPosition(m_Pos.x + 40.0f, m_Pos.y);

	m_TopOfArrow.setRadius(4);
	m_TopOfArrow.setPointCount(4);
	m_TopOfArrow.setFillColor(sf::Color::Red);
	m_TopOfArrow.setOrigin(-46.0f, 4.0f);
	m_TopOfArrow.setPosition(m_Pos.x + 39.0f, m_Pos.y);
}

void Arrow::SetPosition(float _x, float _y) {
	m_Pos = sf::Vector2f(_x, _y);
	m_Stem.setPosition(_x + 40.0f, _y);
	m_TopOfArrow.setPosition(_x + 39.0f, _y);
}

void Arrow::Draw(sf::RenderWindow& win) {
	win.draw(m_Stem);
	win.draw(m_TopOfArrow);
}
