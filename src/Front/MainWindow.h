#include "../header.h"
#include "IncomeLabel.h"
#include "ExpenseLabel.h"
#include "../Back/Company.h"
#pragma once

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void setParams(int month_count, int start_capital, int tax_percentage, int base_demand);
    void drawCapital();
    void drawIncome();
    void drawExpense();
    void openHealthContract();
    void openCarContract();
    void openHouseContract();
private:
    Company company_;
    QTimer* capital_drawing_;
    QTimer* expense_drawing_;
    QTimer* income_drawing_;
    QLabel* bg_label_;
    QString font_family_;
    QLabel* cur_capital_label_;
    QLabel* cur_month_;
    QLabel* inc_label_;
    QLabel* house_inc_label_;
    QLabel* car_inc_label_;
    QLabel* health_inc_label_;
    QLabel* exp_label_;
    QLabel* house_exp_label_;
    QLabel* car_exp_label_;
    QLabel* health_exp_label_;
    QLabel* gov_exp_label_;

    QPushButton* open_health_contract_button_;
    QMainWindow* health_contract_window_;
    QLabel* health_contract_bg_;

    QPushButton* open_car_contract_button_;
    QMainWindow* car_contract_window_;
    QLabel* car_contract_bg_;

    QPushButton* open_house_contract_button_;
    QMainWindow* house_contract_window_;
    QLabel* house_contract_bg_;
    int month_count_;
    int cur_capital_;
    int cur_cap = 0;
    int inc_val_ = 0;
    int exp_val_ = 0;
    int tax_percentage_;
    int base_demand_;
    int cur_month_id_ = 1;
    IncomeLabel* income_label_;
    IncomeLabel* house_income_label_;
    IncomeLabel* car_income_label_;
    IncomeLabel* heath_income_label_;
    ExpenseLabel* expense_label_;
    ExpenseLabel* house_expense_label_;
    ExpenseLabel* car_expense_label_;
    ExpenseLabel* health_expense_label_;
    ExpenseLabel* gov_expense_label_;
};