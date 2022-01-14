/*************************************************************************
	> File Name: graph_item.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2021年12月21日 星期二 15时08分41秒
 ************************************************************************/

#ifndef _GAME_UNIT_H
#define _GAME_UNIT_H

#include <utility>
#include <QList>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "game_view.h"

#define TOTAL_REGION 100

#define TIMER_INTERVAL_MUSHROOM 1000
#define INCREAMENT_PER_TIMER_MUSHROOM 1 
#define MIN_REGION_MUSHROOM 0
#define MAX_REGION_MUSHROOM 91
#define MAX_LIFE_MUSHROOM 30

#define TIMER_INTERVAL_STONE 1000
#define INCREAMENT_PER_TIMER_STONE 1 
#define MIN_REGION_STONE 10
#define MAX_REGION_STONE 91
#define MAX_LIFE_STONE 30

#define TIMER_INTERVAL_FOOD 1000
#define INCREAMENT_PER_TIMER_FOOD 2 
#define MIN_REGION_FOOD 20
#define MAX_REGION_FOOD 60
#define MAX_LIFE_FOOD 1000

class GameView;

class BaseUnit : public QObject, public QGraphicsPixmapItem {
public:
    BaseUnit(quint32 width, quint32 height, QPointF pos = QPointF(-1, -1));

    int random(int min, int max);
    void AddLife();
    quint32 GetLife();
    QPointF GetPos();
    virtual void CheckTimeout();

private:
    quint32 life;
    QPointF pos;
};

// mushroom
class Mushroom : public BaseUnit {
    Q_OBJECT
public:
    enum MUSHROOM_LEVEL {
        MUSHROOM_LEVEL_NONE = 0,
        MUSHROOM_LEVEL_1,
        MUSHROOM_LEVEL_2
    };
    enum MUSHROOM_POISON {
        MUSHROOM_POISON_NONE = 0,
        MUSHROOM_POISON_1 = 10,
        MUSHROOM_POISON_2 = 20
    };
    typedef std::pair<MUSHROOM_LEVEL, MUSHROOM_POISON> TYPE_PAIR;
    Mushroom(GameView *view, qreal width, qreal height, QPointF pos = QPointF(-1, -1));
    TYPE_PAIR GetType();
    ~Mushroom();
    void CheckTimeout() override;

signals:
    void RequestRemoveMushroom(QGraphicsPixmapItem *mushroom);

public:
    static QList<Mushroom *> mushrooms; 

private:
    GameView *view;
    QTimer *timer;
    TYPE_PAIR type;
};

// stone
class Stone : public BaseUnit {
    Q_OBJECT
public:
    Stone(GameView *view, qreal width, qreal height, QPointF pos = QPointF(-1, -1));
    ~Stone();
    void CheckTimeout() override;

signals:
    void RequestRemoveStone(QGraphicsPixmapItem *stone);

public:
    GameView *view;
    QTimer *timer;
    static QList<Stone *> stones; 
};

// food
class Food : public BaseUnit {
    Q_OBJECT
public:
    enum FOOD_LEVEL {
        FOOD_LEVEL_NONE = 0,
        FOOD_LEVEL_1,
        FOOD_LEVEL_2,
        FOOD_LEVEL_3
    };
    enum FOOD_ENERGY {
        FOOD_ENERGY_NONE = 0,
        FOOD_ENERGY_1 = 2,
        FOOD_ENERGY_2 = 4,
        FOOD_ENERGY_3 = 6
    };
    typedef std::pair<FOOD_LEVEL, FOOD_ENERGY> TYPE_PAIR;
    
    Food(GameView *view, qreal width, qreal height, QPointF pos = QPointF(-1, -1));
    TYPE_PAIR GetType();
    ~Food();
    void CheckTimeout() override;

signals:
    void RequestRemoveFood(QGraphicsPixmapItem *food);

public:
    static QList<Food *> foods;
    
private:
    GameView *view;
    QTimer *timer;
    TYPE_PAIR type;
};

#endif
