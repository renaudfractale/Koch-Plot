#include "circle.h"

void Circle::Init(double size,int nbface)
{
    Circle::size=size;
    Circle::nbface=nbface;
    Calcul();
}

void Circle::Calcul()
{
    if(nbface>=3 && nbface<=18)
    {
       Circle::Ok=true;
       Circle::r=size;
       Circle::alpha=(2*PI)/nbface;
       double x1,x2,y1,y2,angle,d;
       Frame frame;
       for(int i=0; i<nbface;i++)
       {
           x1=size/2+r*qCos(Circle::alpha*i);
           y1=size/2+r*qSin(Circle::alpha*i);

           x2=size/2+r*qCos(Circle::alpha*(i+1));
           y2=size/2+r*qSin(Circle::alpha*(i+1));

           angle=qAtan2((y2-y1),(x2-x1));//+PI/2;
           d=qSqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
           frame.Init(x1,y1,d,angle/PI*180);
           Circle::Liste[i]=frame;

       }


    }
    else if(nbface==1)
    {
         Circle::Ok=true;

         Frame frame;
         frame.Init(0,0,size,0);

         Circle::Liste[0]=frame;
    }
    else if(nbface==2)
    {
         Circle::Ok=true;

         Frame frame;
         frame.Init(0,0,size,0);
         Circle::Liste[0]=frame;

         frame.Init(size,0,size,180);
         Circle::Liste[1]=frame;

    }
    else
    {
        Circle::Ok=false ;
    }
}

Frame Circle::Get_frame(int no)
{
    if(Circle::Ok)
    {
        if(no<Circle::nbface)
        {
            return Circle::Liste[no];
        }
        else
        {
            Frame frame;
            frame.Init(0,0,1,0);
            return frame;
        }
    }
    else
    {
        Frame frame;
        frame.Init(0,0,1,0);
        return frame;
    }
}

int Circle::Get_nbface()
{
    if(Circle::Ok)
    {
        return Circle::nbface;
    }
    else
    {
        return -1;
    }
}

int Circle::Get_size()
{
    return Circle::size;
}

void  Circle::Set_nbface(int nb_face)
{
    nbface=nb_face;
    Calcul();
}

void  Circle::Set_size(int Size)
{
    size=Size;
    Calcul();
}
