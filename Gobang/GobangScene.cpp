#include "GobangScene.h"
#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <QDebug>

GobangScene::GobangScene(void)
{
	rows = 19;
	left = 26;
	right = 486;
	top = 26;
	bottom = 486;
	row = (right - left) / qreal(rows - 1) ;
	r = row - 4;

	for(int i = 0; i < rows; i++)
	{
		m_cross.push_back(left + i * row);
	}
	for(int i = 0; i < rows; i++)
	{
		qDebug() << m_cross[i];
	}

//	addChessman(7, 7, Chessboard::Black);
//	addChessman(0, 0, Chessboard::White);
//	addChessman(15, 15, Chessboard::Black);
//	addChessman(0, 15, Chessboard::White);
//	addChessman(15, 0, Chessboard::Black);
}


GobangScene::~GobangScene(void)
{
}

void GobangScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "current pos: " << event->scenePos().x() << "," << event->scenePos().y();
}

void GobangScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "pressed pos: " << event->scenePos().x() << "," << event->scenePos().y();
}

void GobangScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "released pos: " << event->scenePos().x() << "," << event->scenePos().y();
	int x = getCrossPoint(event->scenePos().rx());
	int y = getCrossPoint(event->scenePos().ry());

	static COLOR color= Chessboard::Black;
	addChessman(x, y, color);
	color = Chessboard::Black + Chessboard::White - color; 
}

void GobangScene::addChessman(int x, int y, COLOR color)
{
	if(color == Chessboard::White)
		addEllipse(left + x * row - r/2, top + y * row - r/2, r, r, QPen(Qt::black), QBrush(Qt::white));
	else
		addEllipse(left + x * row - r/2, top + y * row - r/2, r, r, QPen(Qt::black), QBrush(Qt::black));
	m_chessboard.set(x, y, color);
}

int GobangScene::getCrossPoint(qreal p)
{
	for(int i = 0; i < m_cross.size(); i++)
		if(m_cross[i] > p - row/2)
			return i;
	return 0;
}
