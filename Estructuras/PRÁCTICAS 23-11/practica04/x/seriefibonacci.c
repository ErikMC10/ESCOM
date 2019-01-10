/*
AUTORES:
Nu�ez Garc�a Tania Itzel
Quiro D�az Ver�nica Jackeline
Vargas Romero Erick Efra�n

DESCRIPCI�N:Programar en ANSI C la implementaci�n recursiva del t�rmino n de la serie de Fibonacci y Tribonacci,
as� como la implementaci�n recursiva de las Torres de Hanoi para n discos.

EJECUCI�N: seriefibonacci.c (Windows)
*/

//LIBRERIAS
#include <stdio.h>
//PROTOTIPOS
long int fibonacci(long int n);
//PROGRAMA PRINCIPAL
long int main(){
    long int numero,i;//Declaracion de numero y i
    printf("\n \t\tSERIE FIBONACCI\n\n");
    printf("\t Introduzca el numero de elementos:");// Imprime a pantalla
    scanf("%d",&numero);//Almacena la informacion introducida
    printf ("\n");

    for(i=0 ;i<=numero;i++)//El for termina hasta que numero no sea mayor o igual al introducido
    {
        printf("%d \n\t", fibonacci(i));// Imprime a pantalla el resultado de la funcion fibonacci

    }

    return 0;
}
/*
si fibonacci(1)= 1, entonces: fibonacci(n)=fibonacci(n-1)+fibonacci(n-2)

int fibonacci(int n)
Descripcion:Realiza la operacion del numero introducido
Recibe:un int n
Devuelve: el resultado de la operacion: fibonacci(n-1)+ fibonacci(n-2)
*/
long int fibonacci(long int n)
{
    if(n==0|| n==1)//Si se cumple que n es igual a cero � n es igual a 1
    {
        return n;//regresara el numero : n
    }
    else//por el contrario
    {
        return(fibonacci(n-1)+ fibonacci(n-2));// regresara el resultado de esta suma
    }

}
