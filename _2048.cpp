#include "_2048.h"
#include <QTime>
#include <QDebug>

_2048::_2048(QObject *parent) : QObject(parent)
{
    this->score = 0;
}


int array1[4][4] = {  0,  0,  0,  0,
                      0,  0,  0,  0,
                      0,  0,  0,  0,
                      0,  0,  0,  0};

int _2048::getScore()
{
    return this->score;
}

void _2048::copy(int array[][4])//复制数组
{
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            array1[i][j] = array[i][j];
}


bool _2048::isChange(int array[][4])//判断数组是否改变
{
    bool change = false;

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            if (array1[i][j] != array[i][j])
            {
                array1[i][j] = array[i][j];
                change = true;
            }

    return change;
}


void _2048::randomNumber(int array[][4])
{
    int t;

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    t = qrand()%16;
    while ( array[t/4][t%4] != 0)
    {
        t = qrand()%16;
    }

    int seed[7] = {2, 2, 2, 2, 2, 2, 4};

    array[t/4][t%4] = seed[qrand()%7];
}

void _2048::generateNumber(int array[][4])
{
    int num = 0;

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            if (array[i][j] != 0)
                num++;

    if (num != 16)
    {
        this->randomNumber(array);
    }
}

void _2048::isGameOver(int array[][4])
{
    int num = 0;

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            if (array[i][j] != 0)
                num++;
            else
                return;

    if (num == 16)
    {
        for(int i=0; i<4; i++)
            for(int j=0; j<3; j++)
                if (array[i][j] == array[i][j+1])
                    return;

        for(int i=0; i<3; i++)
            for(int j=0; j<4; j++)
                if (array[i][j] == array[i+1][j])
                    return;

        qDebug() <<  "GameOver";
    }
}

void _2048::isSuccess(int array[][4])
{
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            if (array[i][j] == 2048)
                qDebug() <<  "Success";
}


void _2048::calculateArrayRight(int array[][4])
{

    for (int i=0; i<4; i++)
    {
        int temp[4] = {0, 0, 0, 0};
        int m = 0;
        for (int j=3; j>=0; j--)
        {
            if (array[i][j] != 0)
                temp[m++] = array[i][j];
        }
        for (int j=0; j<4; j++)
        {
            array[i][j] = temp[3-j];
            temp[3-j] = 0;
        }

        for (int j=3; j>0; j--)
        {
            if ( (array[i][j] == array[i][j-1]) && array[i][j]!=0 )
            {
                array[i][j] *= 2;
                this->score += array[i][j];

                for (int k=j-1; k>0; k--)
                {
                    array[i][k] = array[i][k-1];
                }
                array[i][0] = 0;

                break;
            }
        }
    }
}


void _2048::calculateArrayLeft(int array[][4])
{
    for (int i=0; i<4; i++)
    {
        int temp[4] = {0, 0, 0, 0};
        int m = 0;
        for (int j=0; j<4; j++)
        {
            if (array[i][j] != 0)
                temp[m++] = array[i][j];
        }
        for (int j=0; j<4; j++)
        {
            array[i][j] = temp[j];
            temp[j] = 0;
        }


        for (int j=0; j<3; j++)
        {
            if ( (array[i][j] == array[i][j+1]) && array[i][j]!=0 )
            {
                array[i][j] *= 2;
                this->score += array[i][j];

                for (int k=j+1; k<3; k++)
                {
                    array[i][k] = array[i][k+1];
                }
                array[i][3] = 0;

                break;
            }
        }
    }
}

void _2048::calculateArrayDown(int array[][4])
{
    for (int i=0; i<4; i++)
    {
        int temp[4] = {0, 0, 0, 0};
        int m = 0;
        for (int j=3; j>=0; j--)
        {
            if (array[j][i] != 0)
                temp[m++] = array[j][i];
        }
        for (int j=0; j<4; j++)
        {
            array[j][i] = temp[3-j];
            temp[3-j] = 0;
        }

        for (int j=3; j>0; j--)
        {
            if ( (array[j][i] == array[j-1][i]) && array[j][i]!=0 )
            {
                array[j][i] *= 2;
                this->score += array[i][j];

                for (int k=j-1; k>0; k--)
                {
                    array[k][i] = array[k-1][i];
                }
                array[0][i] = 0;

                break;
            }
        }
    }
}

void _2048::calculateArrayUp(int array[][4])
{
    for (int i=0; i<4; i++)
    {
        int temp[4] = {0, 0, 0, 0};
        int m = 0;
        for (int j=0; j<4; j++)
        {
            if (array[j][i] != 0)
                temp[m++] = array[j][i];
        }
        for (int j=0; j<4; j++)
        {
            array[j][i] = temp[j];
            temp[j] = 0;
        }

        for (int j=0; j<3; j++)
        {
            if ( (array[j][i] == array[j+1][i]) && array[j][i]!=0)
            {
                array[j][i] *= 2;
                this->score += array[i][j];

                for (int k=j+1; k<3; k++)
                {
                    array[k][i] = array[k+1][i];
                }
                array[3][i] = 0;
                break;
            }

        }
    }
}
