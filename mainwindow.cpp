#include  "mainwindow.h"
#include  "ui_mainwindow.h"

#include <QPainter>
#include <QShortcut>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) :
 QMainWindow(parent),
 ui(new Ui::MainWindow)
{
 ui->setupUi (this);
  colorProcessor = new ColorProcessor(ui->hSelector/*, ui->svSelector*/);
  addActions();
  addShortcuts();
  init();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::init()
{
  QApplication::setStyle("fusion");

  mx = 0;
  my = 0;

  mouseDown = false;

  ui->leHSV->setType(Validator::HSV);
  ui->leRGB->setType(Validator::RGB);
  ui->leCMYK->setType(Validator::CMYK);
  ui->leHSL->setType(Validator::HSL);
  ui->leXYZ->setType(Validator::XYZ);
  ui->leLAB->setType(Validator::LAB);

  ui->hSelector->setInitH(0);
}

void MainWindow::addActions()
{
  connect( ui->hSelector, SIGNAL(hueChanged(QColor)), colorProcessor, SLOT(changeHue(QColor)) );
  connect( colorProcessor, SIGNAL(colorChanged(QColor)), ui->colorSample, SLOT(changeColor(QColor)) );
  connect( ui->colorSample, SIGNAL(colorChanged(QColor)), this, SLOT(updateColorText(QColor)) );
   connect( colorProcessor, SIGNAL(colorChanged(QColor)), this, SLOT(updateColorText(QColor)) );

  connect( ui->leHSV,  SIGNAL(textEdited(QString)), this, SLOT(updateColorHSV(QString)) );
  connect( ui->leRGB,  SIGNAL(textEdited(QString)), this, SLOT(updateColorRGB(QString)) );
  connect( ui->leCMYK, SIGNAL(textEdited(QString)), this, SLOT(updateColorCMYK(QString)) );
  connect( ui->leHSL,  SIGNAL(textEdited(QString)), this, SLOT(updateColorHSL(QString)) );
  connect( ui->leXYZ,  SIGNAL(textEdited(QString)), this, SLOT(updateColorXYZ(QString)) );
  connect( ui->leLAB, SIGNAL(textEdited(QString)), this, SLOT(updateColorLAB(QString)) );
}
void MainWindow::addShortcuts()
{
     QFont f_RGB( "Arial", 10, QFont::Bold);
     ui->label_RGB->setFont(f_RGB);
     ui->label_RGB->setText("RGB");

     QFont f_HSV( "Arial", 10, QFont::Bold);
     ui->label_HSV->setFont(f_HSV);
     ui->label_HSV->setText("HSV");

     QFont f_HSL( "Arial", 10, QFont::Bold);
     ui->label_HSL->setFont(f_HSL);
     ui->label_HSL->setText("HSL");

     QFont f_LAB( "Arial", 10, QFont::Bold);
     ui->label_LAB->setFont(f_LAB);
     ui->label_LAB->setText("LAB");

     QFont f_XYZ( "Arial", 10, QFont::Bold);
     ui->label_XYZ->setFont(f_XYZ);
     ui->label_XYZ->setText("XYZ");

     QFont f_CMYK( "Arial", 10, QFont::Bold);
     ui->label_CMYK->setFont(f_CMYK);
     ui->label_CMYK->setText("CMYK");
}

void MainWindow::updateColorHSV(QString text)
{
  editingField = "HSV";
  text = Validator::correctColorText(text);
  ui->leHSV->updateText(text);
  colorProcessor->updateColorHSV(text);
}

void MainWindow::updateColorRGB(QString text)
{
  editingField = "RGB";
  text = Validator::correctColorText(text);
  ui->leRGB->updateText(text);
  colorProcessor->updateColorRGB(text);
}

void MainWindow::updateColorCMYK(QString text)
{
  editingField = "CMYK";
  text = Validator::correctColorText(text);
  ui->leCMYK->updateText(text);
  colorProcessor->updateColorCMYK(text);
}
void MainWindow::updateColorHSL(QString text)
{
  editingField = "HSL";
  text = Validator::correctColorText(text);
  ui->leHSL->updateText(text);
  colorProcessor->updateColorHSL(text);
}

void MainWindow::updateColorXYZ(QString text)
{
  editingField = "XYZ";
  text = Validator::correctColorText(text);
  ui->leXYZ->updateText(text);
  colorProcessor->updateColorXYZ(text);
}

void MainWindow::updateColorLAB(QString text)
{
  editingField = "LAB";
  text = Validator::correctColorText(text);
  ui->leLAB->updateText(text);
  colorProcessor->updateColorLAB(text);
}

void MainWindow::updateColorText(QColor color)
{
  QString HSV, RGB, CMYK, HSL, XYZ, LAB, Hex;

  HSV = colorProcessor->getHSV(color);
  RGB = colorProcessor->getRGB(color);
  CMYK = colorProcessor->getCMYK(color);
  HSL = colorProcessor->getHSL(color);
  XYZ = colorProcessor->getXYZ(color);
  LAB = colorProcessor->getLAB(color);

  setHSV(HSV);
  setRGB(RGB);
  setCMYK(CMYK);
  setHSL(HSL);
  setXYZ(XYZ);
  setLAB(LAB);
}

void MainWindow::setHSV(QString text)
{
  if (editingField == "HSV") return;
  ui->leHSV->setText(text);
}

void MainWindow::setRGB(QString text)
{
  if (editingField == "RGB") return;
  ui->leRGB->setText(text);
}

void MainWindow::setCMYK(QString text)
{
  if (editingField == "CMYK") return;
  ui->leCMYK->setText(text);
}

void MainWindow::setHSL(QString text)
{
    if (editingField == "HSL") return;
    ui->leHSL->setText(text);
}

void MainWindow::setLAB(QString text)
{
    if (editingField == "LAB") return;
    ui->leLAB->setText(text);
}

void MainWindow::setXYZ(QString text)
{
    if (editingField == "XYZ") return;
    ui->leXYZ->setText(text);
}



QString MainWindow::getHSV()
{
  return ui->leHSV->text();
}

QString MainWindow::getRGB()
{
  return ui->leRGB->text();
}

QString MainWindow::getCMYK()
{
    return ui->leCMYK->text();
}

QString MainWindow::getHSL()
{
    return ui->leHSL->text();
}

QString MainWindow::getLAB()
{
    return ui->leLAB->text();
}

QString MainWindow::getXYZ()
{
    return ui->leXYZ->text();
}




