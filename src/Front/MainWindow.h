#include "../header.h"
#include "IncomeLabel.h"
#include "ExpenseLabel.h"
#include "../Back/Company.h"
#pragma once

struct Contract {
    int month_count = 6;
    int max_pay = 200000;
    int price = 7500;
};

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
    void setHealthContract();
    void setHouseContract();
    void setCarContract();
    void updMonth();
private:
    Company company_;
    resolve resolve;
    std::vector<std::vector<std::pair<int, int>>> peoples_;
    std::vector<std::vector<std::pair<int, double>>> insurance_cases_;
    std::vector<std::vector<std::pair<int, int>>> pref_res;
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
    QLabel* health_contract_text_;
    QLabel* health_label_month_editor_;
    QSpinBox* health_contract_month_editor_;
    QPushButton* health_set_month_count_button_;
    QLabel* health_label_max_pay_editor_;
    QSpinBox* health_contract_max_pay_editor_;
    QLabel* health_label_price_editor_;
    QSpinBox* health_contract_price_editor_;

    QPushButton* open_car_contract_button_;
    QMainWindow* car_contract_window_;
    QLabel* car_contract_bg_;
    QLabel* car_contract_text_;
    QLabel* car_label_month_editor_;
    QSpinBox* car_contract_month_editor_;
    QPushButton* car_set_month_count_button_;
    QLabel* car_label_max_pay_editor_;
    QSpinBox* car_contract_max_pay_editor_;
    QLabel* car_label_price_editor_;
    QSpinBox* car_contract_price_editor_;

    QPushButton* open_house_contract_button_;
    QMainWindow* house_contract_window_;
    QLabel* house_contract_bg_;
    QLabel* house_contract_text_;
    QLabel* house_label_month_editor_;
    QSpinBox* house_contract_month_editor_;
    QPushButton* house_set_month_count_button_;
    QLabel* house_label_max_pay_editor_;
    QSpinBox* house_contract_max_pay_editor_;
    QLabel* house_label_price_editor_;
    QSpinBox* house_contract_price_editor_;

    Contract health_contract_, car_contract_, house_contract_;
    int month_count_;
    int cur_capital_;
    int cur_cap = 0;
    int inc_val_ = 0;
    int house_inc_val_ = 0;
    int car_inc_val_ = 0;
    int health_inc_val_ = 0;
    int exp_val_ = 0;
    int house_exp_val_ = 0;
    int car_exp_val_ = 0;
    int health_exp_val_ = 0;
    int tax_percentage_;
    int base_demand_;
    int cur_month_id_ = 1;

    int health_income_;
    int health_expense_;
    int car_income_;
    int car_expense_;
    int house_income_;
    int house_expense_;
    int MAX = 500000;

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