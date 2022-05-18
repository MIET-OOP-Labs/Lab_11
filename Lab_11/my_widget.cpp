#include "my_widget.h"
#include "circle.h"
#include "n_square.h"
#include <QPainter>
#include <memory>
#include <QDebug>

MyWidget::MyWidget(QWidget * parent) : QWidget(parent), menu("&Menu") {

    QPainter painter(this);
    vector<QPoint> triangle {QPoint(110, 100), QPoint(150, 50), QPoint(200, 100)};

    figArray.fill(make_unique<n_square<CURR_QPOINT_TYPE>>(painter, triangle));

    vector<QPoint> rectangle {QPoint(20, 20), QPoint(50, 20), QPoint(50, 50), QPoint(20, 50)};
    figArray.fill(make_unique<n_square<CURR_QPOINT_TYPE>>(painter, rectangle));

    figArray.fill(make_unique<Circle<CURR_QPOINT_TYPE>>(painter, QPoint(100, 100), 30));
    setMouseTracking(true);

    deleteAction = new QAction("&Delete Fig", this);
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteFig()));

    menu.addAction(deleteAction);
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this); // Создаём новый объект рисовальщика
    for (int it = 0; it < figArray.size(); ++it) {
        figArray[it]->drawFigure();
    }

    p.setPen(QPen(Qt::black, 2, Qt::SolidLine));

    QFont font;
    font.setPixelSize(12);
    p.setFont(font);
    p.drawText(figInfoPos, QString::fromStdString(figInfo));

}

void MyWidget::mouseMoveEvent(QMouseEvent *event) {
    for (int it = 0; it < figArray.size(); it++) {
        if (figArray[it]->isMouseInside(event->pos())) {
            figArray[it]->setColor(Qt::green);
            update();
        } else {
            figArray[it]->setColor(Qt::red);
            update();
        }
    }
}

void MyWidget::mousePressEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton){
        for (int it = 0; it < figArray.size(); it++) {
            if (figArray[it]->isMouseInside(event->pos())) {
                figInfo = figArray[it]->getName();
                figInfoPos.setX(event->pos().x());
                figInfoPos.setY(event->pos().y() - 10);
                hoveredFig = figArray[it].get();
                update();
                return;
            }
        }
    } else if(event->buttons() & Qt::RightButton){
        menu.exec();


    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event){
    if (!(event->buttons() & Qt::LeftButton) && (hoveredFig)){

        hoveredFig->moveFig(event->pos());
        hoveredFig = nullptr;
        update();
    }
}


void MyWidget::deleteFig() {
    qDebug() << "In delete fig";
    for (int it = 0; it < figArray.size(); it++) {
        if (figArray[it].get() == hoveredFig) {
            figArray[it] = nullptr;
            //figArray.erase(figArray.begin()+it);
            update();
            return;
        }
    }
}

MyWidget::~MyWidget(){
    delete deleteAction;
}
