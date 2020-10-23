#include <iostream>
//#include <string>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

void factorizar(double n){
    int primos[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 , 97};
    
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
    
    cout << salida << endl;
    
}
int main(int argc, char** argv) {
    
    
    int op;
    while(op!=3){
        cout<<"          MENU"<<endl
        <<" 1. Teorema Fundamental de la Aritmética"<<endl
        <<" 2. Aproximar valor de pi con n"<<endl
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
                double lim;
                cout << "Ingresa lim para hacer el cálculo: ";
                cin  >> lim;
                
                
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

