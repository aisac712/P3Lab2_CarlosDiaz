#include <iostream>
//#include <string>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

void factorizar(double n){
    int primos[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 , 97};
    int primosUsados[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0};
    
    int temp = 1, i = 0;
    double disminuye=n;
    string salida = "";
    while(temp/n!=1){
        bool seguirConNumero = true;
        
        
        while(seguirConNumero==true){
            double p = disminuye/primos[i];
            
            //cout << primos[i] << endl;
            cout << "p=" << disminuye << "/" << primos[i];
            cout << p << endl;
            
            if(p == (int)p ){
                primosUsados[i] = primosUsados[i]+1;
                disminuye = disminuye / primos[i];
                temp = temp * primos[i];
                salida += std::to_string(primos[i]) + "*";
                //seguirConNumero = true;
                //cout << "el número es entero";
            } else{
                //cout << "el número NO es entero";
                i++;
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

//MAIN
int main(int argc, char** argv) {
    
    
    int op;
    while(op!=4){
        cout<<"          MENU"<<endl
        <<" 1. Teorema Fundamental de la Aritmética"<<endl
        <<" 2. Aproximar valor de euler a la x"<<endl
        <<" 3. Salir"<<endl
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

