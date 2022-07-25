# Polinomial Resolution
## Descripción: 
Este proyecto consta de un programa desarrollado en C++ que resuelva
polinomios de grado 10 y a su vez entregrando las soluciones que pueda encontrar con el metodo de newton-raphson y graficando a su vez el polinomio.

## Requisitos:
Para poder instalar y compilar el programa se necesitará clonar el repositorio en algunas
de las distribuciones de Linux(ubuntu,devian,mint,centOS,etc), en el caso de tener WSL para windows 10,
se necesitará instalar el compilador de C++ después de instarlar WSL.
Con la nueva actualizacion se necesitara instalar Qt con los kits Qt 5.15.2 MinGW 64bits o 32bits dependiendo de su computador.
[Qt](https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5).
[QCustomPlot](https://www.qcustomplot.com/index.php/download)

Para compilar el programa se necesitará estar en la dirección de la carpeta y en el directorio src
luego ejecute el siguiente comando en la terminal de linux
```g++ -o main main.cpp -Wall```
y para ejecutar el programa use
```./main ```
o hacer un makefile, que se necesitara instalar primero
```sudo apt-get install make ```
luego solo debera ejecutar el comado ``` make ``` en la carpeta del repositorio
y para ejecutarlo use ```./src/main ```

## Integrantes:
* Joaquín Abarca Rol: 202030519-6 Estudiante ing. Civil en Telemática
* Fernando Carrasco Rol: 202030542-0 Estudiante ing. Civil en Telemática
* Ricardo Díaz Rol: 202030510-2 Estudiante ing. Civil en Telemática

# LEANME
profesor, es posible que vea muchas issues terminadas, con el mismo nombre resulta que desconociamos 
el hecho de que las issues no se podian borrar, espero que lo considere



#### buenas prácticas:
* con guión o asterisco puedes hacer una itemización(markdown)
* que los commits sean concisos(tu cambias lo que vas a hacer), no a los cambios innecesarios
* todo se commitea ```git commit -m "mensaje"```
* **```** estas comillas(backsticks) son para escribir código 
```cpp
int main(){
    return 0;
}
```
* ```g++ -Wall -o2 main.cpp -o bin/main``` -o2 hace optimizaciones de código -o es el output que se debe guardar en la carpeta bin
* ejecutar main ./bin/main
* antes de empezar a trabajar **SIEMPRE HACER PULL** y también antes de hacer push
* si haces commit y te equivocaste usa ```git reset --soft HEAD~1```(deshace el último commit y deja los cambios staged)
* **IMPORTANTE** una vez hagas push no puede volver a atrás 
* que dos personas no trabajen en el mismo archivo en el mismo tiempo

# C O G I T O   E R G O   C O D E
