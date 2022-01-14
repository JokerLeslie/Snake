/*************************************************************************
	> File Name: game_mode_info_view.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月12日 星期三 16时09分23秒
 ************************************************************************/

#include "log.h"
#include "game_mode_info_view.h"

// common content layout
ContentInfoLayout::ContentInfoLayout(QGraphicsLayoutItem *parent) :
    QGraphicsGridLayout(parent) {
    titleText = new LayoutItem("玩 家 信 息");

    nameText = new LayoutItem("姓 名");
    nameText->setTextWidthRatio(5);
    nameText->setTextHeightRatio(5);

    nameInput = new TextEditItem("输入你的姓名");

    nameHint = new LayoutItem("(输入合法姓名)");
    nameHint->setTextWidthRatio(7);
    nameHint->setTextHeightRatio(7);

    levelText = new LayoutItem("难度");
    levelText->setTextWidthRatio(5);
    levelText->setTextHeightRatio(5);

    levelInput = new TextEditItem("输入游戏难度等级(1—3)");

    levelHint = new LayoutItem("(输入合法等级)");
    levelHint->setTextWidthRatio(7);
    levelHint->setTextHeightRatio(7);


    LayoutItem *contentMargin1 = new LayoutItem();
    LayoutItem *contentMargin2 = new LayoutItem();
    LayoutItem *contentMargin3 = new LayoutItem();
    LayoutItem *contentMargin4 = new LayoutItem();

    addItem(titleText, 0, 0, 1, 3);
    addItem(nameText, 1, 0, 3, 1);
    addItem(nameHint, 1, 2, 3, 1);
    addItem(contentMargin1, 1, 1);
    addItem(nameInput, 2, 1);
    addItem(contentMargin2, 3, 1);
    addItem(levelText, 4, 0, 3, 1);
    addItem(levelHint, 4, 2, 3, 1);
    addItem(contentMargin3, 4, 1);
    addItem(levelInput, 5, 1);
    addItem(contentMargin4, 6, 1);

    setRowStretchFactor(0, 9);
    setRowStretchFactor(1, 1);
    setRowStretchFactor(2, 1);
    setRowStretchFactor(3, 1);
    setRowStretchFactor(4, 1);
    setRowStretchFactor(5, 1);
    setRowStretchFactor(6, 1);
    setColumnStretchFactor(0, 1);
    setColumnStretchFactor(1, 3);
    setColumnStretchFactor(2, 2);
}

ContentInfoLayout::~ContentInfoLayout() {

}


//GameSingleModeInfoView
GameSingleModeInfoView::GameSingleModeInfoView(Game *parent) : parent(parent),
                        QGraphicsWidget(nullptr, Qt::Window) {
    GraphView *view;
    if (parent && (view = parent->GetView())) {
        QPalette palette;
        palette = this->palette();
        QPixmap bg_img("../res/background/back.jpg");
        palette.setBrush(QPalette::Window, QBrush(bg_img));
        setPalette(palette);
        resize(view->sceneRect().width(), view->sceneRect().height());
        view->scene->addItem(this);

        LayoutItem *marginWidget1 = new LayoutItem();
        LayoutItem *marginWidget2 = new LayoutItem();
        LayoutItem *marginWidget3 = new LayoutItem();
        LayoutItem *marginWidget4 = new LayoutItem();

        QGraphicsGridLayout *mainLayout = new QGraphicsGridLayout(this);
        contentLayout = new ContentInfoLayout(mainLayout);
        backButton = new LayoutItem("返 回");
        confirmButton = new LayoutItem("确 认");

        mainLayout->addItem(marginWidget1, 0, 0, 1, 4);
        mainLayout->addItem(marginWidget2, 1, 0, 2, 1);
        mainLayout->addItem(contentLayout, 1, 1, 1, 2);
        mainLayout->addItem(backButton, 2, 1, 1, 1);
        mainLayout->addItem(confirmButton, 2, 2, 1, 1);
        mainLayout->addItem(marginWidget3, 1, 3, 2, 1);
        mainLayout->addItem(marginWidget4, 3, 0, 1, 4);

        mainLayout->setColumnStretchFactor(0, 4);
        mainLayout->setColumnStretchFactor(1, 2);
        mainLayout->setColumnStretchFactor(2, 2);
        mainLayout->setColumnStretchFactor(3, 4);
        mainLayout->setRowStretchFactor(0, 1);
        mainLayout->setRowStretchFactor(1, 4);
        mainLayout->setRowStretchFactor(2, 1);
        mainLayout->setRowStretchFactor(3, 1);

        this->setLayout(mainLayout);

        backButton->setAcceptHoverEvents(true);
        backButton->installSceneEventFilter(this);
        confirmButton->setAcceptHoverEvents(true);
        confirmButton->installSceneEventFilter(this);
    }
    connect(this, &GameSingleModeInfoView::RequestGetSingleModeInfo,
            parent, &Game::ResponseGetSingleModeInfo);
    connect(this, &GameSingleModeInfoView::RequestReturnModeChoose,
            parent, &Game::ResponseReturnModeChoose);
}

