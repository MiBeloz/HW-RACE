#include "BootsAllTerrain.h"


BootsAllTerrain::BootsAllTerrain() : GroundTransport(6, 60) {
	_size = 2;
	_timeRelax = new double[_size] {10, 5};
}

BootsAllTerrain::~BootsAllTerrain() {
	delete[] _timeRelax;
	_timeRelax = nullptr;
}

std::string BootsAllTerrain::getName() const {
	return "Ботинки-вездеходы";
}

void BootsAllTerrain::setDistance(const int distance) {
	calcTime(distance, _timeRelax, _size);
}
