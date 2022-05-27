#include "circle.h"

template<typename TModel, typename TKey>
void Circle<TModel, TKey>::drawFigure(QPainter &painter) {
    painter.setPen(QPen(this->getColor(),
                          this->getWidth(),
                          this->getStyle()));
    painter.drawEllipse(myCenter, myDiam, myDiam);
}

template<typename TModel, typename TKey>
int Circle<TModel, TKey>::circleEq(int x, int y) {
    return (x - myCenter.x())*(x - myCenter.x()) + (y - myCenter.y())*(y - myCenter.y());
}

template<typename TModel, typename TKey>
bool Circle<TModel, TKey>::isMouseInside(TModel mousePos){
    int eq = circleEq(mousePos.x(), mousePos.y());
    return (eq <= ((myDiam/2)*(myDiam/2)));
}

template<typename TModel, typename TKey>
void Circle<TModel, TKey>::moveFig(QPainter &painter, TModel dest) {
    myCenter = dest;
    this->drawFigure(painter);
}

template<typename TModel, typename TKey>
Circle<TModel, TKey>::~Circle(){
}
