#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) {
    setMouseTracking(true);
    setParent(parent);
    QFileInfo file("../src/Front/resources/TenorSans-Regular.ttf");
    int id = QFontDatabase::addApplicationFont(file.absolutePath() + "/TenorSans-Regular.ttf");
    //int id = QFontDatabase::addApplicationFont("/Users/noname/Documents/Programming/Applied/InsuranceCompanyEmulatorTrue/src/Front/resources/PlaywriteDEGrund-VariableFont_wght.ttf");
    font_family_ = QFontDatabase::applicationFontFamilies(id).at(0);

    bg_label_ = new QLabel(this);
    bg_label_->resize(1024, 768);
    bg_label_->setPixmap(QPixmap::fromImage(QImage("../src/Front/resources/bg.png")));

    cur_month_ = new QLabel(this);
    cur_month_->setFont(QFont(font_family_, 20));
    cur_month_->resize(1024, 40);
    cur_month_->move(0, 10);
    cur_month_->setStyleSheet("QLabel {"
                              "color: rgb(0, 0, 0);"
                              "}");
    cur_month_->setAlignment(Qt::AlignCenter);

    cur_capital_label_ = new QLabel(this);
    cur_capital_label_->setFont(QFont(font_family_, 30));
    cur_capital_label_->resize(1024, 70);
    cur_capital_label_->move(0, 40);
    cur_capital_label_->setStyleSheet("QLabel {"
                                      "color: rgb(0, 0, 0);"
                                      "}");
    cur_capital_label_->setAlignment(Qt::AlignCenter);

    inc_label_ = new QLabel(this);
    inc_label_->setFont(QFont(font_family_, 25));
    inc_label_->resize(300, 70);
    inc_label_->move(30, 160);
    inc_label_->setStyleSheet("QLabel {"
                                      "color: rgb(0, 0, 0);"
                                      "}");
    inc_label_->setText("Incomes");
    inc_label_->setAlignment(Qt::AlignLeft);

    income_label_ = new IncomeLabel(this);
    income_label_->setRange(0, 100);
    income_label_->setWidth(300);
    income_label_->resize(10, 10);
    income_label_->move(30, 200);

    house_inc_label_ = new QLabel(this);
    house_inc_label_->setFont(QFont(font_family_, 20));
    house_inc_label_->resize(300, 70);
    house_inc_label_->move(40, 220);
    house_inc_label_->setStyleSheet("QLabel {"
                              "color: rgb(0, 0, 0);"
                              "}");
    house_inc_label_->setText("house");
    house_inc_label_->setAlignment(Qt::AlignLeft);

    house_income_label_ = new IncomeLabel(this);
    house_income_label_->setRange(0, 100);
    house_income_label_->setWidth(300);
    house_income_label_->resize(10, 10);
    house_income_label_->move(40, 250);

    car_inc_label_ = new QLabel(this);
    car_inc_label_->setFont(QFont(font_family_, 20));
    car_inc_label_->resize(300, 70);
    car_inc_label_->move(40, 270);
    car_inc_label_->setStyleSheet("QLabel {"
                                    "color: rgb(0, 0, 0);"
                                    "}");
    car_inc_label_->setText("car");
    car_inc_label_->setAlignment(Qt::AlignLeft);

    car_income_label_ = new IncomeLabel(this);
    car_income_label_->setRange(0, 100);
    car_income_label_->setWidth(300);
    car_income_label_->resize(10, 10);
    car_income_label_->move(40, 300);

    health_inc_label_ = new QLabel(this);
    health_inc_label_->setFont(QFont(font_family_, 20));
    health_inc_label_->resize(300, 70);
    health_inc_label_->move(40, 320);
    health_inc_label_->setStyleSheet("QLabel {"
                                  "color: rgb(0, 0, 0);"
                                  "}");
    health_inc_label_->setText("health");
    health_inc_label_->setAlignment(Qt::AlignLeft);

    heath_income_label_ = new IncomeLabel(this);
    heath_income_label_->setRange(0, 100);
    heath_income_label_->setWidth(300);
    heath_income_label_->resize(10, 10);
    heath_income_label_->move(40, 350);

    exp_label_ = new QLabel(this);
    exp_label_->setFont(QFont(font_family_, 25));
    exp_label_->resize(300, 70);
    exp_label_->move(694, 160);
    exp_label_->setStyleSheet("QLabel {"
                              "color: rgb(0, 0, 0);"
                              "}");
    exp_label_->setText("Expenses");
    exp_label_->setAlignment(Qt::AlignRight);

    expense_label_ = new ExpenseLabel(this);
    expense_label_->resize(10, 10);
    expense_label_->setRange(0, 100);
    expense_label_->move(694, 200);
    expense_label_->setWidth(300);

    house_exp_label_ = new QLabel(this);
    house_exp_label_->setFont(QFont(font_family_, 20));
    house_exp_label_->resize(300, 70);
    house_exp_label_->move(684, 220);
    house_exp_label_->setStyleSheet("QLabel {"
                              "color: rgb(0, 0, 0);"
                              "}");
    house_exp_label_->setText("house");
    house_exp_label_->setAlignment(Qt::AlignRight);

    house_expense_label_ = new ExpenseLabel(this);
    house_expense_label_->resize(10, 10);
    house_expense_label_->setRange(0, 100);
    house_expense_label_->move(684, 250);
    house_expense_label_->setWidth(300);

    car_exp_label_ = new QLabel(this);
    car_exp_label_->setFont(QFont(font_family_, 20));
    car_exp_label_->resize(300, 70);
    car_exp_label_->move(684, 270);
    car_exp_label_->setStyleSheet("QLabel {"
                                    "color: rgb(0, 0, 0);"
                                    "}");
    car_exp_label_->setText("car");
    car_exp_label_->setAlignment(Qt::AlignRight);

    car_expense_label_ = new ExpenseLabel(this);
    car_expense_label_->resize(10, 10);
    car_expense_label_->setRange(0, 100);
    car_expense_label_->move(684, 300);
    car_expense_label_->setWidth(300);

    health_exp_label_ = new QLabel(this);
    health_exp_label_->setFont(QFont(font_family_, 20));
    health_exp_label_->resize(300, 70);
    health_exp_label_->move(684, 320);
    health_exp_label_->setStyleSheet("QLabel {"
                                  "color: rgb(0, 0, 0);"
                                  "}");
    health_exp_label_->setText("health");
    health_exp_label_->setAlignment(Qt::AlignRight);

    health_expense_label_ = new ExpenseLabel(this);
    health_expense_label_->resize(10, 10);
    health_expense_label_->setRange(0, 100);
    health_expense_label_->move(684, 350);
    health_expense_label_->setWidth(300);

    gov_exp_label_ = new QLabel(this);
    gov_exp_label_->setFont(QFont(font_family_, 20));
    gov_exp_label_->resize(300, 70);
    gov_exp_label_->move(684, 370);
    gov_exp_label_->setStyleSheet("QLabel {"
                                     "color: rgb(0, 0, 0);"
                                     "}");
    gov_exp_label_->setText("government");
    gov_exp_label_->setAlignment(Qt::AlignRight);

    gov_expense_label_ = new ExpenseLabel(this);
    gov_expense_label_->resize(10, 10);
    gov_expense_label_->setRange(0, 100);
    gov_expense_label_->move(684, 400);
    gov_expense_label_->setWidth(300);

    open_health_contract_button_ = new QPushButton(this);
    open_health_contract_button_->resize(150, 30);
    open_health_contract_button_->move(20, 728);
    open_health_contract_button_->setFont(QFont(font_family_, 18));
    open_health_contract_button_->setText("Health Contract");
    open_health_contract_button_->setStyleSheet("QPushButton {"
                                "color: #000000;"
                                "background: rgba(0, 0, 0, 30);"
                                "border-radius: 10px;"
                                "}");
    connect(open_health_contract_button_, &QPushButton::released, this, &MainWindow::openHealthContract);

    health_contract_window_ = new QMainWindow();
    health_contract_window_->resize(400, 450);
    health_contract_window_->hide();

    health_contract_bg_ = new QLabel(health_contract_window_);
    health_contract_bg_->resize(400, 550);
    health_contract_bg_->setPixmap(QPixmap::fromImage(QImage("../src/Front/resources/bg.png")));

    health_contract_text_ = new QLabel(health_contract_bg_);
    health_contract_text_->resize(380, 530);
    health_contract_text_->move(10, 10);
    health_contract_text_->setFont(QFont(font_family_, 20));
    health_contract_text_->setStyleSheet("QLabel {"
                                         "color: rgb(0, 0, 0);"
                                         "}");
    health_contract_text_->setText("HEALTH AGREEMENT\n\nBy this agreement you confirm that you are enslaving yourself to our company."
                                   " In turn, in case of health problems, we undertake to provide you with money in the amount "
                                   "of up to " + QString::fromStdString(std::to_string(health_contract_.max_pay)) + "₽\n"
                                   "This agreement is valid for " + QString::fromStdString(std::to_string(health_contract_.month_count)) + " months from the date of signing."
                                   " Cost of conclusion: " +
                                   QString::fromStdString(std::to_string(health_contract_.price))+ "₽\n\n");
    health_contract_text_->setWordWrap(true);
    health_contract_text_->setAlignment(Qt::AlignHCenter);


    health_label_month_editor_ = new QLabel(health_contract_bg_);
    health_label_month_editor_->resize(120, 50);
    health_label_month_editor_->move(15, 290);
    health_label_month_editor_->setFont(QFont(font_family_, 18));
    health_label_month_editor_->setAlignment(Qt::AlignLeft);
    health_label_month_editor_->setStyleSheet("QLabel {"
                                 "color: rgb(0, 0, 0);"
                                 "}");
    health_label_month_editor_->setText("month count");

    health_contract_month_editor_ = new QSpinBox(health_contract_bg_);
    health_contract_month_editor_->setStyleSheet("QSpinBox {"
                                       "color: #000000;"
                                       "background: rgba(120, 120, 120, 40);"
                                       "border-radius: 7px;"
                                       "}");
    health_contract_month_editor_->resize(120, 25);
    health_contract_month_editor_->move(10, 320);
    health_contract_month_editor_->setRange(6, 24);
    health_contract_month_editor_->setValue(health_contract_.month_count);
    health_contract_month_editor_->setAlignment(Qt::AlignCenter);
    health_contract_month_editor_->setFont(QFont(font_family_, 15));

    health_label_max_pay_editor_ = new QLabel(health_contract_bg_);
    health_label_max_pay_editor_->resize(120, 50);
    health_label_max_pay_editor_->move(140, 290);
    health_label_max_pay_editor_->setFont(QFont(font_family_, 18));
    health_label_max_pay_editor_->setAlignment(Qt::AlignHCenter);
    health_label_max_pay_editor_->setStyleSheet("QLabel {"
                                              "color: rgb(0, 0, 0);"
                                              "}");
    health_label_max_pay_editor_->setText("max pay");

    health_contract_max_pay_editor_ = new QSpinBox(health_contract_bg_);
    health_contract_max_pay_editor_->setStyleSheet("QSpinBox {"
                                                 "color: #000000;"
                                                 "background: rgba(120, 120, 120, 40);"
                                                 "border-radius: 7px;"
                                                 "}");
    health_contract_max_pay_editor_->resize(120, 25);
    health_contract_max_pay_editor_->move(140, 320);
    health_contract_max_pay_editor_->setRange(1, 100000);
    health_contract_max_pay_editor_->setValue(health_contract_.max_pay);
    health_contract_max_pay_editor_->setAlignment(Qt::AlignCenter);
    health_contract_max_pay_editor_->setFont(QFont(font_family_, 15));

    health_label_price_editor_ = new QLabel(health_contract_bg_);
    health_label_price_editor_->resize(120, 50);
    health_label_price_editor_->move(270, 290);
    health_label_price_editor_->setFont(QFont(font_family_, 18));
    health_label_price_editor_->setAlignment(Qt::AlignHCenter);
    health_label_price_editor_->setStyleSheet("QLabel {"
                                                "color: rgb(0, 0, 0);"
                                                "}");
    health_label_price_editor_->setText("price");

    health_contract_price_editor_ = new QSpinBox(health_contract_bg_);
    health_contract_price_editor_->setStyleSheet("QSpinBox {"
                                                   "color: #000000;"
                                                   "background: rgba(120, 120, 120, 40);"
                                                   "border-radius: 7px;"
                                                   "}");
    health_contract_price_editor_->resize(120, 25);
    health_contract_price_editor_->move(270, 320);
    health_contract_price_editor_->setRange(1, 100000);
    health_contract_price_editor_->setValue(health_contract_.price);
    health_contract_price_editor_->setAlignment(Qt::AlignCenter);
    health_contract_price_editor_->setFont(QFont(font_family_, 15));


    health_set_month_count_button_ = new QPushButton(health_contract_bg_);
    health_set_month_count_button_->resize(140, 40);
    health_set_month_count_button_->move(130, 360);
    health_set_month_count_button_->setFont(QFont(font_family_, 24));
    health_set_month_count_button_->setText("set");
    health_set_month_count_button_->setStyleSheet("QPushButton {"
                                             "color: #000000;"
                                             "background: rgba(0, 0, 0, 30);"
                                             "border-radius: 10px;"
                                             "}");
    connect(health_set_month_count_button_, &QPushButton::released, this, &MainWindow::setHealthContract);


    open_car_contract_button_ = new QPushButton(this);
    open_car_contract_button_->resize(150, 30);
    open_car_contract_button_->move(180, 728);
    open_car_contract_button_->setFont(QFont(font_family_, 18));
    open_car_contract_button_->setText("House Contract");
    open_car_contract_button_->setStyleSheet("QPushButton {"
                                                "color: #000000;"
                                                "background: rgba(0, 0, 0, 30);"
                                                "border-radius: 10px;"
                                                "}");
    connect(open_car_contract_button_, &QPushButton::released, this, &MainWindow::openCarContract);

    car_contract_window_ = new QMainWindow();
    car_contract_window_->resize(400, 550);
    car_contract_window_->hide();

    car_contract_bg_ = new QLabel(car_contract_window_);
    car_contract_bg_->resize(400, 550);
    car_contract_bg_->setPixmap(QPixmap::fromImage(QImage("../src/Front/resources/bg.png")));

    car_contract_text_ = new QLabel(car_contract_bg_);
    car_contract_text_->resize(380, 530);
    car_contract_text_->move(10, 10);
    car_contract_text_->setFont(QFont(font_family_, 20));
    car_contract_text_->setStyleSheet("QLabel {"
                                         "color: rgb(0, 0, 0);"
                                         "}");
    car_contract_text_->setText("CAR AGREEMENT\n\nBy this agreement you confirm that you are enslaving yourself to our company."
                                   " In turn, in case of car breakdown, we undertake to provide you with money in the amount "
                                   "of up to " + QString::fromStdString(std::to_string(car_contract_.max_pay)) + "₽\n"\
                                   "This agreement is valid for " + QString::fromStdString(std::to_string(car_contract_.month_count))
                                   + " months from the date of signing."\
                                   " Cost of conclusion: " +
                                   QString::fromStdString(std::to_string(car_contract_.price))+ "₽");
    car_contract_text_->setWordWrap(true);
    car_contract_text_->setAlignment(Qt::AlignHCenter);


    open_house_contract_button_ = new QPushButton(this);
    open_house_contract_button_->resize(150, 30);
    open_house_contract_button_->move(340, 728);
    open_house_contract_button_->setFont(QFont(font_family_, 18));
    open_house_contract_button_->setText("Car Contract");
    open_house_contract_button_->setStyleSheet("QPushButton {"
                                             "color: #000000;"
                                             "background: rgba(0, 0, 0, 30);"
                                             "border-radius: 10px;"
                                             "}");
    connect(open_house_contract_button_, &QPushButton::released, this, &MainWindow::openHouseContract);

    house_contract_window_ = new QMainWindow();
    house_contract_window_->resize(400, 550);
    house_contract_window_->hide();

    house_contract_bg_ = new QLabel(house_contract_window_);
    house_contract_bg_->resize(400, 550);
    house_contract_bg_->setPixmap(QPixmap::fromImage(QImage("../src/Front/resources/bg.png")));

    house_contract_text_ = new QLabel(house_contract_bg_);
    house_contract_text_->resize(380, 530);
    house_contract_text_->move(10, 10);
    house_contract_text_->setFont(QFont(font_family_, 20));
    house_contract_text_->setStyleSheet("QLabel {"
                                      "color: rgb(0, 0, 0);"
                                      "}");
    house_contract_text_->setText("HOUSE AGREEMENT\n\nBy this agreement you confirm that you are enslaving yourself to our company."
                                " In turn, in case of fire in house, we undertake to provide you with money in the amount "
                                "of up to " + QString::fromStdString(std::to_string(house_contract_.max_pay)) + "₽\n"\
                                   "This agreement is valid for " + QString::fromStdString(std::to_string(house_contract_.month_count))
                                + " months from the date of signing."\
                                   " Cost of conclusion: " +
                                QString::fromStdString(std::to_string(house_contract_.price))+ "₽");
    house_contract_text_->setWordWrap(true);
    house_contract_text_->setAlignment(Qt::AlignHCenter);


    expense_drawing_ = new QTimer(this);
    connect(expense_drawing_, &QTimer::timeout, this, &MainWindow::drawExpense);

    income_drawing_ = new QTimer(this);
    connect(income_drawing_, &QTimer::timeout, this, &MainWindow::drawIncome);

    capital_drawing_ = new QTimer(this);
    connect(capital_drawing_, &QTimer::timeout, this, &MainWindow::drawCapital);
}

