#include "Camel.h"


Camel::Camel() : GroundTransport(10, 30) {
	_size = 2;
	_timeRelax = new double[_size] {5, 8};
}

Camel::~Camel() {
	delete[] _timeRelax;
	_timeRelax = nullptr;
}

std::string Camel::getName() const {
	return "Верблюд";
}

void Camel::setDistance(const int distance) {
	calcTime(distance, _timeRelax, _size);
}
