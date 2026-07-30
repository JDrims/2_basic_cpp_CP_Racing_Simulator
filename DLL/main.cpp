#include <iostream>

#ifdef LIB_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

int DLL_API main() {

	return 0;
}