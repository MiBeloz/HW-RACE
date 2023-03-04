#pragma once

#include "transport/Transport.h"
#include "transport/BootsAllTerrain.h"
#include "transport/Broom.h"
#include "transport/Camel.h"
#include "transport/Centaur.h"
#include "transport/Eagle.h"
#include "transport/FastCamel.h"
#include "transport/CarpetPlane.h"

#include <iostream>
#include <vector>
#include <algorithm>


enum class MainMenu {
	выход,
	гонка_для_наземного_транспорта,
	гонка_для_воздушного_транспорта,
	гонка_для_наземного_и_воздушного_транспорта
};

enum class MenuST {
	закончить_регистрацию,
	ботинки_вездеходы,
	метла,
	верблюд,
	кентавр,
	орёл,
	верблюд_быстроход,
	ковёр_самолет
};

void menuSelectTransport(std::vector<Transport*>& transport, const int mode);

void transportRegistration(std::vector<Transport*>& transport, Transport& other, const int mode);

bool menuRegistration(std::vector<Transport*>& transport, const int distance);

bool runRace(std::vector<Transport*>& transport, const int distance);

int selectDistance();

bool comp(Transport* a, Transport* b);
