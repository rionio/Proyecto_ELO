#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define EPSILON 1.0e-10
#define LIMIT 10e4

class polinomio
{
public:
    polinomio();
    polinomio(string fct);
    inline map<int, double> vectortomap(vector<double> polinomio);
    inline vector<double> maptovector(map<int, double> polinomio);
    inline map<int, double> derv(map<int, double> &polinomio);
    inline double evaluar(double x);
    inline double evaluar2(map<int, double> &polinomio, double x);
    inline double newton(map<int, double> &polinomio, map<int, double> &polinomio2,double x=200);
    inline map<int, double> div(map<int,double> &polinomio, double div);
    inline vector<double> horners();
    inline map<int, double> split(string s);
    vector<double> Vpoli,result;

private:

    map<int, double> Mpoli;

};

#endif // POLINOMIO_H
