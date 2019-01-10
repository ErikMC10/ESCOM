/* Autor: Vargas Romero Erick Efra�n, 22 de agosto 2016
Versi�n 1.0

Descripci�n: Programa que recibe el valor de filas y columnas para
crear dos matrices din�micas, los valores de las filas y columnas
no ser�n menores a 1, el usuario ingresar� los valores que
contendr� cada matriz din�mica en su posici�n i, j, finalmente
el programa, realizar� la suma y resta de matrices din�micas, esto
lo hace miembro a miembro, y almacenando estos valores en una matriz
resultante, que tambi�n ser� din�mica

Declaraci�n de librer�as, se incluyen las funciones estandar
de entrada y salida*/
#include <stdio.h>

/*Declaraci�n de funciones
Aparta la memoria necesaria para nuestras matrices din�micas, recibe
dos datos de tipo entero*/
int **memoria_matriz(int m, int n);
/*Llenado de las matrices, esta funci�n recibe tres datos uno de tipo
entero doble apuntador, y dos datos de tipo entero */
void llenar_matriz(int **Matriz, int m, int n);
/*Muestreo de lo que contiene la matriz, recibe 3 par�metros uno
de tipo entero doble apuntador y dos datos de tipo entero*/
void mostrar_matriz(int **Matriz, int m, int n);
/*Funci�n para realizar la suma de las matrices, recibe 4 par�metros
dos de tipo entero doble apuntador, y dos de tipo entero*/
void suma_matrices(int **matriz_uno, int **matriz_dos, int m, int n);
/*Funci�n para realizar la resta de las matrices, recibe 4 par�metros
dos de tipo entero doble apuntador, y dos de tipo entero*/
void resta_matrices(int **matriz_uno, int **matriz_dos, int m, int n);

//Programa principal
int main(void)
{
    /*Declaraci�n de variables, dos de tipo entero doble apuntador
    y dos de tipo entero, las dos primeras variables ser�n utilizadas
    para la creaci�n de nuestras matices din�micas, y los �ltimos dos datos
    son utilizados para especificar el n�mero de f�las y columnas que
    tendr�n nuestras matrices din�micas*/
    int **matriz_uno, **matriz_dos, M, N;

    //Inicio de un ciclo de repetici�n
    do
    {
        //Enviamos mensaje a pantalla pidiendo el n�mero de filas
        printf("\nIngresa el numero de filas (Horizontal) -> ");
        //Hacemos la lectura de las filas que desea el usuario
        //Lo ingresado es almacenado en la variable M
        scanf("%d", &M);
        //Enviamos mensaje a pantalla pidiendo el n�mero de columnas
        printf("\nIngresa el numero de columnas (Vertical) -> ");
        //Hacemos la lectura de las columnas que desea el usuario
        //Lo ingresado es almacenado en la variable N
        scanf("%d", &N);
    }
    //Este ciclo se repetir� mientras las variables M y N
    //No sean mayores a cero
    while(!(M > 0 && N > 0));

    /*Llamamos a nuestra funci�n memoria matriz y
    solcitamos memoria para hacer uso de la matriz din�mica
    adem�s le pasamos las variables M y N, tambi�n la funci�n
    memoria_matriz, nos returnar� otra variable de tipo
    int** que ser� guardado en la vriable matriz_uno*/
    matriz_uno = memoria_matriz(M, N);
    /*Verificamos si el valor de nuestra variable_matriz uno
    no sea 0 o bien NULL (Este valor es la memoria que se le ha
    asignado)*/
    if(matriz_uno == NULL)
    {
        /*Si el valor de la variable matriz_uno es NULL, enviamos un mensaje
        a pantalla y finalizamos el programa*/
        printf("\n\nNo hay memoria disponible para la primer matriz...\n");
    }
    /*Si se le ha asignado memoria a matriz_uno entonces...*/
    else
    {
        /*Llamamos a la funci�n llenar_llenar matriz, como el nombre
        lo indica, realizaremos el llenado de nuestra matriz din�mica
        le pasamos variables, nuestra matriz_uno de tipo int** y
        las filas y columnas de nuestra matriz*/
        llenar_matriz(matriz_uno, M, N);
        /*Invocamos a nuestra funci�n mostrar_matriz, como el nombre
        lo indica, mostrar� lo que previamente ingresamos a la matriz
        en este caso, le pasamos 3 datos, el primero matriz_uno, tipo
        int** y el n�mero de filas y columnas*/
        mostrar_matriz(matriz_uno, M, N);

        /*Llamamos a nuestra funci�n memoria matriz y
        solcitamos memoria para hacer uso de la matriz din�mica
        adem�s le pasamos las variables M y N, tambi�n la funci�n
        memoria_matriz, nos returnar� otra variable de tipo
        int** que ser� guardado en la vriable matriz_dos*/
        matriz_dos = memoria_matriz(M, N);
        /*Verificamos si el valor de nuestra variable_matriz uno
        no sea 0 o bien NULL (Este valor es la memoria que se le ha
        asignado)*/
        if(matriz_dos == NULL)
        {
            /*Si el valor de la variable matriz_uno es NULL, enviamos un mensaje
            a pantalla y finalizamos el programa*/
            printf("\n\nNo hay memoria disponible para la segunda matriz...\n");
        }
        /*Si se le ha asignado memoria a matriz_uno entonces...*/
        else
        {
            /*Llamamos a la funci�n llenar_llenar matriz, como el nombre
            lo indica, realizaremos el llenado de nuestra matriz din�mica
            le pasamos variables, nuestra matriz_dos de tipo int** y
            las filas y columnas de nuestra matriz*/
            llenar_matriz(matriz_dos, M, N);
            /*Invocamos a nuestra funci�n mostrar_matriz, como el nombre
            lo indica, mostrar� lo que previamente ingresamos a la matriz
            en este caso, le pasamos 3 datos, el primero matriz_dos, tipo
            int** y el n�mero de filas y columnas*/
            mostrar_matriz(matriz_dos, M, N);
            /*Esta funci�n realizar� la suma de matrices din�micas
            le pasamos 4 variables, matriz_uno, matriz_dos que son
            de tipo int**, tambi�n le pasamos M y N que son el n�mero
            de filas y columnas*/
            suma_matrices(matriz_uno, matriz_dos, M, N);
            /*Esta funci�n realizar� la resta de matrices din�micas
            le pasamos 4 variables, matriz_uno, matriz_dos que son
            de tipo int**, tambi�n le pasamos M y N que son el n�mero
            de filas y columnas*/
            resta_matrices(matriz_uno, matriz_dos, M, N);
        }
    }
    return 0;
}

