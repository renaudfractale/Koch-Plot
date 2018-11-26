#ifndef SVG_H
#define SVG_H
#include "patterne.h"
#include "frame.h"
#include "circle.h"
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>
#include <QBrush>
#include <QDebug>
#include <QProgressBar>

class SVG
{
public:
    void Init(QGraphicsScene *scene,Circle circle, Patterne patterne);
    void Clear();
    void Draw(QColor Color, int niveau_max,int sizePen);
    double Get_x_fin();
    void trace_line();

    double Get_Xmax();
    double Get_Xmin();
    double Get_Ymax();
    double Get_Ymin();

    void File_Open(QString namefile);
    void File_Draw(QColor Color, int niveau_max,int sizePen);
    void File_Draw_line();
    void File_Close();

    void Set_ProgressBar(QProgressBar *progressBar);
private:
    QGraphicsScene *scene;
    Circle circle;
    Patterne patterne;
    Frame frame;
    int niveau_max;
    int niveau;

    QColor Color;
    int sizePen;

    double X_max;
    double Y_max;
    double X_min;
    double Y_min;

    QString name_file;


    QProgressBar *ProgressBar;
    long current_nb_ligne;
    long nb_ligne;

};

#endif // SVG_H
