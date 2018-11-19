#ifndef _2048_H
#define _2048_H

#include <QObject>

namespace Ui {
class _2048;
}

class _2048 : public QObject
{
    Q_OBJECT
public:
    explicit _2048(QObject *parent = 0);

    void copy(int array[][4]);
    bool isChange(int array[][4]);
    int _2048::getScore();
    void randomNumber(int array[][4]);
    void _2048::generateNumber(int array[][4]);
    void _2048::isGameOver(int array[][4]);
    void _2048::isSuccess(int array[][4]);

    void calculateArrayRight(int array[][4]);
    void calculateArrayLeft(int array[][4]);
    void calculateArrayDown(int array[][4]);
    void calculateArrayUp(int array[][4]);


signals:

public slots:

private:
    int score;
};

#endif // _2048_H
