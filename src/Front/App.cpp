#include "App.h"

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
    start_label_->move(0, 20);
    start_label_->setAlignment(Qt::AlignCenter);
    start_label_->setText("Welcome to our company!");
    start_label_->setFont(QFont(font_family_, 40));
    start_label_->setStyleSheet("QLabel {"
                                "color: #fbfbfb"
                                "}");


    month_count_label_ = new QLabel(window_);
    month_count_label_->resize(150, 40);
    month_count_label_->move(200, 100);
    month_count_label_->setText("MONTH COUNT");
    month_count_label_->setFont(QFont(font_family_, 15));

    month_count_editor_ = new QSpinBox(window_);
    month_count_editor_->resize(40, 30);
    month_count_editor_->move(350, 105);
    month_count_editor_->setRange(6, 24);
    month_count_editor_->setValue(6);
    month_count_editor_->setFont(QFont(font_family_, 15));


    start_capital_label_ = new QLabel(window_);
    start_capital_label_->resize(150, 40);
    start_capital_label_->move(155, 150);
    start_capital_label_->setText("CAPITAL COUNT");
    start_capital_label_->setFont(QFont(font_family_, 15));

    start_capital_editor_ = new QSpinBox(window_);
    start_capital_editor_->resize(120, 30);
    start_capital_editor_->move(310, 155);
    start_capital_editor_->setRange(100000, 10000000);
    start_capital_editor_->setValue(100000);
    start_capital_editor_->setFont(QFont(font_family_, 15));


    tax_percentage_label_ = new QLabel(window_);
    tax_percentage_label_->resize(150, 40);
    tax_percentage_label_->move(150, 200);
    tax_percentage_label_->setText("TAX PERCENTAGE");
    tax_percentage_label_->setFont(QFont(font_family_, 15));

    tax_percentage_editor_ = new QSpinBox(window_);
    tax_percentage_editor_->resize(120, 30);
    tax_percentage_editor_->move(310, 205);
    tax_percentage_editor_->setRange(1, 100);
    tax_percentage_editor_->setValue(9);
    tax_percentage_editor_->setFont(QFont(font_family_, 15));

    base_demand_label_ = new QLabel(window_);
    base_demand_label_->resize(150, 40);
    base_demand_label_->move(160, 250);
    base_demand_label_->setText("BASE DEMAND");
    base_demand_label_->setFont(QFont(font_family_, 15));

    base_demand_editor_ = new QSpinBox(window_);
    base_demand_editor_->resize(120, 30);
    base_demand_editor_->move(310, 255);
    base_demand_editor_->setRange(1, 20);
    base_demand_editor_->setValue(5);
    base_demand_editor_->setFont(QFont(font_family_, 15));


    start_game_ = new QPushButton(window_);
    start_game_->resize(400, 70);
    start_game_->move(100, 300);
    start_game_->setFont(QFont(font_family_, 40));
    start_game_->setText("START GAME");
    connect(start_game_, &QPushButton::released, this, &App::GoToMainGame);

    main_window_ = new MainWindow();
    main_window_->setFixedSize(1024, 768);
    main_window_->setStyleSheet("QMainWindow {"
                           "background: #404040"
                           "}");
    main_window_->hide();
}

App::~App() {
    delete window_;
}

void App::GoToMainGame() {
    int m = month_count_editor_->value();
    int c = start_capital_editor_->value();
    int t = tax_percentage_editor_->value();
    int d = base_demand_editor_->value();
    main_window_->setParams(m, c, t, d);
    window_->hide();
    main_window_->show();
}
