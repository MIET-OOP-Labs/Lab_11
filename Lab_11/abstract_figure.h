#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QPainter>

using namespace std;

template<typename TModel>
class AbstractFigure {
    private:
        const string figName = "Abstract";
		QColor myColor = Qt::red;
		int myWidth = 1;
		Qt::PenStyle myPenStyle = Qt::SolidLine;
    public:
        AbstractFigure();

        void setColor(const QColor newColor) {myColor = newColor;};
        void setWidth(const int newWidth) {myWidth = newWidth;};
        void setStyle(const Qt::PenStyle newPenStyle) {myPenStyle = newPenStyle;};

		QColor getColor() {return myColor;};
		int getWidth() {return myWidth;};
		Qt::PenStyle getStyle() {return myPenStyle;};


        virtual void drawFigure() = 0;
        virtual void moveFig(TModel dest) = 0;
        virtual bool isMouseInside(TModel mousePos) = 0;
        virtual string getName() {return figName;};

        virtual ~AbstractFigure();
};

#endif // ABSTRACTFIGURE_H
