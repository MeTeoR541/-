#include "GameManager.h"
GameManager::GameManager(QWidget* parent) :QWidget(parent){
	current_player = false;
	isEnd = false;
    pick = false;
    now_where = 0;
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
void GameManager::newGame() {
    current_player = false;
    isEnd = false;
    pick = false;
    Board newboard;
    this->board = newboard;
}
void GameManager::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    this->setMinimumWidth(460);
    this->setMinimumHeight(510);
    if (now_where == 0)
        viewer.drawhomepage(painter);
    else if (now_where == 1)
        viewer.drawBoard(painter, board);
}
void GameManager::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() != Qt::LeftButton || isEnd == true)
        return;
    QPoint temp = event->pos();
    now = temp;
    if (now_where == 0) {
        if (now.y() >= 270 && now.y() <= 320 && now.x() <= 150 && now.x() >= 30) {
            now_where = 1;
            newGame();
            update();
        }
        else if (now.y() >= 430 && now.y() <= 480 && now.x() <= 150 && now.x() >= 30)
            close();
    }
    else if(now_where==1)
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
        if (cantmove(board, current_player) || kingDie(board, current_player))
            isEnd = true;
        update();
    }
    else {
        board = temp_board;
        pick = false;
        update();
    }
}
bool GameManager::cantmove(const Board& board, bool player) {
    Soldier s;
    Cannon c;
    Rook r;
    Horse h;
    Elephant e;
    Advisor a;
    General g;
    Board temp;
    temp = board;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (temp.map[i][j] % 10 != 0 && temp.BorR[i][j] == player) {
                switch (temp.map[i][j]) {
                case 1:
                    s.move(temp, i, j, current_player);
                    break;
                case 2:
                    c.move(temp, i, j, current_player);
                    break;
                case 3:
                    r.move(temp, i, j, current_player);
                    break;
                case 4:
                    h.move(temp, i, j, current_player);
                    break;
                case 5:
                    e.move(temp, i, j, current_player);
                    break;
                case 6:
                    a.move(temp, i, j, current_player);
                    break;
                case 7:
                    g.move(temp, i, j, current_player);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (temp.map[i][j] > 9)
                return false;
        }
    }
    return true;
}
bool GameManager::kingDie(const Board& board, bool player) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (board.map[i][j] % 10 == 7 && board.BorR[i][j] == player)
                return false;
        }
    }
    return true;
}
