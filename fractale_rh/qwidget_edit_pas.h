#ifndef QWIDGET_EDIT_PAS_H
#define QWIDGET_EDIT_PAS_H


#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtCore>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>

class QWidget_Edit_pas : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_Edit_pas(QWidget *parent = 0);
    double Get_l();
    double Get_alpha();
    void  Set_l(double l);
    void Set_alpha(double alpha);
    void Sans_Label();
    void Avec_Lbel();

    int Get_CheckBox();
    void Set_CheckBox(int box);
private:
        QDoubleSpinBox *DoubleSpinBox_alpha;
        QDoubleSpinBox *DoubleSpinBox_l;
        QDoubleSpinBox *DoubleSpinBox_h;
        QDoubleSpinBox *DoubleSpinBox_v;

        QCheckBox *CheckBox_alpha;
        QCheckBox *CheckBox_h;
        QCheckBox *CheckBox_v;

        QLabel *Label_alpha;
        QLabel *Label_l;
        QLabel *Label_h;
        QLabel *Label_v;


        QGridLayout *layout;

signals:
    void value_changing();
public slots:

        void CheckBox_alpha_update( );
        void CheckBox_h_update( );
        void CheckBox_v_update( );
        void update_value();

};

#endif // QWIDGET_EDIT_PAS_H
