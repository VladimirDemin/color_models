#include "check_values.h"

#include <QtCore>
const int maxH_1 = 359;
const int maxS_1 = 255;
const int maxV_1 = 255;

const int maxRGB = 255;

const int maxCMYK = 255;

const int maxL = 100;
const int maxA = 128;
const int maxB = 128;

const int maxH_2 = 360;
const int maxS_2 = 100;
const int maxL_2 = 100;

const int maxX = 95;
const int maxY = 100;
const int maxZ = 109;

Validator::Validator(QObject *parent) :
  QObject(parent)
{
}

bool Validator::checkColorText(QString text, Validator::ColorType colorType)
{
  int size = getSizeByType(colorType);

  QStringList list;
  list = text.split(" ");
  if (list.size()!=size) return false;

  foreach(QString comp, list)
  {
    if (!comp.length())
      return false;
  }

  foreach(QString comp, list)
  {
    bool ok;
    comp.toInt(&ok);
    if (!ok) return false;
  }

  return true;
}

bool Validator::checkValueByType(QString text, Validator::ColorType colorType) {
  switch (colorType)
  {
    case Validator::HSV:
      return checkValueHSV(text);
    case Validator::RGB:
      return checkValueRGB(text);
    case Validator::CMYK:
      return checkValueCMYK(text);
  }
  return false;
}

bool Validator::checkValueHSV(QString text)
{
  QStringList list;
  list = text.split(" ");

  int h = list[0].toInt();
  int s = list[1].toInt();
  int v = list[2].toInt();

  if (h<0 || h>maxH_1) return false;
  if (s<0 || s>maxH_1) return false;
  if (v<0 || v>maxH_1) return false;

  return true;
}

bool Validator::checkValueRGB(QString text)
{
  QStringList list;
  list = text.split(" ");

  int r = list[0].toInt();
  int g = list[1].toInt();
  int b = list[2].toInt();

  if (r<0 || r>maxRGB) return false;
  if (g<0 || g>maxRGB) return false;
  if (b<0 || b>maxRGB) return false;

  return true;
}

bool Validator::checkValueCMYK(QString text)
{
  QStringList list;
  list = text.split(" ");

  int c = list[0].toInt();
  int m = list[1].toInt();
  int y = list[2].toInt();
  int k = list[3].toInt();

  if (c<0 || c>maxCMYK) return false;
  if (m<0 || m>maxCMYK) return false;
  if (y<0 || y>maxCMYK) return false;
  if (k<0 || k>maxCMYK) return false;

  return true;
}



bool Validator::checkValueHSL(QString text)
{
    QStringList list;
    list = text.split(" ");

    int h = list[0].toInt();
    int s = list[1].toInt();
    int l = list[2].toInt();

    if (h<0 || h>maxH_2) return false;
    if (s<0 || s>maxS_2) return false;
    if (l<0 || l>maxL_2) return false;

    return true;
}

bool Validator::checkValueLAB(QString text)
{
    QStringList list;
    list = text.split(" ");

    int l = list[0].toInt();
    int a = list[1].toInt();
    int b = list[2].toInt();

    if (l<0 || l>maxL) return false;
    if (a<0 || a>maxA) return false;
    if (b<0 || b>maxB) return false;

    return true;
}

bool Validator::checkValueXYZ(QString text)
{
    QStringList list;
    list = text.split(" ");

    int x = list[0].toInt();
    int y = list[1].toInt();
    int z = list[2].toInt();

    if (x<0 || x>maxX) return false;
    if (y<0 || y>maxY) return false;
    if (z<0 || z>maxZ) return false;

    return true;
}

