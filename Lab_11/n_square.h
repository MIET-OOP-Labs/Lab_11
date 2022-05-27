#ifndef N_SQUARE_H
#define N_SQUARE_H

#include "abstract_figure.h"
#include <vector>

using namespace std;

template<typename TModel, typename TKey>
class n_square: public AbstractFigure<TModel, TKey> {

    const string figName = "N_square";
    vector<TModel> myVertexes;
public:
    n_square(const vector<TModel> & vertexes): myVertexes(vertexes){};

    void drawFigure(QPainter &painter)override;
    bool isMouseInside(TModel mousePos) override;
    string getName()override {QString returnStr = QString("%1-square").arg(myVertexes.size()); return returnStr.toStdString();};
    void moveFig(QPainter &painter, TModel dest) override;

    ~n_square();
};

#endif // N_SQUARE_H
