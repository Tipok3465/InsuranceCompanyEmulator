#include "../header.h"
#pragma once

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void setParams(int month_count, int start_capital, int tax_percentage, int base_demand);
private:
    QString font_family_;
    QLabel* cur_capital_;
    int month_count_;
    int start_capital_;
    int tax_percentage_;
    int base_demand_;
};