void MainWindow::setHealthContract() {
    health_contract_.month_count = health_contract_month_editor_->value();
    health_contract_.max_pay = health_contract_max_pay_editor_->value();
    health_contract_.price = health_contract_price_editor_->value();
    health_contract_text_->setText("HEALTH AGREEMENT\n\nBy this agreement you confirm that you are enslaving yourself to our company."
                                   " In turn, in case of health problems, we undertake to provide you with money in the amount "
                                   "of up to " + QString::fromStdString(std::to_string(health_contract_.max_pay)) + "₽\n"\
                                   "This agreement is valid for " +
                                   QString::fromStdString(std::to_string(health_contract_.month_count)) +
                                   " months from the date of signing."\
                                   " Cost of conclusion: " +
                                   QString::fromStdString(std::to_string(health_contract_.price))+ "₽\n\n");
    std::cout << "OK\n";
}

void MainWindow::openHealthContract() {
    if (health_contract_window_->isHidden()) health_contract_window_->show();
    else health_contract_window_->hide();
}
void MainWindow::openCarContract() {
    if (car_contract_window_->isHidden()) car_contract_window_->show();
    else car_contract_window_->hide();
}
void MainWindow::openHouseContract() {
    if (house_contract_window_->isHidden()) house_contract_window_->show();
    else house_contract_window_->hide();
}

