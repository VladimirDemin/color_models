#ifndef COLORSAMPLE_H
#define COLORSAMPLE_H

#include <QWidget>
#include <QMouseEvent>
#include <QColorDialog>
#include "cursor.h"


class CurrentColor: public QWidget
{
  Q_OBJECT

private:
  QColor color_border;
  int h,s,v;


public:
  explicit CurrentColor(QWidget *parent = 0);

  void reupdateColor_1();
  void Choose_Color();

  void setH(int h);
  void setH(QColor color);
  void setInitH(int h);

  void reupdateColor_2();

    const int maxH=360;
    const int maxSV=255;
    const int border=2;
    const int borderRadius=10;
    QColor color;


signals:
  void colorChanged(QColor color);
  void hueChanged(QColor);

public slots:
  void changeColor(QColor color);

protected:
  void paintEvent(QPaintEvent *event);
  void enterEvent(QEvent* e);
  void leaveEvent(QEvent *e);

    int pointerX;
    int pointerY;
private:
  void drawBorder(QPainter& p);
void updateColor();
};

#endif // COLORSAMPLE_H
