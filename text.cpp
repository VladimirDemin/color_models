#include "text.h"

#include <QDebug>

#include "check_values.h"

ColorText::ColorText(QWidget *parent) : QLineEdit(parent)
{
  colorType = Validator::HSV;
  separator = " ";
}

void ColorText::setType(Validator::ColorType colorType)
{
  this->colorType = colorType;
}


void ColorText::updateText(QString text)
{
  int pos = cursorPosition();
  setText(text);
  setCursorPosition(pos);
}




