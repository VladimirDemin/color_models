#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenu>
#include<QString>
#include <QtWidgets>
#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QColorDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QColor brush_color=Qt::white;
    QPen pen;
    QColor pen_color=Qt::black;
    int width=1;

protected:
    void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
