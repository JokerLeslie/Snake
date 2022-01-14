/*************************************************************************
	> File Name: game_mode_view.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月12日 星期三 16时07分47秒
 ************************************************************************/

#include "log.h"
#include "game_mode_view.h"

GameModeView::GameModeView(Game *parent) : parent(parent), /*QGraphicsWidget(nullptr)*/
                        QGraphicsWidget(nullptr, Qt::Window) {
    GraphView *view;
    if (parent && (view = parent->GetView())) {
        //widget = new QGraphicsWidget(nullptr, Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
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
        QGraphicsAnchorLayout *contentLayout = new QGraphicsAnchorLayout(mainLayout);

        textWidget1 = new LayoutItem("选 择 模 式");
        buttonWidget1 = new LayoutItem("AI 模式");
        buttonWidget2 = new LayoutItem("双人模式");

        contentLayout->addCornerAnchors(textWidget1, Qt::TopLeftCorner, contentLayout, Qt::TopLeftCorner);
        contentLayout->addAnchors(buttonWidget1, textWidget1, Qt::Horizontal);
        contentLayout->addAnchor(buttonWidget1, Qt::AnchorTop, textWidget1, Qt::AnchorBottom);
        contentLayout->addAnchors(buttonWidget2, buttonWidget1, Qt::Horizontal);
        contentLayout->addAnchor(buttonWidget2, Qt::AnchorTop, buttonWidget1, Qt::AnchorBottom);
        contentLayout->addCornerAnchors(buttonWidget2, Qt::BottomRightCorner, contentLayout, Qt::BottomRightCorner);

        mainLayout->addItem(marginWidget1, 0, 0, 1, 3);
        mainLayout->addItem(marginWidget2, 1, 0, 1, 1);
        mainLayout->addItem(contentLayout, 1, 1, 1, 1);
        mainLayout->addItem(marginWidget3, 1, 2, 1, 1);
        mainLayout->addItem(marginWidget4, 2, 0, 1, 3);

        mainLayout->setColumnStretchFactor(0, 4);
        mainLayout->setColumnStretchFactor(1, 5);
        mainLayout->setColumnStretchFactor(2, 4);
        mainLayout->setRowStretchFactor(0, 1);
        mainLayout->setRowStretchFactor(1, 5);
        mainLayout->setRowStretchFactor(2, 1);

        this->setLayout(mainLayout);

        textWidget1->setAcceptHoverEvents(true);
        buttonWidget1->setAcceptHoverEvents(true);
        buttonWidget2->setAcceptHoverEvents(true);

        textWidget1->installSceneEventFilter(this);
        buttonWidget1->installSceneEventFilter(this);
        buttonWidget2->installSceneEventFilter(this);
    }
    connect(this, &GameModeView::RequestSingleModeChoose, parent, &Game::ResponseSingleModeChoose);
    connect(this, &GameModeView::RequestDoubleModeChoose, parent, &Game::ResponseDoubleModeChoose);
}

GameModeView::~GameModeView() {
    GraphView *view;
    if (parent && (view = parent->GetView())) {
        view->scene->removeItem(this);
    }
}

bool GameModeView::sceneEventFilter(QGraphicsItem *watched, QEvent *event) {
    if (event->type() == QEvent::GraphicsSceneMousePress) {
        if (watched == buttonWidget1) {
            RequestSingleModeChoose();
            return true;
        } else if (watched == buttonWidget2) {
            RequestDoubleModeChoose();
            return true;
        }
    } else if (event->type() == QEvent::GraphicsSceneHoverEnter) {
        if (watched == buttonWidget1) {
            return buttonWidget1->setBackgroundColor(QColor(255, 0, 0, 100));
        } else if (watched == buttonWidget2) {
            return buttonWidget2->setBackgroundColor(QColor(255, 0, 0, 100));
        }
    } else if (event->type() == QEvent::GraphicsSceneHoverLeave) {
        if (watched == buttonWidget1) {
            return buttonWidget1->setBackgroundColor(QColor(0, 0, 0, 0));
        } else if (watched == buttonWidget2) {
            return buttonWidget2->setBackgroundColor(QColor(0, 0, 0, 0));
        }
    }

    return false;
}

