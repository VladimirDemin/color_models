#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QObject>
#include <QColor>

#include "mainwindow.h"


class Validator : public QObject
{
  Q_OBJECT

public:
    enum ColorType
    {
      HSV, RGB, CMYK, Hex, HSL, XYZ, LAB
    };
  explicit Validator(QObject *parent = 0);

  static bool checkColorText(QString text, ColorType colorType=HSV);

  static bool checkValueHSV(QString text);
  static bool checkValueRGB(QString text);
  static bool checkValueCMYK(QString text);
  static bool checkValueHSL(QString text);
  static bool checkValueLAB(QString text);
  static bool checkValueXYZ(QString text);

  static void correctHSV(QColor& color);
  static void correctRGB(QColor& color);
  static void correctCMYK(QColor& color);
  static void correctHSL(QColor& color);
  static void correctLAB(QColor& color);
  static void correctXYZ(QColor& color);

  static QString correctColorText(QString text);

  static bool checkComponentVal(int val, ColorType colorType=HSV, int group=0, int hexLen=0);
  static bool checkValueByType(QString text, ColorType colorType=HSV);


private:
  static int getSizeByType(ColorType colorType);

signals:

public slots:

};

#endif // VALIDATOR_H
