#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargarArreglo(int A[],int dim);
void mostrarArreglo(int A[],int v);
void suma (int A[],int v);
void pasarPila(int A[],int v,Pila *a);
int cargaraReal(float A[],int dim);
void mostrararregloF(float A[],int v);
void sumaR (float A[],int v);
int buscarDato (char A[],int v,char dato);
int cargarArreglochar(char A[],int dim);
void insertar (char A[],int v,char dato);
int buscaMayor (int A[],int v);
int esCapicua (int A[],int v);
void reves (int A[],int v);
int busquedaMenor (int A[],int v,int pos);
void ordenamientoSeleccion (int A[],int v);
void insercion (int A[],int ultv,int dato);
void ordenamientoInsercion(int A[],int v);
int nuevoOrdenado (int A[],int v1,int B[],int v2,int C[],int dc);

int main()
{
    int arreglo[10],val,val2,flag,val3,m,b[10],c[50];
    Pila p;
    //float arr[100];
    char dato,V[10];

    inicpila(&p);

    val=cargarArreglo(arreglo,10);
    val2=cargarArreglo(b,10);
    //val2=cargaraReal(arr,100);
    //val3=cargarArreglochar(V,10);

    //mostrarArreglo(arreglo,val);

    //suma(arreglo,val);

    //pasarPila(arreglo,val,&p);

    //mostrar(&p);

    //sumaR(arr,val2);

    /*printf("Dato\n");
    fflush(stdin);
    scanf("%c",&dato);

    flag=buscarDato(V,val3,dato);

    if (flag==1)
    {
        printf("Se encuentra dentro");
    }else if (flag==0)
    {
        printf("No se encuentra dentro");
    }*/

    //insertar(V,val3,dato);

    //m=buscaMayor(arreglo,val);

    //printf("El mayor es %d",m);

    //flag=esCapicua(arreglo,val);

    /*if (flag==0)
    {
        printf("Capicua");
    }else
    {
        printf("No es");
    }*/

    //reves(arreglo,val);

    //ordenamientoSeleccion(arreglo,val);

    //ordenamientoInsercion(arreglo,val);

    //mostrarArreglo(arreglo,val);

    val3=nuevoOrdenado(arreglo,val,b,val2,c,50);
    mostrarArreglo(c,val3);

}

/*Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores
 al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo.*/

 int cargarArreglo(int A[],int dim)
 {
     char Continuar='s';
     int validos=0;

     while (Continuar=='s' && validos<dim)
     {
         printf("Ingrese un numero\n");
         fflush(stdin);
         scanf("%d",&A[validos]);
         validos++;
         printf("Desea continuar?\n");
         fflush(stdin);
         scanf("%c",&Continuar);
     }

     return validos;
 }

 int cargarArreglochar(char A[],int dim)
 {
     char Continuar='s';
     int validos=0;

     while (Continuar=='s' && validos<dim)
     {
         printf("Ingrese un numero\n");
         fflush(stdin);
         scanf("%c",&A[validos]);
         validos++;
         printf("Desea continuar?\n");
         fflush(stdin);
         scanf("%c",&Continuar);
     }

     return validos;
 }

 //Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.

 void mostrarArreglo(int A[],int v)
 {
     int i;

     for (i=0;i<v;i++)
     {
         printf("Posicion %d : %d\n",i,A[i]);
     }
 }

 //Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.

 void suma (int A[],int v)
 {
     int i,sum;

     sum=0;

     for (i=0;i<v;i++)
     {
         sum=sum+A[i];
     }

     printf("La suma es %d",sum);
 }

 //Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.

 void pasarPila(int A[],int v,Pila *a)
 {
     int i;

     for (i=0;i<v;i++)
     {
         apilar(a,(A[i]));
     }
 }

 /*Realizar una función que sume los elementos de un arreglo números reales de dimensión 100. (para poder hacer esta función, hay
 que cargar un arreglo de reales, se recomienda hacer una función para cargar y otra para mostrar este tipo de arreglos)*/

