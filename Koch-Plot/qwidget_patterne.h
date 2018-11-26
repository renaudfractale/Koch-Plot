#ifndef QWIDGET_PATTERNE_H
#define QWIDGET_PATTERNE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QGraphicsView>
#include <QDebug>
#include <QDateTime>
#include <QListWidget>
#include <QComboBox>
#include <QGroupBox>

#include "patterne.h"
#include "qwidget_edit_pas.h"
#include "generator.h"
#include "qwidget_generator.h"

class QWidget_Patterne : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_Patterne(QWidget *parent = 0);
    Patterne Get_Patterne();
    void Init();

    int Get_Nb_ligne();
    void Set_Nb_Ligne(int Nb_ligne);

    double Get_l(int no_ligne);
    double Get_alpha(int no_ligne);

    void Set_l(int no_ligne, double l);
    void Set_alpha(int no_ligne, double alpha);

    int Get_CheckBox(int no_ligne);
    void Set_CheckBox(int no_ligne,int box);

    void Set_Patterne(Patterne patterne_loc);

    bool Get_Is_update_current();

    void Set_listWidget(QListWidget *ListWidget);
    void Add_text_listWidget(QString txt);
private:
    Patterne patterne;
    QWidget_Edit_pas *Tab_pas[30];
    QPushButton *Tab_Button_P[30];
    QPushButton *Tab_Button_M[30];
    QGraphicsView *GraphicsView;
    QGraphicsScene *scene;

    QGridLayout *layout_Zoom;
    QPushButton *PushButton_Zoom_P;
    QPushButton *PushButton_Zoom_M;

    QWidget_generator *Widget_generator;

    int size_tab ;
    int nb_pas;

    QVBoxLayout *layout;

    QList<double> List_Rotation;
    QList<double> List_Translation;

    void Update_layout();
    void Get_Config(int add,int remove);
    void Set_config();

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

    void Update_patterne();

    void Generate_Patterne();

    void Zoom_P();
    void Zoom_M();
};

#endif // QWIDGET_PATTERNE_H
