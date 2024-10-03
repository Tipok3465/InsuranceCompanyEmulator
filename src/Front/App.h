#include "../header.h"
#pragma once

class App : public QMainWindow {
    Q_OBJECT

public:
    App(int width, int height);
    ~App() override;

    void render() {
        window_->show();
    }
private:
    QString font_family_;
    QMainWindow* window_;
    QLabel* start_label_;
    QPushButton* start_game_;
};