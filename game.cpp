/*************************************************************************
	> File Name: game.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2021年12月21日 星期二 15时59分51秒
 ************************************************************************/

#include "log.h"
#include "game.h"

Game::Game() : view(nullptr), mode(GAME_MODE_NONE), level(GAME_LEVEL_NONE), gameView(nullptr),
    gameoverSingleModeView(nullptr), gameoverDoubleModeView(nullptr), gamemodeView(nullptr), 
    gameSingleModeInfoView(nullptr), gameDoubleModeInfoView(nullptr) {
    view = new GraphView(this);
    StartGameModeView();
    //gameoverDoubleModeView = new GameOverDoubleModeView(this, "knckinn", 1, 1, "cahng", 2, 2);
    LOG_DEBUG("game constructor");    
}

void Game::Exit() {
}

void Game::Show() {
    view->show();
}

GraphView *Game::GetView() {
    return view;
}

void Game::StartGameModeView() {
    view->EnableResize(true);
    gamemodeView = new GameModeView(this);
}

void Game::StartGameSingleModeInfoView() {
    view->EnableResize(true);
    gameSingleModeInfoView = new GameSingleModeInfoView(this);
    mode = GAME_MODE_SINGLE;
}

void Game::StartGameDoubleModeInfoView() {
    view->EnableResize(true);
    gameDoubleModeInfoView = new GameDoubleModeInfoView(this);
    mode = GAME_MODE_DOUBLE;
}

void Game::StartGameOverSingleModeView(QString name, quint32 score) {
    gameoverSingleModeView = new GameOverSingleModeView(this, name, 1, score);
}

void Game::StartGameOverDoubleModeView(QString winName, quint32 winScore, 
                                       QString loseName, quint32 loseScore) {
    gameoverDoubleModeView = new GameOverDoubleModeView(this, winName, 1, 
                                                        winScore, loseName, 2, loseScore);
}

#define CLEAR_ALL_VIEW(view) {                      \
    if (view) { view->close(); view = nullptr; }    \
}

void Game::ClearAllView() {
    CLEAR_ALL_VIEW(gameoverSingleModeView);
    CLEAR_ALL_VIEW(gameoverDoubleModeView);
    CLEAR_ALL_VIEW(gamemodeView);
    CLEAR_ALL_VIEW(gameSingleModeInfoView);
    CLEAR_ALL_VIEW(gameDoubleModeInfoView);
}

#undef CLEAR_ALL_VIEW

void Game::StartSingleModeGame(QString name, quint32 level) {
    view->EnableResize(false);
    GameInfo info(mode, static_cast<GAME_LEVEL>(level), name);
    ClearAllView();
    gameView = new GameView(info, this);
    gameView->StartGame();
}

void Game::StartDoubleModeGame(QString name1, quint32 level1, 
                               QString name2, quint32 level2) {
    view->EnableResize(false);
    GameInfo info(mode, static_cast<GAME_LEVEL>(level1), name1, name2);
    ClearAllView();
    gameView = new GameView(info, this);
    gameView->StartGame();
}


void Game::ResponseSingleModeChoose() {
    LOG_DEBUG("response single mode choose");
    ClearAllView();
    StartGameSingleModeInfoView();
}

void Game::ResponseDoubleModeChoose() {
    LOG_DEBUG("response double mode choose");
    ClearAllView();
    StartGameDoubleModeInfoView();
}

void Game::ResponseReturnModeChoose() {
    LOG_DEBUG("return mode choose view");
    ClearAllView();
    StartGameModeView();
}

void Game::ResponseGetSingleModeInfo(QString name, quint32 level) {
    LOG_DEBUG("name: %s, level: %d", name.toStdString().c_str(), level);
    if (name.isEmpty()) {
        gameSingleModeInfoView->SetContentNameHint("*姓名不能为空", QColor(255, 0, 0));
        return;
    } else {
        gameSingleModeInfoView->SetContentNameHint("姓名合法", Qt::green);
    }
    
    if (level <= GAME_LEVEL_NONE || level >= GAME_LEVEL_MAX) {
        gameSingleModeInfoView->SetContentLevelHint("*等级不合法", QColor(255, 0, 0));
        return;
    } else {
        gameSingleModeInfoView->SetContentLevelHint("等级合法", Qt::green);
    }
    this->level = static_cast<GAME_LEVEL>(level);
    StartSingleModeGame(name, level);
}

