#include "my_widget.h"
#include "circle.h"
#include "n_square.h"
#include <QPainter>
#include <memory>
#include <QDebug>

MyWidget::MyWidget(QWidget * parent) :QWidget(parent) {

    deleteAction = new QAction("&Delete Fig", this);
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteFig()));
    menu = new QMenu("&Menu");
    menu->addAction(deleteAction);

    vector<QPoint> triangle {QPoint(110, 100), QPoint(150, 50), QPoint(200, 100)};
    figArray.push_back(make_unique<n_square<curr_QPoint, curr_QPolygon>>(triangle));

    vector<QPoint> rectangle {QPoint(120, 120), QPoint(150, 120), QPoint(150, 150), QPoint(120, 150)};
    figArray.push_back(make_unique<n_square<curr_QPoint, curr_QPolygon>>(rectangle));

    vector<QPoint> hexagon {QPoint(20, 20), QPoint(35, 0), QPoint(50, 20), QPoint(50, 50), QPoint(35, 70), QPoint(20, 50)};
    figArray.push_back(make_unique<n_square<curr_QPoint, curr_QPolygon>>(hexagon));

    figArray.push_back(make_unique<Circle<curr_QPoint, curr_QPolygon>>(QPoint(100, 100), 30));
    setMouseTracking(true);
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this); // Создаём новый объект рисовальщика
    for (int it = 0; it < figArray.size(); ++it) {
        figArray[it]->drawFigure(p);
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
            hoveredFigNum = it;
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
                hoveredFigNum = it;
                update();
                return;
            }
        }
    } else if(event->buttons() & Qt::RightButton){
        //menu->exec();
        menu->popup(event->pos());
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event){
    QPainter p(this);
    if (!(event->buttons() & Qt::LeftButton) && (hoveredFigNum >= 0)){
        figArray[hoveredFigNum] ->moveFig(p, event->pos());
        hoveredFigNum = -1;
        update();
    }
}

void MyWidget::deleteFig() {
    qDebug() << "In delete fig";
    int i = 0;
    while (i < figArray.size()) {
        if (i == hoveredFigNum){
            figArray.erase(figArray.begin()+i);
        }
        i++;
    }
}

MyWidget::~MyWidget(){
    delete  deleteAction;
    delete  menu;
}
