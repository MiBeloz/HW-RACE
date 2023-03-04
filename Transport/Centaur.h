#pragma once

#include "GroundTransport.h"


class Centaur : public GroundTransport {
public:
	Centaur();
	~Centaur();

	std::string getName() const override;
	void setDistance(const int distance) override;

private:
	int _size;
	double* _timeRelax;
};

