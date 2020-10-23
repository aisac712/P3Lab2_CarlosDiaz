#include <iostream>
//#include <string>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

//PRIMER EJERCICIO
void factorizar(double n){
    int primos[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 , 97};
    int primosUsados[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0};
    
    int temp = 1, i = 0;                                            //temp es la multiplicación de todos los números primos que forman a n
    double disminuye=n;
    string salida = "";
    while(temp/n!=1){                                               //mientras sean distintos es lo mismo que decir mientras su cociente sea dif a 1
        bool seguirConNumero = true;
        
        
        while(seguirConNumero==true){
            double p = disminuye/primos[i];
            
            //cout << primos[i] << endl;
            //cout << "p=" << disminuye << "/" << primos[i];
            //cout << p << endl;
            
            if(p == (int)p ){                                       //si el número es entero, se sigue dividiendo con ese mismo prmo
                primosUsados[i] = primosUsados[i]+1;
                disminuye = disminuye / primos[i];
                temp = temp * primos[i];
                salida += std::to_string(primos[i]) + "*";
                //seguirConNumero = true;
                //cout << "el número es entero";
            } else{                                                 //si el número resulta decimal, entonces no es con ese primo y...
                //cout << "el número NO es entero";
                i++;                                                //...se procede a calcularlo con el número siguiente
                seguirConNumero = false;
            }
        }
        
        
        //seguirConNumero = true;
    }
    salida += "1";
    
    cout << salida << endl;
    
    string salida2 = "";
    for(int i=0; i<25; i++){
        if(primosUsados[i]!=0){
            salida2 += std::to_string(primos[i]) + "^" + std::to_string(primosUsados[i]) + " * ";
        }
    }
    salida2+="1";
    cout << salida2 << endl;
    
}

//SEGUNDO EJERCICIO
double exponencial(double x, double n){
    //double r=0;                                      //resultado
    if(n==0){
        return 1;
    } else {
        return x * exponencial(x, n-1);
    }
}

double factorial(double n){
    //double r=0;                                      //resultado
    if(n==0 || n==1){
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

void funcionExponencial(double lim, double x){
    double sum = 0;
    cout << lim << " " << x << endl;
    
    for(int n=0; n<=lim; n++){
        double num = exponencial(x, n);
        double denom = factorial(n);
        //cout << num << "/" << denom;
        sum += num/denom;
    }
    cout << "Resultado: " << sum << endl;
}

//TEERCER EJERCICIO
void triangular(int n){
    for (int i=1; i<=n; i++){
        int fila[i];
        
        //para rellenar de prueba
        /*if(i==1 || i==2){
            for (int j=0; j<i; j++){
                fila[j] = 1;
            }
        } else {
            for (int j=0; j<i; j++){
                if(j==1 || j==(i-1)){
                    fila[j] = 1;
                }
                if(j==2 || j==(i-2)){
                    fila[j] = i+1;
                }
            }
        }*/
        //para rellenar
        for (int j=0; j<i; j++){
            fila[j] = 1;
        }
        
        //para imprimir
        for (int j=0; j<i; j++){
            cout << fila[j] << " ";
        }
        cout << "" << endl;
    }
}


//MAIN
int main(int argc, char** argv) {
    
    
    int op;
    while(op!=4){
        cout<<"          MENU"<<endl
        <<" 1. Teorema Fundamental de la Aritmética"<<endl
        <<" 2. Aproximar valor de euler a la x"<<endl
        <<" 3. Triángulo de Pascal"<<endl
        <<" 4. Salir"<<endl
        <<"Ingrese una opción: ";

        cin >> op; 
        while(op < 1 || op > 4){
            cout << " Opción incorrecta, intentá de nuevo: ";
            cin >> op;
        }
        switch(op){
            case 1: {
                double n;
                cout << "Ingresa n para factorizar: ";
                cin  >> n;
                while(n<=0){
                    cout << "Ingresa n (mayor a cero) para factorizar: ";
                    cin  >> n;
                }
                factorizar(n);
                
                break;
            } case 2: {
                double x;
                cout << "Ingresa x para hacer el cálculo: ";
                cin  >> x;
                
                funcionExponencial(30, x);
                break;
            } case 3: {
                int n;
                cout << "Ingresa la cantidad de filas n: ";
                cin  >> n;
                
                triangular(n);
                break;
            } case 4 : {
                cout << "Nos vemos" << endl;
                break;
            }
        }
        cout << "" << endl;
    }
    
    return 0;
}

