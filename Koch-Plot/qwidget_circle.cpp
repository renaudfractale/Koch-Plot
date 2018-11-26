#include "qwidget_circle.h"

QWidget_Circle::QWidget_Circle(QWidget *parent) : QWidget(parent)
{
    //Init widget
    SpinBox_Nbface = new QSpinBox();
    SpinBox_Nbface->setMaximum(18);
    SpinBox_Nbface->setMinimum(1);
    SpinBox_Nbface->setValue(4);

    ComboBox_Nbface = new QComboBox();
    ComboBox_Nbface->addItem("1");
    ComboBox_Nbface->addItem("2");
    ComboBox_Nbface->addItem("3");
    ComboBox_Nbface->addItem("4");
    ComboBox_Nbface->addItem("5");
    ComboBox_Nbface->addItem("6");
    ComboBox_Nbface->addItem("7");
    ComboBox_Nbface->addItem("8");
    ComboBox_Nbface->addItem("9");
    ComboBox_Nbface->addItem("10");
    ComboBox_Nbface->addItem("11");
    ComboBox_Nbface->addItem("12");
    ComboBox_Nbface->addItem("13");
    ComboBox_Nbface->addItem("14");
    ComboBox_Nbface->addItem("15");
    ComboBox_Nbface->addItem("16");
    ComboBox_Nbface->addItem("17");
    ComboBox_Nbface->addItem("18");

    SpinBox_size = new QSpinBox();
    SpinBox_size->setMaximum(10000);
    SpinBox_size->setMinimum(1000);
    SpinBox_size->setValue(1000);

    ComboBox_size = new QComboBox();
    ComboBox_size->addItem("1000");
    ComboBox_size->addItem("1500");
    ComboBox_size->addItem("2000");
    ComboBox_size->addItem("2500");
    ComboBox_size->addItem("3000");
    ComboBox_size->addItem("3500");
    ComboBox_size->addItem("4000");
    ComboBox_size->addItem("4500");

    Label_Nbface = new QLabel("Nombre de face : ");
    Label_size = new QLabel("Taille ");

    layout = new QGridLayout();

    layout->addWidget(Label_Nbface,1,1);
    layout->addWidget(ComboBox_Nbface,1,2);
    layout->addWidget(Label_size,1,3);
    layout->addWidget(ComboBox_size,1,4);
    //signaux
    QObject::connect(ComboBox_Nbface,SIGNAL(currentIndexChanged(int)),this,SIGNAL(value_changing()));
    QObject::connect(ComboBox_size,SIGNAL(currentIndexChanged(int)),this,SIGNAL(value_changing()));
    //Slots
    QObject::connect(SpinBox_Nbface,SIGNAL(valueChanged(int)),this,SLOT(Update_Circle()));
    QObject::connect(SpinBox_size,SIGNAL(valueChanged(int)),this,SLOT(Update_Circle()));
    Update_Circle();

    this->setLayout(layout);
}
void  QWidget_Circle::Set_nbface(int nb_face)
{
    qDebug() << "dans void  QWidget_Circle::Set_nbface(int nb_face)";
    qDebug() << "nb_face = "<< nb_face;
    qDebug() << "ComboBox_Nbface->currentIndex() = "<< ComboBox_Nbface->currentIndex();
    qDebug() << "ComboBox_Nbface->currentText() = "<< ComboBox_Nbface->currentText();
    ComboBox_Nbface->setCurrentIndex(nb_face-1);
    qDebug() << "ComboBox_Nbface->currentIndex() = "<< ComboBox_Nbface->currentIndex();
    qDebug() << "ComboBox_Nbface->currentText() = "<< ComboBox_Nbface->currentText();
    Update_Circle();
}

void  QWidget_Circle::Set_size(int Size)
{
    //SpinBox_size->setValue(Size);
    int no=qRound((qreal(Size-1000))/qreal(500));
    ComboBox_size->setCurrentIndex(no);
    Update_Circle();
}
int QWidget_Circle::Get_size()
{
    return ((ComboBox_size->currentIndex()*500)+1000);

}

int QWidget_Circle::Get_Nbface()
{
    return ComboBox_Nbface->currentIndex()+1;
}

void QWidget_Circle::Update_Circle()
{
    circle.Init(Get_size(),Get_Nbface());
}
Circle  QWidget_Circle::Get_Circle()
{
    return circle;
}
