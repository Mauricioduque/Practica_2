#ifndef PRACTICA2_H
#define PRACTICA2_H
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void cantbilletes(int a);
void conteoletras();
void conteocaracteres(int lon, char a[] , int conteo[]);
int conversionentero(char cadena[]);
void convacadena(char * cad, long long int n, int tam);
int tamano(long long int n);
void minamayus(char *a);
void eliminarcaracteres(char a[], int num);
void separarnum(char *a, int tamano);
void agrupar(char *a, int n,int l);
void numromanos(char a[]);
bool cheqestrella(int a, int b, int c, int d, int e);
bool ingresar(int fil, int col);
int sillarestantes();
void imprimir();
void construirsala(char **matriz);
void reservar(char **matriz,char fila,int num);
void cancelar(char **matriz,char fil,int num);
void pedirDatos(int **puntero_matriz,int n);
void mostrarMatriz(int**puntero_matriz,int n);
void cuadradomagico(int**a,int n);
void caminos(int n);
void matriz5x5();
bool checkamigable (int a);
int sumadiv(int a);
void intercepto(int x[],int y[]);

#endif // PRACTICA2_H
