/*************************************************************************
	> File Name: Game.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2021年12月21日 星期二 15时51分41秒
 ************************************************************************/

#ifndef _GAME_H
#define _GAME_H

#include "graph_view.h"
#include "game_mode_view.h"
#include "game_mode_info_view.h"
#include "game_over_view.h"
#include "game_view.h"

class GraphView;
class GameView;
class GameOverSingleModeView;
class GameOverDoubleModeView;
class GameModeView;
class GameSingleModeView;
class GameSingleModeInfoView;
class GameDoubleModeInfoView;

enum GAME_MODE {
    GAME_MODE_NONE,
    GAME_MODE_SINGLE,
    GAME_MODE_DOUBLE,
    GAME_MODE_MAX
};

enum GAME_LEVEL {
    GAME_LEVEL_NONE,
    GAME_LEVEL_1,
    GAME_LEVEL_2,
    GAME_LEVEL_3,
    GAME_LEVEL_MAX
};

struct GameInfo {
    GAME_MODE mode;
    GAME_LEVEL level;
    QString name1, name2;
    GameInfo(GAME_MODE mode = GAME_MODE_NONE, GAME_LEVEL level = GAME_LEVEL_NONE, 
            QString name1 = nullptr, QString name2 = nullptr) : mode(mode), 
            level(level), name1(name1), name2(name2) {}
};

class Game : public QGraphicsView {
    Q_OBJECT
public:
    Game();
    
    void Exit();
    void Show();
    GraphView *GetView();
    
    void StartGameModeView();
    void StartGameSingleModeInfoView();
    void StartGameDoubleModeInfoView();
    //void StartGameView();
    void StartGameOverSingleModeView(QString name, quint32 score);
    void StartGameOverDoubleModeView(QString winName, quint32 winScore, 
                                     QString loseName, quint32 loseScore);
    void ClearAllView();
    
    void StartSingleModeGame(QString name, quint32 level);
    void StartDoubleModeGame(QString name1, quint32 level1, QString name2, quint32 level2);

    void resizeEvent(QResizeEvent *event) override;
    
public slots:
    //void ResponseGameOver(QObject *item); 
    void ResponseSingleModeChoose();
    void ResponseDoubleModeChoose();
    void ResponseReturnModeChoose();
    void ResponseGetSingleModeInfo(QString name, quint32 level);
    void ResponseGetDoubleModeInfo(quint32 type1, QString name1, quint32 level1, 
                                   quint32 type2, QString name2, quint32 level2);
    void ResponseSingleModeOver(QString name, quint32 score);
    void ResponseDoubleModeOver(QString winName, quint32 winScore, 
                               QString loseName, quint32 loseScore);
    void ResponseGameReplay();
    void ResponseGameRestart();
    void ResponseExitGame();

public:
    GraphView *view;    
    GAME_MODE mode;
    GAME_LEVEL level; 

    GameView *gameView;
    GameOverSingleModeView *gameoverSingleModeView;
    GameOverDoubleModeView *gameoverDoubleModeView;
    GameModeView *gamemodeView;
    GameSingleModeInfoView *gameSingleModeInfoView;
    GameDoubleModeInfoView *gameDoubleModeInfoView;
};

#endif
