#include "abstract_figure.h"
#include "abstract_figure.cpp"

#include "circle.h"
#include "circle.cpp"

#include "n_square.h"
#include "n_square.cpp"

template  class AbstractFigure<QPoint, QPolygon>;
template  class AbstractFigure<QPointF, QPolygonF>;

template  class Circle<QPoint, QPolygon>;
template  class Circle<QPointF, QPolygonF>;

template  class n_square<QPoint, QPolygon>;
template  class n_square<QPointF, QPolygonF>;
