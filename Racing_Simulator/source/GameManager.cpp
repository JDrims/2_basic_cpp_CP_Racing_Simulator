#include "GameManager.h"
#include <limits>

GameManager::GameManager()
	: activeGame(true)
	, typeRace(tRace::NONE)
	, lengthRace(0)
	, m_race(nullptr) {
}

GameManager::~GameManager() {
	if (m_race) {
		destroyRace(m_race);
		m_race = nullptr;
	}
}

void GameManager::run() {
	while (activeGame) {
		selectTypeRace();
		enterLengthRace();

		if (m_race) {
			destroyRace(m_race);
			m_race = nullptr;
		}
		m_race = createRace(static_cast<int>(typeRace), lengthRace);
		if (!m_race) {
			std::cerr << "Ошибка создания гонки!\n";
			continue;
		}

		bool raceFinished = false;
		while (!raceFinished) {
			raceFinished = actionRace();
		}

		showResults();

		if (m_race) {
			destroyRace(m_race);
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
			continue;
		}
		if (choice >= 1 && choice <= 3) {
			typeRace = static_cast<tRace>(choice);
			break;
		}
		else std::cout << "Введен неверный тип гонки\n";
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

bool GameManager::actionRace() {
	bool exitAction = false;
	bool started = false;
	do {
		system("cls");
		std::cout << "Гонка для " << getTypeName() << " транспорта. Расстояние: " << lengthRace << "\n";
		int count = getVehicleCount(m_race);
		if (count > 0) std::cout << "Зарегистрировано транспортных средств: " << printStrRegVehicles() << "\n";
		if (count < 2) std::cout << "Должно быть зарегистрировано хотя бы 2 ТС.\n";
		std::cout << "1. Зарегистрировать транспорт\n";
		if (count > 0) std::cout << "2. Убрать транспорт\n";
		if (count >= 2) std::cout << "3. Начать гонку\n";
		std::cout << "Выберите действие: ";

		bool exitAction = false;
		do {
			int action = 0;
			std::cin >> action;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Введите число из списка действий: ";
				continue;
			}

			switch (action) {
			case 1:
				registerTransport();
				exitAction = true;
				break;
			case 2:
				if (count > 0) {
					exitAction = true;
					deleteTransport();
				}	
				else std::cout << "Неверное действие\n";
				break;
			case 3:
				if (count >= 2) {
					startRace(m_race);
					exitAction = true;
					started = true;
				}
				else std::cout << "Неверное действие\n";
				break;
			default:
				std::cout << "Неверное действие\n";
			}
		} while (!exitAction);
	} while (!started);
	return started;
}

void GameManager::registerTransport() {
	bool exitAction = false;
	bool isRegVehicle = false;
	int numVehicle = -1;
	do {
		system("cls");
		if (isRegVehicle && numVehicle > 0) std::cout << getNameByNumVehicles(numVehicle) << " успешно зарегистрирован!\n";
		else if (!isRegVehicle && numVehicle > 0) std::cout << "Попытка зарегистрировать неверный тип транспортного средства!\n";

		std::cout << "Гонка для " << getTypeName() << " транспорта. Расстояние: " << lengthRace << "\n";
		int count = getVehicleCount(m_race);
		if (count > 0) std::cout << "Зарегистрировано транспортных средств: " << printStrRegVehicles() << "\n";
		if (count < 2) std::cout << "Должно быть зарегистрировано хотя бы 2 ТС.\n";
		std::cout << "Доступные транспортные средства:\n";
		printAvailableVehicles();
		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

		std::cin >> numVehicle;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (numVehicle) {
		case 0:
			exitAction = true;
			break;
		default:
			isRegVehicle = addVehicle(m_race, numVehicle);
			int count = getVehicleCount(m_race);
			if (count >= 7) {
				exitAction = true;
				break;
			}
		}
	} while (!exitAction);
}

void GameManager::deleteTransport() {
	bool exitAction = false;
	bool isDelVehicle = false;
	int numVehicle = -1;
	while (!exitAction) {
		system("cls");
		if (isDelVehicle && numVehicle > 0) std::cout << getNameByNumVehicles(numVehicle) << " успешно исключён из списка!\n";
		else if (!isDelVehicle && numVehicle > 0) std::cout << "Попытка исключить из списка неверный тип транспортного средства!\n";

		std::cout << "Гонка для " << getTypeName() << " транспорта. Расстояние: " << lengthRace << "\n";
		int count = getVehicleCount(m_race);
		if (count < 2) std::cout << "Должно быть зарегистрировано хотя бы 2 ТС.\n";
		std::cout << "Зарегистрированые транспортные средства:\n";
		printListRegVehicles();
		std::cout << "Выберите транспорт или 0 для окончания процесса редактирования: ";

		std::cin >> numVehicle;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (numVehicle) {
		case 0:
			exitAction = true;
			break;
		default:
			isDelVehicle = removeVehicle(m_race, numVehicle);
		}
	}
}

void GameManager::showResults() {
	bool exitAction = false;
	do {
		system("cls");
		const char* results = getResults(m_race);
		std::cout << "Результат гонки:\n" << results << "\n";
		freeResult(results);

		std::cout << "\n1. Провести ещё одну гонку\n";
		std::cout << "2. Выйти\n";
		std::cout << "Выберите действие: ";
		int choice = 0;

		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		switch (choice)
		{
		case 1:
			activeGame = true;
			exitAction = true;
			break;
		case 2:
			activeGame = false;
			exitAction = true;
			break;
		default:
			std::cout << "Неверный выбор. Повторите: ";
			break;
		}
	} while (!exitAction);
}

std::string GameManager::getTypeName() const {
	switch (static_cast<tRace>(typeRace)) {
	case tRace::GROUND: return "наземного";
	case tRace::AERIAL: return "воздушного";
	case tRace::GROUND_AND_AERIAL : return "наземного и воздушного";
	default: return "неизвестного";
	}
}

void GameManager::printAvailableVehicles() {
	int count = 0;
	const char** names = getAvailableVehicles(count);
	for (int i = 0; i < count; ++i) {
		std::cout << i + 1 << ". " << names[i] << "\n";
	}
	freeAvailableVehicles(names, count);
}

void GameManager::printListRegVehicles() {
	int count = 0;
	const char** names = getRegisteredVehicles(m_race, count);
	if (count == 0) {
		std::cout << "Нет зарегистрированых транспортных средст" << std::endl;
		return;
	}
	for (int i = 0; i < count; ++i) {
		std::cout << i + 1 << ". " << names[i] << "\n";
	}
	freeStringArray(names, count);
}

std::string GameManager::printStrRegVehicles() const {
	int count = 0;
	std::string strNames("");
	const char** names = getRegisteredVehicles(m_race, count);
	for (int i = 0; i < count; ++i) {
		strNames += names[i];
		if (i < count - 1) strNames += ", ";
	}
	freeStringArray(names, count);
	return strNames;
}