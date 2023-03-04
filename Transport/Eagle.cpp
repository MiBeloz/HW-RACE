#include "Eagle.h"


Eagle::Eagle() : AirTransport(8) {}

std::string Eagle::getName() const {
	return "Орёл";
}

void Eagle::setDistance(const int distance) {
	_ratio = 6;
	calcTime(distance);
}
