#include "../header.h"
#pragma once

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void setParams(int month_count, int start_capital, int tax_percentage, int base_demand);
private:
    QLabel* bg_label_;
    QString font_family_;
    QLabel* cur_capital_;
    QLabel* cur_month_;
    int month_count_;
    int start_capital_;
    int tax_percentage_;
    int base_demand_;
    int cur_month_id_ = 1;
};