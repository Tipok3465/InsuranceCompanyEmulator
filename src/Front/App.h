#include "../header.h"
#include "MainWindow.h"
#pragma once

class App : public QMainWindow {
    Q_OBJECT

public:
    App(int width, int height);
    ~App() override;

    void render() {
        window_->show();
    }
protected slots:
    void GoToMainGame();
private:
    QString font_family_;
    QMainWindow* window_;
    QLabel* start_label_;
    QSpinBox* month_count_editor_;
    QLabel* month_count_label_;
    QSpinBox* start_capital_editor_;
    QLabel* start_capital_label_;
    QSpinBox* tax_percentage_editor_;
    QLabel* tax_percentage_label_;
    QSpinBox* base_demand_editor_;
    QLabel* base_demand_label_;
    QPushButton* start_game_;
    MainWindow* main_window_;
};