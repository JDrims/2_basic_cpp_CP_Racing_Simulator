#pragma once
#include "RaceAPI.h"
#include <iostream>
#include <string>

enum class TypeRace {
	GROUND = 1,
	AERIAL = 2,
	GROUND_AND_AERIAL = 3
};

class GameManager
{
	bool activeGame;
	TypeRace typeRace;
	unsigned int lengthRace;

	void* m_race;
	//std::vector<std::string> availableNames;

	void selectTypeRace();
	void enterLengthRace();
	void actionRace();
	void registerTransport();
	void deleteTransport();
	void startRace();
	void showResults();

	std::string getTypeName() const;
	void printAvailableVehicles() const;

public:
	GameManager();
	~GameManager();

	void run();
};
