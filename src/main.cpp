#include<iostream>
#include<math.h>
#include<vector>

#define EPSILON 1.0e-6 
#define LIMIT 10e5

using namespace std;

int n;
float x=100;


/* funcion de tipo vector double
 * esta funcion deriva un polinomio dado un vector
 * con los elementos del polinomio
 * siendo el los exponentes los indices del vector
 * y los coeficientes los elementos del vector
 * retornando el polinomio derivado
*/
vector<double> derv(vector<double> &polinomio){
    vector<double> polinomio2(n+1);
    for(int i=1; i <n+1;i++){
        if(polinomio[i]==0){
        }
        else{
            polinomio2[i-1]=polinomio[i]*i;
        } 
    }
    return polinomio2;
}

/*funcion del tipo double
 * esta funcion evalua el polinomio en un punto x
 * recibe como paramentros un vector con los elementos del polinomio
 * y el valor en el punto x a evaluar
 * retornando el x evaluado en el polinomio
*/
double evaluar(vector<double> &polinomio, double x){
    double g=0;
    for(int i=0;i<n+1;i++)
        g+=(double)polinomio[i]*pow(x,i);
    return g;
}

bool flag=false;

/*funcion del tipo double
 * esta funcion realiza el teorema de newton-raphson mediante iteraciones
 * hasta encontrar la solucion mas al polinomio ingresado
 * recibe como paramentros 2 vectores, uno del polinomio normal
 * y el otro el polinomio derivado, junto a una x para empezar la iteracion
 * retornando a si la solucion mas cercana
 * esta funcion tiene un limite de iteraciones y si no encuentra una solucion devuelve un valor falso
*/
double newton(vector<double> &polinomio, vector<double> &polinomio2,double x){
    double y, g, g1;
    int iter = 0;
    g = 0; g1 = 0;
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
vector<double> div(vector<double> &polinomio, double div) {
    vector<double> result(polinomio.size(), 0);
    for (int i = polinomio.size() - 2; i >= 0; --i)
        result[i] = result[i+1] * -div + polinomio[i+1];
    return result;
}

/*funcion del tipo vector double
 * esta funcion realiza el metodo de horner
 * la cual aplica el metodo de newton para encontrar una raiz cercana
 * y luego al encontrar la raiz divide el polinomio en esa raiz
 * luego repite hasta encontrar todas las raices
 * o hasta llegar a un limite de n
 *
*/
vector<double> factorizar(vector<double> polinomio, double x){
    vector<double> polinomioc(n+1),polinomioc2(n+1),result(n);
    double y;
    y=x;
    copy(polinomio.begin(),polinomio.end(),polinomioc.begin());
    for(int i=0; i<n;i++){
        polinomioc2=derv(polinomioc);
        y=newton(polinomioc,polinomioc2,y);
        if(flag){
            result[i]=y;
            polinomioc=div(polinomioc,-y);
        }
        else{
            result.resize(i);
            break;
        }
    }
    return result;
}

int main(){
    float k;
    cout<<"calculadora de polinomios"<<endl;
    cout<<"ingrese el numero del mayor exponente: "; 
	cin>>n;
    vector<double> polinomio(n+1),result(n+1);
    if(n>=1 && n<=10){
        cout<<"ingrese los datos que acompañan a las las Polinomiables, "; 
        cout<<"en caso de no existir ingrese el numero 0"<<endl;
        for(int i=n;i>=0;i--){
			if(i==0){
				cout<<"k: ";
				cin>>k;
				polinomio[i]=k;
			}
			else{
            	cout<<"x^"<<i<<": ";
            	cin>>polinomio[i];
			}
        }
    }
	else{
        cout<<"Lo sentimos, no resolvemos soluciones con un exponente mayor a 10, espera para proximas actualizaciones.\n";
    }
    result=factorizar(polinomio,x);
    cout<<"Las raices son: \n";
    if(result.size()==0)
        cout<<"No tiene raices reales\n";
    else{
        for (double i:result){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
