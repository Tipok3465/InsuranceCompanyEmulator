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
    bg_label_->setStyleSheet("QLabel {"
                             "background: rgb(255, 255, 255);"
                             "}");
//    auto bg = new QMovie("../src/Front/resources/bg.gif");
//    bg_label_->setMovie(bg);
//    bg->start();

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
    inc_label_->move(30, 260);
    inc_label_->setStyleSheet("QLabel {"
                                      "color: rgb(0, 0, 0);"
                                      "}");
    inc_label_->setText("Incomes");
    inc_label_->setAlignment(Qt::AlignLeft);

    income_label_ = new IncomeLabel(this);
    income_label_->setRange(0, 100);
    income_label_->setWidth(300);
    income_label_->resize(10, 10);
    income_label_->move(30, 300);

    exp_label_ = new QLabel(this);
    exp_label_->setFont(QFont(font_family_, 25));
    exp_label_->resize(300, 70);
    exp_label_->move(694, 260);
    exp_label_->setStyleSheet("QLabel {"
                              "color: rgb(0, 0, 0);"
                              "}");
    exp_label_->setText("Expenses");
    exp_label_->setAlignment(Qt::AlignRight);

    expense_label_ = new ExpenseLabel(this);
    expense_label_->resize(10, 10);
    expense_label_->setRange(0, 100);
    expense_label_->move(694, 300);
    expense_label_->setWidth(300);

    expense_drawing_ = new QTimer(this);
    connect(expense_drawing_, &QTimer::timeout, this, &MainWindow::drawExpense);

    income_drawing_ = new QTimer(this);
    connect(income_drawing_, &QTimer::timeout, this, &MainWindow::drawIncome);

    capital_drawing_ = new QTimer(this);
    connect(capital_drawing_, &QTimer::timeout, this, &MainWindow::drawCapital);
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
        else if (abs(cur_cap - cur_capital_) <= 1000) cur_cap += 100;
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
    capital_drawing_->start(1);
    inc_val_ = 100;
    income_drawing_->start(25);
    exp_val_ = 100;
    expense_drawing_->start(25);
    cur_month_->setText(QString::fromStdString(std::to_string(cur_month_id_) +
                                                "/" + std::to_string(month_count_) + " month"));
    tax_percentage_ = tax_percentage;
    base_demand_ = base_demand;
}
