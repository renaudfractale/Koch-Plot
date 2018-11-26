#include "main_fenetre.h"

Main_fenetre::Main_fenetre() : QMainWindow()//QWidget *parent) : QWidget(parent)
{
    Is_update_current=true;

    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    setWindowIcon(QIcon("Icone.ico"));
    setWindowTitle("Fractale plot");
    qDebug() << "coucou 1 ";
    Widget_Patterne=new QWidget_Patterne();
    qDebug() << "coucou 2 ";
    Widget_Plot = new QWidget_Plot();
    qDebug() << "coucou 3 ";
    ProgressBar_Plot = new QProgressBar();
    ProgressBar_Plot->setMaximum(100);;
    ProgressBar_Plot->setMinimum(0);
    ProgressBar_Plot->setValue(100);
    qDebug() << "coucou 4 ";
    listWidget = new QListWidget();
    qDebug() << "coucou 5 ";
    Widget_Plot->Set_ProgressBar(ProgressBar_Plot);
    qDebug() << "coucou 6 ";
    Widget_Patterne->Set_listWidget(listWidget);
    Widget_Plot->Set_listWidget(listWidget);
    qDebug() << "coucou 7 ";

    QGroupBox *QGroupBox_Pattern = new QGroupBox(tr("Pattern"));
    QVBoxLayout *VBoxLayou_Pattern = new QVBoxLayout;
    VBoxLayou_Pattern->addWidget(Widget_Patterne);
    QGroupBox_Pattern->setLayout(VBoxLayou_Pattern);



    qDebug() << "coucou 8 ";
    TextBrowser= new QTextBrowser();
    TextBrowser->setSource(QUrl("Aide.html"));
    //TextBrowser->setEnabled(false);
    TextBrowser->hide();
    qDebug() << "coucou 9 ";



    QGridLayout *layout_main = new QGridLayout;

    layout_main->addWidget(QGroupBox_Pattern,1,1);
    layout_main->addWidget(Widget_Plot,1,2);
    layout_main->addWidget(ProgressBar_Plot,2,1,1,2);
    //layout_main->addWidget(listWidget,3,1,1,2);
    layout_main->addWidget(TextBrowser,1,3,3,1);
    Widget_Plot->Add_text_listWidget("Debut programme");




    QObject::connect(Widget_Patterne,SIGNAL(value_changing()),this,SLOT(change_patterne()));
    //QObject::connect(Widget_Plot,SIGNAL(value_changing()),this,SLOT(change_patterne()));
    //QObject::connect(Widget_Patterne,SIGNAL(value_changing()),Widget_Plot,SLOT(plot_fractal()));

    //Init
    change_patterne();
    Widget_Plot->plot_fractal();

    widget->setLayout(layout_main);
    //fenetre_ok.show();

    //creation menu
    createActions();
    createMenus();

    Widget_Patterne->Init();
    Widget_Plot->Init_forme();
    Widget_Plot->Init_graphique();


}

void Main_fenetre::change_patterne()
{
    //qDebug() << "Dans void Main_fenetre::change_patterne()";
    //qDebug() << "Widget_Patterne->Get_Is_update_current() = " << Widget_Patterne->Get_Is_update_current();
    //qDebug() << "Is_update_current = " << Is_update_current;

    if ( Widget_Patterne->Get_Is_update_current() && Is_update_current)
    {
        Widget_Plot->Set_patterne(Widget_Patterne->Get_Patterne());
        Widget_Plot->plot_fractal();
    }
}

