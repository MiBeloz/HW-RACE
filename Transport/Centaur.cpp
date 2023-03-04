#include "Centaur.h"


Centaur::Centaur() : GroundTransport(15, 8) {
	_size = 1;
	_timeRelax = new double[_size] {2};
}

Centaur::~Centaur() {
	delete[] _timeRelax;
	_timeRelax = nullptr;
}

std::string Centaur::getName() const {
	return "Кентавр";
}

void Centaur::setDistance(const int distance) {
	calcTime(distance, _timeRelax, _size);
}
