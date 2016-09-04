#include "chessboard.h"
#include <QDebug>
#include <cmath>
#include <string>

chessBoard::chessBoard(QWidget *parent) : QLabel(parent)
{
    int vdis = this->width() / 15;
    int hdis = this->height() / 15;
    startPos = QPoint(vdis / 2, hdis / 2);
    r = vdis / 2 - 1;
}

void chessBoard::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    int vdis = this->width() / 15;
    int hdis = this->height() / 15;
    startPos = QPoint(vdis / 2, hdis / 2);
    r = vdis / 2 - 3;
    auto posc = startPos;
    for (int i = 0; i < 15; i++) {
        p.drawLine(posc, posc + QPoint(0, hdis * 14));
        posc += QPoint(vdis, 0);
    }
    posc = startPos;
    for (int i = 0; i < 15; i++) {
        p.drawLine(posc, posc + QPoint(vdis * 14, 0));
        posc += QPoint(0, hdis);
    }

    int sz = chessList.size();
    for (int i = 0; i < sz; i++) {
        if (chessList[i].type == 0) {
            p.setBrush(Qt::black);
            p.setPen(Qt::black);
            auto temp = chessList[i].pos;
            temp = QPoint(startPos.rx() + vdis * temp.rx(), startPos.ry() + hdis * temp.ry());
            p.drawEllipse(temp, r, r);
        }
        else {
            p.setBrush(Qt::white);
            p.setPen(Qt::white);
            auto temp = chessList[i].pos;
            temp = QPoint(startPos.rx() + vdis * temp.rx(), startPos.ry() + hdis * temp.ry());
            p.drawEllipse(temp, r, r);
        }
    }
}

void chessBoard::mousePressEvent(QMouseEvent *ev) {
    if (ev->button() == Qt::LeftButton) {
        auto pos = ev->pos() - startPos;
        int vdis = this->width() / 15;
        int hdis = this->height() / 15;
        int ver = round(pos.rx() / (double)vdis);
        int hor = round(pos.ry() / (double)hdis);
        chessList.append(chess(ver, hor, 1));
        emit dropChess(QString::number(ver) + " " + QString::number(hor));
        update();
    }
}

void chessBoard::addOppo(QString str) {
    int x, y;
    sscanf(str.toStdString().c_str(), "%d %d", &x, &y);
    chessList.append(chess(x, y, 0));
    update();
}
