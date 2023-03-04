#include "main.h"


int main(int argc, char** argv) {
	setlocale(LC_ALL, "ru");
	
	std::vector<Transport*> transport;

	MainMenu mainMenu{};
	int select{};

	while (true) {
		std::cout << "Добро пожаловать в гоночный симулятор!\n" << std::endl
			<< "1 - гонка для наземного транспорта\n"
			<< "2 - гонка для воздушного транспорта\n"
			<< "3 - гонка для наземного и воздушного транспорта\n"
			<< "0 - выход\n" << std::endl;

		std::cout << "Выберите тип гонки: ";
		std::cin >> select;

		if (select < 0 || select > 3) {						//Проверка введенной команды
			system("cls");
			std::cout << "Неправильная команда!\n" << std::endl;
			continue;
		}

		mainMenu = static_cast<MainMenu>(select);

		switch (mainMenu) {
		case MainMenu::выход:
			return 0;

		case MainMenu::гонка_для_наземного_транспорта:
			menuSelectTransport(transport, GROUND_MODE);
			break;

		case MainMenu::гонка_для_воздушного_транспорта:
			menuSelectTransport(transport, AIR_MODE);
			break;

		case MainMenu::гонка_для_наземного_и_воздушного_транспорта:
			menuSelectTransport(transport, ALL_MODE);
			break;
		}
	}

	return 0;
}

void menuSelectTransport(std::vector<Transport*>& transport, const int mode) {
	BootsAllTerrain bootsAllTerrain;
	Broom broom;
	Camel camel;
	Centaur centaur;
	Eagle eagle;
	FastCamel fastCamel;
	CarpetPlane carpetPlane;

	MenuST menuST{};

	int distance = selectDistance();
	int tempTransportSize{};
	int select{};

	//if (menuRegistration(transport, distance)) {			//Возвращает false, если в меню регистрации выбрать 'зарегистрировать транспорт'
	//	return;
	//}
	system("cls");

	while (true) {
		if (tempTransportSize < transport.size()) {			//Если размер 'transport' увеличился - добавился новый транспорт
			std::cout << "Транспорт '" << transport.at(transport.size() - 1)->getName() << "' успешно зарегистрирован!\n" << std::endl;
			tempTransportSize = static_cast<int>(transport.size());
		}

		std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << std::endl << std::endl;

		if (transport.size() > 0) {							//Если размер 'transport' больше 0 - вывод зарегистрированного транспорта
			std::cout << "Зарегистрированные транспортные средства: ";
			for (int i = 0; i < transport.size(); i++) {
				if (i == transport.size() - 1) {
					std::cout << transport.at(i)->getName() << ".\n" << std::endl;
				}
				else {
					std::cout << transport.at(i)->getName() << ", ";
				}
			}
		}

		std::cout
			<< "1 - Ботинки-вездеходы       (наземный)\n"
			<< "2 - Метла                   (воздушный)\n"
			<< "3 - Верблюд                 (наземный)\n"
			<< "4 - Кентавр                 (наземный)\n"
			<< "5 - Орёл                    (воздушный)\n"
			<< "6 - Верблюд-быстроход       (наземный)\n"
			<< "7 - Ковёр самолет           (воздушный)\n"
			<< "0 - Закончить регистрацию\n" << std::endl;

		std::cout << "Введите транспорт или 0 для окончания процесса регистрации: ";
		std::cin >> select;

		if (select < 0 || select > 7) {						//Проверка введенной команды
			system("cls");
			std::cout << "Неправильная команда!\n" << std::endl;
			continue;
		}

		menuST = static_cast<MenuST>(select);

		system("cls");

		switch (menuST) {
		case MenuST::закончить_регистрацию:
			if (menuRegistration(transport, distance)) {	//Возвращает false, если в меню регистрации выбрать 'зарегистрировать транспорт'
				return;
			}
			system("cls");
			break;

		case MenuST::ботинки_вездеходы:
			transportRegistration(transport, bootsAllTerrain, mode);
			break;

		case MenuST::метла:
			transportRegistration(transport, broom, mode);
			break;

		case MenuST::верблюд:
			transportRegistration(transport, camel, mode);
			break;

		case MenuST::кентавр:
			transportRegistration(transport, centaur, mode);
			break;

		case MenuST::орёл:
			transportRegistration(transport, eagle, mode);
			break;

		case MenuST::верблюд_быстроход:
			transportRegistration(transport, fastCamel, mode);
			break;

		case MenuST::ковёр_самолет:
			transportRegistration(transport, carpetPlane, mode);
			break;
		}
	}
}

void transportRegistration(std::vector<Transport*>& transport, Transport& other, const int mode) {
	if (mode == other.typeOfTransport() || mode == ALL_MODE) {
		for (int i = 0; i < transport.size(); i++) {
			if (&other == transport.at(i)) {
				std::cout << "Транспорт '" << transport.at(i)->getName() << "' уже зарегистрирован!\n" << std::endl;
				return;
			}
		}
		transport.push_back(&other);
	}
	else {
		std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n" << std::endl;
	}
}

bool menuRegistration(std::vector<Transport*>& transport, const int distance) {
	system("cls");

	int select{};
	while (true) {
		std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства." << std::endl;
		std::cout
			<< "1 - зарегистрировать транспорт"
			<< ((transport.size() < 2) ? "\n" : "\n2 - начать гонку\n")
			<< "0 - назад в главное меню\n" << std::endl;

		std::cout << "Выберите действие: ";
		std::cin >> select;
		if (select == 0) {
			system("cls");
			transport.clear();
			return true;
		}
		else if (select == 1) {
			return false;
		}
		else if (select == 2 && transport.size() >= 2) {
			if (runRace(transport, distance)) {
				system("cls");
				transport.clear();
				return true;
			}
		}
		else {
			system("cls");
			std::cout << "Неправильная команда!\n" << std::endl;
		}
	}
}

bool runRace(std::vector<Transport*>& transport, const int distance) {
	system("cls");

	for (int i = 0; i < transport.size(); i++) {			//Расчет времени для каждого транспортного средства
		transport.at(i)->setDistance(distance);
	}

	std::sort(transport.begin(), transport.end(), comp);	//Сортировка

	int select{};
	while (true) {
		std::cout << "Результаты гонки:\n" << std::endl;

		for (int i = 0; i < transport.size(); i++) {
			std::cout << i + 1 << " - " << transport.at(i)->getName() << ". Время: " << transport.at(i)->getTime() << std::endl;
		}

		std::cout << "\n\n\n1 - провести еще одну гонку\n0 - выйти\n\nВыберите действие: ";
		std::cin >> select;
		if (select < 0 || select > 1) {						//Проверка введенной команды
			system("cls");
			std::cout << "Неправильная команда!\n" << std::endl;
		}
		else if (select == 0) {
			transport.clear();
			exit(0);
		}
		else {
			return 1;
		}
	}
}

int selectDistance() {
	system("cls");
	int distance{};

	while (distance < 1) {
		std::cout << "Укажите длину дистанции(должна быть положительна): ";
		std::cin >> distance;

		if (distance < 1) {
			system("cls");
			std::cout << "Неверно введена дистанция!\n" << std::endl;
		}
	}

	return distance;
}

bool comp(Transport* a, Transport* b) {
	return *a < *b;
}
