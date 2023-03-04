#pragma once

#include "AirTransport.h"


class CarpetPlane : public AirTransport {
public:
	CarpetPlane();

	std::string getName() const override;
	void setDistance(const int distance) override;
};

