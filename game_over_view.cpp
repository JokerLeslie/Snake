/*************************************************************************
	> File Name: game_over_view.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月12日 星期三 16时10分28秒
 ************************************************************************/

#include "log.h"
#include "game_over_view.h"

// single mode game over view
GameOverSingleModeView::GameOverSingleModeView(Game *parent, QString name, 
                                            quint32 rank, quint32 score) : parent(parent),
                                            QGraphicsWidget(nullptr, Qt::Window) {
    GraphView *view;
    if (parent && (view = parent->GetView())) {
        QPalette palette;
        palette = this->palette();
        palette.setBrush(QPalette::Window, QBrush(QColor(0, 0, 0, 100)));
        setPalette(palette);
        resize(view->sceneRect().width(), view->sceneRect().height());
        setZValue(100);
        view->scene->addItem(this);

        textWidget1 = new LayoutItem("游 戏 结 束");
        QString nameText = "姓名: " + name + "\n\n";
        QString rankText = "排名: " + QString::number(rank) + "\n\n";
        QString scoreText = "得分: " + QString::number(score);
        textWidget2 = new LayoutItem(nameText + rankText + scoreText);
        textWidget2->setTextHeightRatio(10);
        textWidget2->setTextColor(QColor(255, 0, 0));
        buttonWidget1 = new LayoutItem("再 玩 一 次");
        buttonWidget2 = new LayoutItem("重 新 开 始");
        buttonWidget3 = new LayoutItem("结 束 游 戏");

        QGraphicsGridLayout *mainLayout = new QGraphicsGridLayout(this);
        QGraphicsGridLayout *contentLayout = new QGraphicsGridLayout(mainLayout);
        contentLayout->addItem(textWidget1, 0, 0);
        contentLayout->addItem(textWidget2, 1, 0);
        contentLayout->addItem(buttonWidget1, 2, 0);
        contentLayout->addItem(buttonWidget2, 3, 0);
        contentLayout->addItem(buttonWidget3, 4, 0);

        contentLayout->setRowStretchFactor(0, 2);
        contentLayout->setRowStretchFactor(1, 2);
        contentLayout->setRowStretchFactor(2, 1);
        contentLayout->setRowStretchFactor(3, 1);
        contentLayout->setRowStretchFactor(4, 1);

        LayoutItem *marginWidget1 = new LayoutItem();
        LayoutItem *marginWidget2 = new LayoutItem();
        LayoutItem *marginWidget3 = new LayoutItem();
        LayoutItem *marginWidget4 = new LayoutItem();

        mainLayout->addItem(marginWidget1, 0, 0, 1, 3);
        mainLayout->addItem(marginWidget2, 1, 0, 1, 1);
        mainLayout->addItem(contentLayout, 1, 1, 1, 1);
        mainLayout->addItem(marginWidget3, 1, 2, 1, 1);
        mainLayout->addItem(marginWidget4, 2, 0, 1, 3);

        mainLayout->setColumnStretchFactor(0, 4);
        mainLayout->setColumnStretchFactor(1, 5);
        mainLayout->setColumnStretchFactor(2, 4);
        mainLayout->setRowStretchFactor(0, 1);
        mainLayout->setRowStretchFactor(1, 8);
        mainLayout->setRowStretchFactor(2, 1);

        this->setLayout(mainLayout);

        buttonWidget1->setAcceptHoverEvents(true);
        buttonWidget2->setAcceptHoverEvents(true);
        buttonWidget3->setAcceptHoverEvents(true);

        buttonWidget1->installSceneEventFilter(this);
        buttonWidget2->installSceneEventFilter(this);
        buttonWidget3->installSceneEventFilter(this);
    }

    connect(this, &GameOverSingleModeView::RequestGameReplay, parent, &Game::ResponseGameReplay);
    connect(this, &GameOverSingleModeView::RequestGameRestart, parent, &Game::ResponseGameRestart);
    connect(this, &GameOverSingleModeView::RequestExitGame, parent, &Game::ResponseExitGame);
}

