#ifndef COLORPROCESSOR_H
#define COLORPROCESSOR_H

#include <QtCore>
#include <QColor>

#include <QObject>
#include <QClipboard>

#include "palette.h"
#include "cursor.h"

class ColorProcessor :  public ColorWidget
{
  Q_OBJECT

public:
  explicit ColorProcessor(HSelector* hSelector, QWidget* parent=0);

  QString getHSV(QColor color);
  QString getRGB(QColor color);
  QString getCMYK(QColor color);

  QString getHex(QColor color);

  QString getHSL(QColor color);
  QString getLAB(QColor color);
  QString getXYZ(QColor color);

  QColor getColorHSV(QString HSV_Text);
  QColor getColorRGB(QString RGB_Text);
  QColor getColorCMYK(QString CMYK_Text);

  QColor getColorHex(QString Hex_Text);

  QColor getColorHSL(QString HSV_Text);
  QColor getColorLAB(QString RGB_Text);
  QColor getColorXYZ(QString CMYK_Text);

  void updateColorHSV(QString HSV);
  void updateColorRGB(QString RGB);
  void updateColorCMYK(QString CMYK);

  void updateColorHex(QString Hex);

  void updateColorHSL(QString HSV);
  void updateColorLAB(QString RGB);
  void updateColorXYZ(QString CMYK);

  void updateColor(QColor color);
  void updateColor();

  void setS(QColor color);
  void setV(QColor color);
  void setSV(int s, int v);

  void reupdateColor();

signals:
  void updateFinished();
  void colorChanged(QColor);
  void saturationChanged(QColor);
  void valueChanged(QColor);

public slots:
  void changeHue(QColor color);

private:
  HSelector* hSelector;
  QClipboard* clip;

};

#endif // COLORPROCESSOR_H
