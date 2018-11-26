#ifndef MAIN_FENETRE_H
#define MAIN_FENETRE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSpinBox>
#include <QGridLayout>
#include <QtCore>
#include <QActionGroup>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QDataStream>
#include <QDebug>
#include <QProgressBar>
#include <QListWidget>
#include <QDateTime>
#include <QTextBrowser>
#include <QGroupBox>
#include <QRadioButton>


#include "qwidget_type_ligne.h"
#include "qwidget_edit_pas.h"
#include "qwidget_circle.h"
#include "qwidget_patterne.h"
#include "qwidget_plot.h"
#include "generator.h"


class Main_fenetre : public QMainWindow//QWidget
{
    Q_OBJECT
public:
    explicit Main_fenetre();//  QWidget *parent = 0);
    QWidget_Patterne *Widget_Patterne;
    QWidget_Plot *Widget_Plot;


public slots:

    void change_patterne();

private slots:

    void newFile();
    void open();
    void save();
    void save_svg();

    //patterneMenu
        void Patterne_init();
        void patterne_quatype2();
        void patterne_VonClassique();
        void patterne_Von90();
        void patterne_Von0();
        void patterne_toit60();

    //formeMenu
        void Forme_init();
        void forme_triangle();
        void forme_carre();
        void forme_penthagone();
    //plotMenu
        void Plot_init();
        void Plot_N1toN4();
    //exemple
        //flocon von
            void flocon_Von0();
            void flocon_Von30();
            void flocon_Von60();
            void flocon_Von90();
            void flocon_Von120();
            void flocon_Von150();
            void flocon_Von180();

    void Aide_Box();
    void Presentation_dev_Box();
    void Presentation_prog_Box();



private:
    void createActions();
    void createMenus();

    void Open_file(QString fichier);
    void Save_file(QString fichier);

    QMenu *fileMenu;
        QAction *newAct;
        QAction *openAct;
        QAction *saveAct;
        QAction *saveAct_SVG;

    QMenu *patterneMenu;
        QAction *patterne_init_Act;
        QAction *patterne_quatype2_Act;
        QAction *patterne_VonClassique_Act;
        QAction *patterne_Von90_Act;
        QAction *patterne_Von0_Act;
        QAction *patterne_toit60_Act;

    QMenu *formeMenu;
        QAction *forme_init_Act;
        QAction *forme_triangle_Act;
        QAction *forme_carre_Act;
        QAction *forme_penthagone_Act;

    QMenu *plotMenu;
        QAction *plot_init_Act;
        QAction *Plot_N1toN4_Act;
    QMenu *exempleMenu;
         QMenu *flocon_VonSubMenu;
             QAction *flocon_Von0_Act;
             QAction *flocon_Von30_Act;
             QAction *flocon_Von60_Act;
             QAction *flocon_Von90_Act;
             QAction *flocon_Von120_Act;
             QAction *flocon_Von150_Act;
             QAction *flocon_Von180_Act;

    QMenu *aproposMenu;
        QAction *presentation_dev_Act;
        QAction *presentation_prog_Act;
        QAction *aide_Act;


    QProgressBar *ProgressBar_Plot;
    QListWidget *listWidget;

    QTextBrowser *TextBrowser;

    QGroupBox *groupBox_Patterne;

    bool Is_update_current;

};

#endif // MAIN_FENETRE_H
