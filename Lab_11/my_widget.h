#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "abstract_figure.h"
#include <QMouseEvent>
#include <QMenu>

#define FIG_NUM 5
#define CURR_QPOINT_TYPE QPoint

class MyWidget : public QWidget {

    string figInfo = "";
    QPoint figInfoPos;
    std::array<std::unique_ptr<AbstractFigure<CURR_QPOINT_TYPE>>, FIG_NUM> figArray;
    AbstractFigure<CURR_QPOINT_TYPE> * hoveredFig = nullptr;

    QMenu menu;
    QAction *deleteAction;

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

  //public slots:


};

#endif // MYWIDGET_H
