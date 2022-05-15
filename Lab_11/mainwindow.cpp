#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Создаем виджет
    wgt = new MyWidget(this);

    // И кладём его в лайаут
    ui->verticalLayout->addWidget(wgt);
}

void MainWindow::deleteFig() {
    qDebug() << "In delete fig";
    for (int it = 0; it < figArray.size(); it++) {
        if (figArray[it].get() == hoveredFig) {
            figArray.erase(figArray.begin()+it);
            update();
            return;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

