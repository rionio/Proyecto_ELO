#include "graficadora.h"
#include "ui_graficadora.h"
#include "qcustomplot.h"
#include "polinomio.h"
#include "polinomio.cpp"
#include <cstring>
#include <QtWidgets>

#define XMIN -10000.0
#define XMAX 10000.0
#define YMIN -10000.0
#define YMAX 10000.0

/*constructor de la clase graficadora
 * recibe como parametros un vector polinomio
 * aqui se setean configuraciones del grafico
 * como la linea del cero, la geometria del grafico
 * las etiquetas de los ejes, las interacciones con la rueda del raton
 * y la de arrastrar con el mouse, ademas de setear el polinomio como titulo del grafico
 * y graficar el polinomio
 *
*/

Graficadora::Graficadora(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Graficadora)
{
    ui->setupUi(this);
    QPalette pal = window()->palette();
    pal.setColor(QPalette::Window, QRgb(0xd6d6d6));
    pal.setColor(QPalette::WindowText, QRgb(0x121218));
    window()->setPalette(pal);

    ui->customPlot->setInteraction(QCP::iRangeDrag, true);
    ui->customPlot->setInteraction(QCP::iRangeZoom, true);

    //ui->customPlot->setGeometry(0,0,540,410);
    ui->customPlot->setFocus();

    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);

    ui->customPlot->xAxis->setTickLength(0);

    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);

    ui->customPlot->xAxis->grid()->setZeroLinePen(QPen(Qt::DashLine));
    ui->customPlot->yAxis->grid()->setZeroLinePen(QPen(Qt::DashLine));

    ui->customPlot->xAxis->setRange(-10.0,10.0);
    ui->customPlot->yAxis->setRange(-10.0,10.0);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->plotLayout()->insertRow(0);
    ui->customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->customPlot, "f[x]=", QFont("sans", 12, QFont::Bold)));//add the function as title
}
//destructor de la clase graficadora
Graficadora::~Graficadora()
{
    delete ui;
}
/* metodo de la clase graficadora
 * en este metodo en base al QVector
 * creamos un QString para ponerlo como titulo
 * siendo este titulo la forma del polinomio ingresado
*/

void Graficadora::initializer(string fct){
    poli = polinomio(fct);
    size=z;
    setString();
    ui->customPlot->plotLayout()->removeAt(0);
    ui->customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->customPlot, funcion, QFont("sans", 12, QFont::Bold)));//add the function as title


}
void Graficadora::setString(){

    QString cadena;
    cadena+=QString::fromStdString("f[x]=");
    for(int i = size ; i>=0;i--){
        if(poli.Vpoli[i]==0){
        }
        else if(i==0){
            if(poli.Vpoli[i]>0)
                cadena+= QString::fromStdString("+") + QVariant(poli.Vpoli[i]).toString();
            else
                cadena+= QVariant(poli.Vpoli[i]).toString();
        }
        else{
            if(i==size){
                if(poli.Vpoli[i]==1 || poli.Vpoli[i]==-1){
                    if(poli.Vpoli[i]==1){
                        cadena+=QString::fromStdString("x^") + QVariant(i).toString();
                    }
                    else{
                        cadena+=QString::fromStdString("-x^") + QVariant(i).toString();
                    }
                }
                else
                    cadena+=QVariant(poli.Vpoli[i]).toString() + QString::fromStdString("x^") + QVariant(i).toString();
               }
            else{
                if(poli.Vpoli[i]==1 || poli.Vpoli[i]==-1){
                    if(poli.Vpoli[i]==-1)
                        cadena+= QString::fromStdString("-x^") + QVariant(i).toString();
                    else
                        cadena+= QString::fromStdString("+x^") + QVariant(i).toString();
                }
                else if(poli.Vpoli[i]>0)
                    cadena+= QString::fromStdString("+") + QVariant(poli.Vpoli[i]).toString() + QString::fromStdString("x^") + QVariant(i).toString();
                else
                    cadena+= QVariant(poli.Vpoli[i]).toString() + QString::fromStdString("x^") + QVariant(i).toString();
            }
        }
    }
    funcion = cadena;
}
/*metodo de la clase graficadora
 * este metodo genera 3 vectores con los cuales graficaremos el polinomio
 * siendo x un vector llenado desde -XMIN hasta XMAX
 * y el vector y llenado al evaluar el vector x con el polinomio ingresado anteriormente,
 * ademas este metodo crea el grafico  y le da un estilo a la curva generada
 *
*/
void Graficadora::makePlot(){
    QVector<double> x(2*XMAX+1), y1(2*YMAX+1); // initialize with entries
    for (int i=0;i<2*XMAX+1;++i){
        x[i]= (XMIN+i)/10.0;
        y1[i] = poli.evaluar(x[i]);// let's plot a polinomic function
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y1);
    ui->customPlot->graph(0)->setPen(QPen(Qt::red));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);

    ui->customPlot->replot();
}

void Graficadora::on_pushButton_clicked()
{
    QString Qpoli = ui->input->text();
    string Spoli = Qpoli.toStdString();

    initializer(Spoli);


    Graficadora::makePlot();

    Rslt=" ";
    ui->Rsolu->appendPlainText(Rslt);


    for(double i:poli.result){
        if(i != 0)
            Rslt+=QVariant(floor(i*1000+0.5)/1000).toString()+QString::fromStdString("; ");
    }
    ui->Rsolu->appendPlainText(funcion);
    ui->Rsolu->appendPlainText(Rslt);

}

