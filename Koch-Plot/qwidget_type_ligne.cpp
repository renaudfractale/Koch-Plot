#include "qwidget_type_ligne.h"

void QWidget_Type_Ligne::Button_color_clicked()
{
    color = QColorDialog::getColor(Qt::white, this);

    QPalette palette;
    palette.setColor(QPalette::ButtonText, color);
    PushButton_color->setPalette(palette);
}

QWidget_Type_Ligne::QWidget_Type_Ligne(QWidget *parent) : QWidget(parent)
{
    //init widget
    Label_niv=new QLabel("Niveau");

    ComboBox_niv= new QComboBox();
    ComboBox_niv->addItem("0");
    ComboBox_niv->addItem("1");
    ComboBox_niv->addItem("2");
    ComboBox_niv->addItem("3");
    ComboBox_niv->addItem("4");
    ComboBox_niv->addItem("5");
    ComboBox_niv->addItem("6");
    ComboBox_niv->addItem("7");
    ComboBox_niv->addItem("8");


    Label_pen = new QLabel("Epaisseur");

    ComboBox_pen= new QComboBox();
    ComboBox_pen->addItem("5");
    ComboBox_pen->addItem("10");
    ComboBox_pen->addItem("15");
    ComboBox_pen->addItem("20");
    ComboBox_pen->addItem("25");
    ComboBox_pen->addItem("30");
    ComboBox_pen->addItem("35");
    ComboBox_pen->addItem("40");
    ComboBox_pen->addItem("45");
    ComboBox_pen->addItem("50");
    ComboBox_pen->addItem("55");
    ComboBox_pen->addItem("60");
    ComboBox_pen->addItem("65");
    ComboBox_pen->addItem("70");
    ComboBox_pen->addItem("75");
    ComboBox_pen->addItem("80");
    ComboBox_pen->setCurrentIndex(1);

    PushButton_color = new QPushButton("COLORE");


    layout= new QGridLayout();

    //add widget to layout
        //Niveau 1
    layout->addWidget(Label_niv,1,1);
    layout->addWidget(ComboBox_niv,1,2);

    layout->addWidget(Label_pen,1,3);
    layout->addWidget(ComboBox_pen,1,4);

    layout->addWidget(PushButton_color,1,5);


     QObject::connect(PushButton_color,SIGNAL(clicked(bool)),this,SLOT(Button_color_clicked()));

     QObject::connect(PushButton_color,SIGNAL(clicked(bool)),this,SIGNAL(value_changing()));
     QObject::connect(ComboBox_niv,SIGNAL(currentIndexChanged(int)),this,SIGNAL(value_changing()));
     QObject::connect(ComboBox_pen,SIGNAL(currentIndexChanged(int)),this,SIGNAL(value_changing()));

    //setLayout
    this->setLayout(layout);
}


int QWidget_Type_Ligne::Get_niveau()
{
    //return SpinBox_niv->value();
    return ComboBox_niv->currentIndex();
}

int QWidget_Type_Ligne::Get_pen()
{
    //return SpinBox_pen->value();
    return (ComboBox_pen->currentIndex()+1)*5;
}

QColor QWidget_Type_Ligne::Get_color()
{
    return color;
}

void QWidget_Type_Ligne::Set_color(QColor Color)
{
    QPalette palette;
    palette.setColor(QPalette::ButtonText, Color);
    PushButton_color->setPalette(palette);
    color=Color;
}
void QWidget_Type_Ligne::Set_niveau(int Niv)
{
    //SpinBox_niv->setValue(Niv);
    ComboBox_niv->setCurrentIndex(Niv);
}
void QWidget_Type_Ligne::Set_pen(int Pen)
{
    //SpinBox_pen->setValue(Pen);
    //qDebug() << "Pen = "<< Pen;
    int no1=qRound((qreal(Pen)/5.0))-1;
    //qDebug() << "no1 = "<< no1;

    ComboBox_pen->setCurrentIndex(no1);
}
