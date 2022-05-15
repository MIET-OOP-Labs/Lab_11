#include "triangle.h"
#include <vector>

Triangle::Triangle() {
    paramsNum = init_paramsNum;

	params.clear();
	params.push_back(init_x_0);
	params.push_back(init_y_0);
	params.push_back(init_x_1);
	params.push_back(init_y_1);
	params.push_back(init_x_2);
	params.push_back(init_y_2);
}

void Triangle::drawFigure(QPainter *painter) {
	painter->setPen(QPen(myColor, myWidth, myPenStyle));
	int x0 = listGetItem(params, x_0);
	int y0 = listGetItem(params, y_0);
	int x1 = listGetItem(params, x_1);
	int y1 = listGetItem(params, y_1);
	int x2 = listGetItem(params, x_2);
	int y2 = listGetItem(params, y_2);

	QPolygon polygon;
	polygon << QPoint(x0, y0) << QPoint(x1, y1) << QPoint(x2, y2);
	painter->drawPolygon(polygon);  // Draw a triangle on a polygonal model
}



bool Triangle::isMouseInside(QPoint mousePos){
    int trian_x0 = listGetItem(params, x_0);
    int trian_y0 = listGetItem(params, y_0);
    int trian_x1 = listGetItem(params, x_1);
    int trian_y1 = listGetItem(params, y_1);
    int trian_x2 = listGetItem(params, x_2);
    int trian_y2 = listGetItem(params, y_2);

    vector<int> vec_0 = {trian_x1 - trian_x0, trian_y1 - trian_y0};
    vector<int> vec_1 = {trian_x2 - trian_x1, trian_y2 - trian_y1};
    vector<int> vec_2 = {trian_x0 - trian_x2, trian_y0 - trian_y2};

    vector<int> mouse_vec_0 = {mousePos.x() - trian_x0, mousePos.y() - trian_y0};
    vector<int> mouse_vec_1 = {mousePos.x() - trian_x1, mousePos.y() - trian_y1};
    vector<int> mouse_vec_2 = {mousePos.x() - trian_x2, mousePos.y() - trian_y2};

    int multip_0 = (vec_0[0] * mouse_vec_0[1] - vec_0[1] *  mouse_vec_0[0]);
    int multip_1 = (vec_1[0] * mouse_vec_1[1] - vec_1[1] *  mouse_vec_1[0]);
    int multip_2 = (vec_2[0] * mouse_vec_2[1] - vec_2[1] *  mouse_vec_2[0]);

    return ((multip_0 >= 0) && (multip_1 >= 0) && (multip_2 >= 0));
}

void Triangle::moveFig(int to_x, int to_y) {
    int x0 = listGetItem(params, x_0);
    int y0 = listGetItem(params, y_0);
    int x1 = listGetItem(params, x_1);
    int y1 = listGetItem(params, y_1);
    int x2 = listGetItem(params, x_2);
    int y2 = listGetItem(params, y_2);

    int dx = to_x - x0;
    int dy = to_y - y0;

    list<int> newTriangle_params = { x0 + dx, y0 + dy, x1 + dx, y1 + dy, x2 + dx, y2 + dy };
    params.assign(newTriangle_params.begin(), newTriangle_params.end());
}

Triangle::~Triangle(){
}