void MainWindow::drawExpense() {
    if (expense_label_->getValue() == exp_val_) {
        expense_drawing_->stop();
        exp_val_ = 0;
    } else {
        expense_label_->setValue(expense_label_->getValue()+1);
    }
}

void MainWindow::drawIncome() {
    if (income_label_->getValue() == inc_val_) {
        income_drawing_->stop();
        inc_val_ = 0;
    } else {
        income_label_->setValue(income_label_->getValue()+1);
    }
}

void MainWindow::drawCapital() {
    if (cur_cap == cur_capital_) {
        capital_drawing_->stop();
        cur_cap = 0;
    } else {
        if (abs(cur_cap - cur_capital_) <= 10) cur_cap++;
        else if (abs(cur_cap - cur_capital_) <= 1000) cur_cap += 10;
        else if (abs(cur_cap - cur_capital_) <= 10000) cur_cap += 100;
        else if (abs(cur_cap - cur_capital_) <= 100000) cur_cap += 1000;
        else if (abs(cur_cap - cur_capital_) <= 1000000) cur_cap += 10000;
        else if (abs(cur_cap - cur_capital_) <= 10000000) cur_cap += 100000;
        cur_capital_label_->setText(QString::fromStdString("Capital: " + std::to_string(cur_cap) + "₽"));
    }
}

MainWindow::~MainWindow() {
    delete cur_capital_label_;
}

void MainWindow::setParams(int month_count, int start_capital, int tax_percentage, int base_demand) {
    month_count_ = month_count;
    cur_capital_ = start_capital;
    capital_drawing_->start(10);
    inc_val_ = 100;
    income_drawing_->start(25);
    exp_val_ = 100;
    expense_drawing_->start(25);
    cur_month_->setText(QString::fromStdString(std::to_string(cur_month_id_) +
                                               "/" + std::to_string(month_count_) + " month"));
    company_.set_cur_balance(start_capital);
    company_.set_car_insurance_demand(base_demand);
    company_.set_home_insurance_demand(base_demand);
    company_.set_life_insurance_demand(base_demand);
    tax_percentage_ = tax_percentage;
    base_demand_ = base_demand;
}