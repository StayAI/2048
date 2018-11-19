#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <QEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include "_2048.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ex = new _2048;

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            array[i][j] = 0;

    ex->randomNumber(array);
    ex->randomNumber(array);

    showArray(array);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::keyPressEvent(QKeyEvent *e)
{
    ex->copy(array);

    if (e->key() == Qt::Key_W || e->key() == Qt::Key_Up)
    {
        ex->calculateArrayUp(array);
    }
    if (e->key() == Qt::Key_S || e->key() == Qt::Key_Down)
    {
        ex->calculateArrayDown(array);
    }
    if (e->key() == Qt::Key_A || e->key() == Qt::Key_Left)
    {
        ex->calculateArrayLeft(array);
    }
    if (e->key() == Qt::Key_D || e->key() == Qt::Key_Right)
    {
        ex->calculateArrayRight(array);
    }

    if ( ex->isChange(array) )
    {
        ex->generateNumber(array);
    }

    showArray(array);

    ex->isGameOver(array);
    ex->isSuccess(array);
}

void Widget::paintEvent(QPaintEvent *)
{
//    QPainter p(this);

//    //背景图
//    p.drawPixmap(rect(), QPixmap("../image/1.png"));

}

void Widget::showArray(int array[][4])
{
    ui->lcd1->display(array[0][0]);
    ui->lcd2->display(array[0][1]);
    ui->lcd3->display(array[0][2]);
    ui->lcd4->display(array[0][3]);
    ui->lcd5->display(array[1][0]);
    ui->lcd6->display(array[1][1]);
    ui->lcd7->display(array[1][2]);
    ui->lcd8->display(array[1][3]);
    ui->lcd9->display(array[2][0]);
    ui->lcd10->display(array[2][1]);
    ui->lcd11->display(array[2][2]);
    ui->lcd12->display(array[2][3]);
    ui->lcd13->display(array[3][0]);
    ui->lcd14->display(array[3][1]);
    ui->lcd15->display(array[3][2]);
    ui->lcd16->display(array[3][3]);

    ui->lcdScore->display(ex->getScore());
}


