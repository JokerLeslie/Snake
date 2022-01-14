/*************************************************************************
	> File Name: layout_item.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月05日 星期三 15时17分45秒
 ************************************************************************/

#ifndef _LAYOUT_ITEM_H
#define _LAYOUT_ITEM_H

#include <QPainter>
#include <QFont>
#include <QGraphicsLayoutItem>
#include <QGraphicsItem>

class LayoutItem : public QGraphicsLayoutItem, public QGraphicsItem {
public:
    LayoutItem(QGraphicsItem *parent = nullptr);
    LayoutItem(const QString &strs, QGraphicsItem *parent = nullptr);
    ~LayoutItem();
    
    // Inherited from QGraphicsLayoutItem
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    // Inherited from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

    bool setTextColor(const QColor &color);
    bool setBackgroundColor(const QColor &color);
    bool setFamily(const QString &family);
    bool setBold(bool enable);
    bool setTextWidthRatio(quint32 ratio);
    bool setTextHeightRatio(quint32 ratio);
    bool setText(const QString &str);

private:
    QString text;
    QColor textColor;
    QColor backgroundColor;
    quint32 textWidthRatio;
    quint32 textHeightRatio;
    QFont font;
};


#endif
