#include "../header.h"
#include "IncomeLabel.h"
#pragma once

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void setParams(int month_count, int start_capital, int tax_percentage, int base_demand);
    void drawCapital();
    void drawIncome();
private:
    QTimer* capital_drawing_;
    QTimer* income_drawing_;
    QLabel* bg_label_;
    QString font_family_;
    QLabel* cur_capital_label_;
    QLabel* cur_month_;
    int month_count_;
    int cur_capital_;
    int cur_cap = 0;
    int inc_val_ = 0;
    int tax_percentage_;
    int base_demand_;
    int cur_month_id_ = 1;
    IncomeLabel* income_label_;
};