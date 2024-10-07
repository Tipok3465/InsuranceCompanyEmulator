#pragma once

#include "../header.h"


class ExpenseLabel: public QLabel {
public:
    explicit ExpenseLabel(QWidget* parent);
    void setRange(int l, int r);
    void setValue(int x);
    void setWidth(int w);
    int getValue();
private:
    int lhs_ = 0;
    int rhs_ = 0;
    int val_;
    int width_;
    int x_;
};
