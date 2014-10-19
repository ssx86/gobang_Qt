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

void Chessboard::set(int x, int y, COLOR status)
{
    m_data[x][y] = status;
    update(x, y);
}

/*
 * return the winner color
*/
COLOR Chessboard::update(int x, int y)
{

    //x direction
    judgeX(x, y);

    //y direction
    judgeY(x, y);

    //0-xy direction
    judge00_XY(x, y);

    //0y-x0 direction
    judge0Y_X0(x, y);
}


COLOR Chessboard::judgeX(int x, int y)
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
    qDebug() << "the x direction count is :" << count << "  and the color is :" << curColor;
}

COLOR Chessboard::judgeY(int x, int y)
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
    qDebug() << "the Y direction count is :" << count << "  and the color is :" << curColor;
}

COLOR Chessboard::judge00_XY(int x, int y)
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
    qDebug() << "the 00_XY direction count is :" << count << "  and the color is :" << curColor;

}

COLOR Chessboard::judge0Y_X0(int x, int y)
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
    qDebug() << "the 0Y_X0 direction count is :" << count << "  and the color is :" << curColor;

}
