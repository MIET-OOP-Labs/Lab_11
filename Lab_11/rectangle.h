#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "abstract_figure.h"
#include <list>

using namespace std;

class Rectangle : public AbstractFigure {
	enum paramsIndexes { x_0, y_0, x_1, y_1 };

    const string figName = "Rectangle";
    const int init_paramsNum = 4;

	int init_x_0 = 20;
	int init_y_0 = 20;
	int init_x_1 = 50;
	int init_y_1 = 50;

    public:
		Rectangle();
		void drawFigure(QPainter *painter) override;

        bool isMouseInside(QPoint mousePos) override;

        string getName()override {return figName;};

        void moveFig(int to_x, int to_y) override;

        ~Rectangle();
};

#endif // RECTANGLE_H
