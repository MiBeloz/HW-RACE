#include "FastCamel.h"


FastCamel::FastCamel() : GroundTransport(40, 10) {
	_size = 3;
	_timeRelax = new double[_size] {5, 6.5, 8};
}

FastCamel::~FastCamel() {
	delete[] _timeRelax;
	_timeRelax = nullptr;
}

std::string FastCamel::getName() const {
	return "Верблюд-быстроход";
}

void FastCamel::setDistance(const int distance) {
	calcTime(distance, _timeRelax, _size);
}
