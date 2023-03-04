#include "Broom.h"


Broom::Broom() : AirTransport(20) {}

std::string Broom::getName() const {
	return "Метла";
}

void Broom::setDistance(const int distance) {
	_ratio = distance / 1000;
	calcTime(distance);
}
