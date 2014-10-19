#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#define COLOR unsigned char
#define STATUS unsigned char

class Chessboard
{
public:
    Chessboard();

    // if this move is forbidden, the bit 0x10 will be set;
    enum{
        STATUS_Forbidden_33    = 0x11,
        STATUS_Forbidden_44    = 0x12,
        STATUS_Forbidden_LONG  = 0x14,
        STATUS_WIN             = 0x80,
        STATUS_NOTHING         = 0x00
    };


    //status
    typedef enum { Empty = 0, Black = 1, White = 2 } Color;
	//26 486

    //get status
    COLOR get(int x, int y);

    //set status
    void set(int x, int y, COLOR status);

private:
    STATUS update(int x, int y);
    //chessboard map
    COLOR m_data[19][19];

    int judgeX(int x, int y);
    int judgeY(int x, int y);
    int judge00_XY(int x, int y);
    int judge0Y_X0(int x, int y);

};

#endif // CHESSBOARD_H
