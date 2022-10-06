#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>

#include <QLineEdit>

#include "converting_color.h"

#include  "check_values.h"


namespace Ui {
class MainWindow;
}

class MainController;

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
  QSignalMapper *mapper;

  Ui::MainWindow *ui;

  MainController *mainController;

  ColorProcessor *colorProcessor;

  QString editingField;

  bool mouseDown;
  bool mouseMoved;
  int mx, my;


public:

  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void setHSV(QString text);
  void setRGB(QString text);
  void setCMYK(QString text);
  void setHSL(QString text);
  void setLAB(QString text);
  void setXYZ(QString text);

  QString getHSV();
  QString getRGB();
  QString getCMYK();
  QString getHSL();
  QString getLAB();
  QString getXYZ();


private:
  void addActions();
  void addShortcuts();
  void init();



public slots:
  void updateColorHSV(QString HSV);
  void updateColorRGB(QString RGB);
  void updateColorCMYK(QString CMYK);
  void updateColorHSL(QString HSL);
  void updateColorXYZ(QString XYZ);
  void updateColorLAB(QString LAB);

private slots:

  void updateColorText(QColor color);

};

#endif // MAINWINDOW_H
