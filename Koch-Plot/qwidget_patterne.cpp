#include "qwidget_patterne.h"

void QWidget_Patterne::Update_patterne()
{
    patterne.Clear();
    double a=0;
    for(int i=0;i<nb_pas;i++)
    {
        patterne.Add(Tab_pas[i]->Get_alpha()-a,Tab_pas[i]->Get_l());
        a=Tab_pas[i]->Get_alpha();
    }
    patterne.Calcul_Patterne();
    scene = new QGraphicsScene();
    GraphicsView->setScene(scene);

    double x=patterne.ListX[patterne.ListX.length()-1];
    double y=patterne.ListY[patterne.ListY.length()-1];
    QPen blackpen(qRgb(0,254,0));
    if(x>0 && y>=-0.001 && y<=0.001)
    {
        blackpen.setColor(qRgb(0,254,0));
    }
    else
    {
        blackpen.setColor(qRgb(254,0,0));
    }

    blackpen.setWidth(6);
    //qDebug() << "Point " << 0 << ": "<< patterne.ListX[0] << ","<< patterne.ListY[0] << "\n";
   // qDebug() << "patterne.ListX.length() = " << patterne.ListX.length() << "\n";
    for(int i=1;i<patterne.ListX.length();i++)
    {
        scene->addLine(patterne.ListX[i-1],patterne.ListY[i-1],patterne.ListX[i],patterne.ListY[i],blackpen);
       // qDebug() << "Point " << i << ": "<< patterne.ListX[i] << ","<< patterne.ListY[i] << "\n";
    }
}
int QWidget_Patterne::Get_Nb_ligne()
{
    return nb_pas;
}

void QWidget_Patterne::Set_Nb_Ligne(int Nb_ligne)
{
    nb_pas=Nb_ligne;
    Update_layout();
    Update_patterne();
}

double QWidget_Patterne::Get_l(int no_ligne)
{
    return Tab_pas[no_ligne]->Get_l();
}

double QWidget_Patterne::Get_alpha(int no_ligne)
{
    return Tab_pas[no_ligne]->Get_alpha();
}

void QWidget_Patterne::Set_l(int no_ligne, double l)
{
    Tab_pas[no_ligne]->Set_l(l);
}

void QWidget_Patterne::Set_alpha(int no_ligne, double alpha)
{
    Tab_pas[no_ligne]->Set_alpha(alpha);
}

int QWidget_Patterne::Get_CheckBox(int no_ligne)
{
    return Tab_pas[no_ligne]->Get_CheckBox();
}

void QWidget_Patterne::Set_CheckBox(int no_ligne,int box)
{
    return Tab_pas[no_ligne]->Set_CheckBox(box);
}

Patterne QWidget_Patterne::Get_Patterne()
{
    return patterne;
}
bool QWidget_Patterne::Get_Is_update_current()
{
    return Is_update_current;
}
void QWidget_Patterne::Set_listWidget(QListWidget *ListWidget)
{
    QWidget_Patterne::ListWidget=ListWidget;
}
void QWidget_Patterne::Add_text_listWidget(QString txt)
{
    QDateTime currentDate = QDateTime::currentDateTime();
    QListWidgetItem *ListWidgetItem=new QListWidgetItem(currentDate.toString("yyyy/MM/dd hh-mm-ss : ")+txt, ListWidget);
    int row=ListWidget->row(ListWidgetItem);
    ListWidget->setCurrentRow(row);
    //ListWidget->sele
}

void QWidget_Patterne::Set_Patterne(Patterne patterne_loc)
{
    Is_update_current=false;
    nb_pas=patterne_loc.Get_lenght()/2;
    int i=0;
    while(i<patterne_loc.Get_lenght())
    {
        Tab_pas[i/2]->Set_CheckBox(1);
        Tab_pas[i/2]->Set_alpha(patterne_loc.Get_Element(i));
        Tab_pas[i/2]->Set_l(patterne_loc.Get_Element(i+1));
        i=i+2;
    }
    i=i-2;
    Tab_pas[i/2]->Set_l(patterne_loc.Get_Element(i+1)+1);
    Is_update_current=true;
    Tab_pas[i/2]->Set_l(patterne_loc.Get_Element(i+1));
    Update_layout();
}

