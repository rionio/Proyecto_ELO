#include "graficadora.h"
#include "funciones.cpp"

#include <QApplication>

//el main esta enfocado en reunir los datos y generar la salida
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Graficadora w;
    a.setStyle("fusion");
    w.show();
    return a.exec();
}
