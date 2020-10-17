#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <practica2.h>


using namespace std;

void cantbilletes(int a){
    int billetes[]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    int conteo[9]={}; //arreglo que lleva el conteo de cada billete y moneda
    for(int i=0;i<10;i++){
        if(billetes[i]<=a){
            int resultado=a/billetes[i]; // verifica la cantidad de billetes o monedas e cada uno
            conteo[i]=resultado;        // se llena el arreglo conteo
            a=a%billetes[i];           // actualiza el monto ingresado
        }
    }
    for(int i=0; i<10;i++) cout<<billetes[i]<<": "<<conteo[i]<<endl; // imprime la cantida de cada billete y moneda
    cout<< "El faltantes es: "<<a<<endl;
}
void conteoletras(){
    int cont=0;
    char arrletra [199]={}; //arreglo aleatorio que va contener de las letras
    int conteo [26]={};    // arreglo que va contar cada una de las letras
    char letras[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int i=0;i<200;i++){  // generación de arreglo aleatorio e impresion
        arrletra[i]=letras[rand()%26];
        cout<<arrletra[i];
    }
    cout<<endl;
    for(int x=65,z=0;x<=90;x++){  // ciclo anidado que recorre cada una de las letras y lleva su cuenta
        for(int j=0; j<200;j++){
            if(arrletra[j]==x) cont=cont+1;
        }
        conteo[z]=cont;
        z++;
        cont=0;      // se actualiza el contador para pasar a una siguiente letra
    }
    for(int i=0; i<26;i++) cout<<letras[i]<<" : "<<conteo[i]<<endl; // impresion del abecedario con la cantidad de letras segun el arreglo
}


void conteocaracteres(int lon, char a[], int conteo[]){
    int cont=0;
    for(int x=32,z=0;x<=126;x++){  // ciclo anidado que recorre cadena y lleva la cuenta de los caracteres
        for(int j=0; j<lon;j++){
            if(a[j]==x) cont=cont+1;
        }
            conteo[z]=cont;
            z++;
            cont=0;
        }
}

int conversionentero(char cadena[]){
    int num=0;
    int resultado=0;
    for(int i=0;cadena[i]!='\0';i++) num++; // ciclo que determina la lngitud de la cadean
    for (int n=num,z=1;n>0;n--,z=z*10){    //ciclo que convierte las posciones de la cadena en entero
        resultado=resultado+(cadena[n-1]-48)*z;
    }
    return resultado;
}

void convacadena(char * cad, long long int n, int tam){
    int i=0;
    for(;n!=0;n/=10,i++) cad[tam-1-i]=char(n%10+48); // convierte un caracter en numero
    cad[tam]='\0';
}

int tamano(long long int n){ // funcion que realiza el conteo de caracteres
    int cont=0;
    for(;n!=0;cont++) n/=10;
    return cont;
}

void minamayus(char *a){ // convertir una cadena de minusculas a mayusculas
    for(int i=0; a[i]!='\0';i++){
        if (a[i]>=97 && a[i]<=122) a[i]=a[i]-32;
    }
}

void separarnum(char *a, int tamano){
    char *num=new char[tamano+1];
    char *car=new char[tamano+1];
    int j=0,k=0;
    for (int i=0; i<tamano;i++){
        if (a[i]>=48 && a[i]<=57) {
            num[j]=a[i];
            j++;
        }
        else { car[k]=a[i];
            k++;
        }
    }
    num[j]='\0';
    car[k]='\0';
    cout<<"Texto : "<<car<<endl;
    cout<<"Numero : "<<num<<endl;
    delete [] num;
    delete [] car;
}

void eliminarcaracteres(char a[],int num){
    char letra;
    for (int i=0;i<num;i++){
        letra=a[i];
        for (int k=i+1;k<=num;k++){
            if (a[k]!=' '){
                if (a[k]==letra) a[k]=' ';
            }
        }
        if(a[i]!=' ') cout<<a[i];
    }
    cout<<endl;
}

