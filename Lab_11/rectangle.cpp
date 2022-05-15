#include "rectangle.h"

Rectangle::Rectangle() {
    paramsNum = init_paramsNum;

	params.clear();
	params.push_back(init_x_0);
	params.push_back(init_y_0);
	params.push_back(init_x_1);
	params.push_back(init_y_1);
}

void Rectangle::drawFigure(QPainter *painter) {
	painter->setPen(QPen(myColor, myWidth, myPenStyle));
	int x = listGetItem(params, x_0);
	int y = listGetItem(params, y_0);
	int width = listGetItem(params, x_1) - x;
	int height = listGetItem(params, y_1) - y;
	painter->drawRect(x, y, width, height);
}

bool Rectangle::isMouseInside(QPoint mousePos){
    int x0 = listGetItem(params, x_0);
    int y0 = listGetItem(params, y_0);
    int x1 = listGetItem(params, x_1);
    int y1 = listGetItem(params, y_1);
    return ((mousePos.x() >= x0) && (mousePos.x() <= x1) && (mousePos.y() >= y0) && (mousePos.y() <= y1));
}

void Rectangle::moveFig(int to_x, int to_y) {
    int x0 = listGetItem(params, x_0);
    int y0 = listGetItem(params, y_0);
    int x1 = listGetItem(params, x_1);
    int y1 = listGetItem(params, y_1);

    int dx = to_x - x0;
    int dy = to_y - y0;

    list<int> newRectangle_params = { x0 + dx, y0 + dy, x1 + dx, y1 + dy };
    params.assign(newRectangle_params.begin(), newRectangle_params.end());
}

Rectangle::~Rectangle(){
}
