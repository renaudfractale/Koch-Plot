#include "qwidget_plot.h"

QWidget_Plot::QWidget_Plot(QWidget *parent) : QWidget(parent)
{
    Is_update_current=true;

    nb_pas=3;
    min_pas=1;
    max_pas=10;
    size_tab=18;

    //---------------- Widget_Circle ---------------- //
    //Initialisation
        Widget_Circle = new QWidget_Circle();
    // QGroupBox + QVBoxLayout
    QGroupBox *GroupBox_circle = new QGroupBox(tr("Forme de base"));
    QVBoxLayout *VBoxLayout_circle = new QVBoxLayout;
    // Set layout
        VBoxLayout_circle->addWidget(Widget_Circle);
        VBoxLayout_circle->addStretch(1);
    // Set QGroupBox
        GroupBox_circle->setLayout(VBoxLayout_circle);
    //---------------- Widget_Circle ---------------- //

    //---------------- QWidget_Type_Ligne ---------------- //
    //Initialisation
        for(int i=0;i<size_tab;i++)
        {
            Tab_ligne[i]=new QWidget_Type_Ligne();
            Tab_Button_P[i]= new QPushButton("+");
            Tab_Button_M[i]= new QPushButton("-");
        }
    // QGroupBox + QGridLayout
            QGroupBox *GroupBox_Type_Ligne = new QGroupBox(tr("Représentation des niveaux"));
            QGridLayout *GridLayout_Type_Ligne = new QGridLayout;
    // Set layout
        for(int i=0;i<size_tab;i++)
        {
               GridLayout_Type_Ligne->addWidget(Tab_ligne[i],i+1,3);
               GridLayout_Type_Ligne->addWidget(Tab_Button_P[i],i+1,2);
               GridLayout_Type_Ligne->addWidget(Tab_Button_M[i],i+1,1);
        }
    // Set QGroupBox
        GroupBox_Type_Ligne->setLayout(GridLayout_Type_Ligne);
    //---------------- QWidget_Type_Ligne ---------------- //

    //---------------- QGraphicsView---------------- //
        GraphicsView = new QGraphicsView();
        GraphicsView->setBaseSize(GraphicsView->width(),GraphicsView->height()*5);
        //GraphicsView->setFixedSize(GraphicsView->width(),GraphicsView->height()*5);
    //---------------- QGraphicsView---------------- //

    //---------------- PushButton_Zoom---------------- //
        PushButton_Zoom_P = new QPushButton("Zoom +");
        PushButton_Zoom_M = new QPushButton("Zoom -");
        layout_Zoom= new QGridLayout();
        layout_Zoom->addWidget(PushButton_Zoom_P,1,1);
        layout_Zoom->addWidget(PushButton_Zoom_M,1,2);
    //---------------- PushButton_Zoom---------------- //

    //---------------- ProgressBar +  ListWidget---------------- //
        ProgressBar= new QProgressBar();
        ListWidget = new QListWidget();
    //---------------- ProgressBar +  ListWidget ---------------- //

    // ----------------- layout ----------------------//
        layout= new QVBoxLayout();
            layout->addWidget(GroupBox_circle);
            layout->addWidget(GroupBox_Type_Ligne);
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
    QObject::connect( Tab_Button_P[10],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_11()));
    QObject::connect( Tab_Button_P[11],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_12()));
    QObject::connect( Tab_Button_P[12],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_13()));
    QObject::connect( Tab_Button_P[13],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_14()));
    QObject::connect( Tab_Button_P[14],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_15()));
    QObject::connect( Tab_Button_P[15],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_16()));
    QObject::connect( Tab_Button_P[16],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_17()));
    QObject::connect( Tab_Button_P[17],SIGNAL(clicked(bool)),this,SLOT(Add_ligne_18()));



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
    QObject::connect( Tab_Button_M[10],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_11()));
    QObject::connect( Tab_Button_M[11],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_12()));
    QObject::connect( Tab_Button_M[12],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_13()));
    QObject::connect( Tab_Button_M[13],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_14()));
    QObject::connect( Tab_Button_M[14],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_15()));
    QObject::connect( Tab_Button_M[15],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_16()));
    QObject::connect( Tab_Button_M[16],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_17()));
    QObject::connect( Tab_Button_M[17],SIGNAL(clicked(bool)),this,SLOT(Remove_ligne_18()));


    //Zoom
    QObject::connect( PushButton_Zoom_P,SIGNAL(clicked(bool)),this,SLOT(Zoom_P()));
    QObject::connect( PushButton_Zoom_M,SIGNAL(clicked(bool)),this,SLOT(Zoom_M()));


    //Signal
    QObject::connect(Widget_Circle,SIGNAL(value_changing()),this,SIGNAL(value_changing()));
    for(int i=0;i<size_tab;i++)
    {

        QObject::connect(Tab_ligne[i],SIGNAL(value_changing()),this,SIGNAL(value_changing()));
    }
    QObject::connect(this,SIGNAL(value_changing()),this,SLOT(plot_fractal()));

    //Mise a jour de layout
    Update_layout();
    Zoom_M();
    Zoom_M();
    Zoom_M();
     Zoom_M();
      Zoom_M();
       Zoom_M();
    //setLayout

    this->setLayout(layout);

       Init_forme();
       Init_graphique();

}
void QWidget_Plot::Init_forme()
{
    Widget_Circle->Set_nbface(1);
    Widget_Circle->Set_size(1000);


}
void QWidget_Plot::Init_graphique()
{
    QColor color;
    color.setRgb(0,0,0);
    nb_pas=4;
    Is_update_current=false;
    Tab_ligne[0]->Set_niveau(0);
    Tab_ligne[1]->Set_niveau(1);
    Tab_ligne[2]->Set_niveau(2);
    Tab_ligne[3]->Set_niveau(3);

    Tab_ligne[0]->Set_pen(60);
    Tab_ligne[1]->Set_pen(45);
    Tab_ligne[2]->Set_pen(30);
    Tab_ligne[3]->Set_pen(15);

    color.setRgb(254,0,0);
    Tab_ligne[0]->Set_color(color);
    color.setRgb(0,254,0);
    Tab_ligne[1]->Set_color(color);
    color.setRgb(0,0,254);
    Tab_ligne[2]->Set_color(color);
    color.setRgb(0,0,0);
    Tab_ligne[3]->Set_color(color);

    Tab_ligne[3]->Set_pen(14);
    Is_update_current=true;
    Tab_ligne[3]->Set_pen(15);
     Update_layout();

}
Circle QWidget_Plot::Get_Circle()
{
    return circle;
}
int QWidget_Plot::Get_nb_line()
{
    return nb_pas;
}
void QWidget_Plot::Set_nb_line(int nb_line)
{
    nb_pas=nb_line;
    Update_layout();
}
void QWidget_Plot::Set_listWidget(QListWidget *ListWidget)
{
    QWidget_Plot::ListWidget=ListWidget;
}
void QWidget_Plot::Add_text_listWidget(QString txt)
{
    QDateTime currentDate = QDateTime::currentDateTime();
    QListWidgetItem *ListWidgetItem=new QListWidgetItem(currentDate.toString("yyyy/MM/dd hh-mm-ss : ")+txt, ListWidget);
    int row=ListWidget->row(ListWidgetItem);
    ListWidget->setCurrentRow(row);
}

