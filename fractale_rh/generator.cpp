#include "generator.h"

Generator::Generator(int nbpas)
{

    nb_pas=nbpas;

    Generation();
}
void Generator::Set_nb_pas(int nbpas)
{
    nb_pas=nbpas;

    Generation();
}

void Generator::Generation()
{
    //patterne.Clear();
    patterne.Clear();

    //Liste_angle
    Liste_angle.clear();
    Liste_angle.append(30);
    Liste_angle.append(45);
    Liste_angle.append(60);
    Liste_angle.append(90);


    //Liste_pas
    QList <double> Liste_pas;
    Liste_pas.clear();
    QList <double> Liste_pas_temp;
    Liste_pas_temp.clear();

     int no;
    for(int i=0;i<nb_pas;i++)
    {
        Liste_pas_temp=Liste_pas;
        //qDebug() << "Pas No i=" << i <<"\n";
        //print_list(Liste_pas,"Liste_pas");

        int nb_pas_libre=nb_pas-i;
        QList <double> paire_possible;
        paire_possible.clear();
        //print_list(Liste_pas_temp,"Liste_pas_temp");
        //find pair ko
        for(int j=0;j<i;j++)
        {
            double angle_1=Liste_pas_temp[j];
            if (angle_1!=0)
            {
                for(int k=(j+1);k<i;k++)
                {
                    double angle_2=Liste_pas_temp[k];
                    if((angle_2+angle_1)==0)
                    {
                        Liste_pas_temp[j]=0;
                        Liste_pas_temp[k]=0;
                        break;
                    }
                }
            }
        }
        //print_list(Liste_pas_temp,"Liste_pas_temp");
        //find pair ko
        int bn_paire_ko=0;
        double angle;
        for(int j=0;j<i;j++)
        {
            angle=Liste_pas_temp[j];
            if (angle!=0)
            {
                bn_paire_ko++;
                paire_possible.append(-angle);

            }
        }
        //print_list(Liste_pas_temp,"Liste_pas_temp");
        //qDebug() << " ------------- find pair ko ------------";
        //print_list(paire_possible,"paire_possible");
        //qDebug() << "nb_pas_libre= " << nb_pas_libre ;
        nb_pas_libre=nb_pas_libre-bn_paire_ko;
        //qDebug() << "nb_pas_libre= " << nb_pas_libre ;
        //qDebug() << "bn_paire_ko= " << bn_paire_ko ;
        //find element seule
        while(nb_pas_libre>1)
        {

            nb_pas_libre--;
            nb_pas_libre--;
            for(int n=0;n<Liste_angle.length();n++)
            {
                paire_possible.append(Liste_angle[n]);
                paire_possible.append(-Liste_angle[n]);
            }
            paire_possible.append(0);
        }
        if(nb_pas_libre==1)
        {
            paire_possible.append(0);
        }
        //qDebug() << " ------------- find element seule ------------- " ;

        //print_list(paire_possible,"paire_possible");
        //print_list(Liste_pas,"Liste_pas");
        no=qrand() % (paire_possible.length());
        //qDebug() << "paire_possible.length()=" << paire_possible.length()
                    ;
        //qDebug() << "no=" << no <<"\n";
        Liste_pas.append(paire_possible[no]);
        patterne.Add(paire_possible[no],50);

    }
    patterne.Add(0,0);
    patterne.Calcul_Patterne();
}

Patterne Generator::Get_Patterne()
{
    return patterne;
}

void Generator::print_list(QList<double> Liste, QString txt)
{
    qDebug() << " ************ "<< txt <<" ****************" ;
    for(int i=0;i<Liste.length();i++)
    {
        qDebug() << "paire_possible[" << i <<"]="<< Liste[i]  ;
    }
    qDebug() << " //////////////////////////////////////////////////" ;
}
