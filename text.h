#ifndef COLORTEXT_H
#define COLORTEXT_H

#include <QLineEdit>
#include <QKeyEvent>

#include "mainwindow.h"

class ColorText : public QLineEdit
{
  Q_OBJECT

private:
  Validator::ColorType colorType;
  QString separator;
  int len;

public:
  explicit ColorText(QWidget *parent = 0);

  void setType(Validator::ColorType colorType);
  void updateText(QString text);

signals:
  void focusNextField();
  void focusPrevField();


public slots:

protected:


};

#endif // COLORTEXT_H