int QWidget_Plot::Get_Niveau(int no_line)
{
    return Tab_ligne[no_line]->Get_niveau();
}

int QWidget_Plot::Get_SizePen(int no_line)
{
     return Tab_ligne[no_line]->Get_pen();
}

void QWidget_Plot::Set_Niveau(int no_line, int niv)
{
    Tab_ligne[no_line]->Set_niveau(niv);
}

void QWidget_Plot::Set_SizePen(int no_line, int SizePen)
{
    Tab_ligne[no_line]->Set_pen(SizePen);
}


int QWidget_Plot::Get_Circle_Nbface()
{
    return Widget_Circle->Get_Nbface();
}

int QWidget_Plot::Get_Circle_Size()
{
 return Widget_Circle->Get_size();
}

void QWidget_Plot::Set_Circle_Nbface(int nbface)
{
    Widget_Circle->Set_nbface( nbface);
}

void QWidget_Plot::Set_Circle_Size(int Size)
{
    Widget_Circle->Set_size(Size);
}

QColor QWidget_Plot::Get_Color(int no_line)
{
    return Tab_ligne[no_line]->Get_color();
}

void QWidget_Plot::Set_Color(int no_line,QColor color)
{
    Tab_ligne[no_line]->Set_color(color);
}

void QWidget_Plot::Zoom_M()
{
    GraphicsView->scale(0.75,0.75);
}
void QWidget_Plot::Zoom_P()
{
    GraphicsView->scale(1.25,1.25);
}
void QWidget_Plot::Save_As_SVG(QString namefile)
{
    plot_fractal();
    svg.File_Open(namefile);
    for(int i=0;i<nb_pas;i++)
    {
        QColor loc_color=Tab_ligne[i]->Get_color();
        int loc_nivmax=Tab_ligne[i]->Get_niveau();
        int loc_pen=Tab_ligne[i]->Get_pen();
        svg.File_Draw(loc_color,loc_nivmax,loc_pen);
    }
    svg.File_Close();
}

void QWidget_Plot::plot_fractal()
{
    if(Is_update_current)
    {
        Add_text_listWidget("Debut generation du graphique");

        scene = new QGraphicsScene();
        GraphicsView->setScene(scene);

        Widget_Circle->Update_Circle();
        circle=Widget_Circle->Get_Circle();
        Add_text_listWidget("       Initialisation");
        //init SVG
        svg.Init(scene,circle,patterne);
        svg.Set_ProgressBar(ProgressBar);
        for(int i=0;i<nb_pas;i++)
        {

            QColor loc_color=Tab_ligne[i]->Get_color();
            int loc_nivmax=Tab_ligne[i]->Get_niveau();
            int loc_pen=Tab_ligne[i]->Get_pen();
            Add_text_listWidget("       Plot niveau " +  QString::number(loc_nivmax) + ", pen "+  QString::number(loc_pen) + ", color RGB=(" + QString::number(loc_color.red()) + ","+ QString::number(loc_color.green()) + ","+ QString::number(loc_color.blue()) + ")");
            svg.Draw(loc_color,loc_nivmax,loc_pen);
        }
    }

}
void QWidget_Plot::Set_patterne( Patterne patterne_loc)
{
    patterne=patterne_loc;
}

