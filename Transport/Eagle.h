#pragma once

#include "AirTransport.h"


class Eagle : public AirTransport {
public:
	Eagle();

	std::string getName() const override;
	void setDistance(const int distance) override;
};

