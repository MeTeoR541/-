#include "Viewer.h"
Viewer::Viewer(){
}
void Viewer::drawWinMessage(bool winner) {
    if (winner == true) {

    }
}
void Viewer::drawhomepage(QPainter& ptr) {
    ptr.setBrush(QColor(238, 239, 235));
    ptr.drawRect(30, 270, 120, 50);
    ptr.drawRect(30, 350, 120, 50);
    ptr.drawRect(30, 430, 120, 50);
}
void Viewer::drawChess(QPainter& ptr, int x, int y, int value, bool whoose) {
    if (value > 9) {
        if (value % 10 != 0) {
            if (whoose == true)
                ptr.setPen(QColor(0, 0, 0));
            else
                ptr.setPen(QColor(255, 0, 0));
            switch (value % 10) {
            case 1:
                ptr.drawEllipse(x - 24, y - 24, 48, 48);
                ptr.drawEllipse(x - 22, y - 22, 44, 44);
                ptr.setFont(QFont("FangSong"));
                if (whoose == true)
                    ptr.drawText(x, y, "卒");
                else
                    ptr.drawText(x, y, "兵");
                break;
            case 2:
                ptr.drawEllipse(x - 24, y - 24, 48, 48);
                ptr.drawEllipse(x - 22, y - 22, 44, 44);
                ptr.setFont(QFont("FangSong"));
                if (whoose == true)
                    ptr.drawText(x, y, "包");
                else
                    ptr.drawText(x, y, "砲");
                break;
            case 3:
                ptr.drawEllipse(x - 24, y - 24, 48, 48);
                ptr.drawEllipse(x - 22, y - 22, 44, 44);
                ptr.setFont(QFont("FangSong"));
                if (whoose == true)
                    ptr.drawText(x, y, "車");
                else
                    ptr.drawText(x, y, "俥");
                break;
            case 4:
                ptr.drawEllipse(x - 24, y - 24, 48, 48);
                ptr.drawEllipse(x - 22, y - 22, 44, 44);
                ptr.setFont(QFont("FangSong"));
                ptr.drawText(x, y, "馬");
                break;
            case 5:
                ptr.drawEllipse(x - 24, y - 24, 48, 48);
                ptr.drawEllipse(x - 22, y - 22, 44, 44);
                ptr.setFont(QFont("FangSong"));
                if (whoose == true)
                    ptr.drawText(x, y, "象");
                else
                    ptr.drawText(x, y, "相");
                break;
            case 6:
                ptr.drawEllipse(x - 24, y - 24, 48, 48);
                ptr.drawEllipse(x - 22, y - 22, 44, 44);
                ptr.setFont(QFont("FangSong"));
                if (whoose == true)
                    ptr.drawText(x, y, "士");
                else
                    ptr.drawText(x, y, "仕");
                break;
            case 7:
                ptr.drawEllipse(x - 24, y - 24, 48, 48);
                ptr.drawEllipse(x - 22, y - 22, 44, 44);
                ptr.setFont(QFont("FangSong"));
                if (whoose == true)
                    ptr.drawText(x, y, "將");
                else
                    ptr.drawText(x, y, "帥");
                break;
            }
            ptr.setPen(QColor(220, 0, 0));
            ptr.drawEllipse(x - 12, y - 12, 24, 24);
        }
        else {
            ptr.setPen(QColor(220, 0, 0));
            ptr.drawEllipse(x - 12, y - 12, 24, 24);
        }
    }
    else if (value != 0) {
        if (whoose == true)
            ptr.setPen(QColor(0, 0, 0));
        else
            ptr.setPen(QColor(255, 0, 0));
        switch (value % 10) {
        case 1:
            ptr.drawEllipse(x - 24, y - 24, 48, 48);
            ptr.drawEllipse(x - 22, y - 22, 44, 44);
            ptr.setFont(QFont("FangSong"));
            if (whoose == true)
                ptr.drawText(x, y, "卒");
            else
                ptr.drawText(x, y, "兵");
            break;
        case 2:
            ptr.drawEllipse(x - 24, y - 24, 48, 48);
            ptr.drawEllipse(x - 22, y - 22, 44, 44);
            ptr.setFont(QFont("FangSong"));
            if (whoose == true)
                ptr.drawText(x, y, "包");
            else
                ptr.drawText(x, y, "砲");
            break;
        case 3:
            ptr.drawEllipse(x - 24, y - 24, 48, 48);
            ptr.drawEllipse(x - 22, y - 22, 44, 44);
            ptr.setFont(QFont("FangSong"));
            if (whoose == true)
                ptr.drawText(x, y, "車");
            else
                ptr.drawText(x, y, "俥");
            break;
        case 4:
            ptr.drawEllipse(x - 24, y - 24, 48, 48);
            ptr.drawEllipse(x - 22, y - 22, 44, 44);
            ptr.setFont(QFont("FangSong"));
            ptr.drawText(x, y, "馬");
            break;
        case 5:
            ptr.drawEllipse(x - 24, y - 24, 48, 48);
            ptr.drawEllipse(x - 22, y - 22, 44, 44);
            ptr.setFont(QFont("FangSong"));
            if (whoose == true)
                ptr.drawText(x, y, "象");
            else
                ptr.drawText(x, y, "相");
            break;
        case 6:
            ptr.drawEllipse(x - 24, y - 24, 48, 48);
            ptr.drawEllipse(x - 22, y - 22, 44, 44);
            ptr.setFont(QFont("FangSong"));
            if (whoose == true)
                ptr.drawText(x, y, "士");
            else
                ptr.drawText(x, y, "仕");
            break;
        case 7:
            ptr.drawEllipse(x - 24, y - 24, 48, 48);
            ptr.drawEllipse(x - 22, y - 22, 44, 44);
            ptr.setFont(QFont("FangSong"));
            if (whoose == true)
                ptr.drawText(x, y, "將");
            else
                ptr.drawText(x, y, "帥");
            break;
        }
    }
}
void Viewer::drawBoard(QPainter& ptr, const Board& board) {
    for (int i = 0; i < 10; i++) {
        ptr.drawLine(30, 30 + i * 50, 430, 30 + i * 50);
    }
    for (int i = 0; i < 9; i++) {
        if (i == 0 || i == 8) {
            ptr.drawLine(30 + i * 50, 30, 30 + i * 50, 480);
        }
        else {
            ptr.drawLine(30 + i * 50, 30, 30 + i * 50, 230);
            ptr.drawLine(30 + i * 50, 280, 30 + i * 50, 480);
        }
    }
    ptr.drawLine(180, 30, 280, 130);
    ptr.drawLine(280, 30, 180, 130);
    ptr.drawLine(180, 480, 280, 380);
    ptr.drawLine(280, 480, 180, 380);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            drawChess(ptr, 30 + j * 50, 30 + i * 50, board.map[i][j], board.BorR[i][j]);
        }
    }
}