QWidget_Patterne::QWidget_Patterne(QWidget *parent) : QWidget(parent)
{
    Is_update_current=true;
    size_tab=11;
    nb_pas=5;
    // ----------------- Widget_generator --------------------//
    // Initalisation
        Widget_generator= new QWidget_generator();
    // QGroupBox + QVBoxLayout
        QGroupBox *GroupBox_generator = new QGroupBox(tr("Génération automatique de pattern"));
        QVBoxLayout *VBoxLayout_generator = new QVBoxLayout;
    // Set layout
        VBoxLayout_generator->addWidget(Widget_generator);
        VBoxLayout_generator->addStretch(1);
    // Set QGroupBox
        GroupBox_generator->setLayout(VBoxLayout_generator);
    // ----------------- Widget_generator --------------------//

    // ----------------- Widget_Edit_pas ----------------------//
    // Initalisation
        for(int i=0;i<size_tab;i++)
        {
            Tab_pas[i]=new QWidget_Edit_pas();
            Tab_Button_P[i]= new QPushButton("+");
            Tab_Button_M[i]= new QPushButton("-");
            if(i>0)
            {
                Tab_pas[i]->Sans_Label();
            }

        }
    // QGroupBox + QGridLayout
        QGroupBox *GroupBox_manuelle = new QGroupBox(tr("Génération manuelle de pattern"));
        QGridLayout *GridLayout_manuelle = new QGridLayout;
    // Set layout
        for(int i=0;i<size_tab;i++)
        {
               GridLayout_manuelle->addWidget(Tab_Button_M[i],i+1,1);
               GridLayout_manuelle->addWidget(Tab_Button_P[i],i+1,2);
               GridLayout_manuelle->addWidget(Tab_pas[i],i+1,3);
        }
    // Set QGroupBox
        GroupBox_manuelle->setLayout(GridLayout_manuelle);
    // ----------------- Widget_Edit_pas ----------------------//

    // ----------------- QGraphicsView ----------------------//
    // Initalisation
        GraphicsView = new QGraphicsView();
    // ----------------- QGraphicsView ----------------------//

    // ----------------- PushButton_Zoom ----------------------//
    // Initalisation
        PushButton_Zoom_P = new QPushButton("Zoom +");
        PushButton_Zoom_M = new QPushButton("Zoom -");
        layout_Zoom= new QGridLayout();
        layout_Zoom->addWidget(PushButton_Zoom_P,1,1);
        layout_Zoom->addWidget(PushButton_Zoom_M,1,2);
    // ----------------- PushButton_Zoom ----------------------//

    // ----------------- ListWidget ----------------------//
    // Initalisation
        ListWidget = new QListWidget();
    // ----------------- ListWidgets ----------------------//

    // ----------------- layout ----------------------//
        layout= new QVBoxLayout();
            layout->addWidget(GroupBox_generator);
            layout->addWidget(GroupBox_manuelle);
            layout->addWidget(GraphicsView,8);
            layout->addLayout(layout_Zoom);
            //layout->addStretch(1);
    // ----------------- layout ----------------------//
    //Button +
    QObject::connect( Tab_Button_P[0],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_01()));
    QObject::connect( Tab_Button_P[1],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_02()));
    QObject::connect( Tab_Button_P[2],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_03()));
    QObject::connect( Tab_Button_P[3],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_04()));
    QObject::connect( Tab_Button_P[4],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_05()));
    QObject::connect( Tab_Button_P[5],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_06()));
    QObject::connect( Tab_Button_P[6],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_07()));
    QObject::connect( Tab_Button_P[7],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_08()));
    QObject::connect( Tab_Button_P[8],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_09()));
    QObject::connect( Tab_Button_P[9],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_10()));
    QObject::connect( Tab_Button_P[10],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_11()));/*
    QObject::connect( Tab_Button_P[11],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_12()));
    QObject::connect( Tab_Button_P[12],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_13()));
    QObject::connect( Tab_Button_P[13],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_14()));
    QObject::connect( Tab_Button_P[14],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_15()));
    QObject::connect( Tab_Button_P[15],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_16()));
    QObject::connect( Tab_Button_P[16],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_17()));
    QObject::connect( Tab_Button_P[17],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_18()));*/



    //Button -
    QObject::connect( Tab_Button_M[0],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_01()));
    QObject::connect( Tab_Button_M[1],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_02()));
    QObject::connect( Tab_Button_M[2],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_03()));
    QObject::connect( Tab_Button_M[3],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_04()));
    QObject::connect( Tab_Button_M[4],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_05()));
    QObject::connect( Tab_Button_M[5],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_06()));
    QObject::connect( Tab_Button_M[6],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_07()));
    QObject::connect( Tab_Button_M[7],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_08()));
    QObject::connect( Tab_Button_M[8],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_09()));
    QObject::connect( Tab_Button_M[9],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_10()));
    QObject::connect( Tab_Button_M[10],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_11()));/*
    QObject::connect( Tab_Button_M[11],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_12()));
    QObject::connect( Tab_Button_M[12],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_13()));
    QObject::connect( Tab_Button_M[13],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_14()));
    QObject::connect( Tab_Button_M[14],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_15()));
    QObject::connect( Tab_Button_M[15],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_16()));
    QObject::connect( Tab_Button_M[16],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_17()));
    QObject::connect( Tab_Button_M[17],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_18()));*/
 //   QObject::connect( Tab_Button_M[18],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_19()));

    //Zoom
    QObject::connect( PushButton_Zoom_P,SIGNAL(clicked(bool)),this,SLOT(Zoom_P()));
    QObject::connect( PushButton_Zoom_M,SIGNAL(clicked(bool)),this,SLOT(Zoom_M()));

    //Signal
    for(int i=0;i<size_tab;i++)
    {

        QObject::connect(Tab_pas[i],SIGNAL(value_changing()),this,SIGNAL(value_changing()));

    }
    QObject::connect(this,SIGNAL(value_changing()),this,SLOT(Update_patterne()));
    QObject::connect(Widget_generator,SIGNAL(PushButton_Genertor_clicked()),this,SLOT(Generate_Patterne()));
    //Mise a jour de layout
    Update_layout();

    Update_patterne();
    //setLayout
    this->setLayout(layout);

    Init();
}
void QWidget_Patterne::Generate_Patterne()
{
    Add_text_listWidget("Debut generation du Patterne");
    Generator generator(Widget_generator->Get_Nb_ligne());
    Set_Patterne(generator.Get_Patterne());
    Add_text_listWidget("Fin generation du Patterne");
}

