/*************************************************************************
	> File Name: graph_view.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2021年12月20日 星期一 11时36分52秒
 ************************************************************************/

#include "log.h"
#include "graph_view.h"

GraphView::GraphView(Game *parent) : parent(parent) {
    scene = new QGraphicsScene();
    Init();
}

void GraphView::Init() {
    LOG_DEBUG("Init");

    QRect desktopRect = QApplication::desktop()->availableGeometry();
    
    qreal x = desktopRect.width() / 4;
    qreal y = desktopRect.height() / 4;
    qreal width = 2 * desktopRect.width() / 3;
    qreal height = 2 * desktopRect.height() / 3;
    LOG_DEBUG("initial size: x %lf, y %lf, w %lf, h %lf", x, y, width, height);

    /*
    qreal x = o;
    qreal y = 0;
    qreal width = desktopRect.width();
    qreal height = desktopRect.height();
    */
    
    minimumWidth = width;
    minimumHeight = height;
    setMinimumWidth(minimumWidth);
    setMinimumHeight(minimumHeight);
    setGeometry(x, y, width, height);
    setStyleSheet("padding: 0px; border: 0px");

    scene->setSceneRect(0, 0, width, height);
    setScene(scene);

    /*
    QPixmap bg_img("../res/background/back.jpg");
    if (bg_img.isNull()) {
        LOG_DEBUG("background resource img is null");
    }
    QBrush bg_brush(bg_img);
    scene->setBackgroundBrush(bg_brush);
    */
}

void GraphView::EnableResize(bool enable) {
    QSize size;
    if (enable) {
        size = QSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
        setFixedSize(size);
        setMinimumWidth(minimumWidth);
        setMinimumHeight(minimumHeight);
    } else {
        size = this->size();
        setFixedSize(size);
    }
}

void GraphView::resizeEvent(QResizeEvent *event) {
    if (!parent) {
        LOG_ERROR("lack parent");
        return;
    }
    parent->resizeEvent(event);
    //LOG_DEBUG("resize event");
}
