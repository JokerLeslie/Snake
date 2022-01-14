/*************************************************************************
	> File Name: game_mode_view.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月12日 星期三 16时02分21秒
 ************************************************************************/

#ifndef _GAME_MODE_VIEW_H
#define _GAME_MODE_VIEW_H

#include "common_view.h"

class Game;
class LayoutItem;

//GameModeView
class GameModeView : public QGraphicsWidget {
    Q_OBJECT
public:
    GameModeView(Game *parent);
    ~GameModeView();
    bool sceneEventFilter(QGraphicsItem *watched, QEvent *event) override;

signals:
    void RequestSingleModeChoose();
    void RequestDoubleModeChoose();

private:
    Game *parent;
    LayoutItem *textWidget1;
    LayoutItem *buttonWidget1;
    LayoutItem *buttonWidget2;
};

#endif
