#ifndef FRAME_H
#define FRAME_H
#include <QString>
#include <QGraphicsView>
#include <QtMath>
#include <QDebug>
#define PI 3.14159265358979323846

class Frame
{
public:
    void Init(double x,double y,double d,double alpha);
    double Get_x1();
    double Get_y1();
    double Get_x2();
    double Get_y2();
    double Get_d();
    double Get_alpha();
    void Set_d(double d);
    void Add_alpha(double alpha);
    void Move();
    void Set_scene(QGraphicsScene *scene);
    void Plot_line(QColor color,int sizePen);
   /* Qstring print_x1();
    Qstring print_y1();
    Qstring print_s();
    Qstring print_angle();*/
private:
    double x;
    double y;
    double d;
    double alpha;
    QGraphicsScene *scene;
    bool etat_scene;
};

#endif // FRAME_H
