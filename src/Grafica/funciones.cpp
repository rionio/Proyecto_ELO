#include "graficadora.h"

static int z;

inline vector<double> maptovector(map<int, double> polinomio){
    map<int, double>::iterator iter;
    int max = 0 ;
    for(iter = polinomio.begin(); iter != polinomio.end(); iter++){
        if(max < iter->first)
            max = iter->first;
    }
    z=max;
    vector<double> poli(max+1,0);
    for(iter = polinomio.begin(); iter != polinomio.end(); iter++){
        poli[iter->first]=iter->second;
    }
    return poli;
}

inline map<int, double> vectortomap(vector<double> polinomio){
    map<int, double> poli;
    for(int i = 0; i < polinomio.size();i++){
        if(polinomio[i]==0){
        }
        else{
            poli[i]=polinomio[i];
        }
    }
    return poli;
}

/* funcion de tipo vector double
 * esta funcion deriva un polinomio dado un vector
 * con los elementos del polinomio
 * siendo el los exponentes los indices del vector
 * y los coeficientes los elementos del vector
 * retornando el polinomio derivado
*/
inline map<int, double> derv(map<int, double> &polinomio){
    map<int, double> polinomio2;
    map<int, double>::iterator iter;
    for(iter=polinomio.begin(); iter != polinomio.end();iter++){
        if(iter->first !=0)
            polinomio2[iter->first-1]=iter->second*iter->first;
    }
    return polinomio2;
}
/*funcion del tipo double
 * esta funcion evalua el polinomio en un punto x
 * recibe como paramentros un vector con los elementos del polinomio
 * y el valor en el punto x a evaluar
 * retornando el x evaluado en el polinomio
*/
inline double evaluar(map<int, double> &polinomio, double x){
    double g=0;
    map<int, double>::iterator iter;
    for(iter = polinomio.begin(); iter != polinomio.end(); iter++)
        g+=(double)iter->second*pow(x,iter->first);
    return g;
}

static bool flag=false;
/*funcion del tipo double
 * esta funcion realiza el teorema de newton-raphson mediante iteraciones
 * hasta encontrar la solucion mas al polinomio ingresado
 * recibe como paramentros 2 vectores, uno del polinomio normal
 * y el otro el polinomio derivado, junto a una x para empezar la iteracion
 * retornando a si la solucion mas cercana
 * esta funcion tiene un limite de iteraciones y si no encuentra una solucion devuelve un valor falso
*/
inline double newton(map<int, double> &polinomio, map<int, double> &polinomio2,double x=200){
    double y;
    int iter = 0;
    y=x;
    while(++iter < LIMIT){
        y -= (evaluar(polinomio,y)/evaluar(polinomio2,y));
        if(abs(evaluar(polinomio,y))<EPSILON)
            break;
    }
    flag = iter != LIMIT;
    return y;
}
/*funcion del tipo vector double
 * esta funcion divide un polinomio en base a una raiz mediante
 * la regla de ruffini
 * recibe como parametros el vector con los elementos del polinomio
 * y la raiz de este para dividir
 * retorna el polinomio dividido
*/
inline map<int, double> div(map<int,double> &polinomio, double div) {
    vector<double> polinomiocopy=maptovector(polinomio),result(polinomiocopy.size(), 0);
    for (int i = polinomiocopy.size() - 2; i >= 0; --i)
        result[i] = result[i+1] * -div + polinomiocopy[i+1];
    return vectortomap(result);
}
/*funcion del tipo vector double
 * esta funcion realiza el metodo de horner
 * la cual aplica el metodo de newton para encontrar una raiz cercana
 * y luego al encontrar la raiz divide el polinomio en esa raiz
 * luego repite hasta encontrar todas las raices
 * o hasta llegar a un limite de n
 *
*/
inline vector<double> horners(map<int, double> polinomio){
    vector<double> sizevector=maptovector(polinomio);
    int n=sizevector.size();
    map<int,double> polinomioc,polinomioc2;
    vector<double> result(n);
    double y;
    polinomioc=polinomio;
    for(int i=0; i<n;i++){
        polinomioc2=derv(polinomioc);
        y=newton(polinomioc,polinomioc2);
        if(flag){
            result[i]=y;
            polinomioc = div(polinomioc,-y);
        }
        else{
            result.resize(i);
            break;
        }
    }
    return result;
}

/*esta funcion del tipo int hace que el programa no se caiga
 * gracias stack overflow
 *
*/
inline int readInt()
{
    int r;
    while(true)
    {
        if(cin>>r)
            if(r>0)
             if(r>1 && r<=10)
                 return r;
        cout<<"ingresa un valor positivo que sea mayor a 1 y menor o iguala 10\n";
        cin.clear();
        cin.ignore(10000,'\n');

    }
}
/*esta funcion del tipo double
 * hace que el programa no se caiga
 * gracias stack overflow!!!
*/
inline double readdouble()
{
    double r;
    while(true)
    {
        if(cin>>r)
                 return r;
        cout<<"ingresa un valor real\n";
        cin.clear();
        cin.ignore(10000,'\n');

    }
}

inline map<int, double> split(string s){
    bool flag=false;
    map<int, double> polinomio;
    for (int i = 0; i < s.size(); i=0){
        string cat,cat2;
        if(i==0 && s[i]=='x'){
            cat2="1";
            s.erase(i,1);
        }
        else if(s[i]=='+' && s[i+1]=='x'){
            cat2='1';
            flag=true;
            s.erase(i,2);
        }
        else if(s[i]=='-' && s[i+1]=='x'){
            cat2="-1";
            flag=true;
            s.erase(i,2);
        }
        else if(isdigit(s[i]) || s[i]=='-' || s[i]=='+'){
            for (int j = i; j<2; j=i){
                if(isdigit(s[i]) || s[i]=='-' || s[i]=='+'){
                    cat2+=s[j];
                    s.erase(j,1);
                }
                else if(s[j]=='x' && s[j+1]!='^'){
                    s.erase(j,1);
                    flag=true;
                    break;
                }
                else if(s[j]=='x'){
                    s.erase(j,1);
                    break;
                }
                else{
                    break;
                }
            }
        }
        if(s[i]=='^'){
            s.erase(i,1);
            for (int j = i; j < 2; j=i){
                if(isdigit(s[j])){
                    cat+=s[j];
                    s.erase(j,1);
                }
                else{
                    break;
                }
            }
            polinomio[stoi(cat)]=stoi(cat2);
        }
        else if(flag){
            polinomio[1]=stoi(cat2);
            flag=false;
        }
        else{
            polinomio[0]=stoi(cat2);
        }

    }
    return polinomio;
}


