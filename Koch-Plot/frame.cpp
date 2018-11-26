#include "frame.h"
#include <QtMath>

void Frame::Init(double x, double y, double d, double alpha)
{
    Frame::x=x;
    Frame::y=y;
    Frame::d=d;
    Frame::alpha=alpha;
    etat_scene=false;
}

void Frame::Add_alpha(double alpha)
{
    Frame::alpha=Frame::alpha+alpha;
}

void Frame::Set_d(double d)
{
    Frame::d=d;
}

void Frame::Move()
{
    double x2=Frame::Get_x2();
    double y2=Frame::Get_y2();
    Frame::x=x2;
    Frame::y=y2;

}

double Frame::Get_alpha()
{
    return Frame::alpha;
}

double Frame::Get_d()
{
    return Frame::d;
}

double Frame::Get_x1()
{
    return Frame::x;
}

double Frame::Get_y1()
{
    return Frame::y;
}

double Frame::Get_x2()
{
    return Frame::x+qCos(PI*Frame::alpha/180)*Frame::d;
}

double Frame::Get_y2()
{
    return Frame::y+qSin(PI*Frame::alpha/180)*Frame::d;
}

void Frame::Set_scene(QGraphicsScene *scene)
{
    Frame::scene=scene;
    etat_scene=true;
}

void Frame::Plot_line(QColor color, int sizePen)
{
    qDebug()<< "Frame::Plot_line(QColor color, int sizePen)";
    qDebug()<< "etat_scene=" << etat_scene;

    if(etat_scene)
    {
        double x1,x2,y1,y2;
        x1=Get_x1();
        x2=Get_x2();
        y1=Get_y1();
        y2=Get_y2();

        double dx,dy;
        dy=y2-y1;
        dx=x2-x1;
        double angle=qAtan2(dy,dx);
        double dx1,dy1;
        dx1=qAbs(qCos(angle)*sizePen/2);
        dy1=qAbs(qSin(angle)*sizePen/2);
        double l,ld;
        l=qSqrt((dx*dx+dy*dy));
        ld=qSqrt((dx1*dx1+dy1*dy1));

        QPen Pen(color);
        Pen.setWidth(sizePen);
        //QGraphicsLineItem *line;
        double X1,X2,Y1,Y2;
         if(dx>=0)
         {
             X1=x1+dx1;
             X2=x2-dx1;
         }
         else
         {
              X1=x1-dx1;
              X2=x2+dx1;
         }
         if(dy>=0)
         {
             Y1=y1+dy1;
             Y2=y2-dy1;
         }
         else
         {
              Y1=y1-dy1;
              Y2=y2+dy1;
         }
         if(l>ld)
         {
             scene->addLine(X1,Y1,X2,Y2,Pen);
         }

         //Bout color
         QBrush Brush(color);
         Pen.setWidth(0);

         //Bout X2
         X1=x2-(sizePen/2);
         Y1=y2-(sizePen/2);
         X2=x2+(sizePen/2);
         Y2=y2+(sizePen/2);
         double dX,dY;
         dX=X2-X1;
         dY=Y2-Y1;
         scene->addEllipse(X1,Y1,dX,dY,Pen,Brush);

         //Bout X1
         X1=x1-(sizePen/2);
         Y1=y1-(sizePen/2);
         X2=x1+(sizePen/2);
         Y2=y1+(sizePen/2);
         dX=X2-X1;
         dY=Y2-Y1;
         scene->addEllipse(X1,Y1,dX,dY,Pen,Brush);

    }

}
