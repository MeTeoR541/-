#include "Viewer.h"
Viewer::Viewer(){
    blackS.load("blackS.png");
    blackC.load("blackC.png");
    blackR.load("blackR.png");
    blackE.load("blackE.png");
    blackH.load("blackH.png");
    blackA.load("blackA.png");
    blackG.load("blackG.png");
    redS.load("redS.png");
    redC.load("redC.png");
    redR.load("redR.png");
    redE.load("redE.png");
    redH.load("redH.png");
    redA.load("redA.png");
    redG.load("redG.png");

    start.load("start.png");
    read.load("read.png");
    end.load("end.png");
    lose.load("lose.png");
}
void Viewer::drawWinMessage(QPainter& ptr, bool winner) {
    if (winner == true) {
        ptr.setBrush(QColor(238, 239, 235));
        ptr.drawRect(475, 165, 150, 130);
        ptr.setBrush(QColor(0, 0, 0));
        ptr.drawRect(490, 250, 50, 30);
        ptr.drawRect(560, 250, 50, 30);
    }
    else {
        ptr.setBrush(QColor(238, 239, 235));
        ptr.drawRect(475, 165, 150, 130);
        ptr.setBrush(QColor(255, 0, 0));
        ptr.drawRect(490, 250, 50, 30);
        ptr.drawRect(560, 250, 50, 30);
    }
}
void Viewer::drawCheckMessage(QPainter& ptr, bool winner) {
    ptr.setBrush(QColor(238, 239, 235));
    ptr.drawRect(155, 165, 150, 130);
    ptr.setBrush(QColor(238, 0, 0));
    ptr.drawRect(240, 250, 50, 30);
    if (winner == true) {
        ptr.drawText(180, 195, "黑方將軍");
    }
    else {
        ptr.drawText(180, 195, "紅方將軍");
    }
}
void Viewer::drawhomepage(QPainter& ptr) {
    ptr.drawPixmap(30, 270, 120, 50, start);
    ptr.drawPixmap(30, 350, 120, 50, read);
    ptr.drawPixmap(30, 430, 120, 50, end);
}
void Viewer::drawChess(QPainter& ptr, int x, int y, int value, bool whoose) {
    if (value > 9) {
        if (value % 10 != 0) {
            switch (value % 10) {
            case 1:
                if (whoose == true)
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, blackS);
                else
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, redS);
                break;
            case 2:
                if (whoose == true)
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, blackC);
                else
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, redC);
                break;
            case 3:
                if (whoose == true)
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, blackR);
                else
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, redR);
                break;
            case 4:
                if (whoose == true)
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, blackH);
                else
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, redH);
                break;
            case 5:
                if (whoose == true)
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, blackE);
                else
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, redE);
                break;
            case 6:
                if (whoose == true)
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, blackA);
                else
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, redA);
                break;
            case 7:
                if (whoose == true)
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, blackG);
                else
                    ptr.drawPixmap(x - 24, y - 24, 48, 48, redG);
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
        switch (value % 10) {
        case 1:
            if (whoose == true)
                ptr.drawPixmap(x - 24, y - 24, 48, 48, blackS);
            else
                ptr.drawPixmap(x - 24, y - 24, 48, 48, redS);
            break;
        case 2:
            if (whoose == true)
                ptr.drawPixmap(x - 24, y - 24, 48, 48, blackC);
            else
                ptr.drawPixmap(x - 24, y - 24, 48, 48, redC);
            break;
        case 3:
            if (whoose == true)
                ptr.drawPixmap(x - 24, y - 24, 48, 48, blackR);
            else
                ptr.drawPixmap(x - 24, y - 24, 48, 48, redR);
            break;
        case 4:
            if (whoose == true)
                ptr.drawPixmap(x - 24, y - 24, 48, 48, blackH);
            else
                ptr.drawPixmap(x - 24, y - 24, 48, 48, redH);
            break;
        case 5:
            if (whoose == true)
                ptr.drawPixmap(x - 24, y - 24, 48, 48, blackE);
            else
                ptr.drawPixmap(x - 24, y - 24, 48, 48, redE);
            break;
        case 6:
            if (whoose == true)
                ptr.drawPixmap(x - 24, y - 24, 48, 48, blackA);
            else
                ptr.drawPixmap(x - 24, y - 24, 48, 48, redA);
            break;
        case 7:
            if (whoose == true)
                ptr.drawPixmap(x - 24, y - 24, 48, 48, blackG);
            else
                ptr.drawPixmap(x - 24, y - 24, 48, 48, redG);
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

    ptr.drawPixmap(480, 30, 120, 40, lose);
    ptr.drawPixmap(480, 440, 120, 40, lose);
}
