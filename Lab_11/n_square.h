#ifndef N_SQUARE_H
#define N_SQUARE_H

#include "abstract_figure.h"
#include <vector>

using namespace std;

template<typename TModel>
class n_square: public AbstractFigure<TModel> {

    const string figName = "Rectangle";
    QPainter &myPainter;
    vector<TModel> myVertexes;
public:
    n_square(QPainter &painter, const vector<TModel> & vertexes);

    void drawFigure()override;
    bool isMouseInside(TModel mousePos) override;
    string getName()override {return figName;};
    void moveFig(TModel dest) override;

    ~n_square();
};

#endif // N_SQUARE_H
