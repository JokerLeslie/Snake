/*************************************************************************
	> File Name: snake_unit.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2021年12月23日 星期四 10时53分07秒
 ************************************************************************/

#include "log.h"
#include "snake_unit.h"

QList<SnakeUnit *> SnakeUnit::snakes;

#define LOAD_IMG(img, path) {                   \
    img = QPixmap(path);                        \
    if (img.isNull()) {                         \
        LOG_ERROR("resource %s is null",        \
                 path.toStdString().c_str());   \
    }                                           \
}

SnakeUnit::Unit::Unit(QGraphicsScene *scene, const QPixmap &img, 
    const QPointF &pos, SnakeUnit *parent) : 
    QGraphicsPixmapItem(img), parent(parent) {
    setPos(pos);
    if (scene) scene->addItem(this);
} 

SnakeUnit::Unit::~Unit() {
    parent->view->GetScene()->removeItem(this);
}

void SnakeUnit::Unit::UpdateRotation(SNAKE_DIRECTION direction) {
    setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);
    switch (direction) {
        case SNAKE_DIRECTION::SNAKE_DIRECTION_UP:
            setRotation(0);
            break;
        case SNAKE_DIRECTION::SNAKE_DIRECTION_DOWN:
            setRotation(180);
            break;
        case SNAKE_DIRECTION::SNAKE_DIRECTION_LEFT:
            setRotation(270);
            break;
        case SNAKE_DIRECTION::SNAKE_DIRECTION_RIGHT:
            setRotation(90);
            break;
        default:
            break;
    }
}

SnakeUnit::SnakeUnit(const QString &name, GameView *view, bool isAi, const quint32 &speed,
    QPointF pos, SNAKE_TYPE type, SNAKE_DIRECTION direction, const quint32 size) : 
    name(name), view(view), isAi(isAi), speed(speed), energy(0), score(0), type(type), 
    direction(direction), size(3), nameItem(nullptr), boundary(nullptr) {

    QString headImgPath = "../res/snake/snakeUnit" 
        + QString::number(type) + "Head.png";
    LOAD_IMG(headImg, headImgPath);

    QString bodyImgPath = "../res/snake/snakeUnit" 
        + QString::number(type) + ".png";
    LOAD_IMG(bodyImg, bodyImgPath);

    QString weakImgPath = "../res/snake/snakeWeak.png";
    LOAD_IMG(weakImg, weakImgPath);

    QGraphicsScene *scene;
    if (view && (scene = view->GetScene())) {
        if (pos == QPointF(-1, -1)) {
            pos.setX(scene->sceneRect().width() / 2); 
            pos.setY(scene->sceneRect().height() / 2);
        }
        Unit *head = new Unit(scene, headImg, pos, this);
        head->UpdateRotation(direction);
        snake.append(head);

        nameItem = new QGraphicsSimpleTextItem(name);
        nameItem->setFont(QFont("calibri", 9));
        nameItem->setBrush(Qt::white);
        nameItem->setPos(QPointF(pos.x() + 15, pos.y() + 15));
        scene->addItem(nameItem);
       
        boundary = new QGraphicsEllipseItem(QRectF(0, 0, 50, 50));
        boundary->setPos(pos.x() + (headImg.width() - 50) / 2, 
                         pos.y() + (headImg.height() - 50) / 2);
        boundary->setPen(QPen(Qt::transparent));
        scene->addItem(boundary); 

        for (int i = 1; i < size; i++) {
            pos.setX(pos.x() - SNAKE_POSITION_INTERVAL);
            Unit *body = new Unit(scene, bodyImg, pos, this);
            snake.append(body);
        }

        updateTimer = new QTimer(this);
        connect(updateTimer, &QTimer::timeout, this, &SnakeUnit::Update);
        updateTimer->start(speed);

        weakTimer = new QTimer(this);
        weakTimer->setSingleShot(true);
        connect(weakTimer, &QTimer::timeout, this, &SnakeUnit::WeakToNormal);
    }

    connect(this, &SnakeUnit::RequestRemoveMushroom, 
            view, &GameView::ResponseRemoveMushroom);
    connect(this, &SnakeUnit::RequestRemoveFood, 
            view, &GameView::ResponseRemoveFood);
    connect(this, &SnakeUnit::RequestRemoveSnake, 
            view, &GameView::ResponseRemoveSnake);

    snakes.append(this);
}

