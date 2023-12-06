#pragma once

#include "Person.h"

class Archer : public Person {
public:
	Archer() {}
	Archer(float _x, float _y);
	virtual ~Archer() {}
	Archer(const Archer& re) = delete;
	Archer& operator=(const Archer& re) = delete;

	virtual void AddArms();
	void UpdateArms(float angle);
};