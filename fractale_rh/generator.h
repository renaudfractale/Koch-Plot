#ifndef GENERATOR_H
#define GENERATOR_H
#include "patterne.h"
#include <QtCore>
#include <QtMath>
#include <QDebug>
class Generator
{
public:
    Generator(int nbpas=5);
    void Generation();
    Patterne Get_Patterne();
    void Set_nb_pas(int nbpas);
private:
    Patterne patterne;
    int nb_pas;
    QList <double> Liste_angle;
    void print_list(QList <double>  Liste, QString txt);
};

#endif // GENERATOR_H
