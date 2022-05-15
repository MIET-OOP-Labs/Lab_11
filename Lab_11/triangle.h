#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "abstract_figure.h"

class Triangle : public AbstractFigure {
	enum paramsIndexes { x_0, y_0, x_1, y_1, x_2, y_2 };

    const string figName = "Triangle";
    const int init_paramsNum = 6;

	int init_x_0 = 110;
	int init_y_0 = 100;
	int init_x_1 = 150;
	int init_y_1 = 50;
	int init_x_2 = 200;
    int init_y_2 = 100;

    public:

        Triangle();

        void drawFigure(QPainter *painter) override;

        bool isMouseInside(QPoint mousePos) override;

        string getName()override {return figName;};

        void moveFig(int to_x, int to_y) override;

        ~Triangle();
};

#endif // TRIANGLE_H
