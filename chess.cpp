#include "chess.h"

chess::chess()
{

}

chess::chess(int x, int y, int type):type(type) {
    pos = QPoint(x, y);
}