SnakeUnit::~SnakeUnit() {
    QGraphicsScene *scene;
    if (view && (scene = view->GetScene())) {
        for (int i = 0; i < snake.size(); i++) {
            new Food(view, scene->sceneRect().width() - 5, 
                     scene->sceneRect().height() - 5, QPointF(snake[i]->pos())); 
            new Food(view, scene->sceneRect().width() - 5, 
                     scene->sceneRect().height() - 5, QPointF(snake[i]->pos())); 
            delete snake[i];
        } 
    }
    scene->removeItem(nameItem);
    delete(nameItem);
    scene->removeItem(boundary);
    delete(boundary);
    LOG_DEBUG("~SnakeUnit");
}

QString SnakeUnit::GetName() const {
    return name;
}

quint32 SnakeUnit::GetSize() {
    return size;
}

quint32 SnakeUnit::GetScore() {
    return score;
}

void SnakeUnit::IncreaseEnergy(const quint32 val) {
    energy += val;
    int addLength = energy / EVOLUTION_ENERGY;
    if (addLength) {    
        if (!view) {
            LOG_ERROR("snake unit lacking game view");
            return;
        }
        
        QGraphicsScene *scene = view->GetScene();
        if (!scene) {
            LOG_ERROR("snake unit lacking scene");
            return;
        }
        
        for (int i = 0; i < addLength; i++) {
            QPointF pos(-100, -100);
            Unit *body = new Unit(scene, bodyImg, pos, this);
            snake.append(body);
        }
        energy %= 10;
    }
}

void SnakeUnit::DecreaseScore(const quint32 val) {
    if (score < val) { score = 0; return; }
    score -= val;
    //LOG_DEBUG("Decrease score: %d, Present score: %d", val, score);
}

void SnakeUnit::IncreaseScore(const quint32 val) {
    score += val;
    //LOG_DEBUG("Increase score: %d, Present score: %d", val, score);
}

bool SnakeUnit::ChangeDirection(SNAKE_DIRECTION direction) {
    switch (direction) {
        case SNAKE_DIRECTION::SNAKE_DIRECTION_UP: {
            if (this->direction != SNAKE_DIRECTION::SNAKE_DIRECTION_DOWN) {
                this->direction = SNAKE_DIRECTION::SNAKE_DIRECTION_UP;
            }
        } break;
        case SNAKE_DIRECTION::SNAKE_DIRECTION_DOWN: {
            if (this->direction != SNAKE_DIRECTION::SNAKE_DIRECTION_UP) {
                this->direction = SNAKE_DIRECTION::SNAKE_DIRECTION_DOWN;
            }
        } break;
        case SNAKE_DIRECTION::SNAKE_DIRECTION_LEFT: {
            if (this->direction != SNAKE_DIRECTION::SNAKE_DIRECTION_RIGHT) {
                this->direction = SNAKE_DIRECTION::SNAKE_DIRECTION_LEFT;
            }
        } break;
        case SNAKE_DIRECTION::SNAKE_DIRECTION_RIGHT: {
            if (this->direction != SNAKE_DIRECTION::SNAKE_DIRECTION_LEFT) {
                this->direction = SNAKE_DIRECTION::SNAKE_DIRECTION_RIGHT;
            }
        } break;
        default:
            LOG_ERROR("direction error");
            return false;
    }
    snake[0]->UpdateRotation(this->direction);
    return true;
}

bool SnakeUnit::IsAi() {
    return isAi;
}

void SnakeUnit::Stop() {
    if (updateTimer->isActive()) updateTimer->stop();
    if (weakTimer->isActive()) weakTimer->stop();
}

void SnakeUnit::Continue() {
    updateTimer->start(speed);
    //weakTimer->start();
}

void SnakeUnit::Update() {
    UpdateMove();
    UpdateDirection();
    UpdateCollide();
}

