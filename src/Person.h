#pragma once

#include <SFML/Graphics.hpp>

class Person {
protected:
	sf::Vector2f m_Pos;
	sf::RectangleShape m_Floor, m_LegLeft, m_LegRight, m_Stomach, m_Arms;
	sf::CircleShape m_Head, m_Arc;
	void Create();
public:
	Person() {}
	Person(float _x, float _y);
	virtual ~Person() {}
	Person(const Person& re) = delete;
	Person& operator=(const Person& re) = delete;

	virtual void AddArms() = 0;
	void Draw(sf::RenderWindow& win);
	void Init(float _x, float _y);

	inline void ChangePosition(float _x, float _y) { Init(_x, _y); }
	inline sf::Vector2f GetPosition() { return m_Pos; }
};