#include "n_square.h"
QColor foo;

template<typename TModel, typename TKey>
void n_square<TModel, TKey>::drawFigure(QPainter &painter){
    painter.setPen(QPen(this->getColor(),
                          this->getWidth(),
                          this->getStyle()));
    TKey polygon;
    for (const auto &v: myVertexes) {
        polygon << v;
    }
    painter.drawPolygon(polygon);  // Draw a triangle on a polygonal model

}

template<typename TModel, typename TKey>
bool n_square<TModel, TKey>::isMouseInside(TModel mousePos){

    vector<TModel> sides_vec;
    vector<TModel> to_mouse_vec;

    for (typename vector<TModel>::iterator it = myVertexes.begin();
         it != myVertexes.end(); ++it) {

        typename vector<TModel>::iterator it_copy;
        if(it == (myVertexes.end() - 1)){
            it_copy = myVertexes.begin() - 1;
        } else  {
            it_copy = it;
        }
        sides_vec.push_back(*(++it_copy) - *it);
        to_mouse_vec.push_back(mousePos - *it);
    }

    typename vector<TModel>::iterator sides_it = sides_vec.begin();
    for (int i = 0; i <  sides_vec.size(); i++) {
        if ((sides_vec[i].x() * to_mouse_vec[i].y() - sides_vec[i].y() * to_mouse_vec[i].x()) < 0) {
            return false;
        }
    }
    return true;
}

template<typename TModel, typename TKey>
void n_square<TModel, TKey>::moveFig(QPainter &painter, TModel dest) {
    TModel d_x_y = dest - myVertexes[0];
    for (auto &v: myVertexes) {
        v += d_x_y;
    }
    this->drawFigure(painter);
}

template<typename TModel, typename TKey>
n_square<TModel, TKey>::~n_square(){
}
