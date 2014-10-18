#include "gobang.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QDebug>

Gobang::Gobang(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	ui.graphicsView->setScene(&m_scene);
	ui.graphicsView->setFixedSize(520, 520);
	m_scene.setSceneRect(0, 0, 500, 500);
	ui.graphicsView->setMouseTracking(true);

	QPixmap image(":/Gobang/img/board.jpg");
	QBrush brush(image);                //“‘∏√Õº∆¨¥¥Ω®ª≠À¢  
	m_scene.setBackgroundBrush(brush);    //…Ë÷√≥°æ∞±≥æ∞ª≠À¢  
}

Gobang::~Gobang()
{

}
