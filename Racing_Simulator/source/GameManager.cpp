#include "GameManager.h"

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

void GameManager::run() {
	do {
		selectTypeRace();
		enterLengthRace();
		actionRace();
		race();
		resultRace();
	} while (!activeGame);
}

void GameManager::selectTypeRace() {
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	std::cout << "1. Гонка для наземного транспорта\n";
	std::cout << "2. Гонка для воздушного транспорта\n";
	std::cout << "3. Гонка для наземного и воздушного транспорта\n";
	bool isSelectTypeRace = false;
	do {
		std::cout << "Выберите тип гонки: ";
		int num = 0;
		std::cin >> num;
		if ((num > 0) && (num <= 3))
		{
			typeRace = static_cast<TypeRace>(num);
			isSelectTypeRace = true;
		}
		else {
			std::cout << "Введен неверный тип гонки" << std::endl;
		}
	} while (!isSelectTypeRace);
}

void GameManager::enterLengthRace() {
	std::system("cls");
	std::cout << "Укажите длину дистанции (должна быть положительная): ";
	bool isEnterLengthRace = false;
	do {
		int len = 0;
		std::cin >> len;
		if ((len > 0) && (len <= std::numeric_limits<int>::max()))
		{
			lengthRace = len;
			isEnterLengthRace = true;
		}
		else {
			std::cout << "Введен неверное расстояние" << std::endl;
		}
	} while (!isEnterLengthRace);
}

void GameManager::actionRace() {
	bool isActionRace = false;
	do {
		std::system("cls");
		std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства\n";
		std::cout << "1. Зарегистрировать транспорт\n";
		if (countTransports > 0) std::cout << "2. Убрать транспорт\n";
		if (countTransports >= 2) std::cout << "3. Начать гонку\n";
		std::cout << "Выберите действие: ";
		int action = 0;
		std::cin >> action;
		switch (action)
		{
		case 1: // Зарегистрировать транспорт
			registerTransport();
			break;
		case 2: // Убрать транспорт
			if (countTransports > 0) {
				deleteTransport();
			}
			else std::cout << "Выбрано не верное действие" << std::endl;
			break;
		case 3: // Начать гонку
			if (countTransports >= 2) {
				isActionRace = true;
			}
			else std::cout << "Выбрано не верное действие" << std::endl;
			break;
		default:
			std::cout << "Выбрано не верное действие" << std::endl;
			break;
		}
	} while (!isActionRace);
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

void GameManager::race() {

}

void GameManager::resultRace() {
	//std::cout << "Результат гонки:\n";
	//std::cout << 1 << ". " << "Название" << ". Время: " << 111 << std::endl;

	//std::cout << "4. Провести ещё одну гонку\n";
	//std::cout << "5. Выйти\n";
	//std::cout << "Выберите действие: ";
}

std::string GameManager::getNameLastTransport() {
	return "";
}

std::string GameManager::getNameTypeRace() {
	return "";
}

std::string GameManager::getArrRegTransports() {
	return "";
}