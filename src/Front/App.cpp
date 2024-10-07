#include "App.h"

App::App(int width, int height) {
    QFileInfo file("../src/Front/resources/TenorSans-Regular.ttf");
    int id = QFontDatabase::addApplicationFont(file.absolutePath() + "/TenorSans-Regular.ttf");
    font_family_ = QFontDatabase::applicationFontFamilies(id).at(0);
    window_ = new QMainWindow();
    window_->setFixedSize(width, height);
    window_->setStyleSheet("QMainWindow {"
                           "background: #404040;"
                           "}");

    start_bg_ = new QLabel(window_);
    start_bg_->resize(width, height);
    start_bg_->setPixmap(QPixmap::fromImage(QImage("../src/Front/resources/bg.png")));

    start_label_ = new QLabel(window_);
    start_label_->resize(600, 50);
    start_label_->move(0, 20);
    start_label_->setAlignment(Qt::AlignCenter);
    start_label_->setFont(QFont(font_family_, 40));
    start_label_->setText("Welcome to our company!");
    start_label_->setStyleSheet("QLabel {"
                                "color: #000000;"
                                "}");


    month_count_label_ = new QLabel(window_);
    month_count_label_->resize(150, 40);
    month_count_label_->move(157, 100);
    month_count_label_->setText("MONTH COUNT");
    month_count_label_->setStyleSheet("QLabel {"
                                "color: #000000;"
                                "}");
    month_count_label_->setFont(QFont(font_family_, 15));

    month_count_editor_ = new QSpinBox(window_);
    month_count_editor_->setStyleSheet("QSpinBox {"
                                       "color: #000000;"
                                       "background: rgba(120, 120, 120, 40);"
                                       "border-radius: 7px;"
                                       "}");
    month_count_editor_->resize(120, 30);
    month_count_editor_->move(310, 105);
    month_count_editor_->setRange(6, 24);
    month_count_editor_->setValue(6);
    month_count_editor_->setAlignment(Qt::AlignCenter);
    month_count_editor_->setFont(QFont(font_family_, 15));


    start_capital_label_ = new QLabel(window_);
    start_capital_label_->resize(150, 40);
    start_capital_label_->move(155, 150);
    start_capital_label_->setText("CAPITAL COUNT");
    start_capital_label_->setStyleSheet("QLabel {"
                                      "color: #000000;"
                                      "}");
    start_capital_label_->setFont(QFont(font_family_, 15));

    start_capital_editor_ = new QSpinBox(window_);
    start_capital_editor_->setStyleSheet("QSpinBox {"
                                       "color: #000000;"
                                       "background: rgba(120, 120, 120, 40);"
                                       "border-radius: 7px;"
                                       "}");
    start_capital_editor_->resize(120, 30);
    start_capital_editor_->move(310, 155);
    start_capital_editor_->setRange(100000, 10000000);
    start_capital_editor_->setValue(100000);
    start_capital_editor_->setAlignment(Qt::AlignCenter);
    start_capital_editor_->setFont(QFont(font_family_, 15));


    tax_percentage_label_ = new QLabel(window_);
    tax_percentage_label_->resize(150, 40);
    tax_percentage_label_->move(150, 200);
    tax_percentage_label_->setText("TAX PERCENTAGE");
    tax_percentage_label_->setStyleSheet("QLabel {"
                                        "color: #000000;"
                                        "}");
    tax_percentage_label_->setFont(QFont(font_family_, 15));

    tax_percentage_editor_ = new QSpinBox(window_);
    tax_percentage_editor_->setStyleSheet("QSpinBox {"
                                         "color: #000000;"
                                         "background: rgba(120, 120, 120, 40);"
                                         "border-radius: 7px;"
                                         "}");
    tax_percentage_editor_->resize(120, 30);
    tax_percentage_editor_->move(310, 205);
    tax_percentage_editor_->setRange(1, 100);
    tax_percentage_editor_->setValue(9);
    tax_percentage_editor_->setAlignment(Qt::AlignCenter);
    tax_percentage_editor_->setFont(QFont(font_family_, 15));

    base_demand_label_ = new QLabel(window_);
    base_demand_label_->resize(150, 40);
    base_demand_label_->move(163, 250);
    base_demand_label_->setText("BASE DEMAND");
    base_demand_label_->setStyleSheet("QLabel {"
                                         "color: #000000;"
                                         "}");
    base_demand_label_->setFont(QFont(font_family_, 15));

    base_demand_editor_ = new QSpinBox(window_);
    base_demand_editor_->setStyleSheet("QSpinBox {"
                                          "color: #000000;"
                                          "background: rgba(120, 120, 120, 40);"
                                          "border-radius: 7px;"
                                          "}");
    base_demand_editor_->resize(120, 30);
    base_demand_editor_->move(310, 255);
    base_demand_editor_->setRange(1, 20);
    base_demand_editor_->setValue(5);
    base_demand_editor_->setAlignment(Qt::AlignCenter);
    base_demand_editor_->setFont(QFont(font_family_, 15));


    start_game_ = new QPushButton(window_);
    start_game_->resize(300, 60);
    start_game_->move(143, 305);
    start_game_->setFont(QFont(font_family_, 30));
    start_game_->setText("START GAME");
    start_game_->setStyleSheet("QPushButton {"
                               "color: #000000;"
                               "background: rgba(118, 192, 83, 30);"
                               "border-radius: 10px;"
                               "}");
    connect(start_game_, &QPushButton::released, this, &App::GoToMainGame);

    help_button_ = new QPushButton(window_);
    help_button_->resize(120, 30);
    help_button_->move(470, 360);
    help_button_->setFont(QFont(font_family_, 12));
    help_button_->setText("What's going on?..");
    help_button_->setStyleSheet("QPushButton {"
                               "color: #000000;"
                               "background: rgba(0, 0, 0, 30);"
                               "border-radius: 10px;"
                               "}");
    connect(help_button_, &QPushButton::released, this, &App::GoToHelpLabel);

    help_window_ = new QMainWindow();
    help_window_->resize(300, 200);
    help_window_->hide();

    auto help_bg_label_ = new QLabel(help_window_);
    help_bg_label_->resize(300, 200);
    help_bg_label_->setPixmap(QPixmap::fromImage(QImage("../src/Front/resources/bg.png")));

    auto help_text_ = new QLabel(help_bg_label_);
    help_text_->resize(300, 200);
    help_text_->move(0, 0);
    help_text_->setFont(QFont(font_family_, 22));
    help_text_->setText("Our program is a \nmodel of how an \ninsurance company works\n\n"
                        "Set the initial \nsettings and enjoyа;)");
    help_text_->setStyleSheet("QLabel {"
                              "color: rgb(0, 0, 0);"
                              "}");
    help_text_->setAlignment(Qt::AlignCenter);


    main_window_ = new MainWindow();
    main_window_->setFixedSize(1024, 768);
    main_window_->hide();
}

void App::GoToHelpLabel() {
    if (help_window_->isHidden()) help_window_->show();
    else help_window_->hide();
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