void Main_fenetre::createActions()
{
    // Menu Fichier
    newAct = new QAction(tr("&Nouveau"), this);
        newAct->setShortcuts(QKeySequence::New);
        newAct->setStatusTip(tr("Créer un nouveau fichier"));
        connect(newAct, &QAction::triggered, this, &Main_fenetre::newFile);
    openAct=  new QAction(tr("&Ouvrir"), this);
        openAct->setShortcuts(QKeySequence::Open);
        openAct->setStatusTip(tr("Ouvrir un fichier"));
        connect(openAct, &QAction::triggered, this, &Main_fenetre::open);
    saveAct=  new QAction(tr("&Sauvegarder"), this);
        saveAct->setShortcuts(QKeySequence::Save);
        saveAct->setStatusTip(tr("Sauvegarder un fichier"));
        connect(saveAct, &QAction::triggered, this, &Main_fenetre::save);
    saveAct_SVG=  new QAction(tr("S&auvegarder en svg"), this);
        saveAct_SVG->setShortcuts(QKeySequence::SaveAs);
        saveAct_SVG->setStatusTip(tr("Saauvegarder le fichier en svg"));
        connect(saveAct_SVG, &QAction::triggered, this, &Main_fenetre::save_svg);

    //patterneMenu
    patterne_init_Act=  new QAction(tr("Courbe &quadratique de Koch (type 1)"), this);
        patterne_init_Act->setStatusTip(tr("Initialisation du patterne"));
        connect(patterne_init_Act, &QAction::triggered, this, &Main_fenetre::Patterne_init);
    patterne_quatype2_Act = new QAction(tr("Courbe &quadratique de Koch (type 2)"), this);
        connect(patterne_quatype2_Act, &QAction::triggered, this, &Main_fenetre::patterne_quatype2);
    patterne_VonClassique_Act=  new QAction(tr("Courbe de Koch &Classiqie 60°"), this);
        connect(patterne_VonClassique_Act, &QAction::triggered, this, &Main_fenetre::patterne_VonClassique);
    patterne_Von90_Act=  new QAction(tr("Courbe de &Koch à 90°"), this);
        connect(patterne_Von90_Act, &QAction::triggered, this, &Main_fenetre::patterne_Von90);
    patterne_Von0_Act=  new QAction(tr("Courbe de &Koch à 0°"), this);
        connect(patterne_Von0_Act, &QAction::triggered, this, &Main_fenetre::patterne_Von0);
    patterne_toit60_Act=  new QAction(tr("Courbe de &Toit à 60°0°"), this);
            connect(patterne_toit60_Act, &QAction::triggered, this, &Main_fenetre::patterne_toit60);

    //formeMenu
    forme_init_Act=  new QAction(tr("&Ligne"), this);
        forme_init_Act->setStatusTip(tr("Ligne"));
        connect(forme_init_Act, &QAction::triggered, this, &Main_fenetre::Forme_init);
    forme_triangle_Act =  new QAction(tr("&Triangle"), this);
        connect(forme_triangle_Act, &QAction::triggered, this, &Main_fenetre::forme_triangle);
    forme_carre_Act=  new QAction(tr("&Carre"), this);
        connect(forme_carre_Act, &QAction::triggered, this, &Main_fenetre::forme_carre);
    forme_penthagone_Act=  new QAction(tr("&Pentagone"), this);
        connect(forme_penthagone_Act, &QAction::triggered, this, &Main_fenetre::forme_penthagone);

    //plotMenu
    plot_init_Act=  new QAction(tr("Initialisation de la &Représenation des niveaux"), this);
        plot_init_Act->setStatusTip(tr("Initialisation de la représenation des niveaux"));
        connect(plot_init_Act, &QAction::triggered, this, &Main_fenetre::Plot_init);
    Plot_N1toN4_Act=new QAction(tr("&Représenation des niveaux 1 à 4"), this);
        connect(Plot_N1toN4_Act, &QAction::triggered, this, &Main_fenetre::Plot_N1toN4);
    //exemple menu
        //flocon von sub menu
            flocon_Von0_Act= new QAction(tr("&Flocon à 0°"), this);
                connect(flocon_Von0_Act, &QAction::triggered, this, &Main_fenetre::flocon_Von0);
            flocon_Von30_Act= new QAction(tr("&Flocon à 30°"), this);
                connect(flocon_Von30_Act, &QAction::triggered, this, &Main_fenetre::flocon_Von30);
            flocon_Von60_Act= new QAction(tr("&Flocon à 60°"), this);
                connect(flocon_Von60_Act, &QAction::triggered, this, &Main_fenetre::flocon_Von60);
            flocon_Von90_Act= new QAction(tr("&Flocon à 90°"), this);
                connect(flocon_Von90_Act, &QAction::triggered, this, &Main_fenetre::flocon_Von90);
            flocon_Von120_Act= new QAction(tr("&Flocon à 120°"), this);
                connect(flocon_Von120_Act, &QAction::triggered, this, &Main_fenetre::flocon_Von120);
            flocon_Von150_Act= new QAction(tr("&Flocon à 150°"), this);
                connect(flocon_Von150_Act, &QAction::triggered, this, &Main_fenetre::flocon_Von150);
            flocon_Von180_Act= new QAction(tr("&Flocon à 180°"), this);
                connect(flocon_Von180_Act, &QAction::triggered, this, &Main_fenetre::flocon_Von180);

    //A propos
    aide_Act= new QAction(tr("&Aide"),this);
        aide_Act->setStatusTip(tr("Aide du programme"));
        connect(aide_Act, &QAction::triggered, this, &Main_fenetre::Aide_Box);
    presentation_dev_Act= new QAction(tr("A propos du &developeur"),this);
        presentation_dev_Act->setStatusTip(tr("A propos du developeur"));
        connect(presentation_dev_Act, &QAction::triggered, this, &Main_fenetre::Presentation_dev_Box);
    presentation_prog_Act= new QAction(tr("A propos du &programme"),this);
        presentation_prog_Act->setStatusTip(tr("A propos du programme"));
        connect(presentation_prog_Act, &QAction::triggered, this, &Main_fenetre::Presentation_prog_Box);



}
void Main_fenetre::createMenus()
{
    QMenuBar *menuBar_rh=new QMenuBar();
    fileMenu=menuBar_rh->addMenu(tr("&Fichier"));
        fileMenu->addAction(newAct);
        fileMenu->addAction(openAct);
        fileMenu->addAction(saveAct);
        fileMenu->addAction(saveAct_SVG);

    patterneMenu=menuBar_rh->addMenu(tr("&Pattern"));
        patterneMenu->addAction(patterne_init_Act);
        patterneMenu->addAction(patterne_quatype2_Act);
        patterneMenu->addAction(patterne_VonClassique_Act);
        patterneMenu->addAction(patterne_Von90_Act);
        patterneMenu->addAction(patterne_Von0_Act);
        patterneMenu->addAction(patterne_toit60_Act);

    formeMenu=menuBar_rh->addMenu(tr("Forme de &Base"));
        formeMenu->addAction(forme_init_Act);
        formeMenu->addAction(forme_triangle_Act);
        formeMenu->addAction(forme_carre_Act);
        formeMenu->addAction(forme_penthagone_Act);

    plotMenu=menuBar_rh->addMenu(tr("&Representation des niveaux"));
        plotMenu->addAction(plot_init_Act);
        plotMenu->addAction(Plot_N1toN4_Act);
    exempleMenu= menuBar_rh->addMenu(tr("&Exemples"));
        flocon_VonSubMenu=exempleMenu->addMenu("Flocon de Von Koch");
            flocon_VonSubMenu->addAction(flocon_Von0_Act);
            flocon_VonSubMenu->addAction(flocon_Von30_Act);
            flocon_VonSubMenu->addAction(flocon_Von60_Act);
            flocon_VonSubMenu->addAction(flocon_Von90_Act);
            flocon_VonSubMenu->addAction(flocon_Von120_Act);
            flocon_VonSubMenu->addAction(flocon_Von150_Act);
            flocon_VonSubMenu->addAction(flocon_Von180_Act);

    aproposMenu=menuBar_rh->addMenu(tr("&?"));
        aproposMenu->addAction(aide_Act);
        aproposMenu->addAction(presentation_dev_Act);
        aproposMenu->addAction(presentation_prog_Act);

   setMenuBar(menuBar_rh);
}
//Fichier
void Main_fenetre::newFile()
{
    Widget_Patterne->Init();
    Widget_Plot->Init_forme();
    Widget_Plot->Init_graphique();
    change_patterne();
    Widget_Plot->plot_fractal();
}
void Main_fenetre::Open_file(QString fichier)
{
    int niv,nb_ligne,r,g,b;
    QColor color;

    QStringList list2 = fichier.split('.', QString::SkipEmptyParts);
    //qDebug()<< "list2 = " << list2;
    //qDebug()<< "ext= " << list2[list2.size()-1];
    QString ext=list2[list2.size()-1];
    //qDebug()<< "ext==dataplot " << ext.compare("dataplot");
    //qDebug()<< "ext==datapattern " << ext.compare("datapattern");
    //qDebug()<< "ext==datagraphique " << ext.compare("datagraphique");
    bool etat_pattern =false;
    bool etat_graphique =false;
    bool etat_forme =false;

    if(ext.compare("dataplot")==0)
    {
        etat_pattern=true;
        etat_graphique=true;
        etat_forme =true;
    }
    else if(ext.compare("datapattern")==0)
    {
        etat_pattern=true;
        etat_graphique=false;
        etat_forme =false;
    }
    else if(ext.compare("datagraphique")==0)
    {
        etat_pattern=false;
        etat_graphique=true;
        etat_forme =false;
    }
    else //ext.compare("dataforme")==0
    {
        etat_pattern=false;
        etat_graphique=false;
        etat_forme =true;
    }

    QFile file(fichier);
    Is_update_current=false;

    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);

        // type line
        if(etat_graphique)
        {
            in >> nb_ligne;
            Widget_Plot->Set_nb_line(nb_ligne);
            for(int i=0;i<nb_ligne;i++)
            {
                in >> niv;
                Widget_Plot->Set_Niveau(i,niv);

                in >> niv;
                Widget_Plot->Set_SizePen(i,niv);

                in >> r;
                in >> g;
                in >> b;
                color.setRgb(r,g,b);
                Widget_Plot->Set_Color(i, color);
            }
        }
        if(etat_forme)
        {
            // circle
            in >> niv;
            qDebug() << "Set_Circle_Nbface(niv) avec niv="  << niv << "\n";
            Widget_Plot->Set_Circle_Nbface(niv);

            in >> niv;
             qDebug() << "Set_Circle_Size(niv) avec niv="  << niv << "\n";
            Widget_Plot->Set_Circle_Size(niv);
        }


        //Patterne
         if(etat_pattern)
        {
            in >> nb_ligne;
            Widget_Patterne->Set_Nb_Ligne(nb_ligne);
            for(int i=0;i<nb_ligne;i++)
            {
                in >> niv;
                Widget_Patterne->Set_l(i,niv);
                qDebug() << niv;

                in >> niv;
                Widget_Patterne->Set_CheckBox(i,1);
                Widget_Patterne->Set_alpha(i,niv);
                qDebug() << niv;

                in >> niv;
                Widget_Patterne->Set_CheckBox(i,niv);
                qDebug() << niv;
            }
        }

        file.close();
        //QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);

    }
    Is_update_current=true;
    change_patterne();

}
void Main_fenetre::open()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "data plot (*.dataplot);;data pattern(*.datapattern);;data forme(*.dataforme);;data graphique(*.datagraphique)");

    Open_file(fichier);
}
void Main_fenetre::save_svg()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier sous le format SVG", QString(), "svg (*.svg)");
    Widget_Plot->Save_As_SVG(fichier);
}
void Main_fenetre::Save_file(QString fichier)
{
    int input,nb_ligne,r,g,b;
    QColor color;

    QStringList list2 = fichier.split('.', QString::SkipEmptyParts);
    //qDebug()<< "list2 = " << list2;
    //qDebug()<< "ext= " << list2[list2.size()-1];
    QString ext=list2[list2.size()-1];
    //qDebug()<< "ext==dataplot " << ext.compare("dataplot");
    //qDebug()<< "ext==datapattern " << ext.compare("datapattern");
    //qDebug()<< "ext==datagraphique " << ext.compare("datagraphique");

    bool etat_pattern =false;
    bool etat_graphique =false;
    bool etat_forme =false;

    if(ext.compare("dataplot")==0)
    {
        etat_pattern=true;
        etat_graphique=true;
        etat_forme =true;
    }
    else if(ext.compare("datapattern")==0)
    {
        etat_pattern=true;
        etat_graphique=false;
        etat_forme =false;
    }
    else if(ext.compare("datagraphique")==0)
    {
        etat_pattern=false;
        etat_graphique=true;
        etat_forme =false;
    }
    else //ext.compare("dataforme")==0
    {
        etat_pattern=false;
        etat_graphique=false;
        etat_forme =true;
    }
    QFile file(fichier);
    if (file.open(QIODevice::WriteOnly))
    {
         qDebug() << "Open file "  << "\n";
        QDataStream out(&file);
        if(etat_graphique)
        {
            // type line
            out << Widget_Plot->Get_nb_line();
            for(int i=0;i<Widget_Plot->Get_nb_line();i++)
            {
                input=Widget_Plot->Get_Niveau(i);
                //qDebug() << input << "\n";
                out <<  input;//Widget_Plot->Get_Niveau(i);

                out <<  Widget_Plot->Get_SizePen(i);

                color=Widget_Plot->Get_Color(i);
                r=color.red();
                g=color.green();
                b=color.blue();

                qDebug() << "r=" << r  << " g=" << g  << " b=" << b  << "\n";
                out << r;
                out << g;
                out << b;

            }
        }
        if(etat_forme)
        {
            // circle
            out << Widget_Plot->Get_Circle_Nbface();
            out << Widget_Plot->Get_Circle_Size();

        }
        if(etat_pattern)
        {
            //Patterne
            nb_ligne=Widget_Patterne->Get_Nb_ligne();
            out << nb_ligne;
            for(int i=0;i<nb_ligne;i++)
            {
                input=int(Widget_Patterne->Get_l(i));
                //qDebug() << input << "\n";
                out <<  input;

                input=int(Widget_Patterne->Get_alpha(i));
                //qDebug() << input << "\n";
                out <<  input;

                input=Widget_Patterne->Get_CheckBox(i);
                //qDebug() << input << "\n";
                out <<  input;
            }

        }

        file.close();
        //QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
    }
}
void Main_fenetre::save()
{


    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "data plot (*.dataplot);;data pattern(*.datapattern);;data forme(*.dataforme);;data graphique(*.datagraphique)");

    if(!fichier.isEmpty())
        Save_file(fichier);

}
//patterneMenu
void Main_fenetre::Patterne_init()
{
    Widget_Patterne->Init();
    change_patterne();
}
void Main_fenetre::patterne_quatype2()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-90,50);
    pattern.Add(0,50);
    pattern.Add(90,50);
    pattern.Add(90,50);
    pattern.Add(0,50);
    pattern.Add(-90,50);
    pattern.Add(0,50);

    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);
}
void Main_fenetre::patterne_VonClassique()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-60,50);
    pattern.Add(60,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);
}
void Main_fenetre::patterne_Von90()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-45,50);
    pattern.Add(45,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);
}
void Main_fenetre::patterne_Von0()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-90,50);
    pattern.Add(90,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);
}
void Main_fenetre::patterne_toit60()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-60,50);
    pattern.Add(0,50);
    pattern.Add(60,50);
    pattern.Add(0,50);

    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);
}

