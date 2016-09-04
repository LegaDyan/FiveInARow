#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QLabel>
#include <QPaintEvent>
#include <QPoint>
#include <QPainter>
#include <QString>
#include "chess.h"

class chessBoard : public QLabel
{

    Q_OBJECT

signals:
    void dropChess(QString);

public:
    chessBoard(QWidget* parent = 0);
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *ev);
    void addOppo(QString);

private:
    QVector<chess> chessList;
    QPoint startPos;
    int r;
};

#endif // CHESSBOARD_H