void QWidget_Patterne::Zoom_M()
{
    GraphicsView->scale(0.75,0.75);
    Add_text_listWidget("Patterne, Zoom moin");
}
void QWidget_Patterne::Zoom_P()
{
    GraphicsView->scale(1.25,1.25);
    Add_text_listWidget("Patterne, Zoom plus");
}

void QWidget_Patterne::Init()
{
     nb_pas=5;
     Is_update_current=false;

     Tab_pas[0]->Set_l(100);
     Tab_pas[1]->Set_l(100);
     Tab_pas[2]->Set_l(100);
     Tab_pas[3]->Set_l(100);
     Tab_pas[4]->Set_l(100);


     Tab_pas[0]->Set_CheckBox(1);
     Tab_pas[0]->CheckBox_alpha_update();
     Tab_pas[1]->Set_CheckBox(1);
     Tab_pas[1]->CheckBox_alpha_update();
     Tab_pas[2]->Set_CheckBox(1);
     Tab_pas[2]->CheckBox_alpha_update();
     Tab_pas[3]->Set_CheckBox(1);
     Tab_pas[3]->CheckBox_alpha_update();
     Tab_pas[4]->Set_CheckBox(1);
     Tab_pas[4]->CheckBox_alpha_update();

     Tab_pas[0]->Set_alpha(0);
     Tab_pas[1]->Set_alpha(-90);
     Tab_pas[2]->Set_alpha(0);
     Tab_pas[3]->Set_alpha(90);
     Tab_pas[4]->Set_alpha(0);

      Tab_pas[4]->Set_alpha(1);
     Is_update_current=true;
        Tab_pas[4]->Set_alpha(0);
     Update_layout();

     Update_patterne();
}