//formeMenu
void Main_fenetre::Forme_init()
{
    Widget_Plot->Init_forme();
    //change_patterne();
}
void Main_fenetre::forme_triangle()
{
    Widget_Plot->Set_Circle_Nbface(3);
}
void Main_fenetre::forme_carre()
{
    Widget_Plot->Set_Circle_Nbface(4);
}
void Main_fenetre::forme_penthagone()
{
    Widget_Plot->Set_Circle_Nbface(6);
}


//plotMenu
void Main_fenetre::Plot_init()
{
    Widget_Plot->Init_graphique();
    change_patterne();
}
void Main_fenetre::Plot_N1toN4()
{
    Widget_Plot->Set_nb_line(4);

    Widget_Plot->Set_Niveau(0,1);
    Widget_Plot->Set_SizePen(0,60);
    Widget_Plot->Set_Color(0,Qt::blue);

    Widget_Plot->Set_Niveau(1,2);
    Widget_Plot->Set_SizePen(1,45);
    Widget_Plot->Set_Color(1,Qt::red);

    Widget_Plot->Set_Niveau(2,3);
    Widget_Plot->Set_SizePen(2,30);
    Widget_Plot->Set_Color(2,Qt::green);

    Widget_Plot->Set_Niveau(3,4);
    Widget_Plot->Set_SizePen(3,15);
    Widget_Plot->Set_Color(3,Qt::black);




}

