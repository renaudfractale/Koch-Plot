#ifndef QWIDGET_TYPE_LIGNE_H
#define QWIDGET_TYPE_LIGNE_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QColorDialog>
#include <QGridLayout>
#include <QGridLayout>
#include <QComboBox>
#include <QtMath>
#include <QDebug>

class QWidget_Type_Ligne : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_Type_Ligne(QWidget *parent = 0);
    int Get_niveau();
    int Get_pen();
    QColor Get_color();

    void Set_niveau(int Niv);
    void Set_pen(int Pen);
    void Set_color(QColor Color);


private:
    QPushButton *PushButton_color;
    QColor color;

    QComboBox *ComboBox_pen;
    QLabel *Label_pen;

    QComboBox *ComboBox_niv;
    QLabel *Label_niv;

    QGridLayout *layout;


signals:
    void value_changing();
public slots:
    void Button_color_clicked();
};

#endif // QWIDGET_TYPE_LIGNE_H
