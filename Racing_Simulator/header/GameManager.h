#pragma once
#include <Vehicle.h>
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
	Vehicle** transports;
	unsigned int countTransports;

public:
	GameManager();
	~GameManager();

	void run();
	void selectTypeRace();
	void enterLengthRace();
	void actionRace();
	void registerTransport();
	std::string getNameLastTransport();
	std::string getNameTypeRace();
	std::string getArrRegTransports();
	void deleteTransport();
	void race();
	void resultRace();
};
