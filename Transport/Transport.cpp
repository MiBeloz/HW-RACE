#include "Transport.h"


double Transport::getTime() const {
    return _time;
}

bool Transport::operator<(Transport& other) const {
    return _time < other._time;
}

Transport::Transport(const int speed) : _speed(speed), _time(0) {}
