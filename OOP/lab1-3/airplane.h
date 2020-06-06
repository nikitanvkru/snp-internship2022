#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <QMainWindow>
#include <QPainter>
#include <QApplication>
#include <dialog.h>
#include <QFontDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Airplane; }
QT_END_NAMESPACE

class Airplane : public QMainWindow
{
    Q_OBJECT

public:
    Airplane(QWidget *parent = nullptr);
    ~Airplane();

private slots:
    void on_Pusk_clicked();

    void on_Pusk_pressed();

    void on_Pusk_released();

    void on_Tuch_clicked();

    void on_verticalSlider_sliderMoved(int position);

    void on_lcdNumber_overflow();

    void on_Chassi_clicked();

    void on_svet_clicked();

private:
    Ui::Airplane *ui;
    Dialog *window;
    void paintEvent(QPaintEvent *event);
};
#endif // AIRPLANE_H
