/*************************************************************************
	> File Name: layout_item.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月05日 星期三 15时19分13秒
 ************************************************************************/
#include "log.h"
#include "layout_item.h"

LayoutItem::LayoutItem(QGraphicsItem *parent) : QGraphicsLayoutItem(), 
                        QGraphicsItem(parent) { 
    text = "";
    textColor = Qt::white;
    backgroundColor = QColor(0, 0, 0, 0);
    textWidthRatio = 17;
    textHeightRatio = 3;
    font.setFamily("SimSun");
    font.setBold(true);
    setGraphicsItem(this);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, 
                              QSizePolicy::Preferred, QSizePolicy::DefaultType));
}

LayoutItem::LayoutItem(const QString &strs, QGraphicsItem *parent) 
                    : QGraphicsLayoutItem(), QGraphicsItem(parent), text(strs) { 
    textColor = Qt::white;
    backgroundColor = QColor(0, 0, 0, 0);
    textWidthRatio = 17;
    textHeightRatio = 3;
    font.setFamily("SimSun");
    font.setBold(true);
    setGraphicsItem(this);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, 
                              QSizePolicy::Preferred, QSizePolicy::DefaultType));
}

LayoutItem::~LayoutItem() {
}

void LayoutItem::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);
    Q_UNUSED(option);

    QRectF frame(QPointF(0, 0), geometry().size());
    painter->setPen(textColor); 
    painter->fillRect(frame, backgroundColor);

    quint32 pointSize = std::min(frame.width() / textWidthRatio, frame.height() / textHeightRatio);
    //LOG_DEBUG("frame width: %f, height: %f", frame.width(), frame.height());
    //LOG_DEBUG("point size: %d", pointSize);
    font.setPointSize(pointSize);
    
    painter->setFont(font);
    painter->drawText(frame, Qt::AlignCenter, text);
}

QRectF LayoutItem::boundingRect() const {
    return QRectF(QPointF(0,0), geometry().size());
}

void LayoutItem::setGeometry(const QRectF &geom) {
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);
    setPos(geom.topLeft());
}

QSizeF LayoutItem::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const {
    switch (which) {
        case Qt::MinimumSize:
        case Qt::PreferredSize:
            return QSize(10, 10);
        case Qt::MaximumSize:
            return QSizeF(5000, 5000);
        default:
            break;
    }
    return constraint;
}

bool LayoutItem::setTextColor(const QColor &color) {
    textColor = color;
    QGraphicsItem::update();
    return true;
}

bool LayoutItem::setBackgroundColor(const QColor &color) {
    backgroundColor = color;
    QGraphicsItem::update();
    return true;
}

bool LayoutItem::setFamily(const QString &family) {
    font.setFamily(family);
    QGraphicsItem::update();
    return true;
}

bool LayoutItem::setBold(bool enable) {
    font.setBold(enable);
    QGraphicsItem::update();
    return true;
}

bool LayoutItem::setTextWidthRatio(quint32 ratio) {
    textWidthRatio = ratio;
    QGraphicsItem::update();
    return true;
}

bool LayoutItem::setTextHeightRatio(quint32 ratio) {
    textHeightRatio = ratio;
    QGraphicsItem::update();
    return true;
}

bool LayoutItem::setText(const QString &strs) {
    text = strs;
    QGraphicsItem::update();
    return true;
}

