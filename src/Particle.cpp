#include <random>
#include <iostream>
#include "Particle.h"

std::random_device n;
std::mt19937 d(n());
std::uniform_real_distribution<> ran(0, 360);

Particles::Particles()
	: m_Nums(20), m_Particles(20)
{
}

Particles::Particles(size_t count)
	: m_Nums(count), m_Particles(count)
{
}

void Particles::Init(sf::Vector2f pos) {
	m_Pos = pos;
	for (auto& i : m_Particles) {
		i.position = m_Pos;
		i.part.setSize(sf::Vector2f(10.0f, 10.0f));
		i.part.setOrigin(5.0f, 5.0f);
		i.part.setFillColor(sf::Color::Black);
		i.part.setPosition(i.position);

		i.angle = ran(d) * 3.14f / 180.0f;
		i.speed = ran(d);
		i.velocity = sf::Vector2f(cos(i.angle) * i.speed, sin(i.angle) * i.speed);
	}
}

void Particles::Update() {
	for (size_t i = 0; i < m_Particles.size(); i++) {
		Particle& p = m_Particles[i];
		p.position += p.velocity * 0.04f;
		p.velocity.y += 9.81f * 0.3f;
		p.part.setPosition(p.position);
	}
}

void Particles::Draw(sf::RenderWindow& win) {
	for (auto& i : m_Particles) {
		win.draw(i.part);
	}
}