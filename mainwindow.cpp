#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setRange(0, 255);
    ui->horizontalScrollBar->setRange(0, 255);
    ui->spinBox_2->setRange(0, 255);
    ui->horizontalScrollBar_2->setRange(0, 255);
    ui->spinBox_3->setRange(0, 255);
    ui->horizontalScrollBar_3->setRange(0, 255);
        QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalScrollBar, SLOT(setValue(int)));
        QObject::connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
        QObject::connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalScrollBar_2, SLOT(setValue(int)));
        QObject::connect(ui->horizontalScrollBar_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
        QObject::connect(ui->spinBox_3, SIGNAL(valueChanged(int)), ui->horizontalScrollBar_3, SLOT(setValue(int)));
        QObject::connect(ui->horizontalScrollBar_3, SIGNAL(valueChanged(int)), ui->spinBox_3, SLOT(setValue(int)));
//    QWidget *window = new QWidget;
//    QSpinBox *spinBox = new QSpinBox;
//    QSlider *sliderH = new QSlider(Qt::Horizontal);
//    spinBox->setRange(0, 255);
//    sliderH->setRange(0, 255);
//    QObject::connect(spinBox, SIGNAL(valueChanged(int)), sliderH, SLOT(setValue(int)));
//    QObject::connect(sliderH, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
//    spinBox->setValue(50);
//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(spinBox);
//    layout->addWidget(sliderH);
//    window->setLayout(layout);
//    window->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
     pen = QPen(pen_color,width);
//     pen.setDashPattern({ 4, 4 , 4, 4 });
     painter.setPen(pen);
     painter.setBrush(brush_color);
     painter.drawRect(QRect(350, 100, 400, 400));


}

void MainWindow::on_pushButton_clicked()
{
    brush_color = QColorDialog::getColor(Qt::green, this);
        repaint();
}
