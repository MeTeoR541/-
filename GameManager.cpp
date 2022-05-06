#include "GameManager.h"
GameManager::GameManager() {
	current_player = true;
	isEnd = false;
}
void GameManager::playGameManger() {

}
bool GameManager::getNowplayer() {
	return current_player;
}
bool GameManager::getisEnd() {
	return isEnd;
}