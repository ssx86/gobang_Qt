#include "Chessboard.h"
#include <memory>
#include <QDebug>


Chessboard::Chessboard()
{
    memset(m_data, 0, sizeof(19*19*sizeof(COLOR)));
}

COLOR Chessboard::get(int x, int y)
{
    return m_data[x][y];
}

STATUS Chessboard::set(int x, int y, COLOR status)
{
    m_data[x][y] = status;
	return update(x, y);
}

/*
 * return the winner color
*/
STATUS Chessboard::update(int x, int y)
{
    STATUS status = 0;
    int result[4];
    //x direction
    result[0] = judgeX(x, y);

    //y direction
    result[1] = judgeY(x, y);

    //0-xy direction
    result[2] = judge00_XY(x, y);

    //0y-x0 direction
    result[3] = judge0Y_X0(x, y);

    int count_3 = 0;
    int count_4 = 0;
    bool too_long = false;
    bool win = false;
    for(int i = 0; i < 4; i++)
    {
        if( result[i] == 3 ) count_3++;
        if( result[i] == 4 ) count_4++;
        if( result[i] >  5 ) too_long = true;
        if( result[i] == 5 ) win = true;
    }

    //33 forbidden
    if(count_3 > 1)     status |= STATUS_Forbidden_33;
    if(count_4 > 1)     status |= STATUS_Forbidden_44;
    if(too_long)        status |= STATUS_Forbidden_LONG;

    if(status == STATUS_NOTHING && win)
        status |= STATUS_WIN;

    return status;
}


int Chessboard::judgeX(int x, int y)
{
    int tempx, tempy;
    int count = 1; // count to 5 to win the game
    COLOR curColor = get(x, y);

    tempx = x; tempy = y;
    //left
    while(tempx-1 >= 0 && get(tempx-1, tempy) == curColor)
    {
        count++;
        tempx--;
    }
    //right
    tempx = x; tempy = y;
    while(tempx+1 < 19 && get(tempx+1, tempy) == curColor)
    {
        count++;
        tempx++;
    }
	return count;
    //qDebug() << "the x direction count is :" << count << "  and the color is :" << curColor;
}

int Chessboard::judgeY(int x, int y)
{
    int tempx, tempy;
    int count = 1; // count to 5 to win the game
    COLOR curColor = get(x, y);

    tempx = x; tempy = y;
    //top
    while(tempy-1 >= 0 && get(tempx, tempy-1) == curColor)
    {
        count++;
        tempy--;
    }
    //right
    tempx = x; tempy = y;
    while(tempy+1 < 19 && get(tempx, tempy+1) == curColor)
    {
        count++;
        tempy++;
    }
    //qDebug() << "the Y direction count is :" << count << "  and the color is :" << curColor;
	return count;
}

int Chessboard::judge00_XY(int x, int y)
{
    int tempx, tempy;
    int count = 1; // count to 5 to win the game
    COLOR curColor = get(x, y);

    tempx = x; tempy = y;
    //lefttop
    while(tempx-1 >= 0 && tempy-1 >= 0 && get(tempx-1, tempy-1) == curColor)
    {
        count++;
        tempx--;
        tempy--;
    }
    //rightbottom
    tempx = x; tempy = y;
    while(tempx+1 < 19 && tempy+1 < 19 && get(tempx+1, tempy+1) == curColor)
    {
        count++;
        tempx++;
        tempy++;
    }
    //qDebug() << "the 00_XY direction count is :" << count << "  and the color is :" << curColor;
	return count;

}

int Chessboard::judge0Y_X0(int x, int y)
{
    int tempx, tempy;
    int count = 1; // count to 5 to win the game
    COLOR curColor = get(x, y);

    tempx = x; tempy = y;
    //lefttop
    while(tempx-1 >= 0 && tempy+1 < 19 && get(tempx-1, tempy+1) == curColor)
    {
        count++;
        tempx--;
        tempy++;
    }
    //rightbottom
    tempx = x; tempy = y;
    while(tempx+1 < 19 && tempy-1 >= 0 && get(tempx+1, tempy-1) == curColor)
    {
        count++;
        tempx++;
        tempy--;
    }

	return count;
    //qDebug() << "the 0Y_X0 direction count is :" << count << "  and the color is :" << curColor;

}
