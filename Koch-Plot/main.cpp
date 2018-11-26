
#include <QApplication>

#include "main_fenetre.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Main_fenetre *fenetre_ok=new Main_fenetre();
    fenetre_ok->show();
    return a.exec();
}
