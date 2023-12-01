#pragma once
#include <iostream>
#include <conio.h>
#include "Consola.h"
#include <Windows.h>
using namespace std;
class firstModel
{
	int num;
public:
	int getKey() {
		int ch = _getch();
		return (ch != 0xe0) ? ch : (0x000 | _getch());
	}
	void goBack(int i) {
		if (i == 50) {
			system("cls");
		}
	}

};

