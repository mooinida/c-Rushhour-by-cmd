#pragma once
#include <iostream>
#include <conio.h>
#include "Consola.h"
#include "startView.h"
#include <Windows.h>

//#include "firstView.h"
//#include "firstModel.h"
using namespace std;
class startModel
{
public:
	int getKey() {
		int ch = _getch();
		return (ch != 0xe0) ? ch : (0x000 | _getch());
	}

};

