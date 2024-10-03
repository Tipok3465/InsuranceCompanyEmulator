#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) {
    setMouseTracking(true);
    setParent(parent);
    int id = QFontDatabase::addApplicationFont("/Users/noname/Documents/Programming/Applied/InsuranceCompanyEmulatorTrue/src/Front/resources/PlaywriteDEGrund-VariableFont_wght.ttf");
    font_family_ = QFontDatabase::applicationFontFamilies(id).at(0);

    cur_capital_ = new QLabel(this);
    cur_capital_->setFont(QFont(font_family_, 30));
    cur_capital_->resize(1024, 70);
    cur_capital_->move(0, 10);
    cur_capital_->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow() {

}

void MainWindow::setParams(int month_count, int start_capital, int tax_percentage, int base_demand) {
    month_count_ = month_count;
    start_capital_ = start_capital;
    cur_capital_->setText(QString::fromStdString("Capital: " + std::to_string(start_capital_) + "₽"));
    tax_percentage_ = tax_percentage;
    base_demand_ = base_demand;
}
