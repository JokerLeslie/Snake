/*************************************************************************
	> File Name: game_view.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月10日 星期一 14时33分28秒
 ************************************************************************/
#include "log.h"
#include "game_view.h"

#define ADD_TIMER(item, interval) {                 \
    if (!timer##item) {                             \
        timer##item = new QTimer(this);             \
        if (timer##item) {                          \
            connect(timer##item, &QTimer::timeout,  \
            this, &GameView::Add##item);            \
            timer##item->start(interval);           \
        } else {                                    \
            LOG_ERROR(#item " timer is null");      \
        }                                           \
    } else {                                        \
        timer##item->start(interval);               \
    }                                               \
}

#define ADD_ITEM(item, min_region, max_region, ...) {           \
    GraphView *view;                                            \
    if (!(view = parent->GetView())) { LOG_ERROR("graph view is null"); return; }     \
    int num = rand() % TOTAL_REGION;                            \
    if (num >= min_region && num <= max_region) {               \
        item *p = new item(this, view->sceneRect().width() - 5, \
                        view->sceneRect().height() - 5, ##__VA_ARGS__); }   \
}

#define DESTROY_ITEM(p, item, sets) { \
    item *iter = dynamic_cast<item *>(p); \
    if (!iter) { LOG_ERROR("transform " #item " error"); return; } \
    int index = item::sets.indexOf(iter); \
    if (index == -1) { LOG_DEBUG(#item " has been destroyed"); return; } \
    item::sets.removeAt(index); \
    delete iter; \
}

GameView::GameView(const GameInfo &info, Game *parent) : info(new GameInfo(info)), 
            parent(parent), snake1(nullptr), snake2(nullptr), timerMushroom(nullptr), 
            timerStone(nullptr), timerFood(nullptr), isPause(false), isEnd(false) {
    GraphView *view;
    if (parent && (view = parent->GetView())) {
        setRect(view->sceneRect()); 
        view->scene->addItem(this);
        setFlags(flags() | QGraphicsItem::ItemIsFocusable);
        setFocus();
    }
    connect(this, &GameView::RequestSingleModeOver, parent, &Game::ResponseSingleModeOver);    
    connect(this, &GameView::RequestDoubleModeOver, parent, &Game::ResponseDoubleModeOver);    
}

GameView::~GameView(){
    ClearPropUnits();
    delete info;
}

void GameView::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);
    Q_UNUSED(option);

    QRectF frame(QPointF(0, 0), rect().size());
    QPixmap bg_img("../res/background/back.jpg");
    
    if (bg_img.isNull()) {
        LOG_DEBUG("background resource img is null");
    }
    QBrush bgBrush(bg_img);
    painter->fillRect(frame, bgBrush);
}

void GameView::keyPressEvent(QKeyEvent *event) {
    if (!isEnd) {
        switch(event->key()) {
            case Qt::Key_Up: snake1 && snake1->ChangeDirection(SNAKE_DIRECTION_UP); break;
            case Qt::Key_Down: snake1 && snake1->ChangeDirection(SNAKE_DIRECTION_DOWN); break;
            case Qt::Key_Left: snake1 && snake1->ChangeDirection(SNAKE_DIRECTION_LEFT); break;
            case Qt::Key_Right: snake1 && snake1->ChangeDirection(SNAKE_DIRECTION_RIGHT); break;
            case Qt::Key_W: snake2 && snake2->ChangeDirection(SNAKE_DIRECTION_UP); break;
            case Qt::Key_S: snake2 && snake2->ChangeDirection(SNAKE_DIRECTION_DOWN); break;
            case Qt::Key_A: snake2 && snake2->ChangeDirection(SNAKE_DIRECTION_LEFT); break;
            case Qt::Key_D: snake2 && snake2->ChangeDirection(SNAKE_DIRECTION_RIGHT); break;
            case Qt::Key_Space: {
                if (!isPause) StopGame();
                else ContinueGame();
                isPause ^= true;
            } break;
            default: LOG_DEBUG("key event error");
        }
    }
}

void GameView::AddMushroom() {
    for (int i = 0; i < INCREAMENT_PER_TIMER_MUSHROOM; i++) {
        ADD_ITEM(Mushroom, MIN_REGION_MUSHROOM, MAX_REGION_MUSHROOM);
    }
}

void GameView::AddStone() {
    for (int i = 0; i < INCREAMENT_PER_TIMER_STONE; i++) {
        ADD_ITEM(Stone, MIN_REGION_STONE, MAX_REGION_STONE);
    }
}

void GameView::AddFood() {
    for (int i = 0; i < INCREAMENT_PER_TIMER_FOOD; i++) {
        ADD_ITEM(Food, MIN_REGION_FOOD, MAX_REGION_FOOD);
    }
}

void GameView::InitPropUnits() {
    srand(time(0));
    for (int i = 0; i < 100; i++) { AddFood(); }
    ADD_TIMER(Mushroom, TIMER_INTERVAL_MUSHROOM);
    ADD_TIMER(Stone, TIMER_INTERVAL_STONE);
    ADD_TIMER(Food, TIMER_INTERVAL_FOOD);
}

void GameView::ClearPropUnits() {
    for (auto iter = SnakeUnit::snakes.begin();
         iter != SnakeUnit::snakes.end();) {
        delete(*iter);
        iter = SnakeUnit::snakes.erase(iter);
    }
    snake1 = nullptr;
    snake2 = nullptr;

    for (auto iter = Mushroom::mushrooms.begin();
         iter != Mushroom::mushrooms.end();) {
        delete(*iter);
        iter = Mushroom::mushrooms.erase(iter);
    }
    for (auto iter = Stone::stones.begin();
         iter != Stone::stones.end();) {
        delete(*iter);
        iter = Stone::stones.erase(iter);
    }
    for (auto iter = Food::foods.begin();
         iter != Food::foods.end();) {
        delete(*iter);
        iter = Food::foods.erase(iter);
    }
}

QGraphicsScene* GameView::GetScene() {
    GraphView *view;
    if (!(view = parent->GetView())) {
        LOG_DEBUG("view is null");
        return nullptr;
    }
    return view->scene;
}

void GameView::StartGame() {
    if (!parent || !GetScene()) {
        LOG_ERROR("game or view instance error");
        return;
    }
    
    setFocus();
    ClearPropUnits();
    quint32 speed = SNAKE_TIMER_INTERVAL - 
                    info->level * SNAKE_TIMER_BASE_INTERVAL; 
    LOG_DEBUG("speed: %d", speed);
    if (info->mode == GAME_MODE_SINGLE) {
        InitPropUnits();
        snake1 = new SnakeUnit(info->name1, this, false, speed);
        for (int i = 0; i < 10; i++) {
            AiSnakeUnit::GetAiInstance(this, speed);
        }
        isEnd = false;
    } else if (info->mode == GAME_MODE_DOUBLE) {
        InitPropUnits();
        qreal width = GetScene()->sceneRect().width();
        qreal height = GetScene()->sceneRect().height();
        QPointF pos1(width / 4, height / 2);
        QPointF pos2(3 * width / 4, height / 2);
        snake1 = new SnakeUnit(info->name1, this, false, speed, pos1);
        snake2 = new SnakeUnit(info->name2, this, false, speed, pos2);
        isEnd = false;
    } else {
        LOG_DEBUG("game mode error");
    }
}

void GameView::StopGame() {
    for (int i = 0; i < SnakeUnit::snakes.size(); i++) {
        SnakeUnit::snakes[i]->Stop();
    }
}

void GameView::ContinueGame() {
    for (int i = 0; i < SnakeUnit::snakes.size(); i++) {
        SnakeUnit::snakes[i]->Continue();
    }
}

void GameView::ResponseRemoveMushroom(QGraphicsPixmapItem *item) {
    DESTROY_ITEM(item, Mushroom, mushrooms);
}

void GameView::ResponseRemoveStone(QGraphicsPixmapItem *item) {
    DESTROY_ITEM(item, Stone, stones);
}

void GameView::ResponseRemoveFood(QGraphicsPixmapItem *item) {
    DESTROY_ITEM(item, Food, foods);
}

void GameView::ResponseRemoveSnake(QObject *item) {
    SnakeUnit *deadSnake = dynamic_cast<SnakeUnit *>(item);
    
    if (!deadSnake) {
        LOG_ERROR("snake transform error");    
        return;
    }
    LOG_DEBUG("mode: %d, name: %s", info->mode, deadSnake->GetName().toStdString().c_str());
    
    if (deadSnake->IsAi()) {
        DESTROY_ITEM(item, SnakeUnit, snakes);
        return; 
    } 

    StopGame();
    isEnd = true;
    if (info->mode == GAME_MODE_SINGLE) {
        RequestSingleModeOver(snake1->GetName(), snake1->GetScore());
        DESTROY_ITEM(item, SnakeUnit, snakes);
        snake1 = nullptr;
    } else if (info->mode == GAME_MODE_DOUBLE) {
        if (deadSnake->GetName() == snake1->GetName()) {
            RequestDoubleModeOver(snake2->GetName(), snake2->GetScore(), 
                                  snake1->GetName(), snake1->GetScore());
            DESTROY_ITEM(item, SnakeUnit, snakes);
            snake1 = nullptr;
        } else {
            RequestDoubleModeOver(snake1->GetName(), snake1->GetScore(), 
                                  snake2->GetName(), snake2->GetScore());
            DESTROY_ITEM(item, SnakeUnit, snakes);
            snake2 = nullptr;
        }
    }
}