/*Aparta la memoria necesaria para nuestras matrices din�micas, recibe
dos datos de tipo entero, tambi�n tomemos en cuenta que esta funci�n
nos returnar� una variable de tipo int** */
int **memoria_matriz(int m, int n)
{
    /*Como la funci�n nos returnar� una variable de tipo int**,
    declaramos una variable del mismo tipo, tambi�n declaramos
    otra variable "i", que usaremos como contador*/
    int **Matriz, i;
    /*Apartamos la memoria de nuestra matriz, en este caso, la memoria
    para las filas, y es multiplicado el n�mero de filas, o sea la
    variable m por el valor que tenga un dato tipo int*/
    Matriz = malloc(m*sizeof(int));
    /*Iniciamos un ciclo de repetici�n que terminar� cuando nuestr variable
    "i" sea menor que nuestra variable m, la variable i se incrementa 1 a 1*/
    for(i = 0; i<m; i++)
    {
        //Apartamos memoria para las columnas
        Matriz[i] = malloc(n*sizeof(int));
    }
    //Returnamos una variable de tipo int**
    return Matriz;
}


/*Llenado de las matrices, esta funci�n recibe tres datos uno de tipo
entero doble apuntador, y dos datos de tipo entero */
void llenar_matriz(int **Matriz, int m, int n)
{
    //Declaraci�n de dos variables que ser�n contadores
    int i, j;
    //Ciclo de repetici�n, que hace el recorrido de las filas
    for(i = 0; i<m; i++)
    {
        //Ciclo de repetici�n que hace el recorrido de las columnas
        for(j = 0; j<n; j++)
        {
            //Enviamos mensaje solicitando que se asigne un valor en la
            //posici�n mostrada
            printf("\n\nIngresa un numero para la posicion [%d][%d] -> ", i, j);
            //Lectura del n�mero ingresado y almacenado en la posici�n i, j
            scanf("%d", &Matriz[i][j]);
        }
    }
}

