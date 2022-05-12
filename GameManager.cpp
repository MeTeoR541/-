#include "GameManager.h"
GameManager::GameManager(QWidget* parent) :QWidget(parent){
	current_player = false;
    winner = false;
	isEnd = false;
    pick = false;
    now_where = 0;
    file_num = 0;
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
    winner = false;
    Board newboard;
    this->board = newboard;
    temp_board = newboard;
    file_num++;
    string num = to_string(file_num);
    record.open(num + ".txt");
}
void GameManager::Record(int from_x, int from_y, int to_x, int to_y, int chessValue, bool player) {
    string temp;
    if (player == true) {
        temp += "Player: 2, Action: ";
        switch(chessValue) {
        case 1:
            temp += "Soldier ";
            break;
        case 2:
            temp += "Cannon ";
            break;
        case 3:
            temp += "Chariot ";
            break;
        case 4:
            temp += "Horse ";
            break;
        case 5:
            temp += "Elephant ";
            break;
        case 6:
            temp += "Advisor ";
            break;
        case 7:
            temp += "General ";
            break;
        }
    }
    else {
        temp += "Player: 1, Action: ";
        switch (chessValue) {
        case 1:
            temp += "Soldier ";
            break;
        case 2:
            temp += "Cannon ";
            break;
        case 3:
            temp += "Chariot ";
            break;
        case 4:
            temp += "Horse ";
            break;
        case 5:
            temp += "Elephant ";
            break;
        case 6:
            temp += "Advisor ";
            break;
        case 7:
            temp += "General ";
            break;
        }
    }
    temp += "(" + to_string(from_x) + ", " + to_string(from_y) + ") -> (" + to_string(to_x) + ", " + to_string(to_y) + ")\n";
    record << temp;
}
void GameManager::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    this->setMinimumWidth(460);
    this->setMinimumHeight(510);
    if (now_where == 0)
        viewer.drawhomepage(painter);
    else if (isEnd == true) {
        if (winner == true)
            record << "Black Win\n";
        else
            record << "Red Win\n";
        record.close();
        viewer.drawBoard(painter, board);
        viewer.drawWinMessage(painter, winner);
    }
    else if (now_where == 1)
        viewer.drawBoard(painter, board);
    else if (now_where == 2) {
        viewer.drawBoard(painter, board);
        viewer.drawCheckMessage(painter, !current_player);
    }
}
void GameManager::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() != Qt::LeftButton)
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
    else if (isEnd == true) {
        if (now.y() >= 250 && now.y() <= 280 && now.x() <= 220 && now.x() >= 170) {
            now_where = 1;
            newGame();
            update();
        }
        else if (now.y() >= 250 && now.y() <= 280 && now.x() <= 290 && now.x() >= 240) {
            now_where = 0;
            isEnd = false;
            update();
        }
    }
    else if (now_where == 2) {
        if (now.y() >= 250 && now.y() <= 280 && now.x() <= 290 && now.x() >= 240) {
            now_where = 1;
            update();
        }
    }
    else if (now_where == 1) {
        if (now.y() >= 30 && now.y() <= 70 && now.x() <= 600 && now.x() >= 480) {
            isEnd = true;
            winner = false;
            update();
        }
        else if (now.y() >= 440 && now.y() <= 480 && now.x() <= 600 && now.x() >= 480) {
            isEnd = true;
            winner = true;
            update();
        }
        else
            playGameManger();
    }
        
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
        Record(temp_x, temp_y, x, y, now_value, current_player);
        current_player = !current_player;
        temp_board = board;
        pick = false;
        if (cantmove(board, current_player) || kingDie(board, current_player) || movewillDie(board, current_player)) {
            isEnd = true;
            winner = !current_player;
        }
        else if (Check(board, !current_player)) {
            now_where = 2;
        }
        update();
    }
    else {
        board = temp_board;
        pick = false;
        update();
    }
}
bool GameManager::Check(const Board& board, bool player) {
    Board temp = nextmove(board, player);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (temp.map[i][j] > 9 && temp.map[i][j] % 10 == 7)
                return true;
        }
    }
    return false;
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
                Board add = board;
                switch (temp.map[i][j]) {
                case 1:
                    s.move(add, i, j, current_player);
                    break;
                case 2:
                    c.move(add, i, j, current_player);
                    break;
                case 3:
                    r.move(add, i, j, current_player);
                    break;
                case 4:
                    h.move(add, i, j, current_player);
                    break;
                case 5:
                    e.move(add, i, j, current_player);
                    break;
                case 6:
                    a.move(add, i, j, current_player);
                    break;
                case 7:
                    g.move(add, i, j, current_player);
                    break;
                }
                temp = temp + add;
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
Board GameManager::nextmove(const Board& board, bool player) {
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
                Board add = board;
                switch (temp.map[i][j]) {
                case 1:
                    s.move(add, i, j, player);
                    break;
                case 2:
                    c.move(add, i, j, player);
                    break;
                case 3:
                    r.move(add, i, j, player);
                    break;
                case 4:
                    h.move(add, i, j, player);
                    break;
                case 5:
                    e.move(add, i, j, player);
                    break;
                case 6:
                    a.move(add, i, j, player);
                    break;
                case 7:
                    g.move(add, i, j, player);
                    break;
                }
                temp = temp + add;
            }
        }
    }
    return temp;
}
bool GameManager::movewillDie(const Board& board, bool player) {
    Soldier s;
    Cannon c;
    Rook r;
    Horse h;
    Elephant e;
    Advisor a;
    General g;
    bool isTrue = false;
    bool jump = false;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (board.map[i][j] % 10 != 0 && board.BorR[i][j] == player) {
                if (board.map[i][j] == 1) {
                    Board temp;
                    temp = board;
                    Board test;
                    s.move(temp, i, j, player);
                    for (int k = 0; k < 10; k++) {
                        for (int m = 0; m < 9; m++) {
                            if (temp.map[k][m] > 9) {
                                test = board;
                                test = s.change(test, i, j, k, m, player);
                                test = nextmove(test, player);
                                if (test.findKingValue(player) > 10)
                                    isTrue = true;
                                else {
                                    isTrue = false;
                                    jump = true;
                                    break;
                                }
                            }
                        }
                        if (jump == true)
                            break;
                    }
                    if (jump == true)
                        break;
                }
                else if (board.map[i][j] == 2) {
                    Board temp;
                    temp = board;
                    Board test;
                    c.move(temp, i, j, player);
                    for (int k = 0; k < 10; k++) {
                        for (int m = 0; m < 9; m++) {
                            if (temp.map[k][m] > 9) {
                                test = board;
                                test = c.change(test, i, j, k, m, player);
                                test = nextmove(test, player);
                                if (test.findKingValue(player) > 10)
                                    isTrue = true;
                                else {
                                    isTrue = false;
                                    jump = true;
                                    break;
                                }
                            }
                        }
                        if (jump == true)
                            break;
                    }
                    if (jump == true)
                        break;
                }
                else if (board.map[i][j] == 3) {
                    Board temp;
                    temp = board;
                    Board test;
                    r.move(temp, i, j, player);
                    for (int k = 0; k < 10; k++) {
                        for (int m = 0; m < 9; m++) {
                            if (temp.map[k][m] > 9) {
                                test = board;
                                test = r.change(test, i, j, k, m, player);
                                test = nextmove(test, player);
                                if (test.findKingValue(player) > 10)
                                    isTrue = true;
                                else {
                                    isTrue = false;
                                    jump = true;
                                    break;
                                }
                            }
                        }
                        if (jump == true)
                            break;
                    }
                    if (jump == true)
                        break;
                }
                else if (board.map[i][j] == 4) {
                    Board temp;
                    temp = board;
                    Board test;
                    h.move(temp, i, j, player);
                    for (int k = 0; k < 10; k++) {
                        for (int m = 0; m < 9; m++) {
                            if (temp.map[k][m] > 9) {
                                test = board;
                                test = h.change(test, i, j, k, m, player);
                                test = nextmove(test, player);
                                if (test.findKingValue(player) > 10)
                                    isTrue = true;
                                else {
                                    isTrue = false;
                                    jump = true;
                                    break;
                                }
                            }
                        }
                        if (jump == true)
                            break;
                    }
                    if (jump == true)
                        break;
                }
                else if (board.map[i][j] == 5) {
                    Board temp;
                    temp = board;
                    Board test;
                    e.move(temp, i, j, player);
                    for (int k = 0; k < 10; k++) {
                        for (int m = 0; m < 9; m++) {
                            if (temp.map[k][m] > 9) {
                                test = board;
                                test = e.change(test, i, j, k, m, player);
                                test = nextmove(test, player);
                                if (test.findKingValue(player) > 10)
                                    isTrue = true;
                                else {
                                    isTrue = false;
                                    jump = true;
                                    break;
                                }
                            }
                        }
                        if (jump == true)
                            break;
                    }
                    if (jump == true)
                        break;
                }
                else if (board.map[i][j] == 6) {
                Board temp;
                temp = board;
                Board test;
                a.move(temp, i, j, player);
                for (int k = 0; k < 10; k++) {
                    for (int m = 0; m < 9; m++) {
                        if (temp.map[k][m] > 9) {
                            test = board;
                            test = a.change(test, i, j, k, m, player);
                            test = nextmove(test, player);
                            if (test.findKingValue(player) > 10)
                                isTrue = true;
                            else {
                                isTrue = false;
                                jump = true;
                                break;
                            }
                        }
                    }
                    if (jump == true)
                        break;
                }
                if (jump == true)
                    break;
                }
                else if (board.map[i][j] == 7) {
                Board temp;
                temp = board;
                Board test;
                g.move(temp, i, j, player);
                for (int k = 0; k < 10; k++) {
                    for (int m = 0; m < 9; m++) {
                        if (test.map[k][m] > 9) {
                            test = board;
                            test = g.change(test, i, j, k, m, player);
                            test = nextmove(test, player);
                            if (test.findKingValue(player) > 10)
                                isTrue = true;
                            else {
                                isTrue = false;
                                jump = true;
                                break;
                            }
                        }
                    }
                    if (jump == true)
                        break;
                }
                if (jump == true)
                    break;
                }
            }
        }
        if (jump == true)
            break;
    }
    return isTrue;
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
