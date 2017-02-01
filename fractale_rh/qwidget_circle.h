#ifndef QWIDGET_CIRCLE_H
#define QWIDGET_CIRCLE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QtMath>
#include <QDebug>


#include "circle.h"


class QWidget_Circle: public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_Circle(QWidget *parent = 0);
    int Get_size();
    int Get_Nbface();
    Circle Get_Circle();


    void Set_nbface(int nb_face);
    void Set_size(int Size);
private:
    QComboBox *ComboBox_Nbface;
    QSpinBox *SpinBox_Nbface;

    QComboBox *ComboBox_size;
    QSpinBox *SpinBox_size;

    QLabel *Label_Nbface;
    QLabel *Label_size;

    QGridLayout *layout;

    Circle circle;
signals:
    void value_changing();
public slots:
   void Update_Circle();
};

#endif // QWIDGET_CIRCLE_H
