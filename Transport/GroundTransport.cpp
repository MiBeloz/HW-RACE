#include "GroundTransport.h"


int GroundTransport::typeOfTransport() const {
    return GROUND_MODE;
}

GroundTransport::GroundTransport(const int speed, const int timeBeforeRelax) : Transport(speed), _timeBeforeRelax(timeBeforeRelax) {}

void GroundTransport::calcTime(const int distance, const double* timeRelax, const int size) {
	int tempSize{};

	_time = static_cast<double>(distance) / _speed;

	if (static_cast<int>(_time) % _timeBeforeRelax) {
		tempSize = static_cast<int>(_time / _timeBeforeRelax);
	}
	else {
		tempSize = static_cast<int>(_time / _timeBeforeRelax) - 1;
	}

	if (tempSize == 0) {
		return;
	}
	else if (tempSize <= size) {
		for (int i = 0; i < tempSize; i++) {
			_time += timeRelax[i];
		}
	}
	else if (tempSize > size) {
		for (int i = 0; i < size; i++) {
			_time += timeRelax[i];
		}

		tempSize -= size;
		for (int i = 0; i < tempSize; i++) {
			_time += timeRelax[size - 1];
		}
	}
}
