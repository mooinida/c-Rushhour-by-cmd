#pragma once
#include <iostream>
#include <conio.h>
#include "Consola.h"
#include <Windows.h>
using namespace std;
class firstView
{
public:

	void howtoplay() {
		cout << "되돌아가려면 2를 누르시오." << endl;
		setsizexy(100, 100);
		gotoxy(30, 10);
		cout << "------------- 사용 설명서 -------------"; gotoxy(30, 11);
		cout << "-----O버튼으로 ORANGE상자 이동 가능----"; gotoxy(30, 12);
		cout << "-----R버튼으로 RED상자 이동 가능-------"; gotoxy(30, 13);
		cout << "-----B버튼으로 BLUE상자 이동 가능------"; gotoxy(30, 14);
		cout << "-----G버튼으로 GREEN상자 이동 가능-----"; gotoxy(30, 15);
		cout << "-----Y버튼으로 YELLOW상자 이동 가능----"; gotoxy(30, 16);
		cout << "-----C버튼으로 CYAN상자 이동 가능------";
	}
};

