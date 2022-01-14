/*************************************************************************
	> File Name: ../textedit_item.cpp
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2022年01月07日 星期五 11时40分44秒
 ************************************************************************/

#include "textedit_item.h"

TextEditItem::TextEditItem(const QString &text) {
    setPlaceholderText(text);
    setWidget(this); 
    QLineEdit::setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

TextEditItem::~TextEditItem() {

}

