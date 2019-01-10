/**Librerias**/
//Libreria estandar de entrada y salida
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
//Nuestra libreria donde se aloja el c�digo de la pila
#include "Librerias/TADPilaDin/TADPilaDin.c"

#define TAM_CAD 100

typedef struct letras
{
    int bandera;
    float valor;
} letras;

//Prototipos de funciones
/**Descripci�n: El m�todo parentesis(pila mi_pila, char* cadena)
verifica si los parentesis en una ecuaci�n est�n colocados de
manera correcta.
Recibe: Una pila, y un apuntador a caracter
Devuelve: **/

void perentesis(pila mi_pila, char* cadena);
void conversion(pila mi_pila, char* cadena);
boolean esNumero(char caracter);
boolean esSumORest(char caracter);
boolean esMultODivi(char caracter);
boolean esPotencia(char caracter);
char queHayArriba(pila una_pila);

//Programa principal
int main(void)
{

    //Creaci�n de la pila
    pila mi_pila;
    //Inicializaci�n de la pila
    Initialize(&mi_pila);
    //Creaci�n de una cadena de caracteres
    char ecuacion[TAM_CAD];
    //Envio de mensaje a la pantalla
    printf("Ingresa la ecuacion \n-> ");
    //Lectura de una cadena de caracteres
    scanf("%s", ecuacion);

    //Invocaci�n de la funci�n parentesis()
    parentesis(mi_pila, ecuacion);
    return 0;
}

/**Descripci�n: El m�todo parentesis(pila mi_pila, char* cadena)
verifica si los parentesis en una ecuaci�n est�n colocados de
manera correcta.
Recibe: Una pila, y un apuntador a caracter
Devuelve: **/
void parentesis(pila mi_pila, char* cadena)
{
    //Declaraci�n de una variable contador llamada i
    //Declaraci�n de una variable llamada bandera inicializada en 1
    int i, bandera = FALSE;
    //Declaraci�n de una variable tipo elemento llamada mi_elemento
    elemento mi_elemento;
    //Creaci�n de un ciclo de repetici�n que inicia desde cero
    //La condici�n va hasta que sea menor a 100 y es autoincrementable
    for(i=0; i<TAM_CAD; i++)
    {
        //A mi_elemento es una estructura que tiene un par�metro caracter llamado
        //c, en el cual guardamos lo que hay en cadena[i]
        mi_elemento.c = cadena[i];
        //Evaluamos si lo que tiene la cadena es un par�ntesis que abre
        if(cadena[i] == '(')
        {
            //Si la condici�n es verdadera, hacemos un push de nuestra pila
            //Y almacenamos a mi_elemento
            Push(&mi_pila, mi_elemento);
        }
        //Si el elemento de la cadena es un parentesis que cierra entonces
        else if(cadena[i] == ')')
        {
            //Evaluamos si la pila NO est� vac�a
            if(!Empty(&mi_pila))
            {
                //Si no esta vac�a, entonces hacemos un POP de la pila
                Pop(&mi_pila);
            }
            else
            {
                //Si esta vac�a, la variable bandera cambia al valor TRUE
                bandera = TRUE;
            }
        }
    }
    //Finalmente si bandera es igual a TRUE
    if(!Empty(&mi_pila) || bandera == TRUE)//bandera == TRUE)
    {
        //Muestra un mensaje diciendo que un par�ntesis no tiene pareja
        printf("Un parentesis no tiene pareja :'v");
    }
    else
    {
        conversion(mi_pila, cadena);
    }
    return;
}

/**
Descripci�n: El m�todo conversion(pila mi_pila, char* cadena)
hace la conversi�n de notaci�n infija a postfija
Recibe: Una pila, y un apuntador a caracter
Devuelve:
**/

