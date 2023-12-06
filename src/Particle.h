#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Particles {
private:
	struct Particle {
		sf::RectangleShape part;
		sf::Vector2f position;
		sf::Vector2f velocity;
		float angle;
		float speed;
	};

	std::vector<Particle> m_Particles;
	sf::Vector2f m_Pos;
	size_t m_Nums;
public:
	Particles();
	Particles(size_t count);
	virtual ~Particles() {}

	Particles(const Particles& re) = delete;
	Particles& operator=(const Particles& re) = delete;

	void Init(sf::Vector2f pos);
	void Update();
	void Draw(sf::RenderWindow& win);
};