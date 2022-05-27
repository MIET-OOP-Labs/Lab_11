#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QPainter>

using namespace std;

template<typename TModel, typename TKey>
class AbstractFigure {
    private:
		QColor myColor = Qt::red;
		int myWidth = 1;
		Qt::PenStyle myPenStyle = Qt::SolidLine;
    public:

        virtual void setColor(const QColor newColor) {myColor = newColor;};
        virtual void setWidth(const int newWidth) {myWidth = newWidth;};
        virtual void setStyle(const Qt::PenStyle newPenStyle) {myPenStyle = newPenStyle;};

        virtual QColor getColor() {return myColor;};
        virtual int getWidth() {return myWidth;};
        virtual Qt::PenStyle getStyle() {return myPenStyle;};


        virtual void drawFigure(QPainter &painter) = 0;
        virtual void moveFig(QPainter &painter,TModel dest) = 0;
        virtual bool isMouseInside(TModel mousePos) = 0;
        virtual string getName() = 0;

        virtual ~AbstractFigure(){};
};

#endif // ABSTRACTFIGURE_H
