/*************************************************************************
	> File Name: snake_unit.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2021年12月23日 星期四 10时47分26秒
 ************************************************************************/

#ifndef _SNAKE_UNIT_H
#define _SNAKE_UNIT_H

#include <set>
#include <cmath>
#include <QTimer>
#include <QGraphicsPixmapItem>

#include "game_view.h"

#define SNAKE_TIMER_BASE_INTERVAL 25
#define SNAKE_TIMER_INTERVAL 150
#define SNAKE_POSITION_INTERVAL 8
#define EVOLUTION_ENERGY 15

enum SNAKE_TYPE {
    SNAKE_TYPE_NONE = 0,
    SNAKE_TYPE_1,
    SNAKE_TYPE_2,
    SNAKE_TYPE_3,
    SNAKE_TYPE_4,
    SNAKE_TYPE_5,
    SNAKE_TYPE_6,
    SNAKE_TYPE_7,
    SNAKE_TYPE_8,
    SNAKE_TYPE_9,
    SNAKE_TYPE_10
};

enum SNAKE_DIRECTION {
    SNAKE_DIRECTION_NONE = 0,
    SNAKE_DIRECTION_UP = 1,
    SNAKE_DIRECTION_DOWN = 2,
    SNAKE_DIRECTION_LEFT = 4,
    SNAKE_DIRECTION_RIGHT = 8,
    SNAKE_DIRECTION_ALL = 15
};

enum AI_GRADE {
    AI_NORMAL = 5,
    AI_MEDIUM = 10,
    AI_DIFFICULT = 20
};

class Game;
class GameView;

class SnakeUnit : public QObject {
    Q_OBJECT
public:
    class Unit : public QGraphicsPixmapItem {
    public:
        SnakeUnit *parent;
        Unit(QGraphicsScene *scene, const QPixmap &img, 
             const QPointF &pos, SnakeUnit *parent = nullptr);
        ~Unit();
        void UpdateRotation(SNAKE_DIRECTION direction);
    };

    SnakeUnit(const QString &name, GameView *view = nullptr, 
            bool isAi = false, const quint32 &speed = SNAKE_TIMER_INTERVAL, 
            QPointF pos = QPointF(-1, -1), SNAKE_TYPE type = SNAKE_TYPE_1, 
            SNAKE_DIRECTION direction = SNAKE_DIRECTION_RIGHT, const quint32 size = 3);
    ~SnakeUnit();
    
    QString GetName() const;
    quint32 GetSize();
    quint32 GetScore();
    void IncreaseEnergy(const quint32 val);
    void DecreaseScore(const quint32 val);
    void IncreaseScore(const quint32 val);
    bool ChangeDirection(SNAKE_DIRECTION direction);
    void Update();
    void UpdateMove();
    void UpdateCollide();
    virtual void UpdateDirection();
    void UpdateCollideMushroom(QGraphicsItem *item);
    void UpdateCollideStone();
    void UpdateCollideFood(QGraphicsItem *item);
    void UpdateCollideSnake();

    bool IsAi();
    void Stop();
    void Continue();
    void WeakToNormal();
    void NormalToWeak();

signals:
    void RequestRemoveMushroom(QGraphicsPixmapItem *item);
    void RequestRemoveFood(QGraphicsPixmapItem *item);
    void RequestRemoveSnake(QObject *item);

public:
    static QList<SnakeUnit *> snakes;
    QList<Unit *> snake;

protected:
    const QString name;
    GameView *view;
    bool isAi;
    quint32 speed;
    quint32 size;
    quint32 energy;
    quint32 score;
    SNAKE_TYPE type;
    SNAKE_DIRECTION direction;
    QPixmap headImg, bodyImg, weakImg;
    QTimer *updateTimer, *weakTimer;
    QGraphicsSimpleTextItem *nameItem;
    QGraphicsEllipseItem *boundary;
};

class AiSnakeUnit : public SnakeUnit {
public:
    AiSnakeUnit(const QString &name, GameView *view = nullptr, 
            bool isAi = false, const quint32 &speed = SNAKE_TIMER_INTERVAL, 
            QPointF pos = QPointF(-1, -1), SNAKE_TYPE type = SNAKE_TYPE_1, 
            SNAKE_DIRECTION direction = SNAKE_DIRECTION_RIGHT, const quint32 size = 3);
    ~AiSnakeUnit();
    void UpdateDirection() override;
    SNAKE_DIRECTION AvoidCollide();
    SNAKE_DIRECTION EatFood();
    quint32 GetDirection(const QPointF &posSrc, const QPointF &posDst);
    SNAKE_DIRECTION RecommendDirection(SNAKE_DIRECTION curDirection, quint32 avalible);

public:
    static std::set<QString> aiNames;
    static AiSnakeUnit *GetAiInstance(GameView *view, const quint32 speed);
    static QString GetAiName();

private:
    AI_GRADE grade;
};

#endif
