/*************************************************************************
	> File Name: game_view.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月10日 星期一 14时33分09秒
 ************************************************************************/

#ifndef _GAME_VIEW_H
#define _GAME_VIEW_H

#include <QGraphicsRectItem>
#include "game.h"
#include "game_unit.h"
#include "snake_unit.h"

class SnakeUnit;
class AiSnakeUnit;
struct GameInfo;

class GameView : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    GameView(const GameInfo &info, Game *parent = nullptr);
    ~GameView();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    void keyPressEvent(QKeyEvent *event) override;

    QGraphicsScene* GetScene();
    
    void AddMushroom();
    void AddStone();
    void AddFood();
    void InitPropUnits();
    void ClearPropUnits();
    void StartGame();
    void StopGame();
    void ContinueGame();

signals:
    void RequestSingleModeOver(QString name, quint32 score);
    void RequestDoubleModeOver(QString winName, quint32 winScore, 
                               QString loseName, quint32 loseScore);

public slots:
    void ResponseRemoveMushroom(QGraphicsPixmapItem *item);
    void ResponseRemoveStone(QGraphicsPixmapItem *item);
    void ResponseRemoveFood(QGraphicsPixmapItem *item); 
    void ResponseRemoveSnake(QObject *item);

private:
    GameInfo *info;
    Game *parent;
    SnakeUnit *snake1, *snake2; 
    QTimer *timerMushroom;
    QTimer *timerStone;
    QTimer *timerFood;
    bool isPause;
    bool isEnd;
};

#endif
