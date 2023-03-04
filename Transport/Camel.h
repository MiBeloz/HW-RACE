#pragma once

#include "GroundTransport.h"


class Camel : public GroundTransport {
public:
	Camel();
	~Camel();

	std::string getName() const override;
	void setDistance(const int distance) override;

private:
	int _size;
	double* _timeRelax;
};

