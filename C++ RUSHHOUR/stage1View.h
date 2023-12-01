#pragma once
#include <iostream>
#include "Consola.h"
using namespace std;
class stage1View
{
public:
	void xyputc(int x, int y, const char* c) {
		gotoxy(x, y);
		cout << c;
	}
	void xyputn(int x, int y,int num) {
		gotoxy(x, y);
		cout << num;
	}
	void xyputstr(int x, int y, const char* str) {
		gotoxy(x, y);
		while (*str) {
			cout << *str;
			str++;
		}

	}
	void fillbox(int x1, int y1, int x2, int y2, int color) {
		textbackground(color);
		for (int row = y1; row < y2; row++)
			for (int col = x1; col < x2; col++)
				xyputc(col, row, " ");

	}
	void fillwordbox(int x1, int y1, int x2, int y2, const char* c1, const char* c2) {
		textbackground(YELLOW);
		for (int row = y1; row < y2; row++)
			for (int col = x1; col < x2; col++) {
				if (row % 2 == 0 && col % 2 == 0)xyputc(col, row, c1);
				else if (row % 2 == 1 && col % 2 == 0)xyputc(col, row, c1);
				else xyputc(col, row, c2);
			}

	}
	void checktcnt(int cnt,int t,int score){
		clrscr();
		gotoxy(20, 10);
		cout << "소요 시간 : "<<t;
		gotoxy(20, 11);
		cout << "움직인 횟수 : " << cnt;
		gotoxy(20, 12);
		cout << "Stage 등급 : " << score;
	}
};

