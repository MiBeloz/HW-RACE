#pragma once

#include "Transport.h"


class AirTransport : public Transport {
public:
	int typeOfTransport() const override;

protected:
	explicit AirTransport(const int speed);

	void calcTime(const int distance);

	int _ratio;
};

