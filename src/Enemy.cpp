#include "Enemy.h"

Enemy::Enemy(float _x, float _y) {
	ChangePosition(_x, _y);
}

void Enemy::AddArms() {
	m_Arms.setSize(sf::Vector2f(80.0f, 3.0f));
	m_Arms.setPosition(m_Pos.x, m_Pos.y);
	m_Arms.setFillColor(sf::Color::Black);
}