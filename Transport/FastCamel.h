#pragma once

#include "GroundTransport.h"


class FastCamel : public GroundTransport {
public:
	FastCamel();
	~FastCamel();

	std::string getName() const override;
	void setDistance(const int distance) override;

private:
	int _size;
	double* _timeRelax;
};

