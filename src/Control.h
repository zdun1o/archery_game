#pragma once

#include <SFML/Graphics.hpp>

class Control {
private:
	sf::Event m_Event;
	sf::Vector2f m_Pos, m_ClickPos;
	float m_Angle;
public:
	float arrowSpeed;
	bool canPlay, canRotate, canShoot, resetArrow, buttonPressed;
	
	Control();
	virtual ~Control() {}
	Control(const Control& re) = delete;
	Control operator=(const Control& re) = delete;

	void SetAngle(sf::Vector2f archerPos);
	void MouseInput(sf::RenderWindow& win, bool& shoot);
	bool MouseInputGameOver(sf::RenderWindow& win);

	inline sf::Vector2f GetPosition() { return m_Pos; }
	inline sf::Vector2f GetClickPosition() { return m_ClickPos; }
	inline float GetAngle() { return m_Angle; }
};