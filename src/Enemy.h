#pragma once

#include "Person.h"

class Enemy : public Person {
public:
	Enemy() {}
	Enemy(float _x, float _y);
	virtual ~Enemy() {}
	Enemy(const Enemy& re) = delete;
	Enemy& operator=(const Enemy& re) = delete;

	virtual void AddArms();
};