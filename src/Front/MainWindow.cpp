#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) {
    setMouseTracking(true);
    setParent(parent);
    QFileInfo file("../src/Front/resources/PlaywriteDEGrund-VariableFont_wght.ttf");
    int id = QFontDatabase::addApplicationFont(file.absolutePath() + "/PlaywriteDEGrund-VariableFont_wght.ttf");
    //int id = QFontDatabase::addApplicationFont("/Users/noname/Documents/Programming/Applied/InsuranceCompanyEmulatorTrue/src/Front/resources/PlaywriteDEGrund-VariableFont_wght.ttf");
    font_family_ = QFontDatabase::applicationFontFamilies(id).at(0);

    cur_month_ = new QLabel(this);
    cur_month_->setFont(QFont(font_family_, 20));
    cur_month_->resize(1024, 40);
    cur_month_->move(0, 10);
    cur_month_->setAlignment(Qt::AlignCenter);

    cur_capital_ = new QLabel(this);
    cur_capital_->setFont(QFont(font_family_, 30));
    cur_capital_->resize(1024, 70);
    cur_capital_->move(0, 40);
    cur_capital_->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow() {
    delete cur_capital_;
}

void MainWindow::setParams(int month_count, int start_capital, int tax_percentage, int base_demand) {
    month_count_ = month_count;
    start_capital_ = start_capital;
    cur_capital_->setText(QString::fromStdString("Capital: " + std::to_string(start_capital_) + "₽"));
    cur_month_->setText(QString::fromStdString(std::to_string(cur_month_id_) +
                                                "/" + std::to_string(month_count_) + " month"));
    tax_percentage_ = tax_percentage;
    base_demand_ = base_demand;
}
