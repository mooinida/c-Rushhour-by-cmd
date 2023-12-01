#pragma once
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include "Consola.h"
#include "startModel.h"
#include "startView.h"
#include <Windows.h>
#include "firstView.h";
#include "firstModel.h"
#include "stage1Model.h"
#include "stage1View.h"
#include "stage2Model.h"
#include "stage3Model.h"
#include "ctime";//시간 측정에 활용할 것.




using namespace std;
class startControll
{
	startModel* model;
	startView* view;
	firstModel* fModel;
	firstView* fView;
	stage1Model* s1Model;
	stage1View* s1View;
	stage2Model* s2Model;
	stage3Model* s3Model;
	int key;
	int firstpagekey;
public:
	startControll() {
		model = new startModel;
		view = new startView;
		fModel = new firstModel;
		fView = new firstView;
		s1View = new stage1View;
		s1Model = new stage1Model;
		s2Model = new stage2Model;
		s3Model = new stage3Model;

	}
	~startControll() {
		delete model;
		delete view;
		delete fModel;
		delete fView;
		delete s1View;
		delete s1Model;
		delete s2Model;
		delete s3Model;
	}
	void start() {
		Recursive();
		
	}

	
	int Recursive() {
		view->showTitle();
		view->showStart();
		key = model->getKey();
		firstpagekey = view->goNext(key);
		if (firstpagekey == 50) {
			fView->howtoplay();
			fModel->goBack(fModel->getKey());
			return Recursive();
		}
		else if (firstpagekey == 49) {
			cout << "hello" << endl;
		}
		else exit(0);
	}
	int stage1start() {
		textbackground(YELLOW);
		textcolor(BLUE);
		_setcursortype(_NOCURSOR);
		int key, inkey, cnt = 0;
		clrscr();
		s1View->xyputstr(100, 1, "이동 횟수 : ");
		s1View->xyputn(112, 1, cnt);

		int myx = 2, myy = 12;
		int mywidth = 10, myheight = 3;
		s1View->fillwordbox(myx, myy, myx + mywidth, myy + myheight, "m", "y");

		int bx = 5, by = 20; int bwidth = 23, bheight = 8;
		s1View->fillbox(bx, by, bx + bwidth, by + bheight, BLACK);

		int redx = 40, redy = 8; int redwidth = 7, redheight = 13;
		s1View->fillbox(redx, redy, redx + redwidth, redy + redheight, RED);
		
		
		textcolor(BLACK);
		int nx = 14,ny = 2; int nwidth = 7, nheight = 12;
		s1View->fillwordbox(nx, ny, nx + nwidth, ny + nheight, "N","O");

		int cx = 25, cy = 2; int cwidth = 30, cheight = 5;
		s1View->fillbox(cx, cy, cx + cwidth, cy + cheight, CYAN);

		int lgx = 50, lgy = 10; int lgwidth = 15, lgheight = 5;
		s1View->fillbox(lgx, lgy, lgx + lgwidth, lgy + lgheight,LIGHTGRAY);

		int gx = 50, gy = 16; int gwidth = 15, gheight = 14;
		s1View->fillbox(gx, gy, gx + gwidth, gy + gheight, GREEN);

		textcolor(BLUE);
		textbackground(YELLOW);
		s1View->xyputstr(80,13, "도착");

		time_t start, finish;
		double duration;

		start = time(NULL);
		
		while (!(myx == 70 && myy == 12)) {
			key = s1Model->getaKey();
			if (key == 97) {//a를 누르면...x를 누르기 전까지 a의 좌표를 변하게 할 수 있다...... 그럴려면 if문안에서 while문을 또 돌려야한다..
				s1View->xyputstr(100,2,"Control - 나의 말");
				textbackground(YELLOW);
				textcolor(BLUE);
				do {
					int oldx = myx;
					int oldy = myy;
					inkey = s1Model->getKey();
					
					s1Model->mySwitchBBmy(inkey,myx, myy, mywidth, myheight,bx,by, bwidth, bheight, redx, redy, redwidth, redheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight);
					
					
					if (oldx != myx || oldy != myy) {

						s1View->fillwordbox(oldx, oldy, oldx + mywidth, oldy + myheight, " ", " ");
						if (myx % 2 == 0)s1View->fillwordbox(myx, myy, myx + mywidth, myy + myheight, "m", "y");
						else s1View->fillwordbox(myx, myy, myx + mywidth, myy + myheight, "y", "m");
						cnt++;
						s1View->xyputstr(100, 1, "이동 횟수 : ");
						s1View->xyputn(112, 1, cnt);
					}
				} while (inkey != 120 && !(myx == 70 && myy == 12));
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
				
			}
			else if (key == 98) {//b버튼을 눌렀을 떄 이다. 블랙상자가 선택됨
				
				s1View->xyputstr(100, 2, "Control - 검은 상자");
				textbackground(YELLOW);
				do {
					int oldx = bx;
					int oldy = by;
					inkey = s1Model->getKey();

					s1Model->mySwitchBBleftright(inkey, bx, by, bwidth, bheight, myx, myy, mywidth, myheight, redx, redy, redwidth, redheight,
						nx,ny,nwidth,nheight,cx,cy,cwidth,cheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight);
					if (oldx != bx || oldy != by) {

						s1View->fillbox(oldx, oldy, oldx+bwidth, oldy + bheight, YELLOW);
						textbackground(YELLOW);
						s1View->fillbox(bx, by, bx + bwidth, by + bheight, BLACK);
						textbackground(YELLOW);
						
					}
					textbackground(YELLOW);
				} while (inkey != 120 );
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

			}
			else if (key == 114) {//r버튼을 눌렀을 떄 이다. 빨간상자가 선택됨

				s1View->xyputstr(100, 2, "Control - 빨간 상자");
				textbackground(YELLOW);
				do {
					int oldx = redx;
					int oldy = redy;
					inkey = s1Model->getKey();

					s1Model->mySwitchBBupdown(inkey, redx, redy, redwidth, redheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight);
					if (oldx != redx || oldy != redy) {

						s1View->fillbox(oldx, oldy, oldx + redwidth, oldy + redheight, YELLOW);
						textbackground(YELLOW);
						s1View->fillbox(redx, redy, redx + redwidth, redy + redheight, RED);
						textbackground(YELLOW);

					}
					textbackground(YELLOW);
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

			}
			else if (key == 99) {//c버튼을 눌렀을 떄 이다. cyan색 상자가 선택됨

				s1View->xyputstr(100, 2, "Control - CYAN 상자");
				textbackground(YELLOW);
				do {
					int oldx = cx;
					int oldy = cy;
					inkey = s1Model->getKey();

					s1Model->mySwitchBBleftright(inkey, cx, cy, cwidth, cheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
						nx, ny, nwidth, nheight, redx, redy, redwidth, redheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight);
					if (oldx != cx || oldy != cy) {

						s1View->fillbox(oldx, oldy, oldx + cwidth, oldy + cheight, YELLOW);
						textbackground(YELLOW);
						s1View->fillbox(cx, cy, cx + cwidth, cy + cheight, CYAN);
						textbackground(YELLOW);

					}
					textbackground(YELLOW);
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

			}
			else if (key == 110) {//N버튼을 눌렀을 떄 이다. NO 상자가 선택됨

				s1View->xyputstr(100, 2, "Control - NO 상자");
				textbackground(YELLOW);
				do {
					int oldx = nx;
					int oldy = ny;
					inkey = s1Model->getKey();

					s1Model->mySwitchBBupdown(inkey, nx, ny, nwidth, nheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
						cx, cy, cwidth, cheight, redx, redy, redwidth, redheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight);
					if (oldx != nx || oldy != ny) {
						textcolor(BLACK);
						s1View->fillwordbox(oldx, oldy, oldx + nwidth, oldy + nheight, " "," ");
						textbackground(YELLOW);
						s1View->fillwordbox(nx, ny, nx + nwidth, ny + nheight, "N", "O");
						textbackground(YELLOW);

					}
					textbackground(YELLOW);
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

				}
			else if (key == 100) {//d버튼을 눌렀을 떄 이다. lightgray 상자가 선택됨

					s1View->xyputstr(100, 2, "Control - 회색 상자");
					textbackground(YELLOW);
					do {
						int oldx = lgx;
						int oldy = lgy;
						inkey = s1Model->getKey();

						s1Model->mySwitchBBupdown(inkey, lgx, lgy, lgwidth, lgheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
							cx, cy, cwidth, cheight, redx, redy, redwidth, redheight, nx, ny, nwidth, nheight, gx, gy, gwidth, gheight);
						if (oldx != lgx || oldy != lgy) {
							textcolor(BLACK);
							s1View->fillbox(oldx, oldy, oldx + lgwidth, oldy + lgheight, YELLOW);
							textbackground(YELLOW);
							s1View->fillbox(lgx, lgy, lgx + lgwidth, lgy + lgheight, LIGHTGRAY);
							textbackground(YELLOW);

						}
						textbackground(YELLOW);
					} while (inkey != 120);
					//inkey가 x가 눌리면 do while문이 풀린다. 
					s1View->xyputstr(100, 2, "Control -           ");

					}
			else if (key == 103) {//g버튼을 눌렀을 떄 이다. green 상자가 선택됨

						s1View->xyputstr(100, 2, "Control - 초록 상자");
						textbackground(YELLOW);
						do {
							int oldx = gx;
							int oldy = gy;
							inkey = s1Model->getKey();

							s1Model->mySwitchBBupdown(inkey, gx, gy, gwidth, gheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
								cx, cy, cwidth, cheight, redx, redy, redwidth, redheight, nx, ny, nwidth, nheight, lgx, lgy, lgwidth, lgheight);
							if (oldx != gx || oldy != gy) {
								textcolor(BLACK);
								s1View->fillbox(oldx, oldy, oldx + gwidth, oldy + gheight, YELLOW);
								textbackground(YELLOW);
								s1View->fillbox(gx, gy, gx + gwidth, gy + gheight, GREEN);
								textbackground(YELLOW);

							}
							textbackground(YELLOW);
						} while (inkey != 120);
						//inkey가 x가 눌리면 do while문이 풀린다. 
						s1View->xyputstr(100, 2, "Control -           ");

						}
		}
		finish = time(NULL);
		duration = (double)(finish - start);
		clrscr();
		
		s1View->checktcnt( cnt, duration,s1Model->level(duration,cnt));
		Sleep(10000);
		textcolor(WHITE);
		return 0;
	}
	int stage2start() {
		textbackground(YELLOW);
		textcolor(BLUE);
		_setcursortype(_NOCURSOR);
		int key, inkey, cnt = 0;
		clrscr();
		s1View->xyputstr(100, 1, "이동 횟수 : ");
		s1View->xyputn(112, 1, cnt);

		int myx = 2, myy = 10;
		int mywidth = 10, myheight = 3;
		s1View->fillwordbox(myx, myy, myx + mywidth, myy + myheight, "m", "y");

		int bx = 57, by = 16; int bwidth = 18, bheight = 4;
		s1View->fillbox(bx, by, bx + bwidth, by + bheight, BLACK);
		int bx1 = 39, by1 = 20; int b1width = 36, b1height = 8;
		s1View->fillbox(bx1, by1, bx1 + b1width, by1 + b1height, BLACK);

		int redx = 25, redy = 8; int redwidth = 16, redheight = 3;
		s1View->fillbox(redx, redy, redx + redwidth, redy + redheight, RED);
		int redx1 = 33, redy1 = 11; int red1width = 8, red1height = 3;
		s1View->fillbox(redx1, redy1, redx1 + red1width, redy1 + red1height, RED);

		textcolor(BLACK);
		int nx = 25, ny = 18; int nwidth = 7, nheight = 10;
		s1View->fillwordbox(nx, ny, nx + nwidth, ny + nheight, "O", "N");

		int cx = 25, cy = 2; int cwidth = 50, cheight = 5;
		s1View->fillbox(cx, cy, cx + cwidth, cy + cheight, CYAN);

		int lgx = 14, lgy =2; int lgwidth = 10, lgheight = 13;
		s1View->fillbox(lgx, lgy, lgx + lgwidth, lgy + lgheight, LIGHTGRAY);

		int gx = 42, gy = 8; int gwidth = 18, gheight = 6;
		s1View->fillbox(gx, gy, gx + gwidth, gy + gheight, GREEN);

		textcolor(BLUE);
		textbackground(YELLOW);
		s1View->xyputstr(80, 11, "도착");

		time_t start, finish;
		double duration;

		start = time(NULL);

		while (!(myx == 70 && myy == 10)) {
			key = s1Model->getaKey();
			if (key == 97) {//a를 누르면...x를 누르기 전까지 a의 좌표를 변하게 할 수 있다...... 그럴려면 if문안에서 while문을 또 돌려야한다..
				s1View->xyputstr(100, 2, "Control - 나의 말");
				textbackground(YELLOW);
				textcolor(BLUE);
				do {
					int oldx = myx;
					int oldy = myy;
					inkey = s1Model->getKey();

					s1Model->mySwitchBBmy(inkey, myx, myy, mywidth, myheight, bx, by, bwidth, bheight, redx, redy, redwidth, redheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight);


					if (oldx != myx || oldy != myy) {

						s1View->fillwordbox(oldx, oldy, oldx + mywidth, oldy + myheight, " ", " ");
						if (myx % 2 == 0)s1View->fillwordbox(myx, myy, myx + mywidth, myy + myheight, "m", "y");
						else s1View->fillwordbox(myx, myy, myx + mywidth, myy + myheight, "y", "m");
						cnt++;
						s1View->xyputstr(100, 1, "이동 횟수 : ");
						s1View->xyputn(112, 1, cnt);
					}
				} while (inkey != 120 && !(myx == 70 && myy == 10));
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");

			}
			else if (key == 98) {//b버튼을 눌렀을 떄 이다. 블랙상자가 선택됨

				s1View->xyputstr(100, 2, "Control - 검은 상자");
				textbackground(YELLOW);
				do {
					int oldx = bx;
					int oldy = by;
					int oldx1 = bx1;
					int oldy1 = by1;
					inkey = s1Model->getKey();

					s2Model->mySwitchBBleftright(inkey, bx, by, bwidth, bheight, redx, redy, redwidth, redheight,
						myx, myy, mywidth, myheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight,
						bx1, by1, b1width, b1height,redx1, redy1, red1width, red1height);
					if (oldx != bx || oldy != by|| oldx1 != bx1 || oldy1 != by1) {

						s1View->fillbox(oldx, oldy, oldx + bwidth, oldy + bheight, YELLOW);
						s1View->fillbox(oldx1, oldy1, oldx1 + b1width, oldy1 + b1height, YELLOW);
						textbackground(YELLOW);
						s1View->fillbox(bx, by, bx + bwidth, by + bheight, BLACK);
						s1View->fillbox(bx1, by1, bx1 + b1width, by1 + b1height, BLACK);
						textbackground(YELLOW);

					}
					textbackground(YELLOW);
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

			}
			else if (key == 114) {//r버튼을 눌렀을 떄 이다. 빨간상자가 선택됨

				s1View->xyputstr(100, 2, "Control - 빨간 상자");
				textbackground(YELLOW);
				do {
					int oldx = redx;
					int oldy = redy;
					int oldx1 = redx1;
					int oldy1 = redy1;
					inkey = s1Model->getKey();

					s2Model->mySwitchBBupdown(inkey, redx, redy, redwidth, redheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight,
						redx1, redy1, red1width, red1height, bx1, by1, b1width, b1height);
					if (oldx != redx || oldy != redy || oldx1 != redx1 || oldy1 != redy1) {

						s1View->fillbox(oldx, oldy, oldx + redwidth, oldy + redheight, YELLOW);
						s1View->fillbox(oldx1, oldy1, oldx1 + red1width, oldy1 + red1height, YELLOW);
						textbackground(YELLOW);
						s1View->fillbox(redx, redy, redx + redwidth, redy + redheight, RED);
						s1View->fillbox(redx1, redy1, redx1 + red1width, redy1 + red1height, RED);
						textbackground(YELLOW);

					}
					textbackground(YELLOW);
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

			}
			else if (key == 99) {//c버튼을 눌렀을 떄 이다. cyan색 상자가 선택됨

				s1View->xyputstr(100, 2, "Control - CYAN 상자");
				textbackground(YELLOW);
				do {
					int oldx = cx;
					int oldy = cy;
					inkey = s1Model->getKey();

					s1Model->mySwitchBBleftright(inkey, cx, cy, cwidth, cheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
						nx, ny, nwidth, nheight, redx, redy, redwidth, redheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight);
					if (oldx != cx || oldy != cy) {

						s1View->fillbox(oldx, oldy, oldx + cwidth, oldy + cheight, YELLOW);
						textbackground(YELLOW);
						s1View->fillbox(cx, cy, cx + cwidth, cy + cheight, CYAN);
						textbackground(YELLOW);

					}
					textbackground(YELLOW);
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

			}
			else if (key == 110) {//N버튼을 눌렀을 떄 이다. NO 상자가 선택됨

				s1View->xyputstr(100, 2, "Control - NO 상자");
				textbackground(YELLOW);
				do {
					int oldx = nx;
					int oldy = ny;
					inkey = s1Model->getKey();

					s1Model->mySwitchBBupdown(inkey, nx, ny, nwidth, nheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
						cx, cy, cwidth, cheight, redx, redy, redwidth, redheight, lgx, lgy, lgwidth, lgheight, gx, gy, gwidth, gheight);
					if (oldx != nx || oldy != ny) {
						textcolor(BLACK);
						s1View->fillwordbox(oldx, oldy, oldx + nwidth, oldy + nheight, " ", " ");
						textbackground(YELLOW);
						s1View->fillwordbox(nx, ny, nx + nwidth, ny + nheight, "N", "O");
						textbackground(YELLOW);

					}
					textbackground(YELLOW);
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

			}
			else if (key == 100) {//d버튼을 눌렀을 떄 이다. lightgray 상자가 선택됨

				s1View->xyputstr(100, 2, "Control - 회색 상자");
				textbackground(YELLOW);
				do {
					int oldx = lgx;
					int oldy = lgy;
					inkey = s1Model->getKey();

					s2Model->mySwitchBBupdownforgg(inkey, lgx, lgy, lgwidth, lgheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
						cx, cy, cwidth, cheight, redx, redy, redwidth, redheight, nx, ny, nwidth, nheight, gx, gy, gwidth, gheight,
						bx1, by1, b1width, b1height);
					if (oldx != lgx || oldy != lgy) {
						textcolor(BLACK);
						s1View->fillbox(oldx, oldy, oldx + lgwidth, oldy + lgheight, YELLOW);
						textbackground(YELLOW);
						s1View->fillbox(lgx, lgy, lgx + lgwidth, lgy + lgheight, LIGHTGRAY);
						textbackground(YELLOW);

					}
					textbackground(YELLOW);
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

			}
			else if (key == 103) {//g버튼을 눌렀을 떄 이다. green 상자가 선택됨

				s1View->xyputstr(100, 2, "Control - 초록 상자");
				textbackground(YELLOW);
				do {
					int oldx = gx;
					int oldy = gy;
					inkey = s1Model->getKey();

					s2Model->mySwitchBBupdownforgg(inkey, gx, gy, gwidth, gheight, bx, by, bwidth, bheight, myx, myy, mywidth, myheight,
						cx, cy, cwidth, cheight, redx, redy, redwidth, redheight, nx, ny, nwidth, nheight, lgx, lgy, lgwidth, lgheight,
						bx1, by1, b1width, b1height);
					if (oldx != gx || oldy != gy) {
						textcolor(BLACK);
						s1View->fillbox(oldx, oldy, oldx + gwidth, oldy + gheight, YELLOW);
						textbackground(YELLOW);
						s1View->fillbox(gx, gy, gx + gwidth, gy + gheight, GREEN);
						textbackground(YELLOW);

					}
					textbackground(YELLOW);
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 
				s1View->xyputstr(100, 2, "Control -           ");

			}
		}
		finish = time(NULL);
		duration = (double)(finish - start);
		clrscr();

		s1View->checktcnt(cnt, duration, s1Model->level(duration, cnt));
		Sleep(10000);
		textcolor(WHITE);
		return 0;
	}
	int stage3start() {
		textbackground(YELLOW);
		textcolor(BLUE);
		_setcursortype(_NOCURSOR);
		int key, inkey, cnt = 0;
		clrscr();
		s1View->xyputstr(100, 1, "이동 횟수 : ");
		s1View->xyputn(112, 1, cnt);

		int myx = 2, myy = 12;
		int mywidth = 20, myheight = 5;
		s1View->fillwordbox(myx, myy, myx + mywidth, myy + myheight, "m", "y");

		int bx = 2, by = 17; int bwidth = 20, bheight = 5;
		s1View->fillbox(bx, by, bx + bwidth, by + bheight, BLACK);
		int cx = 2, cy = 22; int cwidth = 20, cheight = 5;
		s1View->fillbox(cx, cy, cx + cwidth, cy + cheight, CYAN);

		int redx = 22, redy = 12; int redwidth = 10, redheight = 10;
		s1View->fillbox(redx, redy, redx + redwidth, redy + redheight, RED);

		int sx = 22, sy = 7; int swidth = 20, sheight = 5;
		s1View->fillbox(sx, sy, sx + swidth, sy + sheight, MAGENTA);

		textcolor(MAGENTA);
		int qx = 32, qy = 12; int qwidth = 10, qheight = 10;
		s1View->fillwordbox(qx, qy, qx + qwidth, qy + qheight, "Q", "Q");

		textcolor(BLUE);
		int wx = 32, wy = 22; int wwidth = 30, wheight = 5;
		s1View->fillwordbox(wx, wy, wx + wwidth, wy + wheight, "W", "W");

		textcolor(BLACK);
		int ex = 42, ey = 17; int ewidth = 20, eheight = 5;
		s1View->fillwordbox(ex, ey, ex + ewidth, ey + eheight, "E", "E");

		textcolor(GREEN);
		int nx = 22, ny = 12; int nwidth = 10, nheight = 10;
		s1View->fillwordbox(nx, ny, nx + nwidth, ny + nheight, "N", "O");

		int lgx = 42, lgy = 7; int lgwidth = 10, lgheight = 10;
		s1View->fillbox(lgx, lgy, lgx + lgwidth, lgy + lgheight, LIGHTGRAY);
	
		int gx = 52, gy = 2; int gwidth = 10, gheight = 12;
		s1View->fillbox(gx, gy, gx + gwidth, gy + gheight, GREEN);

		int rx = 22, ry = 22; int rwidth = 10, rheight = 5;
		s1View->fillbox(rx, ry, rx + rwidth, ry + rheight, RED);

		textcolor(BLUE);
		textbackground(YELLOW);
		s1View->xyputstr(80, 13, "도착");

		time_t start, finish;
		double duration;

		start = time(NULL);
		while (!(myx == 66 && myy == 12)) {
			key = s1Model->getaKey();
			if (key == 97) {//a를 눌렀을때
				s1View->xyputstr(100, 2, "Control - 내 말");
				textbackground(YELLOW);
				textcolor(BLUE);
				do {
					int oldx = myx;
					int oldy = myy;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBleftright(inkey, myx, myy, mywidth, myheight, wx, wy, wwidth, wheight, bx, by, bwidth, bheight, rx, ry, rwidth, rheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight,
						gx, gy, gwidth, gheight, sx, sy, swidth, sheight, qx, qy, qwidth, qheight,
						ex, ey, ewidth, eheight);


					if (oldx != myx || oldy != myy) {
						s1View->fillwordbox(oldx, oldy, oldx + mywidth, oldy + myheight, " ", " ");
						if (myx % 2 == 0)s1View->fillwordbox(myx, myy, myx + mywidth, myy + myheight, "m", "y");
						else s1View->fillwordbox(myx, myy, myx + mywidth, myy + myheight, "y", "m");
						cnt++;
						s1View->xyputstr(100, 1, "이동 횟수 : ");
						s1View->xyputn(112, 1, cnt);
					}
				} while (inkey != 120 && !(myx == 66 && myy == 12));
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
			}
			else if (key == 115) {//s를 눌렀을때
				s1View->xyputstr(100, 2, "Control - 마젠타색 말");
				textbackground(YELLOW);
				textcolor(BLUE);
				do {
					int oldx = sx;
					int oldy = sy;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBleftright(inkey, sx, sy, swidth, sheight, bx, by, bwidth, bheight, rx, ry, rwidth, rheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight,
						gx, gy, gwidth, gheight, wx, wy, wwidth, wheight, qx, qy, qwidth, qheight,
						myx, myy, mywidth, myheight, ex, ey, ewidth, eheight);


					if (oldx != sx || oldy != sy) {

						s1View->fillbox(oldx, oldy, oldx + swidth, oldy + sheight, YELLOW);

						s1View->fillbox(sx, sy, sx + swidth, sy + sheight, MAGENTA);

					}
				} while (inkey != 120 && !(myx == 70 && myy == 12)); textbackground(YELLOW);
				textcolor(BLUE);
				
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
			}
			else if (key == 119) {//w를 눌렀을때
				s1View->xyputstr(100, 2, "Control - W 상자");
				textbackground(YELLOW);
				textcolor(BLUE);
				do {
					int oldx = wx;
					int oldy = wy;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBleftright(inkey, wx, wy, wwidth, wheight, bx, by, bwidth, bheight, rx, ry, rwidth, rheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight,
						gx, gy, gwidth, gheight, sx, sy, swidth, sheight, qx, qy, qwidth, qheight,
						myx, myy, mywidth, myheight, ex, ey, ewidth, eheight);


					if (oldx !=wx || oldy != wy) {

						s1View->fillwordbox(oldx, oldy, oldx + wwidth, oldy + wheight, " "," ");

						s1View->fillwordbox(wx, wy, wx + wwidth, wy + wheight, "W","W");

					}
				} while (inkey != 120); textbackground(YELLOW);
				textcolor(BLUE);
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
			}
			else if (key == 101) {//e를 눌렀을때
				s1View->xyputstr(100, 2, "Control - E 상자");
				textbackground(YELLOW);
				textcolor(BLACK);
				do {
					int oldx = ex;
					int oldy = ey;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBleftright(inkey, ex, ey, ewidth, eheight, bx, by, bwidth, bheight, rx, ry, rwidth, rheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight,
						gx, gy, gwidth, gheight, sx, sy, swidth, sheight, qx, qy, qwidth, qheight,
						myx, myy, mywidth, myheight, wx, wy, wwidth, wheight);


					if (oldx !=ex || oldy != ey) {

						s1View->fillwordbox(oldx, oldy, oldx + ewidth, oldy + eheight, " ", " ");

						s1View->fillwordbox(ex, ey, ex + ewidth, ey + eheight, "E", "E");

					}
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
			}
			else if (key == 98) {//b를 눌렀을때
				s1View->xyputstr(100, 2, "Control - 검은 상자");
				textbackground(YELLOW);
				textcolor(BLACK);
				do {
					int oldx = bx;
					int oldy = by;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBleftright(inkey, bx, by, bwidth, bheight, ex, ey, ewidth, eheight, rx, ry, rwidth, rheight,
						nx, ny, nwidth, nheight, cx, cy, cwidth, cheight, lgx, lgy, lgwidth, lgheight,
						gx, gy, gwidth, gheight, sx, sy, swidth, sheight, qx, qy, qwidth, qheight,
						myx, myy, mywidth, myheight, wx, wy, wwidth, wheight);


					if (oldx != bx || oldy != by) {

						
						s1View->fillbox(oldx, oldy, oldx + bwidth, oldy + bheight, YELLOW);

						s1View->fillbox(bx, by, bx + bwidth, by + bheight, BLACK);

					}
				} while (inkey != 120);
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
				}
			else if (key == 99) {//c를 눌렀을때
				s1View->xyputstr(100, 2, "Control - CYAN색 상자");
				textbackground(YELLOW);
				textcolor(BLACK);
				do {
					int oldx = cx;
					int oldy = cy;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBleftright(inkey, cx, cy, cwidth, cheight, bx, by, bwidth, bheight, ex, ey, ewidth, eheight, 
						rx, ry, rwidth, rheight,
						nx, ny, nwidth, nheight, lgx, lgy, lgwidth, lgheight,
						gx, gy, gwidth, gheight, sx, sy, swidth, sheight, qx, qy, qwidth, qheight,
						myx, myy, mywidth, myheight, wx, wy, wwidth, wheight);


					if (oldx != cx || oldy != cy) {


						s1View->fillbox(oldx, oldy, oldx + cwidth, oldy + cheight, YELLOW);

						s1View->fillbox(cx, cy, cx + cwidth, cy + cheight, CYAN);

					}
				} while (inkey != 120);
				textbackground(YELLOW);
				textcolor(BLUE);
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
				}
			else if (key == 103) {//g를 눌렀을때
				s1View->xyputstr(100, 2, "Control - 초록색 상자");
				textbackground(YELLOW);
				textcolor(BLACK);
				do {
					int oldx = gx;
					int oldy = gy;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBupdown(inkey, gx, gy, gwidth, gheight, cx, cy, cwidth, cheight, bx, by, bwidth, bheight, ex, ey, ewidth, eheight,
						rx, ry, rwidth, rheight,
						nx, ny, nwidth, nheight, lgx, lgy, lgwidth, lgheight,
						 sx, sy, swidth, sheight, qx, qy, qwidth, qheight,
						myx, myy, mywidth, myheight, wx, wy, wwidth, wheight);


					if (oldx != gx || oldy != gy) {


						s1View->fillbox(oldx, oldy, oldx + gwidth, oldy + gheight, YELLOW);

						s1View->fillbox(gx, gy,gx + gwidth, gy + gheight,GREEN);

					}
				} while (inkey != 120); textbackground(YELLOW);
				textcolor(BLUE);
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
				}
			else if (key == 100) {//d를 눌렀을때
				s1View->xyputstr(100, 2, "Control - 회색 상자");
				textbackground(YELLOW);
				textcolor(BLACK);
				do {
					int oldx = lgx;
					int oldy = lgy;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBupdown(inkey, lgx, lgy, lgwidth, lgheight, 
						gx, gy, gwidth, gheight, cx, cy, cwidth, cheight, bx, by, bwidth, bheight, ex, ey, ewidth, eheight,
						rx, ry, rwidth, rheight,
						nx, ny, nwidth, nheight, 
						sx, sy, swidth, sheight, qx, qy, qwidth, qheight,
						myx, myy, mywidth, myheight, wx, wy, wwidth, wheight);


					if (oldx != lgx || oldy != lgy) {


						s1View->fillbox(oldx, oldy, oldx + lgwidth, oldy + lgheight,YELLOW);

						s1View->fillbox(lgx, lgy, lgx + lgwidth, lgy + lgheight, LIGHTGRAY);

					}
				} while (inkey != 120);
				textbackground(YELLOW);
				textcolor(BLUE);
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
				}
			else if (key == 114) {//r를 눌렀을때
				s1View->xyputstr(100, 2, "Control - 빨간 상자");
				textbackground(YELLOW);
				textcolor(BLACK);
				do {
					int oldx = rx;
					int oldy = ry;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBupdown(inkey, rx, ry, rwidth, rheight, lgx, lgy, lgwidth, lgheight,
						gx, gy, gwidth, gheight, cx, cy, cwidth, cheight, bx, by, bwidth, bheight, ex, ey, ewidth, eheight,
						
						nx, ny, nwidth, nheight,
						sx, sy, swidth, sheight, qx, qy, qwidth, qheight,
						myx, myy, mywidth, myheight, wx, wy, wwidth, wheight);


					if (oldx != rx || oldy != ry) {


						s1View->fillbox(oldx, oldy, oldx + rwidth, oldy + rheight, YELLOW);

						s1View->fillbox(rx, ry, rx + rwidth, ry + rheight, RED);

					}
				} while (inkey != 120); textcolor(BLACK);
				textbackground(YELLOW);
				textcolor(BLUE);
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
				}
			else if (key == 113) {//q를 눌렀을때
				s1View->xyputstr(100, 2, "Control - Q 상자");
				textbackground(YELLOW);
				textcolor(MAGENTA);
				do {
					int oldx = qx;
					int oldy = qy;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBupdown(inkey, qx, qy, qwidth, qheight, 
						gx, gy, gwidth, gheight, cx, cy, cwidth, cheight, bx, by, bwidth, bheight, ex, ey, ewidth, eheight,
						rx, ry, rwidth, rheight,
						nx, ny, nwidth, nheight, lgx, lgy, lgwidth, lgheight,
						sx, sy, swidth, sheight, 
						myx, myy, mywidth, myheight, wx, wy, wwidth, wheight);


					if (oldx !=qx || oldy != qy) {


						s1View->fillwordbox(oldx, oldy, oldx + qwidth, oldy + qheight, " "," ");

						s1View->fillwordbox(qx, qy, qx + qwidth, qy + qheight, "Q","Q");

					}
				} while (inkey != 120); textbackground(YELLOW);
				textcolor(BLUE);
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
				}
			else if (key == 110) {//n를 눌렀을때
				s1View->xyputstr(100, 2, "Control - NO 상자");
				textbackground(YELLOW);
				textcolor(GREEN);
				do {
					int oldx = nx;
					int oldy = ny;
					inkey = s1Model->getKey();

					s3Model->mySwitchBBupdown(inkey, nx, ny, nwidth, nheight, qx, qy, qwidth, qheight,
						gx, gy, gwidth, gheight, cx, cy, cwidth, cheight, bx, by, bwidth, bheight, ex, ey, ewidth, eheight,
						rx, ry, rwidth, rheight,
						 lgx, lgy, lgwidth, lgheight,
						sx, sy, swidth, sheight,
						myx, myy, mywidth, myheight, wx, wy, wwidth, wheight);


					if (oldx != qx || oldy != qy) {


						s1View->fillwordbox(oldx, oldy, oldx + nwidth, oldy + nheight, " ", " ");

						s1View->fillwordbox(nx, ny,nx + nwidth, ny + nheight, "N","O");

					}
				} while (inkey != 120); textbackground(YELLOW);
				textcolor(BLUE);
				//inkey가 x가 눌리면 do while문이 풀린다. 또한 나의 말이 도착지점에 갔을때 풀린다.
				s1View->xyputstr(100, 2, "Control -           ");
				}
			}
			finish = time(NULL);
			duration = (double)(finish - start);
			clrscr();

			s1View->checktcnt(cnt, duration, s1Model->level(duration, cnt));
			Sleep(10000);
			textcolor(WHITE);
			return 0;
	}
};