void conversion(pila mi_pila, char* cadena)
{
    elemento mi_elemento;
    int i = 0, bandera_global = FALSE, bandera_local = FALSE;
    char resultado[TAM_CAD] = {' '}, auxiliar_global[2]= {' '}, auxiliar_local[2] = {' '}, siguiente[2] = {' '};

    while(cadena[i] != '\0')
    {
        printf("\n\tPosicion -> %d -> CARACTER -> %c", i, cadena[i]);
        mi_elemento.c = cadena[i];
        siguiente[0] = cadena[i+1];
        auxiliar_global[0] = mi_elemento.c;

        if(esNumero(mi_elemento.c))
        {
            printf("\nEs numero -> %c\n", mi_elemento.c);
            strcat(resultado, auxiliar_global);
        }
        else
        {
            if(esPotencia(mi_elemento.c))
            {
                printf("\nEs potencia -> %c\n", mi_elemento.c);
                if(esNumero(siguiente[0]))
                {
                    strcat(resultado, siguiente);
                    bandera_local = TRUE;
                }
                if(bandera_local)
                {
                    i++;
                }
                Push(&mi_pila, mi_elemento);
            }
            if(esMultODivi(mi_elemento.c))
            {
                printf("\nEs mult o divi -> %c\n", mi_elemento.c);
                while(esSumORest(queHayArriba(mi_pila)) || esPotencia(queHayArriba(mi_pila)))
                {
                    auxiliar_local[0] = queHayArriba(mi_pila);
                    Pop(&mi_pila);
                    strcat(resultado, auxiliar_local);
                }
                if(esMultODivi(queHayArriba(mi_pila)))
                {
                    auxiliar_local[0] = queHayArriba(mi_pila);
                    Pop(&mi_pila);
                    strcat(resultado, auxiliar_local);
                }
                Push(&mi_pila, mi_elemento);
            }
            if(esSumORest(mi_elemento.c))
            {
                printf("\nEs sum o rest -> %c\n", mi_elemento.c);
                printf("Tope tiene -> %c", queHayArriba(mi_pila));
                while(esMultODivi(queHayArriba(mi_pila)) || esPotencia(queHayArriba(mi_pila)))
                {
                    auxiliar_local[0] = queHayArriba(mi_pila);
                    Pop(&mi_pila);
                    strcat(resultado, auxiliar_local);
                }
                if(esSumORest(queHayArriba(mi_pila)))
                {
                    auxiliar_local[0] = queHayArriba(mi_pila);
                    Pop(&mi_pila);
                    strcat(resultado, auxiliar_local);
                }
                Push(&mi_pila, mi_elemento);
            }
            printf("\nNo es numero -> %c\n", mi_elemento.c);
            if(mi_elemento.c == '(')
            {
                printf("\nEs parentesis abierto -> %c\n", mi_elemento.c);
                Push(&mi_pila, mi_elemento);
            }
            if(mi_elemento.c == ')')
            {
                printf("\nEs parentesis cerrado -> %c\n", mi_elemento.c);
                while(queHayArriba(mi_pila) != '(')
                {
                    auxiliar_local[0] = queHayArriba(mi_pila);
                    Pop(&mi_pila);
                    strcat(resultado, auxiliar_local);
                }
                if(queHayArriba(mi_pila) == '('){
                    Pop(&mi_pila);
                }
            }
        }
        i++;
    }
    printf("\nTope tiene -> %c", queHayArriba(mi_pila));

    while(esPotencia(queHayArriba(mi_pila))|| esSumORest(queHayArriba(mi_pila)) || esMultODivi(queHayArriba(mi_pila)))
    {
        auxiliar_global[0] = queHayArriba(mi_pila);
        Pop(&mi_pila);
        strcat(resultado, auxiliar_global);
    }
    printf("\nConversion: %s\n", resultado);
}


/*int prioridad(char caracter){
    int quepriodidad;
    switch(caracter){
    case '^':
        quepriodidad = 4;
        break;
    case '*':
        quepriodidad = 3;
        break;
    case '/':
        quepriodidad = 3;
        break;
    case '+':
        quepriodidad = 1;
        break;
    case '-':

        break;
        default

    }
}*/
boolean esNumero(char caracter)
{
    boolean bandera;
    if(caracter != '^' && caracter != '*' && caracter != '/' && caracter != '+'
            && caracter != '-' && caracter != '(' && caracter != ')' && caracter != '\0')
    {
        bandera = TRUE;
    }
    else
    {
        bandera = FALSE;
    }
    return bandera;
}

boolean esPotencia(char caracter)
{
    boolean bandera = FALSE;
    if(caracter == '^')
    {
        bandera = TRUE;
    }
    else
    {
        bandera = FALSE;
    }
    return bandera;
}

boolean esMultODivi(char caracter)
{
    boolean bandera = FALSE;
    if(caracter =='*' || caracter == '/')
    {
        bandera = TRUE;
    }
    else
    {
        bandera = FALSE;
    }
    return bandera;
}

boolean esSumORest(char caracter)
{
    boolean bandera = FALSE;
    if(caracter == '+' || caracter == '-')
    {
        bandera = TRUE;
    }
    else
    {
        bandera = FALSE;
    }
    return bandera;
}

char queHayArriba(pila una_pila){
    char caracter;
    if(!Empty(&una_pila)){
        caracter = Top(&una_pila).c;
    } else {
        caracter = "";
    }
    return caracter;
}
