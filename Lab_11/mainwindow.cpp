#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Создаем виджет
    wgt = new MyWidget(ui->centralwidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

