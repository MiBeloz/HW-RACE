#pragma once

#include "GroundTransport.h"


class BootsAllTerrain : public GroundTransport {
public:
	BootsAllTerrain();
	~BootsAllTerrain();

	std::string getName() const override;
	void setDistance(const int distance) override;

private:
	int _size;
	double* _timeRelax;
};

