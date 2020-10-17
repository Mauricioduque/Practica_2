#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <practica2.h>
/*

*/

using namespace std;

int main()
{
    int num,dinero,longitud=0,resultado=0,len_A,len_B;
    int **puntero_matriz;
    long long int numero;
    int tam;
    char **matriz;
    char menu,fila;
    bool e,estrella;
    char *cadena1,*cadena2;
    char cadena[20],copia[20],rectA[8],rectB[8];
    int A[4] = {0,0,0,0}, B[4] = {0,0,0,0},x[4] = {0,0,0,0}, y[4] = {0,0,0,0};
    int posicion=0;
    //int conteo1 [94]={};
    //int conteo2 [94]={};
    float estrellas[6][8]={{0,3,4,0,0,0,6,8},
                          {5,13,6,0,0,0,2,3},
                          {2,6,2,7,3,0,10,0},
                          {0,0,4,15,4,1,6,0},
                          {0,0,7,12,6,9,10,4},
                          {5,0,6,10,6,4,8,0}};
    int permutacion[]={0,1,2,3,4,5,6,7,8,9};

    while (true) {
        cout << "Ingrese el numero del problema: ";
        cin >> num;
        switch(num){
            case 1:
                cout<<"Ingrese el monto de dinero: ";
                cin>>dinero;
                cantbilletes(dinero);
            break;
            case 2:
                conteoletras();
            break;
            case 3:
                e=true;
                cout<< "Ingrese la longitud de las cadenas: ";
                cin>>longitud;
                cadena1=new char[longitud];
                cadena2=new char[longitud];
                cout<< "Ingrese cadena 1: "<<endl;
                cin>>cadena1;
                cout<< "Ingrese cadena 2: "<<endl;
                cin>>cadena2;
                for(int n=0;n<longitud;n++) if(cadena1[n]!=cadena2[n]) e=false;
                if(e==false) cout<<"Las cadenas son diferentes"<<endl;
                else cout<<"Las cadenas son iguales"<<endl;
                delete [] cadena1;
                delete [] cadena2;
            break;
            case 4:
                cout<< "Ingrese la cadena: ";
                cin>>cadena;
                resultado=conversionentero(cadena);
                cout<<"El entero es : "<<resultado<<endl;
            break;
            case 5:
                cout<< "Ingrese el entero: ";
                cin>>numero;
                tam=tamano(numero);
                cadena1=new char[tam+1];
                convacadena(cadena1,numero,tam);
                cout <<"La cadena de caracteres es: "<< cadena1 << endl;
                delete[] cadena1;
            break;
            case 6:
                cout<<"Ingrese el tamano de la cadena: ";
                cin>>longitud;
                cadena1=new char [longitud+1];
                cout<<"Ingrese los caracteres: ";
                for(int i=0; i<longitud;i++) cin>>cadena1[i];
                cout <<"Original: "<<cadena1<<endl;
                minamayus(cadena1);
                cout<<"En mayuscula: "<<cadena1<<endl;
                delete[] cadena1;
            break;
            case 7:
                cout<<"Ingrese la cadena:";
                cin>>cadena;
                num=0;
                for(int i=0;cadena[i]!='\0';i++){
                    copia[i]=cadena[i];
                    num++;
                }
                copia[num]='\0';
                cout<<"La cadena original es: ";
                for(int j=0;copia[j]!='\0';j++) cout<<copia[j];
                cout<<endl;
                cout<<"La cadena sin repetidos es: ";
                eliminarcaracteres(cadena,num);
            break;
            case 8:
                cout<<"Ingrese el tamano de la cadena: ";
                cin>>longitud;
                cadena1=new char [longitud+1];
                cout<<"Ingrese los caracteres: ";
                for(int i=0; i<longitud;i++) cin>>cadena1[i];
                cout <<"Original: "<<cadena1<<endl;
                separarnum(cadena1,longitud);
                delete [] cadena1;
            break;
            case 9:
                 cout<<"Ingrese el tamano de la cadena: ";
                 cin>>longitud;
                 cout<< "Ingrese el valor de n: ";
                 cin>>num;
                 cadena1=new char [longitud+1];
                 cout<<"Ingrese los caracteres numericos: ";
                 for(int i=0; i<longitud;i++) cin>>cadena1[i];
                 cadena1[longitud]='\0';
                 cout <<"Original: "<<cadena1<<endl;
                 agrupar(cadena1,num,longitud);
                 delete [] cadena1;
            break;
            case 10:
                cout<<"Ingrese numero romano:";
                cin>>cadena;
                cout<<"El numero ingresado fue: "<<cadena<<endl;
                numromanos(cadena);
            break;
            case 11:
            matriz= new char *[15+1];
            for(int i=0; i<20; i++){
               matriz[i]= new char[20+1];
            }
            construirsala(matriz);
            menu=0;
            while(menu!='S'){
                cout<<"Ingrese R-para reservar, C-para cancelar o S-para salir: ";
                cin>>menu;
                if(menu=='R'){
                    cout<<"Ingrese la fila que desea reservar(letras A-O): ";
                    cin>>fila;
                    cout<<"Ingrese el # de asiento que desea reservar(# 1-20): ";
                    cin>>num;
                    reservar(matriz,fila,num);
                }
                else if(menu=='C'){
                    cout<<"Ingrese la fila que desea cancelar(letras A-O): ";
                    cin>>fila;
                    cout<<"Ingrese el # de asiento que desea cancelar(# 1-20): ";
                    cin>>num;
                    cancelar(matriz,fila,num);
                }

            }
            break;
            case 12:
            cout<<"Ingrese la dimension n de la matriz cuadrada: ";
            cin>>num;
            puntero_matriz= new int *[num];
            for(int i=0; i<num; i++){
                puntero_matriz[i]= new int[num];
            }
            pedirDatos(puntero_matriz,num);
            mostrarMatriz(puntero_matriz,num);
            cuadradomagico(puntero_matriz, num);
            for(int i=0; i < num; i++){
                delete [] puntero_matriz[i];
            }
            delete [] puntero_matriz; // borrar memoria dinamica
            break;
            case 13:
                num=0;
                for(int fila=1;fila<5;fila++){
                    for(int col=1;col<7;col++){
                      estrella=cheqestrella(*(*(estrellas+fila)+col),*(*(estrellas+fila)+col-1),*(*(estrellas+fila)+col+1),*(*(estrellas+fila-1)+col),*(*(estrellas+fila+1)+col));
                      if (estrella==true) num++;
                    }
                }
                cout<< "El numero de estrellas encontradas fue: "<< num<<endl;
            break;
            case 14:
                cout<< "Matriz 5x5 "<<endl;
                matriz5x5();
            break;
            case 15:
            cout << "Ingrese las coordenadas del rect  A (x,y,ancho,altura) presione enter para ingresar cada una: ";
            for(int i=0;i<4;i++) cin>>A[i];
            cout << "Ingrese las coordenadas del rect  B (x,y,ancho,altura) presione enter para ingresar cada una: ";
            for(int i=0;i<4;i++) cin>>B[i];
            if(A[0]<B[0]){
                x[0]=A[0];
                x[1]=A[2]+A[0];//x={x11,x12,x21,x22}
                x[2]=B[0];
                x[3]=B[2]+B[0];
            }
            else{
                x[0]=B[0];
                x[1]=B[2]+B[0];//x={x11,x12,x21,x22}
                x[2]=A[0];
                x[3]=A[2]+A[0];
            }
            if(A[1]<B[1]){
                y[0]=A[1];
                y[1]=A[3]+A[1];//x={x11,x12,x21,x22}
                y[2]=B[1];
                y[3]=B[3]+B[1];
            }
            else{
                y[0]=B[1];
                y[1]=B[3]+B[1];//y={y11,y12,y21,y22}
                y[2]=A[1];
                y[3]=A[3]+A[1];
            }
            //x={x11,x12,x21,x22}
            if(x[2]>x[1] || y[2]>y[1]) cout<<"No hay interesccion";
            else if(x[1]<x[3] && y[1]<y[3]) cout<<" "<<x[2]<<","<<y[2]<<","<<x[1]-x[2]<<","<<y[1]-y[2];
            else cout<<x[2]<<","<<y[2]<<","<<x[3]-x[2]<<","<<y[3]-y[2];
            break;
            case 16:
                cout<<"Ingrese la dimension n de la cuadricula cuadrada: ";
                cin>>num;
                caminos(num);
            break;
            case 17:
                cout<<"Ingrese el numero: ";
                cin>>num;
                resultado=0;
                while(num>0){
                    if(checkamigable(num)==true){
                        resultado+=num;
                    }
                    num--;
                }
                cout<<"La suma es: "<<resultado<<endl;
            break;
            case 18:
                cout<<"Ingrese el numero: ";
                cin>>num;
                for (int i=0;i<=num;i++){
                    next_permutation(permutacion, permutacion+10);
                }
                cout<<"La permutacion numero "<<num<<" es: ";
                for(int j=0;j<10;j++){
                    cout<<permutacion[j];
                }
                cout<<'\n';
            break;
        }
    }
  return 0;
}


