#include "App.h"

App::~App() {
    delete window_;
}

App::App(int width, int height) {
    int id = QFontDatabase::addApplicationFont("/Users/noname/Documents/Programming/Applied/InsuranceCompanyEmulatorTrue/src/Front/resources/PlaywriteDEGrund-VariableFont_wght.ttf");
    font_family_ = QFontDatabase::applicationFontFamilies(id).at(0);
    window_ = new QMainWindow();
    window_->setFixedSize(width, height);
    window_->setStyleSheet("QMainWindow {"
                           "background: #404040"
                           "}");

    start_label_ = new QLabel(window_);
    start_label_->resize(600, 50);
    start_label_->move(0, 30);
    start_label_->setAlignment(Qt::AlignCenter);
    start_label_->setText("Welcome to our company!");
    start_label_->setFont(QFont(font_family_, 40));
    start_label_->setStyleSheet("QLabel {"
                                "color: #fbfbfb"
                                "}");

    start_game_ = new QPushButton(window_);
    start_game_->resize(400, 70);
    start_game_->move(100, 100);
    start_game_->setFont(QFont(font_family_, 40));
    start_game_->setText("START GAME");
}