bool Validator::checkComponentVal(int val, Validator::ColorType colorType, int group, int hexLen) {
  if (colorType == Validator::HSV)
  {
    switch (group)
    {
    case 0:
      return (val >= 0 && val <= maxH_1);
    case 1:
      return (val >= 0 && val <= maxS_1);
    case 2:
      return (val >= 0 && val <= maxV_1);
    }
  }

  if (colorType == Validator::RGB)
  {
    return (val >= 0 && val <= maxRGB);
  }

  if (colorType == Validator::CMYK)
  {
    switch (group)
    {
    case 0:
      return (val >= 0 && val <= maxCMYK);
    case 1:
      return (val >= 0 && val <= maxCMYK);
    case 2:
      return (val >= 0 && val <= maxCMYK);
    case 3:
      return (val >= 0 && val <= maxCMYK);
    }
  }

  if (colorType == Validator::HSL)
  {
    switch (group)
    {
    case 0:
      return (val >= 0 && val <= maxH_2);
    case 1:
      return (val >= 0 && val <= maxS_2);
    case 2:
      return (val >= 0 && val <= maxL_2);
    }
  }

  if (colorType == Validator::LAB)
  {
    switch (group)
    {
    case 0:
      return (val >= 0 && val <= maxL);
    case 1:
      return (val >= 0 && val <= maxA);
    case 2:
      return (val >= 0 && val <= maxB);
    }
  }

  if (colorType == Validator::XYZ)
  {
    switch (group)
    {
    case 0:
      return (val >= 0 && val <= maxX);
    case 1:
      return (val >= 0 && val <= maxY);
    case 2:
      return (val >= 0 && val <= maxZ);
    }
  }

  return false;
}


void Validator::correctHSV(QColor& color)
{
  int h = color.hue();
  int s = color.saturation();
  int v = color.value();

  h = qMin(maxH_1, qMax(0, h));
  s = qMin(maxS_1, qMax(0, s));
  v = qMin(maxV_1, qMax(0, v));

  color.setHsv(h, s, v);
}

void Validator::correctRGB(QColor& color)
{
  int r = color.red();
  int g = color.green();
  int b = color.blue();

  r = qMin(maxRGB, qMax(0, r));
  g = qMin(maxRGB, qMax(0, g));
  b = qMin(maxRGB, qMax(0, b));

  color.setRgb(r, g, b);
}

void Validator::correctCMYK(QColor& color)
{
  int c = color.cyan();
  int m = color.magenta();
  int y = color.yellow();
  int k = color.black();

  c = qMin(maxCMYK, qMax(0, c));
  m = qMin(maxCMYK, qMax(0, m));
  y = qMin(maxCMYK, qMax(0, y));
  k = qMin(maxCMYK, qMax(0, k));

  color.setCmyk(c, m, y, k);
}

void Validator::correctHSL(QColor &color)
{
    int h = color.hue();
    int s = color.saturation();
    int l = color.lightness();

    h = qMin(maxH_1, qMax(0, h));
    s = qMin(maxS_1, qMax(0, s));
    l = qMin(maxV_1, qMax(0, l));

    color.setHsl(h, s, l);
}

void Validator::correctLAB(QColor &color)
{
    int l = color.lightness();
    int a = color.red();
    int b = color.blue();

    l = qMin(maxL, qMax(0, l));
    a = qMin(maxA, qMax(0, a));
    b = qMin(maxB, qMax(0, b));

    color.setHsl(l, a, b);
}

void Validator::correctXYZ(QColor &color)
{
    int x = color.red();
    int y = color.green();
    int z = color.blue();

    x = qMin(maxX, qMax(0, x));
    y = qMin(maxY, qMax(0, y));
    z = qMin(maxZ, qMax(0, z));

    color.setHsl(x, y, z);
}


QString Validator::correctColorText(QString text)
{
  if (!text.length()) return text;
  return text.trimmed().replace(",", " ").replace(QRegExp("\\s+"), " ");
}

int Validator::getSizeByType(Validator::ColorType colorType)
{
  switch (colorType)
  {
    case Validator::HSV:
      return 3;
    case Validator::RGB:
      return 3;
    case Validator::CMYK:
      return 4;
  case Validator::HSL:
    return 3;
  case Validator::LAB:
    return 3;
  case Validator::XYZ:
    return 3;
    default:
      return 0;
  }
}
