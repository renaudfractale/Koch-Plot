#include "qwidget_generator.h"

QWidget_generator::QWidget_generator(QWidget *parent) : QWidget(parent)
{
    Label_Genertor= new QLabel("Nombre de Segnmants : ");

    PushButton_Genertor=new QPushButton("Generateur de motif");

    ComboBox_Genertor = new QComboBox();
    ComboBox_Genertor->addItem("1");
    ComboBox_Genertor->addItem("2");
    ComboBox_Genertor->addItem("3");
    ComboBox_Genertor->addItem("4");
    ComboBox_Genertor->addItem("5");
    ComboBox_Genertor->addItem("6");
    ComboBox_Genertor->addItem("7");
    ComboBox_Genertor->addItem("8");
    ComboBox_Genertor->addItem("9");
    ComboBox_Genertor->addItem("10");
    /*
    ComboBox_Genertor->addItem("11");
    ComboBox_Genertor->addItem("12");
    ComboBox_Genertor->addItem("13");
    ComboBox_Genertor->addItem("14");
    ComboBox_Genertor->addItem("15");
    ComboBox_Genertor->addItem("16");
    ComboBox_Genertor->addItem("17");
    ComboBox_Genertor->addItem("18");
    */
    Set_Nb_ligne(5);

    layout= new QGridLayout;
        layout->addWidget(Label_Genertor,0,1);
        layout->addWidget(ComboBox_Genertor,0,2);
        layout->addWidget(PushButton_Genertor,0,3);
    //Sinal
    QObject::connect(PushButton_Genertor,SIGNAL(clicked(bool)),this,SIGNAL(PushButton_Genertor_clicked()));

    this->setLayout(layout);

}
int QWidget_generator::Get_Nb_ligne()
{
    return ComboBox_Genertor->currentIndex()+1;
}

void QWidget_generator::Set_Nb_ligne(int nb_ligne)
{
    if(nb_ligne>=1 && nb_ligne<=18)
    {
        ComboBox_Genertor->setCurrentIndex(nb_ligne-1);
    }
}
