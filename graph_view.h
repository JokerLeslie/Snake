/*************************************************************************
	> File Name: graph_view.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2021年12月20日 星期一 11时34分03秒
 ************************************************************************/

#ifndef _GRAPH_VIEW_H
#define _GRAPH_VIEW_H

#include <QObject>
#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "game.h"

class Game;

class GraphView : public QGraphicsView {
public:
    GraphView(Game *parent = nullptr);
    void Init();
    void EnableResize(bool enable);

    void resizeEvent(QResizeEvent *event) override;

public:
    QGraphicsScene *scene;

private:
    Game *parent;
    quint32 minimumWidth;
    quint32 minimumHeight;
};





#endif