//exemple Menu
//flocpn von sub menu
void Main_fenetre::flocon_Von0()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-90,50);
    pattern.Add(90,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);

    forme_triangle();

    Plot_N1toN4();
}
void Main_fenetre::flocon_Von30()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-75,50);
    pattern.Add(75,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);

    forme_triangle();

    Plot_N1toN4();
}
void Main_fenetre::flocon_Von60()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-60,50);
    pattern.Add(60,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);

    forme_triangle();

    Plot_N1toN4();
}
void Main_fenetre::flocon_Von90()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-45,50);
    pattern.Add(45,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);

    forme_triangle();

    Plot_N1toN4();
}
void Main_fenetre::flocon_Von120()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-30,50);
    pattern.Add(30,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);

    forme_triangle();

    Plot_N1toN4();
}
void Main_fenetre::flocon_Von150()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(-15,50);
    pattern.Add(15,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);

    forme_triangle();

    Plot_N1toN4();
}
void Main_fenetre::flocon_Von180()
{
    Patterne pattern;
    pattern.Add(0,50);
    pattern.Add(0,50);
    pattern.Add(0,50);
    pattern.Add(0,50);
    pattern.Calcul_Patterne();
    Widget_Patterne->Set_Patterne(pattern);

    forme_triangle();

    Plot_N1toN4();
}



