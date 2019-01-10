/*
AUTORES:
Nu�ez Garc�a Tania Itzel
Quiro D�az Ver�nica Jackeline
Vargas Romero Erick Efra�n

DESCRIPCI�N:Programar en ANSI C la implementaci�n recursiva del t�rmino n de la serie de Fibonacci y Tribonacci,
as� como la implementaci�n recursiva de las Torres de Hanoi para n discos.

EJECUCI�N: torresdehanoi.c (Windows)
*/

//LIBRERIAS
#include <stdio.h>
//PROTOTIPOS
void hanoi(char from, char to, char other, int n);

//PROGRAMA PRINCIPAL
int main()
{
int n;//Declaracion de n
printf("introduzca un numero: ");//Imprime a pantalla
scanf("%d",&n);//almacena la informacion en n
hanoi ('A', 'C','B',n);//llama la funcion con esos argumentos :A,B y C son los palos
return 0;
}
/*
void hanoi(char from, char to, char other, int n)
Descripcion:Da la solucion de como deben organizarse o moverse los discos
Recibe:tres char: char from, char to, char other, y un int n
*/
void hanoi(char from, char to, char other, int n)
{
if(n>0)//Si n es mayor a 0, e realiza lo siguiente
{
    hanoi(from, other, to, n-1);// llama a la misma funcion,aqui se aplica la recursividad
    printf("%c -> %c\n", from, to);//Imprime a pantalla
    hanoi(other, to, from, n-1);//llama a la misma funcion, de nnuevo se aplica recursividad
}
}

