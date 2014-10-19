#pragma once

#include <QGraphicsScene>
#include "Chessboard.h"
#include <QVector>

class GobangScene :
	public QGraphicsScene
{
public:
	GobangScene(void);
	~GobangScene(void);

protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	void addChessman(int x, int y, COLOR color);
	int getCrossPoint(qreal p);
	void update(STATUS status);

	int rows;
	qreal left;
	qreal right;
	qreal top;
	qreal bottom;
	qreal row;
	qreal r;
	QVector<qreal> m_cross;

	Chessboard m_chessboard;
};

