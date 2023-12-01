#pragma once
#include <iostream>
#include <conio.h>
#include "Consola.h"
#include <Windows.h>
#include "Key.h"
using namespace std;
class stage2Model
{
private:

public:
    int level(int cnt, int time) {// 스테이지를 깬 레벨이 어느정도 인지를 확인해주려한다.
        int score;
        if (cnt < 80) {
            if (time < 50) { score = 1; }
            else { score = 2; }
        }
        else if (cnt < 90) {
            if (time < 70) { score = 2; }
            else { score = 3; }
        }
        else {
            if (time < 100) { score = 3; }
            else { score = 4; }
        }
        return score;

    }

    int getKey() {//알파벳이나 방향키를 눌렀을 때 쓸거임
        int ch = _getch();
        return (ch != 0xe0) ? ch : (0x000 | _getch());
    }
    int getaKey() {//숫자를 입력했을 때 쓸거임
        int ch = _getch();
        return ch;
    }

    bool checkMeetPB(int px, int py, int bx, int by, int width, int height) {
        return (bx - 1) < px && px < (bx + width) && (by - 1) < py && py < (by + height);
    }//점을 주체로, 상자의 경계와 마주쳤을 때 true 반환
    bool checkMeetBP(int bx, int by, int px, int py, int width, int height) {
        return (px - width) < bx && bx < (px + 1) && (py - height) < by && by < (py + 1);
    }//상자를 주체로, 점과 마주쳤을 때 true 반환
    bool checkMeetBB(int bx, int by, int bwidth, int bheight, int bx1, int by1, int b1width, int b1height) {
        return bx<bx1 + b1width && bx + bwidth>bx1 && by<by1 + b1height && by + bheight>by1;
    }//상자와 상자가 마주쳤을 때 true반환

    void mySwitchBBleftright(int key, int& bx, int& by, int bwidth, int bheight, int& bx1, int& by1, int b1width, int b1height
        , int& bx2, int& by2, int b2width, int b2height, int& bx3, int& by3, int b3width, int b3height,
        int& bx4, int& by4, int b4width, int b4height, int& bx5, int& by5, int b5width, int b5height,
        int& bx6, int& by6, int b6width, int b6height, int& bx7, int& by7, int b7width, int b7height,
        int& bx8, int& by8, int b8width, int b8height) {
        switch (key) {

        case KEY_LEFT:
            if (bx > 2&&bx7>2) bx --,bx7--;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx, by, bwidth, bheight))  bx++, bx7++;
            break;

        case KEY_RIGHT:
            if (bx+bwidth < 79 && bx7+b7width) bx += 1,bx7++;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx, by, bwidth, bheight))  bx--,bx7--;
            break;
        }
    }
    void mySwitchBBmy(int key, int& bx, int& by, int bwidth, int bheight, int& bx1, int& by1, int b1width, int b1height
        , int& bx2, int& by2, int b2width, int b2height, int& bx3, int& by3, int b3width, int b3height,
        int& bx4, int& by4, int b4width, int b4height, int& bx5, int& by5, int b5width, int b5height,
        int& bx6, int& by6, int b6width, int b6height, int& bx7, int& by7, int b7width, int b7height,
        int& bx8, int& by8, int b8width, int b8height) {
        switch (key) {
            /*case KEY_UP:
                if (by > 1) by--;
                if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height)) by = by + 1;
                break;

            case KEY_DOWN:
                if (by+bheight< 30) by++;
                if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                    checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height)) by = by - 1;
                break;*/

        case KEY_LEFT:
            if (bx > 2) bx -= 1;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx8, by8, b8width, b8height))bx = bx + 1;
            break;

        case KEY_RIGHT:
            if (bx < 79) bx += 1;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx8, by8, b8width, b8height))bx = bx + 1;
            break;
        }
    }
    void mySwitchBBupdown(int key, int& bx, int& by, int bwidth, int bheight, int& bx1, int& by1, int b1width, int b1height
        , int& bx2, int& by2, int b2width, int b2height, int& bx3, int& by3, int b3width, int b3height,
        int& bx4, int& by4, int b4width, int b4height, int& bx5, int& by5, int b5width, int b5height,
        int& bx6, int& by6, int b6width, int b6height, int& bx7, int& by7, int b7width, int b7height,
        int& bx8, int& by8, int b8width, int b8height) 
        {
        switch (key) {
        case KEY_UP:
            if (by > 1 && by7>1) by--,by7--;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx8, by8, b8width, b8height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx8, by8, b8width, b8height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx8, by8, b8width, b8height)) by = by + 1,by7++;
            break;

        case KEY_DOWN:
            if (by + bheight < 30&&by7+b7height<30) by++,by7++;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx8, by8, b8width, b8height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx8, by8, b8width, b8height) ||
                checkMeetBB(bx7, by7, b7width, b7height, bx8, by8, b8width, b8height)) by --, by7--;
            break;
        }

    }
    void mySwitchBBupdownforgg(int key, int& bx, int& by, int bwidth, int bheight, int& bx1, int& by1, int b1width, int b1height
        , int& bx2, int& by2, int b2width, int b2height, int& bx3, int& by3, int b3width, int b3height,
        int& bx4, int& by4, int b4width, int b4height, int& bx5, int& by5, int b5width, int b5height,
        int& bx6, int& by6, int b6width, int b6height, int& bx7, int& by7, int b7width, int b7height) {
        switch (key) {
        case KEY_UP:
            if (by > 1) by--;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height)) by = by + 1;
            break;

        case KEY_DOWN:
            if (by + bheight < 30) by++;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height)) by = by - 1;
            break;
        }

    }

};

