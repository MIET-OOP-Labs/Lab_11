#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "abstract_figure.h"
#include <QMouseEvent>
#include <QMenu>

using curr_QPoint = QPoint;
using curr_QPolygon = QPolygon;
using unique_figure = std::unique_ptr<AbstractFigure<QPoint, QPolygon>>;

class MyWidget : public QWidget {

    Q_OBJECT

    string figInfo = "";
    QPoint figInfoPos;
    vector <unique_figure> figArray;
    int hoveredFigNum = -1;

    QAction *deleteAction;
    QMenu *menu;

  protected:
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


public slots:
    void deleteFig();

  public:
   explicit MyWidget(QWidget * parent);
      ~MyWidget();


};

#endif // MYWIDGET_H
