/*************************************************************************
	> File Name: ../textedit_item.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月07日 星期五 11时40分13秒
 ************************************************************************/

#ifndef _TEXTEDIT_ITEM_H
#define _TEXTEDIT_ITEM_H

#include <QGraphicsProxyWidget>
#include <QLineEdit>

class TextEditItem : public QGraphicsProxyWidget, public QLineEdit {
public:
    TextEditItem(const QString &text = nullptr);
    ~TextEditItem();

    // Inherited from QGraphicsLayoutItem
    //void setGeometry(const QRectF &geom) override;
    //QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;
    //QSize sizeHint() const override;
};

#endif
