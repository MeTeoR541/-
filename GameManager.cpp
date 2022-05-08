#include "GameManager.h"
GameManager::GameManager(QWidget* parent) :QWidget(parent){
	current_player = false;
	isEnd = false;
    pick = false;
    Soldier s;
    chess.push_back(s);
    Cannon c;
    chess.push_back(c);
    Rook r;
    chess.push_back(r);
    Horse h;
    chess.push_back(h);
    Elephant e;
    chess.push_back(e);
    Advisor a;
    chess.push_back(a);
    General g;
    chess.push_back(g);
}
void GameManager::newGame(QPainter& ptr) {
	current_player = false;
	isEnd = false;
	
}
void GameManager::drawChess(QPainter& ptr, int x, int y, int value, bool whoose) {
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
void GameManager::drawBoard(QPainter& ptr, const Board& board) {
    this->setMinimumWidth(460);
    this->setMinimumHeight(510);
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
void GameManager::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    drawBoard(painter,board);
}
void GameManager::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() != Qt::LeftButton || isEnd == true)
        return;
    QPoint temp = event->pos();
    now = temp;
    playGameManger();
}
void GameManager::playGameManger() {
    int x = now.x() - 6;
    int y = now.y() - 6;
    x = x / 50;
    y = y / 50;
    if (board.map[y][x] != 0 && board.BorR[y][x] == current_player && pick == false) {
        temp_board = board;
        temp_x = x;
        temp_y = y;
        pick = true;
        Soldier s;        
        Cannon c;        
        Rook r;        
        Horse h;
        Elephant e;
        Advisor a;
        General g;
        switch (board.map[y][x]) {
        case 1:
            s.move(board, y, x, current_player);
            now_value = s.getValue();
            break;
        case 2:
            c.move(board, y, x, current_player);
            now_value = c.getValue();
            break;
        case 3:
            r.move(board, y, x, current_player);
            now_value = r.getValue();
            break;
        case 4:
            h.move(board, y, x, current_player);
            now_value = h.getValue();
            break;
        case 5:
            e.move(board, y, x, current_player);
            now_value = e.getValue();
            break;
        case 6:
            a.move(board, y, x, current_player);
            now_value = a.getValue();
            break;
        case 7:
            g.move(board, y, x, current_player);
            now_value = g.getValue();
            break;
        }
        update();
    }
    else if (board.map[y][x] != 0 && board.map[y][x] < 10 && board.BorR[y][x] == current_player) {
        board = temp_board;
        pick = false;
        temp_board = board;
        temp_x = x;
        temp_y = y;
        pick = true;
        Soldier s;
        Cannon c;
        Rook r;
        Horse h;
        Elephant e;
        Advisor a;
        General g;
        switch (board.map[y][x]) {
        case 1:
            s.move(board, y, x, current_player);
            now_value = s.getValue();
            break;
        case 2:
            c.move(board, y, x, current_player);
            now_value = c.getValue();
            break;
        case 3:
            r.move(board, y, x, current_player);
            now_value = r.getValue();
            break;
        case 4:
            h.move(board, y, x, current_player);
            now_value = h.getValue();
            break;
        case 5:
            e.move(board, y, x, current_player);
            now_value = e.getValue();
            break;
        case 6:
            a.move(board, y, x, current_player);
            now_value = a.getValue();
            break;
        case 7:
            g.move(board, y, x, current_player);
            now_value = g.getValue();
            break;
        }
        update();
    }
   else if (board.map[y][x] > 9 && pick == true) {
        Chess r(now_value);
        board = r.change(temp_board, temp_y, temp_x, y, x, current_player);
        current_player = !current_player;
        temp_board = board;
        pick = false;
        update();
    }
    else {
        board = temp_board;
        pick = false;
        update();
    }
}
bool GameManager::getNowplayer() {
	return current_player;
}
bool GameManager::getisEnd() {
	return isEnd;
}