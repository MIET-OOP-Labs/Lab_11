#include "circle.h"

Circle::Circle() {
    paramsNum = init_paramsNum;
	params.clear();
	params.push_back(init_x_0);
	params.push_back(init_y_0);
	params.push_back(init_diam);
}

void Circle::drawFigure(QPainter *painter) {
	painter->setPen(QPen(myColor, myWidth, myPenStyle));
	int x = listGetItem(params, x_0);
	int y = listGetItem(params, y_0);
	int diam = listGetItem(params, diameter);
    painter->drawEllipse(x - diam/2, y - diam/2, diam, diam);
}

int Circle::circleEq(int x, int y) {
    int center_x = listGetItem(params, x_0);
    int center_y = listGetItem(params, y_0);
    return (x - center_x)*(x - center_x) + (y - center_y)*(y - center_y);
}

bool Circle::isMouseInside(QPoint mousePos){
    int diam = listGetItem(params, diameter);
    int eq = circleEq(mousePos.x(), mousePos.y());
    return (eq <= ((diam/2)*(diam/2)));
}

void Circle::moveFig(int to_x, int to_y) {
    int diam = listGetItem(params, diameter);
    list<int> moveCircle_params = { to_x, to_y, diam };
    params.assign(moveCircle_params.begin(), moveCircle_params.end());
}

Circle::~Circle(){
}