GameOverSingleModeView::~GameOverSingleModeView() {
    GraphView *view;
    if (parent && (view = parent->GetView())) {
        view->scene->removeItem(this);
    }
}

bool GameOverSingleModeView::sceneEventFilter(QGraphicsItem *watched, QEvent *event) {
    if (event->type() == QEvent::GraphicsSceneMousePress) {
        if (watched == buttonWidget1) {
            RequestGameReplay();
            return true;
        } else if (watched == buttonWidget2) {
            RequestGameRestart();
            return true;
        } else if (watched == buttonWidget3) {
            RequestExitGame();
            return true;
        }
    } else if (event->type() == QEvent::GraphicsSceneHoverEnter) {
        if (watched == buttonWidget1) {
            return buttonWidget1->setBackgroundColor(QColor(255, 0, 0, 100));
        } else if (watched == buttonWidget2) {
            return buttonWidget2->setBackgroundColor(QColor(255, 0, 0, 100));
        } else if (watched == buttonWidget3) {
            return buttonWidget3->setBackgroundColor(QColor(255, 0, 0, 100));
        }
    } else if (event->type() == QEvent::GraphicsSceneHoverLeave) {
        if (watched == buttonWidget1) {
            return buttonWidget1->setBackgroundColor(QColor(0, 0, 0, 0));
        } else if (watched == buttonWidget2) {
            return buttonWidget2->setBackgroundColor(QColor(0, 0, 0, 0));
        } else if (watched == buttonWidget3) {
            return buttonWidget3->setBackgroundColor(QColor(0, 0, 0, 0));
        }
    }

    return false;
}

