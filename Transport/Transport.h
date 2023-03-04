#pragma once

#include <string>

#define GROUND_MODE 1
#define AIR_MODE 2
#define ALL_MODE 3


class Transport {
public:
	virtual int typeOfTransport() const = 0;
	virtual std::string getName() const = 0;
	virtual void setDistance(const int distance) = 0;
	double getTime() const;

	bool operator<(Transport& other) const;

protected:
	explicit Transport(const int speed);

	int _speed;
	double _time;
};

