#ifndef CIRCLE_H
#define CIRCLE_H

#include "abstract_figure.h"

template<typename TModel, typename TKey>
class Circle : public AbstractFigure<TModel, TKey> {
    const string figName = "Circle";

    TModel myCenter;
    int myDiam;
    int circleEq(int x, int y);

    public:

    Circle(const TModel center, const int diam):myCenter(center), myDiam(diam){};

    void drawFigure(QPainter &painter) override;
    bool isMouseInside(TModel mousePos) override;

    void moveFig(QPainter &painter, TModel dest) override;

    string getName()override {return figName;};

    ~Circle();
};

#endif // CIRCLE_H
