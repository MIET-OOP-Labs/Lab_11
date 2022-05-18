#include "circle.h"

template<typename TModel>
void Circle<TModel>::drawFigure() {
    myPainter.setPen(QPen(AbstractFigure<TModel>::getColor(),
                          AbstractFigure<TModel>::getWidth(),
                          AbstractFigure<TModel>::getStyle()));
    myPainter.drawEllipse(myCenter, myDiam, myDiam);
}

template<typename TModel>
int Circle<TModel>::circleEq(int x, int y) {
    return (x - myCenter.x())*(x - myCenter.x()) + (y - myCenter.y())*(y - myCenter.y());
}

template<typename TModel>
bool Circle<TModel>::isMouseInside(TModel mousePos){
    int eq = circleEq(mousePos.x(), mousePos.y());
    return (eq <= ((myDiam/2)*(myDiam/2)));
}

template<typename TModel>
void Circle<TModel>::moveFig(TModel dest) {
    myCenter = dest;
    this->drawFigure();
}

template<typename TModel>
Circle<TModel>::~Circle(){
}
