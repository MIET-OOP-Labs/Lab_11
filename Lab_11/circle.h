#ifndef CIRCLE_H
#define CIRCLE_H

#include "abstract_figure.h"

template<typename TModel>
class Circle : public AbstractFigure<TModel> {
    const string figName = "Circle";

    TModel myCenter;
    int myDiam;
    QPainter &myPainter;
    int circleEq(int x, int y);
    public:

    Circle(QPainter &painter, TModel center, int diam): myPainter(painter), myCenter(center), myDiam(diam){};

    void drawFigure() override;
    bool isMouseInside(TModel mousePos) override;

    void moveFig(TModel dest) override;

    string getName()override {return figName;};

    ~Circle();
};

#endif // CIRCLE_H
