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
		cout << "�ǵ��ư����� 2�� �����ÿ�." << endl;
		setsizexy(100, 100);
		gotoxy(30, 10);
		cout << "------------- ��� ���� -------------"; gotoxy(30, 11);
		cout << "-----O��ư���� ORANGE���� �̵� ����----"; gotoxy(30, 12);
		cout << "-----R��ư���� RED���� �̵� ����-------"; gotoxy(30, 13);
		cout << "-----B��ư���� BLUE���� �̵� ����------"; gotoxy(30, 14);
		cout << "-----G��ư���� GREEN���� �̵� ����-----"; gotoxy(30, 15);
		cout << "-----Y��ư���� YELLOW���� �̵� ����----"; gotoxy(30, 16);
		cout << "-----C��ư���� CYAN���� �̵� ����------";
	}
};

