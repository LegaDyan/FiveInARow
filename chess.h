#ifndef CHESS_H
#define CHESS_H

#include <QPoint>

class chess
{
public:
    chess();
    chess(int x, int y, int type);
    QPoint pos;
    int type;
};

#endif // CHESS_H
