//
// Created by Данил Подлягин on 23.09.2024.
//

#include "ExpenseLabel.h"

ExpenseLabel::ExpenseLabel(QWidget *parent) {
    setParent(parent);
    setStyleSheet("QLabel {"
                  "background-color: rgba(215, 5, 5, 100);"
                  "border-radius: 5px;"
                  "}");
}

void ExpenseLabel::setRange(int l, int r) {
    lhs_ = l;
    rhs_ = r;
}

void ExpenseLabel::setWidth(int w) {
    x_ = this->x();
    width_ = w;
    this->resize(std::max(10, width_ * val_ / rhs_), this->height());
    this->move(x_ + width_ - this->width(), this->y());
}

void ExpenseLabel::setValue(int x) {
    if (rhs_ < x) return;
    if (x <= lhs_) {
        this->resize(10, this->height());
        return;
    }
    val_ = x;
    this->resize(std::max(10, width_ * val_ / rhs_), this->height());
    this->move(x_ + width_ - this->width(), this->y());
}

int ExpenseLabel::getValue() {
    return val_;
}
