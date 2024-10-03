#include "src/header.h"
#include "src/Front/App.h"

int32_t main(int32_t argc, char *argv[]) {
    QApplication a(argc, argv);
    App Company(600, 200);
    Company.render();
    return QApplication::exec();
}