/*Muestreo de lo que contiene la matriz, recibe 3 par�metros uno
de tipo entero doble apuntador y dos datos de tipo entero*/
void mostrar_matriz(int **Matriz, int m, int n)
{
    //Declaraci�n de dos variables que ser�n contadores
    int i, j;
    //Ciclo de repetici�n, que hace el recorrido de las filas
    for(i = 0; i<m; i++)
    {
        //Damos dos saltos de linea
        printf("\n\n");
        //Ciclo de repetici�n, que hace el recorrido de las columnas
        for(j = 0; j<n; j++)
        {
            //Mostramos el valor que tiene la variable Matriz, en
            //su posici�n i, j, adem�s damos un tabulador entre cada
            //dato mostrado
            printf("%d \t", Matriz[i][j]);
        }
    }
    //Damos dos saltos de linea
    printf("\n\n");
    //Pausamos el programa
    system("pause");
}

/*Funci�n para realizar la suma de las matrices, recibe 4 par�metros
dos de tipo entero doble apuntador, y dos de tipo entero*/
void suma_matrices(int **matriz_uno, int **matriz_dos, int m, int n)
{
    //Declaraci�n de variables, dos contadores y una variable
    //tipo int** llamad matriz, suma
    int i, j, **matriz_suma;
    /*Como realizaremos una suma de matrices, debemos de crear
    una tercer matriz, o matriz resultante*/
    matriz_suma = memoria_matriz(m, n);
    //Verificamos si hay memoria disponible para la matriz resultante
    if(matriz_suma == NULL)
    {
        //Si no hay memoria, enviamos un mensaje
        printf("\n\nNo hay memoria disponible para la matriz resultante...\n");
    }
    else
    {
        //Si la memoria es suficiente
        //limpiamos pantalla
        system("cls");
        //Enviamos mensaje
        printf("\nEl resultado de sumar la matriz \n\n");
        //Invocamos a la funci�n mostrar matriz, e indicamos
        //que la matriz a mostrar es matriz_uno
        mostrar_matriz(matriz_uno, m, n);
        //Enviamos mensaje
        printf("\n\nCon la matriz \n\n");
        //Invocamos a la funci�n mostrar matriz, e indicamos
        //que la matriz a mostrar es matriz_dos
        mostrar_matriz(matriz_dos, m, n);
        //Mostramos mensaje
        printf("\n\nes: ");
        //iniciamos un ciclo de repetici�n para las filas
        for(i = 0; i<m; i++)
        {
            //Iniciamos un segundo ciclo de repetici�n para columnas
            for(j = 0; j<n; j++)
            {
                //Realizamos la suma entre matrices y almacenamos en
                //nuestra matriz resultante
                matriz_suma[i][j] = matriz_uno[i][j] + matriz_dos[i][j];
            }
        }
        //mostramos nuestra matriz resultante usando la
        //funci�n mostrar_matriz
        mostrar_matriz(matriz_suma, m, n);
    }
}

/*Funci�n para realizar la resta de las matrices, recibe 4 par�metros
dos de tipo entero doble apuntador, y dos de tipo entero*/
void resta_matrices(int **matriz_uno, int **matriz_dos, int m, int n)
{
    //Declaraci�n de variables, dos contadores y una variable
    //tipo int** llamad matriz, suma
    int i, j, **matriz_resta;
    /*Como realizaremos una suma de matrices, debemos de crear
    una tercer matriz, o matriz resultante*/
    matriz_resta = memoria_matriz(m, n);
    //Verificamos si hay memoria disponible para la matriz resultante
    if(matriz_resta == NULL)
    {
        //Si no hay memoria, enviamos un mensaje
        printf("\n\nNo hay memoria disponible para la matriz resultante...\n");
    }
    else
    {
        //Si la memoria es suficiente
        //limpiamos pantalla
        system("cls");
        //Enviamos mensaje
        printf("\nEl resultado de restar la matriz \n\n");
        //Invocamos a la funci�n mostrar matriz, e indicamos
        //que la matriz a mostrar es matriz_uno
        mostrar_matriz(matriz_uno, m, n);
        //Enviamos mensaje
        printf("\n\nCon la matriz \n\n");
        //Invocamos a la funci�n mostrar matriz, e indicamos
        //que la matriz a mostrar es matriz_dos
        mostrar_matriz(matriz_dos, m, n);
        //Mostramos mensaje
        printf("\n\nes: ");
        //iniciamos un ciclo de repetici�n para las filas
        for(i = 0; i<m; i++)
        {
            //Iniciamos un segundo ciclo de repetici�n para columnas
            for(j = 0; j<n; j++)
            {
                //Realizamos la resta entre matrices y almacenamos en
                //nuestra matriz resultante
                matriz_resta[i][j] = matriz_uno[i][j] - matriz_dos[i][j];
            }
        }
        //Mostramos la matriz resultante
        mostrar_matriz(matriz_resta, m, n);
    }
}

