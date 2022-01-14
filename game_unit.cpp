/*************************************************************************
	> File Name: graph_item.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2021年12月21日 星期二 15时09分20秒
 ************************************************************************/

#include "log.h"
#include "game_unit.h"

#define ADD_TIMER(item, interval) {         \
    timer = new QTimer(this);               \
    connect(timer, &QTimer::timeout,        \
            this, &item::CheckTimeout);     \
    timer->start(interval);                 \
}

#define CONNECT_ITEM(item) connect(this, &item::RequestRemove##item, \
                                   view, &GameView::ResponseRemove##item)

#define CHECKOUT_TIMEOUT(item, max_life) {                      \
    if (!timer) { LOG_ERROR(#item " timer is null"); return; }  \
    AddLife();                                                  \
    if (GetLife() > max_life) { RequestRemove##item(this); }    \
}


BaseUnit::BaseUnit(quint32 width, quint32 height, 
                   QPointF pos) : life(0), pos(pos) {
    if (pos.x() == -1 && pos.y() == -1) {
        pos = QPointF(random(0, width - 1), random(0, height - 1));
    } 
    setPos(pos);
};

int BaseUnit::random(int min, int max) {
    if (min > max) return -1;

    int ans = min;
    ans += rand() % (max - min + 1);
    return ans;
}

void BaseUnit::AddLife() {
    ++life;
}

quint32 BaseUnit::GetLife() {
    return life;
}

QPointF BaseUnit::GetPos() {
    return pos;
}

void BaseUnit::CheckTimeout() {
    return;
}

// Mushroom
QList<Mushroom *> Mushroom::mushrooms;

Mushroom::Mushroom(GameView *view, qreal width, qreal height, QPointF pos) : 
    BaseUnit(width, height, pos), view(view), timer(nullptr),
    type(TYPE_PAIR(MUSHROOM_LEVEL_NONE, MUSHROOM_POISON_NONE)) {
    if (random(1, 2) == 1) {
        type.first = MUSHROOM_LEVEL_1; type.second = MUSHROOM_POISON_1;
    } else {
        type.first = MUSHROOM_LEVEL_2; type.second = MUSHROOM_POISON_2;
    }

    QPixmap img("../res/mushroom/mushroom" + QString::number(type.first) + ".png");
    if (img.isNull()) {
        LOG_DEBUG("mushroom img resource is null");
    }
    setPixmap(img);

    QGraphicsScene *scene = view->GetScene();
    if (!scene) {
        LOG_ERROR("scene is null");
    }
    scene->addItem(this);
    mushrooms.append(this);

    ADD_TIMER(Mushroom, 1000);
    CONNECT_ITEM(Mushroom);
    //LOG_DEBUG("mushroom %d position: x %lf, y %lf", GetType().first, GetPos().x(), GetPos().y());
}

Mushroom::~Mushroom() {
    QGraphicsScene *scene = view->GetScene();
    if (!scene) {
        LOG_ERROR("scene is null");
    }
    scene->removeItem(this);
}

Mushroom::TYPE_PAIR Mushroom::GetType() {
    return type;
}

void Mushroom::CheckTimeout() {
    CHECKOUT_TIMEOUT(Mushroom, MAX_LIFE_MUSHROOM);
}

//Stone
QList<Stone *> Stone::stones;

Stone::Stone(GameView *view, qreal width, qreal height, QPointF pos) : 
    BaseUnit(width, height, pos), view(view), timer(nullptr) {
    QPixmap img("../res/stone/stone.png");
    if (img.isNull()) {
        LOG_DEBUG("stone img resource is null");
    }
    setPixmap(img);
   
    QGraphicsScene *scene = view->GetScene();
    if (!scene) {
        LOG_ERROR("scene is null");
    }
    scene->addItem(this);
    stones.append(this);

    ADD_TIMER(Stone, 1000);
    CONNECT_ITEM(Stone);
    //LOG_DEBUG("stone position: x %lf, y %lf", GetPos().x(), GetPos().y());
}

Stone::~Stone() {
    QGraphicsScene *scene = view->GetScene();
    if (!scene) {
        LOG_ERROR("scene is null");
    }
    scene->removeItem(this);
}

void Stone::CheckTimeout() {
    CHECKOUT_TIMEOUT(Stone, MAX_LIFE_STONE);
}

// food
QList<Food *> Food::foods;

Food::Food(GameView *view, qreal width, qreal height, QPointF pos) : 
    BaseUnit(width, height, pos), view(view), timer(nullptr), 
    type(TYPE_PAIR(FOOD_LEVEL_NONE, FOOD_ENERGY_NONE)) {
    QPixmap img("../res/food/food" + QString::number(random(1, 7)) + ".png");
    if (img.isNull()) {
        LOG_DEBUG("food img resource is null");
    }
    setPixmap(img);

    switch(random(1, 3)) {
        case 1: {
            type = TYPE_PAIR(FOOD_LEVEL_1, FOOD_ENERGY_1);
            setScale(0.25);
        } break;
        case 2: {
            type = TYPE_PAIR(FOOD_LEVEL_2, FOOD_ENERGY_2);
            setScale(0.5);
        } break;
        case 3: {
            type = TYPE_PAIR(FOOD_LEVEL_3, FOOD_ENERGY_3);
            setScale(1.0);
        } break;
        default: LOG_DEBUG("food type error");
    }

    QGraphicsScene *scene = view->GetScene();
    if (!scene) {
        LOG_ERROR("scene is null");
    }
    scene->addItem(this);
    foods.append(this);

    CONNECT_ITEM(Food);
    ADD_TIMER(Food, 1000);
    //LOG_DEBUG("food position: level %d x %lf, y %lf", GetType().first, GetPos().x(), GetPos().y());
}

Food::~Food() {
    QGraphicsScene *scene = view->GetScene();
    if (!scene) {
        LOG_ERROR("scene is null");
    }
    scene->removeItem(this);
}

Food::TYPE_PAIR Food::GetType() {
    return type;
}

void Food::CheckTimeout() {
    CHECKOUT_TIMEOUT(Food, MAX_LIFE_FOOD);
}
