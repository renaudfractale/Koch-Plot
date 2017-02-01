#include "patterne.h"

void Patterne::Add(double Rotation, double Translation)
{
    Patterne::ListPatterne.append(Rotation);
    Patterne::ListPatterne.append(Translation);
}

/*
void Patterne::Make_ListPatterne()
{


    for(int i=0;i<Patterne::ListRotation.length();i++)
    {
        Patterne::ListPatterne.append(Patterne::ListRotation[i]);
        Patterne::ListPatterne.append(Patterne::ListTranslation[i]);
    }
}
*/
void Patterne::Calcul_Patterne()
{
    // Create frame
    Frame frame;
    frame.Init(0,0,0,0);

    //init x,y debut
    Patterne::x_debut=0;
    Patterne::y_debut=0;

    //init limite
    Patterne::x_max=0;
    Patterne::y_max=0;
    Patterne::x_min=0;
    Patterne::y_min=0;

    Patterne::ListX.append(frame.Get_x2());
    Patterne::ListY.append(frame.Get_y2());

    for(int i=0;i<Patterne::ListPatterne.length();i++)
    {
        if(i%2==1) // impaire --> Tranlation
        {
            //Definition de deplacement
            frame.Set_d(Patterne::ListPatterne[i]);
            //Mise à jour de list X
            Patterne::ListX.append(frame.Get_x2());
            Patterne::ListY.append(frame.Get_y2());
            // move frame
            frame.Move();
        }
        else // paire --> Rotation
        {
            frame.Add_alpha(Patterne::ListPatterne[i]);
        }
        //calcule de limite
        if(Patterne::x_max<frame.Get_x2())
            Patterne::x_max=frame.Get_x2();

        if(Patterne::y_max<frame.Get_y2())
            Patterne::y_max=frame.Get_y2();

        if(Patterne::x_min>frame.Get_x2())
            Patterne::x_min=frame.Get_x2();

        if(Patterne::y_min>frame.Get_y2())
            Patterne::y_min=frame.Get_y2();
    }
    //Init x,y fin
    Patterne::x_fin=frame.Get_x1();
    Patterne::y_fin=frame.Get_y1();

    Patterne::Ok=true;
}


void Patterne::Clear()
{
    Patterne::ListPatterne.clear();
    Patterne::ListX.clear();
    Patterne::ListY.clear();

    Patterne::Ok=false;

}

int Patterne::Get_lenght()
{
    return Patterne::ListPatterne.length();
}

double Patterne::Get_Element(int no)
{
    return Patterne::ListPatterne[no];
}
