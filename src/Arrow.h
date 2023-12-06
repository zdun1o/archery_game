#pragma once

#include <SFML/Graphics.hpp>

class Arrow {
private:
	sf::Vector2f m_Pos;
	sf::RectangleShape m_Stem;
	sf::CircleShape m_TopOfArrow;
	
	void Init(float _x, float _y);
	void Draw(sf::RenderWindow& win);

	float arrowSpeed;
	sf::Vector2f arrowVelocity;
public:
	Arrow();
	virtual ~Arrow() {}
	Arrow(const Arrow& re) = delete;
	Arrow& operator=(const Arrow& re) = delete;
	
	void SetPosition(float _x, float _y);
	
	friend class Engine;
};