GameSingleModeInfoView::~GameSingleModeInfoView() {

}

bool GameSingleModeInfoView::sceneEventFilter(QGraphicsItem *watched, QEvent *event) {
    if (event->type() == QEvent::GraphicsSceneMousePress) {
        if (watched == backButton) {
            RequestReturnModeChoose();
            return true;
        } else if (watched == confirmButton) {
            QString name = contentLayout->nameInput->text();
            QString level = contentLayout->levelInput->text();
            RequestGetSingleModeInfo(name, level.toInt());
            return true;
        }

    } else if (event->type() == QEvent::GraphicsSceneHoverEnter) {
        if (watched == backButton) {
            return backButton->setBackgroundColor(QColor(255, 0, 0, 100));
        } else if (watched == confirmButton) {
            return confirmButton->setBackgroundColor(QColor(255, 0, 0, 100));
        }
    } else if (event->type() == QEvent::GraphicsSceneHoverLeave) {
        if (watched == backButton) {
            return backButton->setBackgroundColor(QColor(0, 0, 0, 0));
        } else if (watched == confirmButton) {
            return confirmButton->setBackgroundColor(QColor(0, 0, 0, 0));
        }
    }
    return false;
}

void GameSingleModeInfoView::SetContentTitle(const QString &title) {
   contentLayout->titleText->setText(title);
}

void GameSingleModeInfoView::SetContentNameHint(const QString &text,
                                           QColor color) {
    contentLayout->nameHint->setText(text);
    contentLayout->nameHint->setTextColor(color);
}

void GameSingleModeInfoView::SetContentLevelHint(const QString &text,
                                            QColor color) {
    contentLayout->levelHint->setText(text);
    contentLayout->levelHint->setTextColor(color);
}