// double mode game over view
GameOverDoubleModeView::GameOverDoubleModeView(Game *parent, QString name1, quint32 rank1, 
                                               quint32 score1, QString name2, quint32 rank2, 
                                               quint32 score2) : parent(parent), 
                                                QGraphicsWidget(nullptr, Qt::Window) {
    GraphView *view;
    if (parent && (view = parent->GetView())) {
        QPalette palette;
        palette = this->palette();
        palette.setBrush(QPalette::Window, QBrush(QColor(0, 0, 0, 100)));
        setPalette(palette);
        resize(view->sceneRect().width(), view->sceneRect().height());
        setZValue(100);
        view->scene->addItem(this);

        textWidget1 = new LayoutItem("游 戏 结 束");
        
        QString nameText1 = "姓名: " + name1 + "\n\n";
        QString rankText1 = "排名: " + QString::number(rank1) + "\n\n";
        QString scoreText1 = "得分: " + QString::number(score1);
        textWidget2 = new LayoutItem(nameText1 + rankText1 + scoreText1);
        textWidget2->setTextHeightRatio(10);
        textWidget2->setTextColor(QColor(255, 0, 0));
        
        QString nameText2 = "姓名: " + name2 + "\n\n";
        QString rankText2 = "排名: " + QString::number(rank2) + "\n\n";
        QString scoreText2 = "得分: " + QString::number(score2);
        textWidget3 = new LayoutItem(nameText2 + rankText2 + scoreText2);
        textWidget3->setTextHeightRatio(10);
        textWidget3->setTextColor(QColor(255, 0, 0));
        
        buttonWidget1 = new LayoutItem("再 玩 一 次");
        buttonWidget2 = new LayoutItem("重 新 开 始");
        buttonWidget3 = new LayoutItem("结 束 游 戏");

        QGraphicsGridLayout *mainLayout = new QGraphicsGridLayout(this);
        QGraphicsGridLayout *contentLayout = new QGraphicsGridLayout(mainLayout);
        contentLayout->addItem(textWidget1, 0, 0, 1, 2);
        contentLayout->addItem(textWidget2, 1, 0);
        contentLayout->addItem(textWidget3, 1, 1);
        contentLayout->addItem(buttonWidget1, 2, 0, 1, 2);
        contentLayout->addItem(buttonWidget2, 3, 0, 1, 2);
        contentLayout->addItem(buttonWidget3, 4, 0, 1, 2);

        contentLayout->setRowStretchFactor(0, 2);
        contentLayout->setRowStretchFactor(1, 2);
        contentLayout->setRowStretchFactor(2, 1);
        contentLayout->setRowStretchFactor(3, 1);
        contentLayout->setRowStretchFactor(4, 1);

        LayoutItem *marginWidget1 = new LayoutItem();
        LayoutItem *marginWidget2 = new LayoutItem();
        LayoutItem *marginWidget3 = new LayoutItem();
        LayoutItem *marginWidget4 = new LayoutItem();

        mainLayout->addItem(marginWidget1, 0, 0, 1, 3);
        mainLayout->addItem(marginWidget2, 1, 0, 1, 1);
        mainLayout->addItem(contentLayout, 1, 1, 1, 1);
        mainLayout->addItem(marginWidget3, 1, 2, 1, 1);
        mainLayout->addItem(marginWidget4, 2, 0, 1, 3);

        mainLayout->setColumnStretchFactor(0, 4);
        mainLayout->setColumnStretchFactor(1, 5);
        mainLayout->setColumnStretchFactor(2, 4);
        mainLayout->setRowStretchFactor(0, 1);
        mainLayout->setRowStretchFactor(1, 8);
        mainLayout->setRowStretchFactor(2, 1);

        this->setLayout(mainLayout);

        buttonWidget1->setAcceptHoverEvents(true);
        buttonWidget2->setAcceptHoverEvents(true);
        buttonWidget3->setAcceptHoverEvents(true);

        buttonWidget1->installSceneEventFilter(this);
        buttonWidget2->installSceneEventFilter(this);
        buttonWidget3->installSceneEventFilter(this);
    }

    connect(this, &GameOverDoubleModeView::RequestGameReplay, parent, &Game::ResponseGameReplay);
    connect(this, &GameOverDoubleModeView::RequestGameRestart, parent, &Game::ResponseGameRestart);
    connect(this, &GameOverDoubleModeView::RequestExitGame, parent, &Game::ResponseExitGame);
}

GameOverDoubleModeView::~GameOverDoubleModeView() {
    GraphView *view;
    if (parent && (view = parent->GetView())) {
        view->scene->removeItem(this);
    }
}

bool GameOverDoubleModeView::sceneEventFilter(QGraphicsItem *watched, QEvent *event) {
    if (event->type() == QEvent::GraphicsSceneMousePress) {
        if (watched == buttonWidget1) {
            RequestGameReplay();
            return true;
        } else if (watched == buttonWidget2) {
            RequestGameRestart();
            return true;
        } else if (watched == buttonWidget3) {
            RequestExitGame();
            return true;
        }
    } else if (event->type() == QEvent::GraphicsSceneHoverEnter) {
        if (watched == buttonWidget1) {
            return buttonWidget1->setBackgroundColor(QColor(255, 0, 0, 100));
        } else if (watched == buttonWidget2) {
            return buttonWidget2->setBackgroundColor(QColor(255, 0, 0, 100));
        } else if (watched == buttonWidget3) {
            return buttonWidget3->setBackgroundColor(QColor(255, 0, 0, 100));
        }
    } else if (event->type() == QEvent::GraphicsSceneHoverLeave) {
        if (watched == buttonWidget1) {
            return buttonWidget1->setBackgroundColor(QColor(0, 0, 0, 0));
        } else if (watched == buttonWidget2) {
            return buttonWidget2->setBackgroundColor(QColor(0, 0, 0, 0));
        } else if (watched == buttonWidget3) {
            return buttonWidget3->setBackgroundColor(QColor(0, 0, 0, 0));
        }
    }

    return false;
}
