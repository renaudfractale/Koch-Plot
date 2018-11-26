#include "svg.h"





void SVG::Init(QGraphicsScene *scene,Circle circle, Patterne patterne)
{
    SVG::scene=scene;
    SVG::circle=circle;
    SVG::patterne=patterne;
    X_max=0;
    X_min=0;
    Y_max=0;
    Y_min=0;


}

void SVG::Clear()
{
    SVG::scene->clear();
}
void SVG::Set_ProgressBar(QProgressBar *progressBar)
{
    ProgressBar=progressBar;
}

void SVG::Draw(QColor Color, int niveau_max,int sizePen)
{

    SVG::Color=Color;
    SVG::niveau_max=niveau_max;
    SVG::sizePen=sizePen;

    current_nb_ligne=0;
    nb_ligne=qPow(patterne.Get_lenght()/2,niveau_max)*circle.Get_nbface();

    ProgressBar->setMaximum(10000);;
    ProgressBar->setMinimum(0);;
    ProgressBar->setValue(0);;


    X_max=0;
    X_min=0;
    Y_max=0;
    Y_min=0;
    niveau=niveau_max;
        for(int i=0;i<circle.Get_nbface();i++)
        {
            frame=circle.Get_frame(i);
            trace_line();
        }

}

double SVG::Get_x_fin()
{
    return patterne.x_fin;
}

void SVG::trace_line()
{
    double ration;
    ration=frame.Get_d()/ Get_x_fin();

    SVG::niveau--;
    if(SVG::niveau>-1)
    {
        for(int i=0;i<patterne.Get_lenght();i++)
        {
            if(i%2==1)  // impaire --> Tranlation
            {
               SVG::frame.Set_d(patterne.Get_Element(i)*ration);
                trace_line();
            }
            else
            {  // paire --> Rotation
                SVG::frame.Add_alpha(patterne.Get_Element(i));
            }
        }
    }
    else
    {
        current_nb_ligne++;
        int pr=current_nb_ligne*(long)ProgressBar->maximum()/nb_ligne;
        ProgressBar->setValue(pr);
 /*       qDebug()<< " ------------------------------------------------- ";
        qDebug()<< "current_nb_ligne / nb_ligne = " << current_nb_ligne << "/" << nb_ligne;
        qDebug()<< "current_nb_ligne / nb_ligne = pr = " << pr;
        qDebug()<< "ProgressBar->value() = " << ProgressBar->value();
        qDebug()<< "patterne.Get_lenght() = " << patterne.Get_lenght();
        qDebug()<< "circle.Get_nbface() = " << circle.Get_nbface();
        qDebug()<< "niveau_max = " << niveau_max;
*/
        if(SVG::frame.Get_d()>0)
        {
            frame.Set_scene(scene);
            frame.Plot_line(Color,sizePen);
        }
        SVG::frame.Move();
    }
    SVG::niveau++;
}

double SVG::Get_Xmax()
{
    return X_max;
}

double SVG::Get_Xmin()
{
    return X_min;
}

double SVG::Get_Ymax()
{
    return Y_max;
}

double SVG::Get_Ymin()
{
    return Y_min;
}


void SVG::File_Open(QString namefile)
{
    name_file=namefile;
    QFile file(name_file);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
        out << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"" << X_max-X_min+200 <<"\" height=\"" << Y_max-Y_min+200 << "\">\n";
        file.close();
    }

}
void SVG::File_Draw(QColor Color, int niveau_max,int sizePen)
{
    SVG::Color=Color;
    SVG::niveau_max=niveau_max;
    SVG::sizePen=sizePen;
    niveau=niveau_max;

    current_nb_ligne=0;
    nb_ligne=long(qPow(patterne.Get_lenght()/2,niveau_max))*long(circle.Get_nbface());

    ProgressBar->setMaximum(10000);;
    ProgressBar->setMinimum(0);
    ProgressBar->setValue(0);

    for(int i=0;i<circle.Get_nbface();i++)
        {
            frame=circle.Get_frame(i);
            File_Draw_line();
        }

}
void SVG::File_Draw_line()
{
    double ration;
    ration=frame.Get_d()/ Get_x_fin();

    SVG::niveau--;
    if(SVG::niveau>-1)
    {
        for(int i=0;i<patterne.Get_lenght();i++)
        {
            if(i%2==1)  // impaire --> Tranlation
            {
               SVG::frame.Set_d(patterne.Get_Element(i)*ration);
                File_Draw_line();
            }
            else
            {  // paire --> Rotation
                SVG::frame.Add_alpha(patterne.Get_Element(i));
            }
        }
    }
    else
    {
        current_nb_ligne++;
        int pr=current_nb_ligne*ProgressBar->maximum()/nb_ligne;
        ProgressBar->setValue(pr);
        if(SVG::frame.Get_d()>0)
        {

            double x1,x2,y1,y2;
            x1=frame.Get_x1()-X_min+100;
            x2=frame.Get_x2()-X_min+100;
            y1=frame.Get_y1()-Y_min+100;
            y2=frame.Get_y2()-Y_min+100;
            QFile file(name_file);
            if(file.open(QIODevice::Append  | QIODevice::Text))
            {
                QTextStream out(&file);
                if(circle.Get_nbface()==1)
                {
                    out << "<circle cx=\"" << x1 <<"\" cy=\"" << y1 << "\" r=\"" << sizePen/2 << "\" fill=\"rgb(" << Color.red() <<"," << Color.green() << "," << Color.blue() << ")\"/> \n";
                }
                out << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" stroke=\"rgb(" << Color.red() <<"," << Color.green() << "," << Color.blue() << ")\" stroke-width=\"" << sizePen << "\"/>\n";
                out << "<circle cx=\"" << x2 <<"\" cy=\"" << y2 << "\" r=\"" << sizePen/2 << "\" fill=\"rgb(" << Color.red() <<"," << Color.green() << "," << Color.blue() << ")\"/> \n";
                file.close();
            }

        }
        SVG::frame.Move();
    }
    SVG::niveau++;
}

void SVG::File_Close()
{
    QFile file(name_file);
    if(file.open(QIODevice::Append  | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "</svg>";
        file.close();
    }
}