void QWidget_Plot::Update_layout()
{
    //cacher les boutons
    for(int i=0;i<size_tab;i++)
    {
        Tab_ligne[i]->hide();
        Tab_Button_P[i]->hide();
        Tab_Button_M[i]->hide();

    }
    // si nb_pas = max
    if(nb_pas>=max_pas)
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
    if(nb_pas<=min_pas)
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
        Tab_ligne[i]->setVisible(true);
        Tab_Button_P[i]->setVisible(true);
        Tab_Button_M[i]->setVisible(true);
    }
   if(nb_pas<max_pas)
    {
           Tab_Button_P[nb_pas]->setVisible(true);
    }

}

void QWidget_Plot::Get_Config(int add, int remove)
{
    Is_update_current=false;
    int decalage=0;
    int  j=0;
    for(int i=0;i<size_tab;i++)
    {
        if(i==(add-1))
        {
            Tab_Niveau[i]=2;
            Tab_SizePen[i]=5;
            Tab_Color[i]=qRgb(0,0,0);
            decalage++;
        }
        j=i+decalage;
        if(i!=(remove-1))
        {
            Tab_Niveau[j]=Tab_ligne[i]->Get_niveau();
            Tab_SizePen[j]=Tab_ligne[i]->Get_pen();
            Tab_Color[j]=Tab_ligne[i]->Get_color();
        }
        else
        {
            decalage--;
        }
    }
}
void QWidget_Plot::Set_ProgressBar(QProgressBar *progressBar)
{
    ProgressBar=progressBar;
}

void QWidget_Plot::Set_config()
{
    for(int i=0;i<nb_pas;i++)
    {
        Tab_ligne[i]->Set_color(Tab_Color[i]);
        Tab_ligne[i]->Set_niveau(Tab_Niveau[i]);

        if(i==nb_pas-1)
        {
            Is_update_current=true;
            Tab_ligne[i]->Set_pen(Tab_SizePen[i]+1);
            Tab_ligne[i]->Set_pen(Tab_SizePen[i]);
        }
        else
           Tab_ligne[i]->Set_pen(Tab_SizePen[i]);

    }

    /*for(int i=0;i<nb_pas;i++)
    {
        Tab_ligne[i]->Set_niveau(List_Niveau[i]);
        Tab_ligne[i]->Set_pen(List_Pen[i]);
    }*/
}


void QWidget_Plot::Add_ligne_01()
{
    Get_Config(1,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_02()
{
    Get_Config(2,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_03()
{
    Get_Config(3,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_04()
{
    Get_Config(4,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_05()
{
    Get_Config(5,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_06()
{
    Get_Config(6,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_07()
{
    Get_Config(7,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_08()
{
    Get_Config(8,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_09()
{
    Get_Config(9,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_10()
{
    Get_Config(10,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_11()
{
    Get_Config(11,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_12()
{
    Get_Config(12,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_13()
{
    Get_Config(13,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_14()
{
    Get_Config(14,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_15()
{
    Get_Config(15,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_16()
{
    Get_Config(16,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_17()
{
    Get_Config(17,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}


void QWidget_Plot::Add_ligne_18()
{
    Get_Config(18,-1);
    if(nb_pas<max_pas)
    {
        nb_pas++;
    }
    Set_config();
    Update_layout();
}

void QWidget_Plot::Remove_ligne_01()
{
    Get_Config(-1,1);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_02()
{
    Get_Config(-1,2);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_03()
{
    Get_Config(-1,3);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_04()
{
    Get_Config(-1,4);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_05()
{
    Get_Config(-1,4);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_06()
{
    Get_Config(-1,6);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_07()
{
    Get_Config(-1,7);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_08()
{
    Get_Config(-1,8);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_09()
{
    Get_Config(-1,9);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_10()
{
    Get_Config(-1,10);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_11()
{
    Get_Config(-1,11);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_12()
{
    Get_Config(-1,12);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_13()
{
    Get_Config(-1,13);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_14()
{
    Get_Config(-1,14);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_15()
{
    Get_Config(-1,15);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_16()
{
    Get_Config(-1,16);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_17()
{
    Get_Config(-1,17);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_18()
{
    Get_Config(-1,18);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
void QWidget_Plot::Remove_ligne_19()
{
    Get_Config(-1,19);
    if(nb_pas>min_pas)
    {
       nb_pas--;
    }
    Set_config();
    Update_layout();
}
