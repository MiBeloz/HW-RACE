#include "CarpetPlane.h"


CarpetPlane::CarpetPlane() : AirTransport(10) {}

std::string CarpetPlane::getName() const {
	return "Ковёр-самолет";
}

void CarpetPlane::setDistance(const int distance) {
	distance < 1000 ? _ratio = 0 : distance < 5000 ? _ratio = 3 : distance < 10000 ? _ratio = 10 : _ratio = 5;
	calcTime(distance);
}
