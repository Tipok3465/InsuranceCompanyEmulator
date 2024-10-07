#pragma once

#include "../header.h"


class IncomeLabel: public QLabel {
public:
    explicit IncomeLabel(QWidget* parent);
    void setWidth(int w);
    void setRange(int l, int r);
    void setValue(int x);
    int getValue();
private:
    int lhs_ = 0;
    int rhs_ = 0;
    int val_;
    int width_;
};
