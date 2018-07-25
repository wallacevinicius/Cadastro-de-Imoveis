#include "clear.h"
#ifdef __unix__         
	#include <unistd.h>
	#include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32) 
	#define OS_Windows
	#include <windows.h>
#endif

void Clear() {
	#ifdef OS_Windows
	/* Codigo Windows */
	system("cls");
	#else
	/* Codigo GNU/Linux */
	system("clear");
	#endif    
}