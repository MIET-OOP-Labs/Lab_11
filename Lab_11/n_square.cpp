#include "n_square.h"

template<typename TModel>
n_square<TModel>::n_square(QPainter &painter, const vector<TModel> & vertexes):
    myPainter(painter), myVertexes(vertexes){
}

template<typename TModel>
void n_square<TModel>::drawFigure(){
    myPainter.setPen(QPen(AbstractFigure<TModel>::getColor(),
                          AbstractFigure<TModel>::getWidth(),
                          AbstractFigure<TModel>::getStyle()));
    QPolygon polygon;
    for (const auto &v: myVertexes) {
        polygon << v;
    }
    myPainter.drawPolygon(polygon);  // Draw a triangle on a polygonal model

}

template<typename TModel>
bool n_square<TModel>::isMouseInside(TModel mousePos){

    vector<TModel> sides_vec;
    vector<TModel> to_mouse_vec;

    for (typename vector<TModel>::iterator it = myVertexes.begin();
         it != myVertexes.end(); ++it) {

        typename vector<TModel>::iterator it_copy;
        if(it == (myVertexes.end() - 1)){
            it_copy = myVertexes.begin();
        } else  {
            it_copy = it;
        }
        sides_vec.push_back(*(++it_copy) - *it);
        to_mouse_vec.push_back(mousePos - *it);
    }

    typename vector<TModel>::iterator sides_it = sides_vec.begin();
    for (typename vector<TModel>::iterator to_mouse_it = to_mouse_vec.begin();
         to_mouse_it != to_mouse_vec.end(); ++to_mouse_it) {

        if ((sides_it.x() * to_mouse_it.y() - sides_it.y() * to_mouse_it.x()) < 0) {
            return false;
        }
        return true;
    }
}

template<typename TModel>
void n_square<TModel>::moveFig(TModel dest) {
    for (const auto &v: myVertexes) {
        v += dest;
    }
    this->drawFigure();
}

template<typename TModel>
n_square<TModel>::~n_square(){
}
