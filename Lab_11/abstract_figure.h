#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QPainter>
#include <list>
#include <QPoint>

using namespace std;

class AbstractFigure {
	protected:
        list<int> params = {};

        int paramsNum = 0;

        const string figName = "Abstract";


		QColor myColor = Qt::red;
		int myWidth = 1;
		Qt::PenStyle myPenStyle = Qt::SolidLine;
		int listGetItem(list<int> _list, int index);

	public:
		AbstractFigure();
        virtual void drawFigure(QPainter *painter) = 0;

		void setColor(QColor newColor) {myColor = newColor;};
		void setWidth(int newWidth) {myWidth = newWidth;};
		void setStyle(Qt::PenStyle newPenStyle) {myPenStyle = newPenStyle;};

		QColor getColor() {return myColor;};
		int getWidth() {return myWidth;};
		Qt::PenStyle getStyle() {return myPenStyle;};

		void setParams(list<int> newParams);

        virtual void moveFig(int to_x, int to_y) = 0;

        virtual bool isMouseInside(QPoint mousePos){return false;};

        virtual string getName() {return figName;};

        virtual ~AbstractFigure();
};

#endif // ABSTRACTFIGURE_H