void QWidget_Patterne::Update_layout()
{
    //cacher les boutons
    for(int i=0;i<size_tab;i++)
    {
        Tab_pas[i]->hide();
        Tab_Button_P[i]->hide();
        Tab_Button_M[i]->hide();

    }
    // si nb_pas = max
    if(nb_pas==size_tab)
    {
        for(int i=0;i<nb_pas;i++)
        {
            Tab_Button_P[i]->setEnabled(false);
        }
    }
    else
    {
        for(int i=0;i<nb_pas;i++)
        {
            Tab_Button_P[i]->setEnabled(true);
        }
    }
    // si nb_pas = min
    if(nb_pas<=3)
    {
        for(int i=0;i<nb_pas;i++)
        {
            Tab_Button_M[i]->setEnabled(false);
        }
    }
    else
    {
        for(int i=0;i<nb_pas;i++)
        {
            Tab_Button_M[i]->setEnabled(true);
        }
    }
    //affiche bouton
    for(int i=0;i<nb_pas;i++)
    {
        Tab_pas[i]->setVisible(true);
        Tab_Button_P[i]->setVisible(true);
        Tab_Button_M[i]->setVisible(true);
    }
   if(nb_pas<size_tab)
    {
           Tab_Button_P[nb_pas]->setVisible(true);
    }



}
void QWidget_Patterne::Get_Config(int add,int remove)
{
    Is_update_current=false;
    List_Rotation.clear();
    List_Translation.clear();
    for(int i=0;i<nb_pas;i++)
    {
        if(i==(add-1))
        {
            List_Rotation.append(0);
            List_Translation.append(0);
        }
        if(i!=(remove-1))
        {
            List_Rotation.append(Tab_pas[i]->Get_alpha());
            List_Translation.append(Tab_pas[i]->Get_l());
        }
    }
    if(nb_pas==(add-1))
    {
        List_Rotation.append(0);
        List_Translation.append(0);
    }
}

void QWidget_Patterne::Set_config()
{
    for(int i=0;i<nb_pas;i++)
    {
        Tab_pas[i]->Set_alpha(List_Rotation[i]);
        Tab_pas[i]->Set_l(List_Translation[i]);
    }
    if(List_Translation[nb_pas-1]>0)
        Tab_pas[nb_pas-1]->Set_l(List_Translation[nb_pas-1]-1);
    else
        Tab_pas[nb_pas-1]->Set_l(List_Translation[nb_pas-1]+1);
    Is_update_current=true;
    Tab_pas[nb_pas-1]->Set_l(List_Translation[nb_pas-1]);
}

void QWidget_Patterne::Add_ligne_01()
{
    Get_Config(1,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_02()
{
    Get_Config(2,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_03()
{
    Get_Config(3,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_04()
{
    Get_Config(4,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_05()
{
    Get_Config(5,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_06()
{
    Get_Config(6,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_07()
{
    Get_Config(7,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_08()
{
    Get_Config(8,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_09()
{
    Get_Config(9,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_10()
{
    Get_Config(10,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_11()
{
    Get_Config(11,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_12()
{
    Get_Config(12,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_13()
{
    Get_Config(13,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_14()
{
    Get_Config(14,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_15()
{
    Get_Config(15,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_16()
{
    Get_Config(16,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_17()
{
    Get_Config(17,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Patterne::Add_ligne_18()
{
    Get_Config(18,-1);
    if(nb_pas<=18)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}

void QWidget_Patterne::Remove_ligne_01()
{
    Get_Config(-1,1);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_02()
{
    Get_Config(-1,2);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_03()
{
    Get_Config(-1,3);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_04()
{
    Get_Config(-1,4);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_05()
{
    Get_Config(-1,4);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_06()
{
    Get_Config(-1,6);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_07()
{
    Get_Config(-1,7);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_08()
{
    Get_Config(-1,8);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_09()
{
    Get_Config(-1,9);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_10()
{
    Get_Config(-1,10);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_11()
{
    Get_Config(-1,11);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_12()
{
    Get_Config(-1,12);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_13()
{
    Get_Config(-1,13);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_14()
{
    Get_Config(-1,14);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_15()
{
    Get_Config(-1,15);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_16()
{
    Get_Config(-1,16);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_17()
{
    Get_Config(-1,17);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_18()
{
    Get_Config(-1,18);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Patterne::Remove_ligne_19()
{
    Get_Config(-1,19);
    if(nb_pas>=3)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
