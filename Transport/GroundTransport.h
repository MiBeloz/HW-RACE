#pragma once

#include "Transport.h"


class GroundTransport : public Transport {
public:
	int typeOfTransport() const override;

protected:
	explicit GroundTransport(const int speed, const int timeBeforeRelax);

	void calcTime(const int distance, const double* timeRelax, const int size);

	int _timeBeforeRelax;
};