void SnakeUnit::UpdateMove() {
    for (int i = snake.size() - 1; i >= 1; --i) {
        snake[i]->setX(snake[i - 1]->x());
        snake[i]->setY(snake[i - 1]->y());
    }

    QGraphicsScene *scene;
    if (!view || !(scene = view->GetScene())) {
        LOG_ERROR("scene is null");
        return;
    }

    qreal viewWidth = scene->sceneRect().width();
    qreal viewHeight = scene->sceneRect().height();
    qreal headX = snake[0]->x();
    qreal headY = snake[0]->y();
    switch (this->direction) {
        case SNAKE_DIRECTION::SNAKE_DIRECTION_UP: {
            headY -= SNAKE_POSITION_INTERVAL;
            if (headY >= 0) snake[0]->setY(headY);
            else snake[0]->setY(viewHeight - 1);
        } break;
        case SNAKE_DIRECTION::SNAKE_DIRECTION_DOWN: {
            headY += SNAKE_POSITION_INTERVAL;
            if (headY < viewHeight) snake[0]->setY(headY);
            else snake[0]->setY(0);
        } break;
        case SNAKE_DIRECTION::SNAKE_DIRECTION_LEFT: {
            headX -= SNAKE_POSITION_INTERVAL;
            if (headX >= 0) snake[0]->setX(headX);
            else snake[0]->setX(viewWidth - 1);
        } break;
        case SNAKE_DIRECTION::SNAKE_DIRECTION_RIGHT: {
            headX += SNAKE_POSITION_INTERVAL;
            if (headX < viewWidth) snake[0]->setX(headX);
            else snake[0]->setX(0);
        } break;
        default:
            LOG_ERROR("direction error");
            break;
    }
    boundary->setPos(QPointF(snake[0]->x() + (headImg.width() - 50) / 2, 
                             snake[0]->y() + (headImg.height() - 50) / 2));
    nameItem->setPos(QPointF(snake[0]->x() + 15, snake[0]->y() + 15));
}

void SnakeUnit::UpdateCollide() {
    QGraphicsPixmapItem *head = snake[0];
    QList<QGraphicsItem *> list = head->collidingItems();
    for (int i = 0; i < list.size(); i++) {
        if (dynamic_cast<Mushroom *>(list[i])) {
            UpdateCollideMushroom(list[i]);
        } else if (dynamic_cast<Stone *>(list[i])) {
            UpdateCollideStone();
            break;  //如果不break，主线程会直接销毁snake，再次运行出现段错误
        } else if (dynamic_cast<Food *>(list[i])) {
            UpdateCollideFood(list[i]);
        } else if (dynamic_cast<SnakeUnit::Unit *>(list[i])) {
            SnakeUnit::Unit *p = dynamic_cast<SnakeUnit::Unit *>(list[i]);
            if (p->parent == this) { continue; }
            UpdateCollideSnake();
            break;
        } else {
            //LOG_DEBUG("transform error");
        }
    }
}

void SnakeUnit::UpdateDirection() {
}

void SnakeUnit::UpdateCollideMushroom(QGraphicsItem *item) {
    Mushroom *p = dynamic_cast<Mushroom *>(item);
    Mushroom::TYPE_PAIR type = p->GetType();
    DecreaseScore(type.second);
    if (!weakTimer->isActive()) {
        //NormalToWeak();
        //weakTimer->start(3000);
    }
    RequestRemoveMushroom(static_cast<QGraphicsPixmapItem *>(p));
}

void SnakeUnit::UpdateCollideStone() {
    RequestRemoveSnake(this);
}

void SnakeUnit::UpdateCollideFood(QGraphicsItem *item) {
    Food *p = dynamic_cast<Food *>(item);
    Food::TYPE_PAIR type = p->GetType();
    IncreaseScore(type.second);
    IncreaseEnergy(type.second);
    RequestRemoveFood(static_cast<QGraphicsPixmapItem *>(p));
}

void SnakeUnit::UpdateCollideSnake() {
    RequestRemoveSnake(this);
}

void SnakeUnit::WeakToNormal() {
    Unit *head = snake[0];
    head->setPixmap(headImg);
    //head->UpdateRotation(direction);
}

void SnakeUnit::NormalToWeak() {
    Unit *head = snake[0];
    head->setPixmap(weakImg);
    //head->UpdateRotation(direction);
}

// Ai Snake
std::set<QString> AiSnakeUnit::aiNames {"Joker", "Lily", "Marshell", "Alron",
                                        "Ted", "Patrick", "McCauley", "Daine", 
                                        "Kane", "Karol", "Odom", "Galen", "Garner"};

static int random(int min, int max) {
    if (min > max) return -1;

    int ans = min;
    ans += rand() % (max - min + 1);
    return ans;
}

QString AiSnakeUnit::GetAiName() {
    for (auto iter = AiSnakeUnit::aiNames.begin(); 
         iter != AiSnakeUnit::aiNames.end(); iter++) {
             bool  flag = true;
             for (int i = 0 ; i < SnakeUnit::snakes.size(); i++) {
                if (SnakeUnit::snakes[i]->GetName() == *iter) {
                    flag = false;
                    break;
                }
             }
            if (flag) { return *iter; } 
    }
    return nullptr;
}

