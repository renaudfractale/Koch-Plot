#ifndef QWIDGET_GENERATOR_H
#define QWIDGET_GENERATOR_H

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
#include <QLabel>
class QWidget_generator : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_generator(QWidget *parent = 0);

    int Get_Nb_ligne();
    void Set_Nb_ligne(int nb_ligne);
private:
    QPushButton *PushButton_Genertor;
    QComboBox *ComboBox_Genertor;
    QLabel *Label_Genertor;

    QGridLayout *layout;
signals:
    void PushButton_Genertor_clicked();
public slots:
};

#endif // QWIDGET_GENERATOR_H
