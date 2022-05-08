#include "GameManager.h"
GameManager::GameManager() {
	current_player = false;
	isEnd = false;
}
void GameManager::newGame(QPainter& ptr) {
	current_player = false;
	isEnd = false;
	viewer.drawBoard(ptr, board);
}
QPoint GameManager::turnMsPoint(QPoint pt) {
	QPoint temp;
	temp.setX(pt.x() / 460);
	temp.setY(pt.y() / 510);
	return temp;
}
void GameManager::mouseReleaseEvent(QMouseEvent* ev) {
	cout << "dfds";
	if (ev->button() != Qt::LeftButton)
		return;
	QPoint temp = ev->pos();
	temp = turnMsPoint(temp);

}




void GameManager::playGameManger() {

}
bool GameManager::getNowplayer() {
	return current_player;
}
bool GameManager::getisEnd() {
	return isEnd;
}