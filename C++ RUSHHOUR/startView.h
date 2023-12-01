#pragma once
#include <iostream>
#include <conio.h>
#include "Consola.h"
#include <Windows.h>

#include "firstView.h"
//#include "firstController.h"
using namespace std;
class startView
{

public:
	void showTitle() {
		_setcursortype(_NOCURSOR);

		cout << endl << endl << endl << endl; gotoxy(30, 5);
		cout << "ooooo o   o ooooo o   o o   o ooooo o   o ooooo " << endl; gotoxy(30, 6);
		cout << "o   o o   o o     o   o o   o o   o o   o o   o " << endl; gotoxy(30, 7);
		cout << "o   o o   o o     o   o o   o o   o o   o o   o " << endl; gotoxy(30, 8);
		cout << "o   o o   o o     o   o o   o o   o o   o o   o " << endl; gotoxy(30, 9);
		cout << "ooooo o   o ooooo ooooo ooooo o   o o   o ooooo " << endl; gotoxy(30, 10);
		cout << "oo    o   o     o o   o o   o o   o o   o oo    " << endl; gotoxy(30, 11);
		cout << "o o   o   o     o o   o o   o o   o o   o o o   " << endl; gotoxy(30, 12);
		cout << "o  o  o   o     o o   o o   o o   o o   o o  o  " << endl; gotoxy(30, 13);
		cout << "o   o o   o     o o   o o   o o   o o   o o   o " << endl; gotoxy(30, 14);
		cout << "o   o ooooo ooooo o   o o   o ooooo ooooo o   o " << endl;
	}
	void showStart() {
		gotoxy(30, 16);
		cout << "                    1. START                         " << endl;
		gotoxy(30, 18);
		cout << "                    2. HOW                           " << endl;
		gotoxy(30, 20);
		cout << "                    3. END                           " << endl;

	}

	int goNext(int i) {
		if (i == 49) {
			system("cls");
			///cout << "게임이 시작됩니다.";
			//Sleep(1000);
			//system("cls");
			//cout << " 화면이 넘어간다!";
			return i;
		}
		else if (i == 50) {
			system("cls");

			return 50;
		}
		else {
			system("cls");
			cout << "End...";
			exit;
			return 0;

		}

	}

};

