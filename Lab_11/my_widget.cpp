#include "my_widget.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include <QPainter>
#include <memory>
#include <QDebug>

MyWidget::MyWidget(QWidget * parent) : QWidget(parent), menu("&Menu") {

    figArray.push_back(make_unique<Triangle>());
    figArray.push_back(make_unique<Rectangle>());

    list<int> newRectangle_params = { 200, 70, 250, 100 };
    figArray[1]->setParams(newRectangle_params);

    figArray.push_back(make_unique<Circle>());
    figArray.push_back(make_unique<Circle>());

    list<int> newCircle_params = { 100, 100, 30 };
    figArray[3]->setParams(newCircle_params);

    figArray.push_back(make_unique<Rectangle>());

    setMouseTracking(true);

    deleteAction = new QAction("&Delete Fig", this);
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteFig()));

    menu.addAction(deleteAction);
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this); // Создаём новый объект рисовальщика
    for (int it = 0; it < figArray.size(); ++it) {
        figArray[it]->drawFigure(&p);
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
        hoveredFig->moveFig(event->pos().x(), event->pos().y());
        hoveredFig = nullptr;
        update();
    }
}

MyWidget::~MyWidget(){
    delete deleteAction;
}
