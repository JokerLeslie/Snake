/*************************************************************************
	> File Name: game_over_view.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月12日 星期三 16时06分32秒
 ************************************************************************/

#ifndef _GAME_OVER_VIEW_H
#define _GAME_OVER_VIEW_H

#include "common_view.h"

class Game;
class LayoutItem;

class GameOverSingleModeView : public QGraphicsWidget {
    Q_OBJECT
public:
    GameOverSingleModeView(Game *parent, QString name, quint32 rank, quint32 score);
    ~GameOverSingleModeView();
    bool sceneEventFilter(QGraphicsItem *watched, QEvent *event) override;

signals:
    void RequestGameReplay();
    void RequestGameRestart();
    void RequestExitGame();

private:
    Game *parent;
    LayoutItem *textWidget1;
    LayoutItem *textWidget2;
    LayoutItem *buttonWidget1;
    LayoutItem *buttonWidget2;
    LayoutItem *buttonWidget3;
};


class GameOverDoubleModeView : public QGraphicsWidget {
    Q_OBJECT
public:
    GameOverDoubleModeView(Game *parent, QString name1, quint32 rank1, quint32 score1, 
                          QString name2, quint32 rank2, quint32 score2);
    ~GameOverDoubleModeView();
    bool sceneEventFilter(QGraphicsItem *watched, QEvent *event) override;

signals:
    void RequestGameReplay();
    void RequestGameRestart();
    void RequestExitGame();

private:
    Game *parent;
    LayoutItem *textWidget1;
    LayoutItem *textWidget2;
    LayoutItem *textWidget3;
    LayoutItem *buttonWidget1;
    LayoutItem *buttonWidget2;
    LayoutItem *buttonWidget3;
};
#endif
