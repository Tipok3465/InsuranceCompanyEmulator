//
// Created by Данил Подлягин on 23.09.2024.
//

#include "IncomeLabel.h"

IncomeLabel::IncomeLabel(QWidget *parent) {
    setParent(parent);
    setStyleSheet("QLabel {"
                  "background-color: green;"
                  "border-radius: 5px;"
                  "}");
}

void IncomeLabel::setRange(int l, int r) {
    lhs_ = l;
    rhs_ = r;
}

void IncomeLabel::setValue(int x) {
    if (rhs_ < x) return;
    if (x <= lhs_) {
        this->resize(10, this->height());
        return;
    }
    val_ = x;
    this->resize(std::max(10, width_ * val_ / rhs_), this->height());
}

int IncomeLabel::getValue() {
    return val_;
}

void IncomeLabel::setWidth(int w) {
    width_ = w;
}
