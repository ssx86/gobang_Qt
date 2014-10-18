#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#define COLOR unsigned char

class Chessboard
{
public:
    Chessboard();

    //status
    typedef enum { Empty = 0, Black = 1, White = 2 } Color;
	//26 486

    //get status
    COLOR get(int x, int y);

    //set status
    void set(int x, int y, COLOR status);

private:
	void update();
    //chessboard map
    COLOR m_data[19][19];
	
};

#endif // CHESSBOARD_H
