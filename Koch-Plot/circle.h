#ifndef CIRCLE_H
#define CIRCLE_H
#include "frame.h"
#include <QtMath>

class Circle
{
public:
    void Init(double size,int nbface);
    Frame Get_frame(int no);
    int Get_nbface();
    int Get_size();

    void Set_nbface(int nb_face);
    void Set_size(int Size);

    void Calcul();
private:
    int nbface;
    int size;
    double r;
    double alpha;
    Frame Liste[20];
    bool Ok=false;
};

#endif // CIRCLE_H
