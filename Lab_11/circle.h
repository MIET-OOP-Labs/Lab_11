#ifndef CIRCLE_H
#define CIRCLE_H

#include "abstract_figure.h"

class Circle : public AbstractFigure {
	enum paramsIndexes { x_0, y_0, diameter };
	paramsIndexes myParams = x_0;

    const string figName = "Circle";


    const int init_paramsNum = 3;
    int init_x_0 = 100;
    int init_y_0 = 200;
	int init_diam = 60;

    int circleEq(int x, int y);
    public:

		Circle();

		void drawFigure(QPainter *painter) override;
        bool isMouseInside(QPoint mousePos) override;

        void moveFig(int to_x, int to_y) override;

        string getName()override {return figName;};

        ~Circle();
};

#endif // CIRCLE_H