//A propos
void Main_fenetre::Presentation_dev_Box()
{
   QMessageBox::about(this, "A propos du développeur",
                      "Développeur en C++, python, PHP et JavaScript, je suis passionné par la programmation et les mathématiques, notamment les fractales. Mes autres passions sont la photo et les panoramas à 360°.:\n" \
                      "Mes sites internet sont :\n" \
                      "> CV Mécatronique : http://www.renaud-henry.fr \n" \
                      "> Galerie photo : http://piwigo.rhenry.fr \n" \
                      "> Portfolio Photo : http://photo.rhenry.fr \n" \
                      "> Panoramas : http://pano.rhenry.fr \n" \
                      "> Visite virtuelle :  http://visite-virtuel.rhenry.fr");
}
void Main_fenetre::Presentation_prog_Box()
{
   QMessageBox::about(this, "A propos du programme",
                      "Nom du programme : Fractale plot \n" \
                      "Version : 1.1 \n" \
                      "Date : 30 juin 2016 \n" \
                      "Développeur : Renaud HENRY \n" \
                      "Site web : http://frataleplot.rhenry.fr (en cours de construction) \n" \
                      "Email : frataleplot@rhenry.fr");
}
void Main_fenetre::Aide_Box()
{
    if(TextBrowser->isHidden())
    {
        TextBrowser->show();
    }
    else
    {
        TextBrowser->hide();
    }
}
