#pragma once
#include "key.h"
class stage3Model
{
public:
    bool checkMeetBB(int bx, int by, int bwidth, int bheight, int bx1, int by1, int b1width, int b1height) {
        return bx<bx1 + b1width && bx + bwidth>bx1 && by<by1 + b1height && by + bheight>by1;
    }//상자와 상자가 마주쳤을 때 true반환
    
            
    void mySwitchBBupdown(int key, int& bx, int& by, int bwidth, int bheight, int& bx1, int& by1, int b1width, int b1height
        , int& bx2, int& by2, int b2width, int b2height, int& bx3, int& by3, int b3width, int b3height,
        int& bx4, int& by4, int b4width, int b4height, int& bx5, int& by5, int b5width, int b5height,
        int& bx6, int& by6, int b6width, int b6height, int& bx7, int& by7, int b7width, int b7height,
        int& bx8, int& by8, int b8width, int b8height, int& bx9, int& by9, int b9width, int b9height,
        int& bx10, int& by10, int b10width, int b10height) {
        switch (key) {
        case KEY_UP:
            if (by > 2) by--;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height)||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx8, by8, b8width, b8height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx9, by9, b9width, b9height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx10, by10, b10width, b10height) ) by++;
            break;

        case KEY_DOWN:
            if (by + bheight < 30) by++;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx8, by8, b8width, b8height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx9, by9, b9width, b9height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx10, by10, b10width, b10height) ) by--;
            break;
        }

    }
    void mySwitchBBleftright(int key, int& bx, int& by, int bwidth, int bheight, int& bx1, int& by1, int b1width, int b1height
        , int& bx2, int& by2, int b2width, int b2height, int& bx3, int& by3, int b3width, int b3height,
        int& bx4, int& by4, int b4width, int b4height, int& bx5, int& by5, int b5width, int b5height,
        int& bx6, int& by6, int b6width, int b6height, int& bx7, int& by7, int b7width, int b7height,
        int& bx8, int& by8, int b8width, int b8height, int& bx9, int& by9, int b9width, int b9height,
        int& bx10, int& by10, int b10width, int b10height){
        switch (key) {
        case KEY_RIGHT:
            if (bx < 79) bx++;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx8, by8, b8width, b8height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx9, by9, b9width, b9height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx10, by10, b10width, b10height)  ) bx--;
            break;

        case KEY_LEFT:
            if (bx > 2) bx -= 1;
            if (checkMeetBB(bx, by, bwidth, bheight, bx1, by1, b1width, b1height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx2, by2, b2width, b2height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx3, by3, b3width, b3height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx4, by4, b4width, b4height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx5, by5, b5width, b5height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx6, by6, b6width, b6height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx7, by7, b7width, b7height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx8, by8, b8width, b8height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx9, by9, b9width, b9height) ||
                checkMeetBB(bx, by, bwidth, bheight, bx10, by10, b10width, b10height)  ) bx++;
            break;
        }

    }
};

