#ifndef PATTERNE_H
#define PATTERNE_H
#include <QCoreApplication>
#include "frame.h"
#include <QtMath>

class Patterne
{
public:
    QList<double> ListX;
    QList<double> ListY;


    double x_debut;
    double y_debut;
    double x_fin;
    double y_fin;

    double x_min;
    double y_min;
    double x_max;
    double y_max;

    bool Ok=false;
    void Calcul_Patterne();
    void Add(double Rotation, double Translation);
    void Clear();
    int Get_lenght();
    double Get_Element(int no);


private:

    QList<double> ListPatterne;



};

#endif // PATTERNE_H