void agrupar(char *a, int n,int l){
    int resultado=0;
    int t=0,k=0;
    for (int i=0;i<l%n; i++){
        t=t*10+(a[k++]-'0');
    }
    resultado+=t;
    t=0;
    for (int j=l%n,i=0;a[k]!='\0';j+=n){
        t=t*10+(a[k++]-'0');
        i++;
        if(i==n){
            resultado+=t;
            i=0,t=0;
        }
    }
    resultado+=t;
    cout<<"La suma es: "<<resultado<<endl;
}

void construirsala(char **matriz){
    for(int fil=0;fil<15;fil++){
        for(int col=0; col<20; col++){
            *(*(matriz+fil)+col)='-';
            cout<<*(*(matriz+fil)+col)<<" ";
        }
        cout<<endl;
    }
}

void reservar(char **matriz,char fil,int num){
    char filas [15] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79};
    int columnas[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(int i = 0; i < 15 ; i++){//Recorre fila.
        for(int j = 0; j < 20; j++){//Recorre columna.
            if(fil == *(filas+i) && num == *(columnas+j)){//Coordenada.
                *(*(matriz+i)+j) = 43;//Agrega + de reserva.
                cout << *(*(matriz+i)+j)<<" ";//Imprime.
            }
            else{
                cout << *(*(matriz+i)+j)<<" ";//Imprime.
            }

        }
        cout<<endl;
    }
}

void cancelar(char **matriz,char fil,int num){
    char filas [15] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79};
    int columnas[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(int i = 0; i < 15 ; i++){//Recorre fila.
        for(int j = 0; j < 20; j++){//Recorre columna.
            if(fil == *(filas+i) && num == *(columnas+j)){//Coordenada.
                *(*(matriz+i)+j) = 45;//Agrega - de reserva.
                cout << *(*(matriz+i)+j)<<" ";//Imprime.
            }
            else{
                cout << *(*(matriz+i)+j)<<" ";//Imprime.
            }

        }
        cout<<endl;
    }
}

void numromanos(char a[]){
  //  int *romano=new int [t];
    int romano[15]={};
    int resultado=0;
    for(int i=0;a[i]!='\0';i++){
        if(a[i]=='M') romano[i] =1000; //M
        else if(a[i]=='D')romano[i]=500;//D
        else if(a[i]=='C')romano[i]=100; //C
        else if(a[i]=='L')romano[i]=50; //L
        else if(a[i]=='X')romano[i]=10; //X
        else if(a[i]=='V')romano[i]=5; //V
        else if(a[i]=='I')romano[i]=1; //I
        else cout<<"No es numero romano.";
    }
    resultado=romano[0];
    for(int i=0;a[i]!='\0';i++){
        if(romano[i]>=romano[i+1]) resultado=resultado+romano[i+1];
        else resultado= romano[i+1]-resultado;

    }
    cout<<"Que corresponde a: "<<resultado<<endl;
}


bool cheqestrella(int a, int b, int c, int d, int e){
    if ( float(a+b+c+d+e)/float(5) > 6.0) return true;
    else return false;
}

void pedirDatos(int **puntero_matriz,int n){
    cout<< "Digite los elementos de la matriz"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"digite un numero ["<<i<<"]["<<j<<"]: ";
            cin>> *(*(puntero_matriz+i)+j);
        }
    }
}

void intercepto(int x[],int y[]){
    //x={x11,x12,x21,x22}
    if(x[2]>x[1] || y[2]>y[1]) cout<<"No hay interesccion";
    else if(x[1]<x[3]) cout<<" "<<x[2]<<","<<x[1]-x[2];
    else cout<<" "<<x[2]<<","<<x[3]-x[2];

    if(y[1]<y[3]) cout<<","<<y[2]<<","<<y[1]-y[2];
    else cout<<" "<<y[2]<<","<<y[3]-y[2];

}

void mostrarMatriz(int**puntero_matriz,int n){
    cout<<"Imprimiendo la matriz"<<endl;
     for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
              cout<<*(*(puntero_matriz+i)+j)<<" ";
          }
          cout<<"\n";
     }
}

