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
	update();
}

void Chessboard::update()
{
	//col
	COLOR color = Empty;
	int count = 0;
	for(int i = 0; i < 19; i++)
	{
		count = 0;
		for(int j = 0; j < 19; j++)
		{
			if(get(i, j) == Empty)
				count = 0;
			else if(color == get(i, j))
				count++;
			else
			{
				color = get(i, j);
				count = 1;
			}

			if(count == 5)
				qDebug() << "!!!!!!!!!!!!!!!!!!!!!";
		}
	}
	//row
	color = Empty;
	count = 0;
	for(int j = 0; j < 19; j++)
	{
		count = 0;
		for(int i = 0; i < 19; i++)
		{
			if(get(i, j) == Empty)
				count = 0;
			else if(color == get(i, j))
				count++;
			else
			{
				color = get(i, j);
				count = 1;
			}

			if(count == 5)
				qDebug() << "!!!!!!!!!!!!!!!!!!!!!";
		}
	}
	//lefttop-rightbottom
	//righttop-leftbottom
}