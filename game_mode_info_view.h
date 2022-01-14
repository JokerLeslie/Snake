/*************************************************************************
	> File Name: game_mode_info_view.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月12日 星期三 16时03分46秒
 ************************************************************************/

#ifndef _GAME_MODE_INFO_VIEW_H
#define _GAME_MODE_INFO_VIEW_H

#include "common_view.h"

class Game;
class LayoutItem;
class TextEditItem;

//ContentInfoLayout
class ContentInfoLayout : public QGraphicsGridLayout {
public:
    ContentInfoLayout(QGraphicsLayoutItem *parent = nullptr);
    ~ContentInfoLayout();

private:
    LayoutItem *titleText;
    LayoutItem *nameText;
    LayoutItem *levelText;
    TextEditItem *nameInput;
    TextEditItem *levelInput;
    LayoutItem *nameHint;
    LayoutItem *levelHint;

    friend class GameSingleModeInfoView;
    friend class GameDoubleModeInfoView;
};

//GameSingleModeInfoView
class GameSingleModeInfoView : public QGraphicsWidget {
    Q_OBJECT
public:
    GameSingleModeInfoView(Game *parent);
    ~GameSingleModeInfoView();
    bool sceneEventFilter(QGraphicsItem *watched, QEvent *event) override;
    
    void SetContentTitle(const QString &title);
    void SetContentNameHint(const QString &nameHint, QColor textColor);
    void SetContentLevelHint(const QString &levelHint, QColor textColor);

signals:
    void RequestGetSingleModeInfo(QString name, quint32 level);
    void RequestReturnModeChoose();

private:
    Game *parent;
    ContentInfoLayout *contentLayout;
    LayoutItem *backButton;
    LayoutItem *confirmButton;
};

//GameDoubleModeInfoView
class GameDoubleModeInfoView : public QGraphicsWidget {
    Q_OBJECT
public:
    GameDoubleModeInfoView(Game *parent);
    ~GameDoubleModeInfoView();
    bool sceneEventFilter(QGraphicsItem *watched, QEvent *event) override;
    
    void SetContentTitle(quint32 type, const QString &title);
    void SetContentNameHint(quint32 type, const QString &nameHint, QColor textColor);
    void SetContentLevelHint(quint32 type, const QString &levelHint, QColor textColor);

signals:
    void RequestGetDoubleModeInfo(quint32 type1, QString name1, quint32 level1, 
                                  quint32 type2, QString name2, quint32 level2);
    void RequestReturnModeChoose();

private:
    Game *parent;
    ContentInfoLayout *contentLayout1;
    ContentInfoLayout *contentLayout2;
    LayoutItem *backButton;
    LayoutItem *confirmButton;
};

#endif
