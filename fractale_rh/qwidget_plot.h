#ifndef QWIDGET_PLOT_H
#define QWIDGET_PLOT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QGraphicsView>
#include <QProgressBar>
#include <QDateTime>
#include <QListWidget>
#include <QGroupBox>

#include "qwidget_circle.h"
#include "qwidget_type_ligne.h"
#include "patterne.h"
#include "svg.h"
#include "circle.h"

class QWidget_Plot : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_Plot(QWidget *parent = 0);

    void Set_patterne( Patterne patterne_loc);
    void Init_forme();
    void Init_graphique();

    Circle Get_Circle();
    int Get_nb_line();
    void Set_nb_line(int nb_line);
    int Get_Niveau(int no_line);
    int Get_SizePen(int no_line);

    void Set_Niveau(int no_line, int niv);
    void Set_SizePen(int no_line, int SizePen);

    int Get_Circle_Nbface();
    int Get_Circle_Size();

    void Set_Circle_Nbface(int nbface);
    void Set_Circle_Size(int Size);

    QColor Get_Color(int no_line);
    void Set_Color(int no_line,QColor color);

    void Save_As_SVG(QString namefile);

    void Set_ProgressBar(QProgressBar *progressBar);

    void Set_listWidget(QListWidget *ListWidget);
    void Add_text_listWidget(QString txt);

private:
    void Update_layout();

    void Get_Config(int add,int remove);
    void Set_config();

    //QWidget_Type_Ligne *Tab_ligne[30];
    QWidget_Circle *Widget_Circle ;
    QPushButton *Tab_Button_P[30];
    QPushButton *Tab_Button_M[30];

    QWidget_Type_Ligne *Tab_ligne[30];
    QGridLayout *layout_Zoom;
    QPushButton *PushButton_Zoom_P;
    QPushButton *PushButton_Zoom_M;


    QColor Tab_Color[30];
    int Tab_Niveau[30];
    int Tab_SizePen[30];


    QVBoxLayout *layout;

    QGraphicsView *GraphicsView;
    QGraphicsScene *scene;

    int size_tab ;
    int nb_pas;
    int min_pas;
    int max_pas;

    Patterne patterne;
    SVG svg;
    Circle circle;

    QProgressBar *ProgressBar;
    bool Is_update_current;

    QListWidget *ListWidget;

signals:
    void value_changing();
public slots:
    void Add_ligne_01();
    void Add_ligne_02();
    void Add_ligne_03();
    void Add_ligne_04();
    void Add_ligne_05();
    void Add_ligne_06();
    void Add_ligne_07();
    void Add_ligne_08();
    void Add_ligne_09();
    void Add_ligne_10();
    void Add_ligne_11();
    void Add_ligne_12();
    void Add_ligne_13();
    void Add_ligne_14();
    void Add_ligne_15();
    void Add_ligne_16();
    void Add_ligne_17();
    void Add_ligne_18();


    void Remove_ligne_01();
    void Remove_ligne_02();
    void Remove_ligne_03();
    void Remove_ligne_04();
    void Remove_ligne_05();
    void Remove_ligne_06();
    void Remove_ligne_07();
    void Remove_ligne_08();
    void Remove_ligne_09();
    void Remove_ligne_10();
    void Remove_ligne_11();
    void Remove_ligne_12();
    void Remove_ligne_13();
    void Remove_ligne_14();
    void Remove_ligne_15();
    void Remove_ligne_16();
    void Remove_ligne_17();
    void Remove_ligne_18();
    void Remove_ligne_19();

    void plot_fractal();

    void Zoom_P();
    void Zoom_M();

};

#endif // QWIDGET_PLOT_H
