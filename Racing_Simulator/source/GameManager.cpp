#include "GameManager.h"

GameManager::GameManager() 
	: activeGame(true)
	, typeRace(TypeRace::GROUND)
	, lengthRace(0)
	, m_race(nullptr) {
	// Загружаем список доступных ТС из DLL (кэшируем)
	int count = 0;
	const char** names = lib::getAvailableVehicles(count);
	//availableNames.clear();
	//for (int i = 0; i < count; ++i) {
	//	availableNames.push_back(names[i]);
	//}
	lib::freeAvailableVehicles(names, count);

}

GameManager::~GameManager() {
	if (m_race) {
		lib::destroyRace(m_race);
		m_race = nullptr;
	}
}

void GameManager::run() {
	while (activeGame) {
		selectTypeRace();
		enterLengthRace();

		if (m_race) {
			lib::destroyRace(m_race);
			m_race = nullptr;
		}
		m_race = lib::createRace(static_cast<int>(typeRace), lengthRace);
		if (!m_race) {
			std::cerr << "Ошибка создания гонки!\n";
			continue;
		}

		bool raceFinished = false;
		while (!raceFinished) {
			actionRace();
		}

		showResults();

		if (m_race) {
			lib::destroyRace(m_race);
			m_race = nullptr;
		}
	}
}

void GameManager::selectTypeRace() {
	system("cls");
	std::cout << "Добро пожаловать в гоночный симулятор!\n";
	std::cout << "1. Гонка для наземного транспорта\n";
	std::cout << "2. Гонка для воздушного транспорта\n";
	std::cout << "3. Гонка для наземного и воздушного транспорта\n";

	int choice = 0;
	do {
		std::cout << "Выберите тип гонки: ";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Введите число!\n";
			continue;
		}
		if (choice >= 1 && choice <= 3) {
			typeRace = static_cast<TypeRace>(choice);
			break;
		}
		else {
			std::cout << "Введен неверный тип гонки\n";
		}
	} while (true);
}

void GameManager::enterLengthRace() {
	system("cls");
	std::cout << "Укажите длину дистанции (должна быть положительная): ";
	int len = 0;
	do {
		std::cin >> len;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Введите положительное целое число: ";
			continue;
		}
		if (len > 0) {
			lengthRace = static_cast<unsigned int>(len);
			break;
		}
		else {
			std::cout << "Дистанция должна быть больше нуля: ";
		}
	} while (true);
}

void GameManager::actionRace() {
	bool exitAction = false;
	while (!exitAction) {
		system("cls");
		std::cout << "Гонка для " << getTypeName() << " транспорта. Расстояние: " << lengthRace << "\n";
		int count = lib::getVehicleCount(m_race);
		std::cout << "Зарегистрировано транспортных средств: " << count << "\n";
		std::cout << "Должно быть зарегистрировано хотя бы 2 ТС.\n";
		std::cout << "1. Зарегистрировать транспорт\n";
		if (count > 0) std::cout << "2. Убрать транспорт\n";
		if (count >= 2) std::cout << "3. Начать гонку\n";
		std::cout << "Выберите действие: ";

		int action = 0;
		std::cin >> action;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Введите число!\n";
			continue;
		}

		switch (action) {
		case 1:
			registerTransport();
			break;
		case 2:
			if (count > 0) deleteTransport();
			else std::cout << "Нет зарегистрированных ТС\n";
			break;
		case 3:
			if (count >= 2) {
				startRace();
				exitAction = true;
			}
			else {
				std::cout << "Недостаточно ТС для старта (нужно минимум 2).\n";
			}
			break;
		default:
			std::cout << "Неверное действие\n";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void GameManager::registerTransport() {
	bool isRegisterTransport = false;
	bool newTransport = false;
	do {
		std::system("cls");
		if (newTransport && countTransports > 0)
			std::cout << getNameLastTransport() << " успешно зарегистрирован!";
		std::cout << "Гонка для " << getNameTypeRace() 
			<< " транспорта. Расстояние: " << lengthRace << std::endl;
		if (countTransports > 0)
			std::cout << "Зарегистрированные транспортные средства: " << getArrRegTransports();
		//СПИСОК ТРАНСПОРТА
		//std::cout << 1 << ". " << "Название";
		//std::cout << 0 << ". " << "Закончить регистрацию";
		//std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
		//int selTransport;
		//std::cin >> selTransport;
		//РЕГИСТРАЦИЯ
		break;
	} while (!isRegisterTransport);

	//std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!";
}

void GameManager::deleteTransport() {
	//std::cout << "Название" << " успешно исключен из списка!";

	bool isRegisterTransport = false;
	bool newTransport = false;
	do {
		std::system("cls");
		if (newTransport && countTransports > 0)
			std::cout << getNameLastTransport() << " успешно зарегистрирован!";
		std::cout << "Гонка для " << getNameTypeRace()
			<< " транспорта. Расстояние: " << lengthRace << std::endl;
		if (countTransports > 0)
			std::cout << "Зарегистрированные транспортные средства: " << getArrRegTransports();
		//СПИСОК ТРАНСПОРТА
		//std::cout << 1 << ". " << "Название";
		//std::cout << 0 << ". " << "Закончить регистрацию";
		//std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
		//int selTransport;
		//std::cin >> selTransport;
		//РЕГИСТРАЦИЯ
		break;
	} while (!isRegisterTransport);

	//std::cout << "Попытка удалить неправильный тип транспортного средства!";
}

void GameManager::startRace() {
	lib::startRace(m_race);
	std::cout << "Гонка завершена!\n";
}

void GameManager::showResults() {
	system("cls");
	const char* results = lib::getResults(m_race);
	std::cout << "Результат гонки:\n" << results << "\n";
	lib::freeResult(results); // освобождаем память, выделенную в DLL

	std::cout << "\n1. Провести ещё одну гонку\n";
	std::cout << "2. Выйти\n";
	std::cout << "Выберите действие: ";
	int choice = 0;
	do {
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (choice == 1) {
			activeGame = true;
			break;
		}
		else if (choice == 2) {
			activeGame = false;
			break;
		}
		else {
			std::cout << "Неверный выбор. Повторите: ";
		}
	} while (true);
}

std::string GameManager::getTypeName() const {
	switch (typeRace) {
	case TypeRace::GROUND: return "наземного";
	case TypeRace::AERIAL: return "воздушного";
	case TypeRace::GROUND_AND_AERIAL: return "наземного и воздушного";
	default: return "неизвестного";
	}
}

void GameManager::printAvailableVehicles() const {
	//for (size_t i = 0; i < availableNames.size(); ++i) {
	//	std::cout << i + 1 << ". " << availableNames[i] << "\n";
	//}
}