//GameDoubleModeInfoView
GameDoubleModeInfoView::GameDoubleModeInfoView(Game *parent) : parent(parent),
                        QGraphicsWidget(nullptr, Qt::Window) {
    GraphView *view;
    if (parent && (view = parent->GetView())) {
        QPalette palette;
        palette = this->palette();
        QPixmap bg_img("../res/background/back.jpg");
        palette.setBrush(QPalette::Window, QBrush(bg_img));
        setPalette(palette);
        resize(view->sceneRect().width(), view->sceneRect().height());
        view->scene->addItem(this);

        LayoutItem *marginWidget1 = new LayoutItem();
        LayoutItem *marginWidget2 = new LayoutItem();
        LayoutItem *marginWidget3 = new LayoutItem();
        LayoutItem *marginWidget4 = new LayoutItem();
        LayoutItem *marginWidget5 = new LayoutItem();
        LayoutItem *marginWidget6 = new LayoutItem();
        LayoutItem *marginWidget7 = new LayoutItem();
        LayoutItem *marginWidget8 = new LayoutItem();

        QGraphicsGridLayout *mainLayout = new QGraphicsGridLayout(this);
        contentLayout1 = new ContentInfoLayout(mainLayout);
        SetContentTitle(1, "玩 家 1 信 息");
        contentLayout2 = new ContentInfoLayout(mainLayout);
        SetContentTitle(2, "玩 家 2 信 息");
        backButton = new LayoutItem("返 回");
        confirmButton = new LayoutItem("确 认");

        mainLayout->addItem(marginWidget1, 0, 0, 1, 5);
        mainLayout->addItem(marginWidget2, 1, 0);
        mainLayout->addItem(contentLayout1, 1, 1);
        mainLayout->addItem(marginWidget3, 1, 2);
        mainLayout->addItem(contentLayout2, 1, 3);
        mainLayout->addItem(marginWidget4, 1, 4);
        mainLayout->addItem(marginWidget5, 2, 0);
        mainLayout->addItem(backButton, 2, 1);
        mainLayout->addItem(marginWidget6, 2, 2);
        mainLayout->addItem(confirmButton, 2, 3);
        mainLayout->addItem(marginWidget6, 2, 4);
        mainLayout->addItem(marginWidget7, 3, 0, 1, 5);

        mainLayout->setColumnStretchFactor(0, 1);
        mainLayout->setColumnStretchFactor(1, 4);
        mainLayout->setColumnStretchFactor(2, 2);
        mainLayout->setColumnStretchFactor(3, 4);
        mainLayout->setColumnStretchFactor(4, 1);
        mainLayout->setRowStretchFactor(0, 1);
        mainLayout->setRowStretchFactor(1, 4);
        mainLayout->setRowStretchFactor(2, 1);
        mainLayout->setRowStretchFactor(3, 1);

        this->setLayout(mainLayout);

        backButton->setAcceptHoverEvents(true);
        backButton->installSceneEventFilter(this);
        confirmButton->setAcceptHoverEvents(true);
        confirmButton->installSceneEventFilter(this);
    }
    connect(this, &GameDoubleModeInfoView::RequestGetDoubleModeInfo,
            parent, &Game::ResponseGetDoubleModeInfo);
    connect(this, &GameDoubleModeInfoView::RequestReturnModeChoose,
            parent, &Game::ResponseReturnModeChoose);
}

GameDoubleModeInfoView::~GameDoubleModeInfoView() {

}

bool GameDoubleModeInfoView::sceneEventFilter(QGraphicsItem *watched, QEvent *event) {
    if (event->type() == QEvent::GraphicsSceneMousePress) {
        if (watched == backButton) {
            RequestReturnModeChoose();
            return true;
        } else if (watched == confirmButton) {
            QString name1 = contentLayout1->nameInput->text();
            QString level1 = contentLayout1->levelInput->text();
            QString name2 = contentLayout2->nameInput->text();
            QString level2 = contentLayout2->levelInput->text();
            RequestGetDoubleModeInfo(1, name1, level1.toInt(), 2, name2, level2.toInt());
            return true;
        }

    } else if (event->type() == QEvent::GraphicsSceneHoverEnter) {
        if (watched == backButton) {
            return backButton->setBackgroundColor(QColor(255, 0, 0, 100));
        } else if (watched == confirmButton) {
            return confirmButton->setBackgroundColor(QColor(255, 0, 0, 100));
        }
    } else if (event->type() == QEvent::GraphicsSceneHoverLeave) {
        if (watched == backButton) {
            return backButton->setBackgroundColor(QColor(0, 0, 0, 0));
        } else if (watched == confirmButton) {
            return confirmButton->setBackgroundColor(QColor(0, 0, 0, 0));
        }
    }
    return false;
}

void GameDoubleModeInfoView::SetContentTitle(quint32 type, const QString &title) {
    if (type == 1) {
        contentLayout1->titleText->setText(title);
    } else if (type == 2) {
        contentLayout2->titleText->setText(title);
    } else {
        LOG_ERROR("type error");
    }
}

void GameDoubleModeInfoView::SetContentNameHint(quint32 type, const QString &text,
                                           QColor color) {
    if (type == 1) {
        contentLayout1->nameHint->setText(text);
        contentLayout1->nameHint->setTextColor(color);
    } else if (type == 2) {
        contentLayout2->nameHint->setText(text);
        contentLayout2->nameHint->setTextColor(color);
    } else {
        LOG_ERROR("type error");
    }
}

void GameDoubleModeInfoView::SetContentLevelHint(quint32 type, const QString &text,
                                            QColor color) {
    if (type == 1) {
        contentLayout1->levelHint->setText(text);
        contentLayout1->levelHint->setTextColor(color);
    } else if (type == 2) {
        contentLayout2->levelHint->setText(text);
        contentLayout2->levelHint->setTextColor(color);
    } else {
        LOG_ERROR("type error");
    }
}

