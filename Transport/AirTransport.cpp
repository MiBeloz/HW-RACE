#include "AirTransport.h"


int AirTransport::typeOfTransport() const {
    return AIR_MODE;
}

AirTransport::AirTransport(const int speed) : Transport(speed), _ratio(0) {}

void AirTransport::calcTime(const int distance) {
	if (_ratio != 0) {
		_time = (static_cast<double>(distance) - static_cast<double>(distance) / 100 * _ratio) / _speed;
	}
	else {
		_time = static_cast<double>(distance) / _speed;
	}
}