int cargaraReal(float A[],int dim)
{
    char Continuar='s';
    int validos=0;

    while (Continuar=='s'&&validos<dim)
    {
        printf("Ingrese un numero\n");
        fflush(stdin);
        scanf("%f",&A[validos]);

        validos++;

        printf("Desea continuar?\n");
        fflush(stdin);
        scanf("%c",&Continuar);
    }

    return validos;
}

 void mostrararregloF(float A[],int v)
 {
     int i;

     for (i=0;i<v;i++)
     {
         printf("%f\n",A[i]);
     }
 }

  void sumaR (float A[],int v)
 {
     int i;
     float sum;

     sum=0;

     for (i=0;i<v;i++)
     {
         sum=sum+A[i];
     }

     printf("La suma es %f",sum);
 }

 //Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres

 int buscarDato (char A[],int v,char dato)
 {
     int i=0;
     int flag=0;

     while (i<v&&flag==0)
     {
         if (dato==A[i])
         {
             flag=1;
         }else
         {
             i++;
         }
     }

     return flag;
 }

 //Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.

 void insertar (char A[],int v,char dato)
 {
     int i=v-1;

     while (i>=0 && dato<A[i])
     {
         A[i+1]=A[i];
         i--;
     }
     A[i+1]=dato;
 }

 //Realizar una función que obtenga el máximo carácter de un arreglo dado.

 int buscaMayor (int A[],int v)
 {
     int i,mayor;

     mayor=0;

     for (i=0;i<v;i++)
     {
         if (A[i]>mayor)
         {
             mayor=A[i];
         }
     }

    return mayor;
 }

 //Realizar una función que determine si un arreglo es capicúa.

 int esCapicua (int A[],int v)
 {
     int i=0;
     int j=v-1;
     int flag=0;

     while (i<j && flag==0)
     {
         if (A[j]!=A[i])
         {
             flag=1;
         }else
         {
             i++;
             j++;
         }

         return flag;
     }
 }

 //Realizar una función que invierta los elementos de un arreglo.

 void reves (int A[],int v)
 {
     int i=0;
     int j=v-1;
     int a1,a2;

     while (i<j)
     {
         a1=A[i];
         a2=A[j];
         A[i]=a2;
         A[j]=a1;

         j--;
         i++;
     }
 }

 //Ordenar un arreglo según los siguientes métodos:
 //Selección
 //Inserción

 int busquedaMenor (int A[],int v,int pos)//ORDENAMIENTO SELECCIÓN, PRIMERO BUSCAMOS LA POSICIÓN DEL MENOR.
 {
    int menor=A[pos];
    int posMenor=pos;
    int i=pos+1;

    while (i<v)
    {
        if (A[i]<menor)
        {
            menor=A[i];
            posMenor=i;
        }

        i++;
    }

    return posMenor;
 }

 void ordenamientoSeleccion (int A[],int v)
 {
     int i=0;
     int posMenor;
     int aux;

     while (i<v-1)
     {
         posMenor=busquedaMenor(A,v,i);
         aux=A[posMenor];
         A[posMenor]=A[i];
         A[i]=aux;

         i++;
     }
 }

 void insercion (int A[],int ultv,int dato)
 {
     int i=ultv;

     while (i>=0 && dato<A[i])
     {
         A[i+1]=A[i];
         i--;
     }

     A[i+1]=dato;

 }

 void ordenamientoInsercion(int A[],int v)
 {
     int i=0;

     while (i<v-1)
     {
         insercion(A,i,A[i+1]);
         i++;
     }
 }

 //Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.

 int nuevoOrdenado (int A[],int d1,int B[],int d2,int C[])
 {
     int iA=0;
     int iB=0;
     int iC=0;
     int dC=d1+d2

     while (iA<v1 && iB<v2 && iC<dc)
     {
         if (A[iA]<B[iB])
         {
             C[iC]=A[iA];
             iC++;
             iA++;
         }else
         {
             C[iC]=B[iB];
             iC++;
             iB++;
         }
     }

     while (iA<v1 && iC<dc)
     {
          C[iC]=A[iA];
             iC++;
             iA++;
     }
     while (iB<v2 && iC<dc)
     {
         C[iC]=B[iB];
             iC++;
             iB++;
     }

     return iC;
 }
