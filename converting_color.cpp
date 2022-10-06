#include "converting_color.h"

#include <QApplication>

#include "check_values.h"

ColorProcessor::ColorProcessor(HSelector *hSelector, QWidget* parent) : ColorWidget(parent)
{
  this->hSelector = hSelector;
  clip = QApplication::clipboard();
}

QString ColorProcessor::getHSV(QColor color)
{
  QString res;
  Validator::correctHSV(color);

  int h = color.hue();
  int s = color.saturation();
  int v = color.value();

  res = QString("%1 %2 %3").arg(h).arg(s).arg(v);
  return res;
}

QString ColorProcessor::getRGB(QColor color)
{
  QString res;

  Validator::correctRGB(color);

  int r = color.red();
  int g = color.green();
  int b = color.blue();

  res = QString("%1 %2 %3").arg(r).arg(g).arg(b);
  return res;
}

QString ColorProcessor::getCMYK(QColor color)
{
  QString res;
  Validator::correctCMYK(color);

  int c = color.cyan();
  int m = color.magenta();
  int y = color.yellow();
  int k = color.black();

  res = QString("%1 %2 %3 %4").arg(c).arg(m).arg(y).arg(k);
  return res;
}

QString ColorProcessor::getHSL(QColor color)
{
    QString res;
    Validator::correctHSL(color);

    int h = color.hue();
    int s = color.saturation();
    int l = color.lightness();

    res = QString("%1 %2 %3").arg(h).arg(s).arg(l);
    return res;
}

QString ColorProcessor::getLAB(QColor color)
{
    QString res;
    Validator::correctLAB(color);

    int l = color.lightness();
    int a = color.red();
    int b = color.blue();

    res = QString("%1 %2 %3").arg(l).arg(a).arg(b);
    return res;
}

QString ColorProcessor::getXYZ(QColor color)
{
    QString res;
    Validator::correctHSV(color);

    int x = color.red();
    int y = color.green();
    int z = color.blue();

    res = QString("%1 %2 %3").arg(x).arg(y).arg(z);
    return res;
}

QColor ColorProcessor::getColorHSV(QString HSV_Text)
{
  QStringList list;
  QColor color;

  list = HSV_Text.split(" ");
  int h = list[0].toInt();
  int s = list[1].toInt();
  int v = list[2].toInt();

  color.setHsv(h, s, v);

  return color;
}

QColor ColorProcessor::getColorRGB(QString RGB_Text)
{
  QStringList list;
  QColor color;

  list = RGB_Text.split(" ");
  int r = list[0].toInt();
  int g = list[1].toInt();
  int b = list[2].toInt();

  color.setRgb(r, g, b);

  return color;
}

QColor ColorProcessor::getColorCMYK(QString CMYK_Text)
{
  QStringList list;
  QColor color;

  list = CMYK_Text.split(" ");
  int c = list[0].toInt();
  int m = list[1].toInt();
  int y = list[2].toInt();
  int k = list[3].toInt();

  color.setCmyk(c, m, y, k);

  return color;
}

QColor ColorProcessor::getColorHSL(QString HSL_Text)
{
    QStringList list;
    QColor color;

    list = HSL_Text.split(" ");
    int h = list[0].toInt();
    int s = list[1].toInt();
    int l = list[2].toInt();

    color.setHsv(h, s, l);

    return color;
}

QColor ColorProcessor::getColorLAB(QString LAB_Text)
{
    QStringList list;
    QColor color;

    list = LAB_Text.split(" ");
    int l = list[0].toInt();
    int a = list[1].toInt();
    int b = list[2].toInt();

    color.setHsv(l, a, b);

    return color;
}

QColor ColorProcessor::getColorXYZ(QString XYZ_Text)
{
    QStringList list;
    QColor color;

    list = XYZ_Text.split(" ");
    int x = list[0].toInt();
    int y = list[1].toInt();
    int z = list[2].toInt();

    color.setHsv(x, y, z);

    return color;
}

void ColorProcessor::updateColor()
{
  s = pointerX - border;
  v = maxSV - (pointerY - border);

  s = qMax(0, s);             // s = qMin( maxSV, qMax(0, s) );
  s = qMin(maxSV, s);

  v = qMax(0, v);
  v = qMin(maxSV, v);

  color.setHsv(h, s, v);

  emit colorChanged(color);
  emit saturationChanged(color);
  emit valueChanged(color);
}

void ColorProcessor::reupdateColor()
{
  emit saturationChanged(color);
  emit valueChanged(color);
}

void ColorProcessor::changeHue(QColor color)
{
  selectorDrawn = false;

  h = color.hue();

  QColor newColor;
  newColor.setHsv(h, s, v);
  emit colorChanged(newColor);

  update();
}

void ColorProcessor::setS(QColor color)
{
  s = color.saturation();

  update();

  updateColor();
}

void ColorProcessor::setV(QColor color)
{
  v = color.value();

  update();

  updateColor();
}

void ColorProcessor::setSV(int s, int v)
{
  this->s = s;
  this->v = v;

  update();

  updateColor();
}
void ColorProcessor::updateColorHSV(QString HSV_Text)
{
  if ( !Validator::checkColorText(HSV_Text, Validator::HSV) ) return;
  if ( !Validator::checkValueHSV(HSV_Text) ) return;

  QColor color = getColorHSV(HSV_Text);
  updateColor(color);
}

void ColorProcessor::updateColorRGB(QString RGB_Text)
{
  if ( !Validator::checkColorText(RGB_Text, Validator::RGB) ) return;
  if ( !Validator::checkValueRGB(RGB_Text) ) return;

  QColor color = getColorRGB(RGB_Text);
  updateColor(color);
}

void ColorProcessor::updateColorCMYK(QString CMYK_Text)
{
  if ( !Validator::checkColorText(CMYK_Text, Validator::CMYK) ) return;
  if ( !Validator::checkValueCMYK(CMYK_Text) ) return;

  QColor color = getColorCMYK(CMYK_Text);
  updateColor(color);
}


void ColorProcessor::updateColorHSL(QString HSL_Text)
{
    if ( !Validator::checkColorText(HSL_Text, Validator::HSL) ) return;
    if ( !Validator::checkValueHSV(HSL_Text) ) return;

    QColor color = getColorHSL(HSL_Text);
    updateColor(color);
}

void ColorProcessor::updateColorLAB(QString LAB_Text)
{
    if ( !Validator::checkColorText(LAB_Text, Validator::LAB) ) return;
    if ( !Validator::checkValueLAB(LAB_Text) ) return;

    QColor color = getColorLAB(LAB_Text);
    updateColor(color);
}

void ColorProcessor::updateColorXYZ(QString XYZ_Text)
{
    if ( !Validator::checkColorText(XYZ_Text, Validator::XYZ) ) return;
    if ( !Validator::checkValueXYZ(XYZ_Text) ) return;

    QColor color = getColorXYZ(XYZ_Text);
    updateColor(color);
}

void ColorProcessor::updateColor(QColor color)
{
  int h = color.hue();
  int s = color.saturation();
  int v = color.value();

  hSelector->setH(h);
  setSV(s, v);

  emit updateFinished();
}
