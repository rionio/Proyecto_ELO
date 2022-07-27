#ifndef GRAFICADORA_H
#define GRAFICADORA_H
#ifdef QT_NO_DEBUG_OUTPUT
#undef QT_NO_DEBUG_OUTPUT
#endif

#include <QMainWindow>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string>

#include "polinomio.h"

#include <QGroupBox>


using namespace std;

#define EPSILON 1.0e-10
#define LIMIT 10e4

QT_BEGIN_NAMESPACE
namespace Ui { class Graficadora; }
QT_END_NAMESPACE

class Graficadora : public QMainWindow
{
    Q_OBJECT

public:
    Graficadora(QWidget *parent = nullptr);
    ~Graficadora();
    void initializer(string fct);
    void setString();
    QString funcion;
    int size;



private slots:
    void makePlot();
    void on_pushButton_clicked();

private:
    polinomio poli;
    QVector<double> Resultados;
    Ui::Graficadora *ui;
    QString Rslt;

};


#endif // GRAFICADORA_H