AiSnakeUnit *AiSnakeUnit::GetAiInstance(GameView *view, const quint32 speed) {
    QString name = AiSnakeUnit::GetAiName();
    if (name == nullptr) {
        LOG_DEBUG("names are used up");
        return nullptr;
    }

    QPointF pos(random(0, view->GetScene()->sceneRect().width() - 1), 
               random(0, view->GetScene()->sceneRect().height() - 1));
    SNAKE_TYPE type = static_cast<SNAKE_TYPE>(random(SNAKE_TYPE_1, SNAKE_TYPE_10));
    SNAKE_DIRECTION direction = static_cast<SNAKE_DIRECTION>(pow(2, random(0, 3)));
    
    AiSnakeUnit *snake = new AiSnakeUnit(name, view, true, speed, pos, type, direction);
    return snake;
}

AiSnakeUnit::AiSnakeUnit(const QString &name, GameView *view, bool isAi,
                         const quint32 &speed, QPointF pos, SNAKE_TYPE type,
                        SNAKE_DIRECTION direction, const quint32 size) :
                        SnakeUnit(name, view, isAi, speed, pos, type, direction) {
    
    int temp = random(0, 2);
    switch (temp) {
        case 0: grade = AI_NORMAL; break; 
        case 1: grade = AI_MEDIUM; break; 
        case 2: grade = AI_DIFFICULT; break; 
    }
    LOG_DEBUG("ai snake instance, grade: %d", grade);
}

AiSnakeUnit::~AiSnakeUnit() {
    LOG_DEBUG("~AiSnakeUnit");
}

quint32 AiSnakeUnit::GetDirection(const QPointF &posSrc, const QPointF &posDst) {
    quint32 ans = 0;
    if (posDst.x() > posSrc.x()) ans |= SNAKE_DIRECTION_RIGHT;
    if (posDst.x() < posSrc.x()) ans |= SNAKE_DIRECTION_LEFT;
    if (posDst.y() > posSrc.y()) ans |= SNAKE_DIRECTION_DOWN;
    if (posDst.y() < posSrc.y()) ans |= SNAKE_DIRECTION_UP;
    return ans;
}

SNAKE_DIRECTION AiSnakeUnit::RecommendDirection(SNAKE_DIRECTION curDirection, quint32 available) {
    if (available & curDirection) return curDirection;
    if (curDirection == SNAKE_DIRECTION_UP || curDirection == SNAKE_DIRECTION_DOWN) {
        if (available & SNAKE_DIRECTION_LEFT) return SNAKE_DIRECTION_LEFT;
        if (available & SNAKE_DIRECTION_RIGHT) return SNAKE_DIRECTION_RIGHT;
    } else {
        if (available & SNAKE_DIRECTION_UP) return SNAKE_DIRECTION_UP;
        if (available & SNAKE_DIRECTION_DOWN) return SNAKE_DIRECTION_DOWN;
    }
    return SNAKE_DIRECTION_NONE;
}

void AiSnakeUnit::UpdateDirection() {
    // avoid collide
    SNAKE_DIRECTION avoidDir = AvoidCollide();
    if (random(0, grade) && avoidDir != this->direction) {
        ChangeDirection(avoidDir);
        return;
    }

    // eat food
    if (random(0, 1)) {
        SNAKE_DIRECTION foodDir = EatFood();
        if (foodDir != SNAKE_DIRECTION_NONE) ChangeDirection(foodDir);
    }
}

SNAKE_DIRECTION AiSnakeUnit::AvoidCollide() {
    QList<QGraphicsItem *> list = boundary->collidingItems();
    for (int i = 0; i < list.size(); i++) {
        if (dynamic_cast<Stone *>(list[i]) || 
            dynamic_cast<SnakeUnit::Unit *>(list[i]) || 
            dynamic_cast<QGraphicsEllipseItem *>(list[i])) {
            quint32 dir = SNAKE_DIRECTION_ALL ^ GetDirection(snake[0]->pos(), list[i]->pos()); 
            SNAKE_DIRECTION recommend = RecommendDirection(this->direction, dir);
            if (recommend != this->direction) {
                return recommend;
                break;
            }
        }
    }
    return this->direction;
}

SNAKE_DIRECTION AiSnakeUnit::EatFood() {
    QList<QGraphicsItem *> list = boundary->collidingItems();
    for (int i = 0; i < list.size(); i++) {
        if (dynamic_cast<Food *>(list[i])) {
            quint32 dir = GetDirection(snake[0]->pos(), list[i]->pos());
            return RecommendDirection(this->direction, dir);
        }
    } 
    return SNAKE_DIRECTION_NONE;
}