void cuadradomagico(int **a, int n){
    int aux=0, resultado=0,resultado2=0;
    bool magicofil=false,magicocol=false,magicodia=false;
    //verifico filas
    for (int fil=0; fil<n;fil++){
        resultado=aux;
        aux=0;
        for (int col=0; col<n;col++) aux=aux+*(*(a+fil)+col);
        if(resultado==aux) magicofil=true;
    }
    resultado=0;
    //verifico columnas
    for (int col=0; col<n;col++){
        resultado=aux;
        aux=0;
        for (int fil=0; fil<n;fil++) aux=aux+*(*(a+col)+fil);
        if(resultado==aux) magicocol=true;
    }
    resultado=0;
    //verifico diagonales
    for (int col=0; col<n;col++){ // suma de la diagonal 1
        aux=0;
        for (int fil=0; fil<n;fil++){
            if (fil==col){
                aux=aux+*(*(a+col)+fil);
                resultado+=aux;
            }
        }
    }
    for (int col=n-1,fil=0;col>=0 && fil<n ;col--,fil++){ //suma de la diagonal 2
        aux=0;
        aux=aux+*(*(a+col)+fil);
        resultado2+=aux;
                }
    if (resultado==resultado2) magicodia=true; // se compara si las diagonales son iguales

    if(magicocol==true && magicofil==true && magicodia==true) cout<<"Es un cuadrado magico"<<endl;
    else cout<<"No es cuadrado magico"<<endl;
}

void caminos(int n){
    int numerador=1,denominador=1,resultado;
    int num=n*2;
    for(int i=1;i<=num;i++) numerador=numerador*i;
    for(int i=1;i<=n;i++) denominador=denominador*i;
    resultado=numerador/(denominador*denominador);
    cout<<"En la malla de "<<n<<"x"<<n<<" puntos hay "<<resultado<<" caminos"<<endl;
}

void matriz5x5(){
    int k=1;
    int **puntero_matriz= new int *[5];
    for(int i=0; i<5; i++) puntero_matriz[i]= new int[5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) *(*(puntero_matriz+i)+j)=k++;
    }
    for(int i=0; i<5; i++){   // recorre filas
         for(int j=0; j<5; j++){
             if (i<2) cout<<*(*(puntero_matriz+i)+j)<<"  ";
             else cout<<*(*(puntero_matriz+i)+j)<<" ";
         }
         cout<<"\n";
    }
    cout<<endl;
    cout<<"Matriz rotada 90 grados"<<endl;
    for(int j=0; j<5; j++){
         for(int i=4; i>=0; i--){
              cout<<*(*(puntero_matriz+i)+j)<<" ";
         }
         cout<<"\n";
    }
    cout<<endl;
    cout<<"Matriz rotada 180 grados"<<endl;
    for(int i=4; i>=0; i--){
         for(int j=4; j>=0; j--){
              if (i<2) cout<<*(*(puntero_matriz+i)+j)<<"  ";
              else cout<<*(*(puntero_matriz+i)+j)<<" ";
         }
         cout<<"\n";
    }

    cout<<endl;
    cout<<"Matriz rotada 270 grados"<<endl;
    for(int j=4; j>=0; j--){
         for(int i=0; i<5; i++){
            cout<<*(*(puntero_matriz+i)+j)<<" ";

         }
         cout<<"\n";
    }
    for(int i=0; i < 5; i++){
        delete [] puntero_matriz[i];
    }
    delete [] puntero_matriz; // borrar memoria dinamica
}


bool checkamigable (int a){
    bool ban=false;
    int b;
    b=sumadiv(a);
    if (sumadiv(b)== a && sumadiv(a)==b) ban=true;
    return ban;

}

int sumadiv(int a){
    int suma = 0;
    for (int i = 1; i < a; i++){//Recorre el numero a.
        if (a % i == 0){//Si a modulo i es 0
            suma = suma + i;//Es divisor y se suma.
        }
    }
    return suma;//Retorna la suma.
}
