#include <Windows.h>
#include <GameManager.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GameManager game;
	game.run();

	return 0;
}