void Game::ResponseGetDoubleModeInfo(quint32 type1, QString name1, quint32 level1, 
                                     quint32 type2, QString name2, quint32 level2) {
    LOG_DEBUG("type: %d, name: %s, level: %d", type1, name1.toStdString().c_str(), level1);    
    LOG_DEBUG("type: %d, name: %s, level: %d", type2, name2.toStdString().c_str(), level2);    

    if (name1.isEmpty()) {
        gameDoubleModeInfoView->SetContentNameHint(type1, "*姓名不能为空", Qt::red);
        return;
    } else {
        gameDoubleModeInfoView->SetContentNameHint(type1, "姓名合法", Qt::green);
    }

    if (level1 <= GAME_LEVEL_NONE || level1 >= GAME_LEVEL_MAX) {
        gameDoubleModeInfoView->SetContentLevelHint(type1, "*等级不合法", Qt::red);
        return;
    } else {
        gameDoubleModeInfoView->SetContentLevelHint(type1, "等级合法", Qt::green);
    }

    if (name2.isEmpty()) {
        gameDoubleModeInfoView->SetContentNameHint(type2, "*姓名不能为空", Qt::red);
        return;
    } else {
        gameDoubleModeInfoView->SetContentNameHint(type2, "姓名合法", Qt::green);
    }

    if (level2 <= GAME_LEVEL_NONE || level2 >= GAME_LEVEL_MAX) {
        gameDoubleModeInfoView->SetContentLevelHint(type2, "*等级不合法", Qt::red);
        return;
    } else {
        gameDoubleModeInfoView->SetContentLevelHint(type2, "等级合法", Qt::green);
    }

    if (name1 == name2) {
        gameDoubleModeInfoView->SetContentNameHint(type1, "*姓名不能相同", Qt::red);
        gameDoubleModeInfoView->SetContentNameHint(type2, "*姓名不能相同", Qt::red);
        return;
    }

    if (level1 != level2) {
        gameDoubleModeInfoView->SetContentLevelHint(type1, "*等级必须一致", Qt::red);
        gameDoubleModeInfoView->SetContentLevelHint(type2, "*等级必须一致", Qt::red);
        return;
    }
    
    this->level = static_cast<GAME_LEVEL>(level1);
    StartDoubleModeGame(name1, level1, name2, level2);
}

void Game::ResponseSingleModeOver(QString name, quint32 score) {
    //LOG_DEBUG("<single mode> name: %s, score: %d", 
                                //name.toStdString().c_str(), score);
    StartGameOverSingleModeView(name, score);
}

void Game::ResponseDoubleModeOver(QString winName, quint32 winScore,
                               QString loseName, quint32 loseScore) {
    //LOG_DEBUG("<double mode> winner: %s, score: %d", 
                                   //winName.toStdString().c_str(), winScore);
    //LOG_DEBUG("<double mode> loser: %s, score: %d", 
                                   //loseName.toStdString().c_str(), loseScore);
    StartGameOverDoubleModeView(winName, winScore, loseName, loseScore);
}

void Game::ResponseGameReplay() {
    LOG_DEBUG("response game replay");
    ClearAllView();
    if (!gameView) {
        LOG_ERROR("game view is null");
        return;
    }
    gameView->StartGame();
}

void Game::ResponseGameRestart() {
    LOG_DEBUG("response game restart");
    ClearAllView();
    delete(gameView);
    gameView = nullptr;
    StartGameModeView();
}

void Game::ResponseExitGame() {
    LOG_DEBUG("response exit game");
}

void Game::resizeEvent(QResizeEvent *event) {
    QSize size = event->size();
    //LOG_DEBUG("size width: %d, height: %d", size.width(), size.height()); 
    view->setSceneRect(0, 0, size.width(), size.height());
    if (gameoverSingleModeView) gameoverSingleModeView->resize(size); 
    if (gameoverDoubleModeView) gameoverDoubleModeView->resize(size); 
    if (gamemodeView) gamemodeView->resize(size);  
    if (gameSingleModeInfoView) gameSingleModeInfoView->resize(size);
    if (gameDoubleModeInfoView) gameDoubleModeInfoView->resize(size);
}
