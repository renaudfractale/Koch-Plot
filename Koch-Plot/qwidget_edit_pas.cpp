#define PI 3.14159265358979323846
#include "qwidget_edit_pas.h"

void QWidget_Edit_pas::CheckBox_alpha_update()
{
    //alpha
    CheckBox_alpha->setChecked(true);
    CheckBox_alpha->setEnabled(false);
    DoubleSpinBox_alpha->setEnabled(true);

    //h
    CheckBox_h->setChecked(false);
    CheckBox_h->setEnabled(true);
    DoubleSpinBox_h->setEnabled(false);

    //v
    CheckBox_v->setChecked(false);
    CheckBox_v->setEnabled(true);
    DoubleSpinBox_v->setEnabled(false);
}

void QWidget_Edit_pas::CheckBox_h_update()
{
    //alpha
    CheckBox_alpha->setChecked(false);
    CheckBox_alpha->setEnabled(true);
    DoubleSpinBox_alpha->setEnabled(false);

    //h
    CheckBox_h->setChecked(true);
    CheckBox_h->setEnabled(false);
    DoubleSpinBox_h->setEnabled(true);

    //v
    CheckBox_v->setChecked(false);
    CheckBox_v->setEnabled(true);
    DoubleSpinBox_v->setEnabled(false);
}

void QWidget_Edit_pas::CheckBox_v_update()
{
    //alpha
    CheckBox_alpha->setChecked(false);
    CheckBox_alpha->setEnabled(true);
    DoubleSpinBox_alpha->setEnabled(false);

    //h
    CheckBox_h->setChecked(false);
    CheckBox_h->setEnabled(true);
    DoubleSpinBox_h->setEnabled(false);

    //v
    CheckBox_v->setChecked(true);
    CheckBox_v->setEnabled(false);
    DoubleSpinBox_v->setEnabled(true);
}
int QWidget_Edit_pas::Get_CheckBox()
{
    if(CheckBox_alpha->isChecked())
    {
        return 1;
    }
    if(CheckBox_h->isChecked())
    {
        return 2;
    }
    if(CheckBox_v->isChecked())
    {
        return 3;
    }
    return 0;
}

void QWidget_Edit_pas::Set_CheckBox(int box)
{
    if(box==1)
    {
        CheckBox_alpha_update();
    }
    else if(box==2)
    {
         CheckBox_h_update();
    }
    else
    {
        CheckBox_v_update();
    }
}

void QWidget_Edit_pas::update_value()
{
    // declaration des variables
    double a,l,v,h;
    bool etat_a,etat_v,etat_h;

    //assignatuin
    a=DoubleSpinBox_alpha->value();
    l=DoubleSpinBox_l->value();
    h=DoubleSpinBox_h->value();
    v=DoubleSpinBox_v->value();

    etat_a=CheckBox_alpha->checkState();
    etat_h=CheckBox_h->checkState();
    etat_v=CheckBox_v->checkState();

    if(etat_a) //si alpha
    {
        h=qCos(a*PI/180)*l;
        v=qSin(a*PI/180)*l;

    }

    if(etat_h) //si horisontal (x)
    {
        if(qAbs(h)>l)
        {
            if (h>0)
            {
                h=l;
            }
            else
            {
                h=-l;
            }

        }
        if(v>=0)
            v=qSqrt((l*l)-(h*h));
        else
            v=-qSqrt((l*l)-(h*h));
        a=qAtan2(v,h)*180/PI;
    }
     if(etat_v) //si horisontal (y)
     {
         if(qAbs(v)>l)
         {
             if(v>=0)
                v=l;
             else
                 v=-l;
         }
         if(h>=0)
            h=qSqrt((l*l)-(v*v));
         else
             h=-qSqrt((l*l)-(v*v));
         a=qAtan2(v,h)*180/PI;
     }

     //Set value
     DoubleSpinBox_alpha->setValue(a);
     DoubleSpinBox_h->setValue(h);
     DoubleSpinBox_v->setValue(v);

}

