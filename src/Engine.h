#pragma once

#include "Archer.h"
#include "Enemy.h"
#include "Arrow.h"
#include "Particle.h"
#include "Control.h"

class Engine {
protected:
	sf::RenderWindow m_Window;
	sf::Text m_LogoText, m_LivesText, m_ScoreText, m_Author;
	Control m_Controls;
	Archer m_Archer;
	Enemy m_Enemy;
	Arrow m_Arrow;
	Particles m_Blood;
	sf::RectangleShape borderOfPower, Power;
	sf::Font m_Font;
	bool m_Shoot;
	int m_Lives, m_Score;
public:
	Engine();
	virtual ~Engine() {}
	Engine(const Engine& re) = delete;
	Engine& operator=(const Engine& re) = delete;

	void RotateArrow(float angle);
	void MoveArrow();
	void RotateArms();
	void ShootArrow(sf::Vector2f posMouse);
	bool CheckCollision();
	void GameOver();

	void Play();

};