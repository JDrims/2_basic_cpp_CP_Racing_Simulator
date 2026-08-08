#pragma once
#include "RaceAPI.h"
#include "TypeDef.h"
#include <iostream>
#include <vector>
#include <string>

class GameManager
{
	bool activeGame;
	tRace typeRace;
	unsigned int lengthRace;

	void* m_race;

	void selectTypeRace();
	void enterLengthRace();
	bool actionRace();
	void registerTransport();
	void deleteTransport();
	void showResults();

	std::string getTypeName() const;
	void printAvailableVehicles();
	void printListRegVehicles();
	std::string printStrRegVehicles() const;

public:
	GameManager();
	~GameManager();

	void run();
};
