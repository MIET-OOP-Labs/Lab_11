#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "abstract_figure.h"
#include <QMouseEvent>
#include <QMenu>

class MyWidget : public QWidget {

    string figInfo = "";
    QPoint figInfoPos;

    //std::unique_ptr<AbstractFigure> figArray[FIG_NUM];
    vector<std::unique_ptr<AbstractFigure>> figArray;

    AbstractFigure * hoveredFig = nullptr;

    QMenu menu;
    QAction *deleteAction;

  protected:
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
  public:
    MyWidget(QWidget * parent = 0);
      ~MyWidget();

  //public slots:


};

#endif // MYWIDGET_H