QWidget_Edit_pas::QWidget_Edit_pas(QWidget *parent) : QWidget(parent)
{
    //init widget
    // DoubleSpinBox
    DoubleSpinBox_alpha = new QDoubleSpinBox();
    DoubleSpinBox_alpha->setMaximum(360);
    DoubleSpinBox_alpha->setMinimum(-360);

    DoubleSpinBox_l = new QDoubleSpinBox();
    DoubleSpinBox_l->setMaximum(100);
    DoubleSpinBox_l->setMinimum(0);

    DoubleSpinBox_h = new QDoubleSpinBox();
    DoubleSpinBox_h->setMaximum(100);
    DoubleSpinBox_h->setMinimum(-100);

    DoubleSpinBox_v = new QDoubleSpinBox();
    DoubleSpinBox_v->setMaximum(100);
    DoubleSpinBox_v->setMinimum(-100);

    //CheckBox
    CheckBox_alpha= new QCheckBox();
    CheckBox_h= new QCheckBox();
    CheckBox_v= new QCheckBox();

    //Label
    Label_alpha=new QLabel("Rotation");
    Label_alpha->setAlignment(Qt::AlignCenter);

    Label_l=new QLabel("Longeur");
    Label_l->setAlignment(Qt::AlignCenter);

    Label_h=new QLabel("dX");
    Label_h->setAlignment(Qt::AlignCenter);

    Label_v=new QLabel("dY");
    Label_v->setAlignment(Qt::AlignCenter);

    //layout
    layout= new QGridLayout;;

    //add widget to layout
        //Niveau 1
        layout->addWidget(Label_l,1,1);

        layout->addWidget(Label_alpha,1,2,1,2);

        layout->addWidget(Label_h,1,4,1,2);

        layout->addWidget(Label_v,1,6,1,2);

        //viveau 2
        layout->addWidget(DoubleSpinBox_l,2,1);

        layout->addWidget(CheckBox_alpha,2,2);
        layout->addWidget(DoubleSpinBox_alpha,2,3);

        layout->addWidget(CheckBox_h,2,4);
        layout->addWidget(DoubleSpinBox_h,2,5);

        layout->addWidget(CheckBox_v,2,6);
        layout->addWidget(DoubleSpinBox_v,2,7);



    //Init
    // alpha
    CheckBox_alpha->setChecked(true);
    CheckBox_alpha->setEnabled(false);

    DoubleSpinBox_h->setEnabled(false);
    DoubleSpinBox_v->setEnabled(false);

    // Connexion choix
    QObject::connect(CheckBox_alpha,SIGNAL(clicked(bool)),this,SLOT(CheckBox_alpha_update()));
    QObject::connect(CheckBox_h,SIGNAL(clicked(bool)),this,SLOT(CheckBox_h_update()));
    QObject::connect(CheckBox_v,SIGNAL(clicked(bool)),this,SLOT(CheckBox_v_update()));
    //conect signal
    QObject::connect(DoubleSpinBox_alpha,SIGNAL(valueChanged(double)),this,SIGNAL(value_changing()));
    QObject::connect(DoubleSpinBox_l,SIGNAL(valueChanged(double)),this,SIGNAL(value_changing()));
    //QObject::connect(DoubleSpinBox_h,SIGNAL(valueChanged(double)),this,SIGNAL(value_changing()));
    //QObject::connect(DoubleSpinBox_v,SIGNAL(valueChanged(double)),this,SIGNAL(value_changing()));
    // Connexion update
    QObject::connect(DoubleSpinBox_alpha,SIGNAL(valueChanged(double)),this,SLOT(update_value()));
    QObject::connect(DoubleSpinBox_l,SIGNAL(valueChanged(double)),this,SLOT(update_value()));
    QObject::connect(DoubleSpinBox_h,SIGNAL(valueChanged(double)),this,SLOT(update_value()));
    QObject::connect(DoubleSpinBox_v,SIGNAL(valueChanged(double)),this,SLOT(update_value()));

    //update_value()
    update_value();

    //setLayout
    this->setLayout(layout);
}
double QWidget_Edit_pas::Get_l()
{
    return DoubleSpinBox_l->value();
}
double QWidget_Edit_pas::Get_alpha()
{
    return DoubleSpinBox_alpha->value();
}
void  QWidget_Edit_pas::Set_l(double l)
{
    DoubleSpinBox_l->setValue(l);
}

void QWidget_Edit_pas::Set_alpha(double alpha)
{
    DoubleSpinBox_alpha->setValue(alpha);
}

void QWidget_Edit_pas::Sans_Label()
{
    Label_alpha->hide();
    Label_h->hide();
    Label_l->hide();
    Label_v->hide();

}

void QWidget_Edit_pas::Avec_Lbel()
{
    Label_alpha->setVisible(true);
    Label_h->setVisible(true);;
    Label_l->setVisible(true);
    Label_v->setVisible(true);

}
