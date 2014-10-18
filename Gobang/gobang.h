#ifndef GOBANG_H
#define GOBANG_H

#include <QtWidgets/QMainWindow>
#include "ui_gobang.h"

#include "Chessboard.h"
#include "GobangScene.h"


class QGraphicsScene;

class Gobang : public QMainWindow
{
	Q_OBJECT

public:
	Gobang(QWidget *parent = 0);
	~Gobang();

private:
	GobangScene m_scene;
private:
	Ui::GobangClass ui;
};

#endif // GOBANG_H
