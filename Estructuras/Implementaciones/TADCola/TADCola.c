/*
IMPLEMENTACION DE LA LIBRERIA DEL TAD COLA DINAMICA implementada con TADLista
AUTOR: Vargas Romero Erick Efra�n (C) Noviembre 2016
VERSI�N: 1.0

DESCRIPCI�N: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos din�mica
cuando se le asigna memoria a medida que es necesitada,
durante la ejecuci�n del programa.

*/

//LIBRERAS
#include "..\TADLista\TADLista.c"
#include "TADCola.h"
#include <stdio.h>
#include <stdlib.h>

/*
void Initialize(cola *c);
Descripci�n: Inicializar cola (Iniciar una cola para su uso)
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: El usuario a creado una cola y c tiene la referencia a ella,
si esto no ha pasado se ocasionara un error.

NOTA: No es necesario recrear esta funci�n ya que el TAD Lista tiene impl�cita
esta funci�n solo hay que modificar el header del TADCola
*/
/**void Initialize(cola * c)
{
	c->frente = NULL;
	c->final = NULL;
	c->num_elem=0;
	return;
}**/

/*
void Queue(cola * c, elemento e);
Descripci�n: Recibe una cola y agrega un elemento al final de ella.
Recibe: cola *c (Referencia a la cola "c" a operar) elemento e (Elemento a encolar)
Devuelve:
Observaciones: El usuario a creado una cola y ha sido inicializada y c tiene la referencia a ella,
si esto no ha pasado se ocasionara un error.

NOTA: Esta funci�n es f�cil de crear con el TADLista, ya que solo utilizamos la funci�n Add para
a�adir un elemento al final de la cola
*/
void Queue(cola * c, elemento e)
{
    Add(c, e);
}

/*
elemento Dequeue(cola * c);
Descripci�n: Recibe una cola y devuelve el elemento que se encuentra al
frente de esta, quit�ndolo de la cola.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve: elemento (Elemento desencolado)
Observaciones: El usuario a creado una cola y la cola tiene elementos, si no
se genera un error y se termina el programa.

Nota: Al hacer uso del TAD Lista solo debemos recuperar un elemento que es el primero de la cola
y eliminarlo posteriormente. Esto es posible utilizando las funciones First para recuperar el elemento
y la funci�n Remove para eliminar el elemento de la Cola finalmente retornamos el elemento
que fue recuperado.
*/
elemento Dequeue(cola * c)
{
    elemento e;
    e = First(c)->e;
    Remove(c, First(c));
    return e;
}


/*
boolean Empty(cola * c);
Descripci�n: Recibe una cola y TRUE si la cola esta vacia y FALSE en caso contrario
Recibe: cola *c (Referencia a la cola "c" a verificar)
Devuelve: boolean TRUE O FALSE
Observaciones: El usuario a creado una cola y la cola fue correctamente inicializada

Nota: No es necesario recrear esta funci�n ya que el TAD Lista ya la tiene en
existencia, solo es necesario modificar el Header del tadCola
*/
/**boolean Empty(cola * c)
{
	return (c->num_elem==0) ? TRUE : FALSE;
}**/

/*
elemento Front(cola * c);
Descripci�n: Recibe una cola y devuelve el elemento que se encuentra al frente de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del frente de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD

Nota: Esta funci�n como se hace referencia en la descripci�n muestra el elemento que est� frente a la lista
para lo cual usamos la funci�n First del TADLista, y retornamos el elemento de la posicion que retorna
*/
elemento Front(cola * c)
{
	return First(c)->e;
}

/*
elemento Final_Element(cola * c);
Descripci�n: Recibe una cola y devuelve el elemento que se encuentra al final de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del final de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD

Nota: Esta funci�n existe en el TAD Lista como Final, en el TAD Cola ya existe pero devuelven
diferentes cosas, siendo as� complicado mantener el mismo nombre por tanto
se modific� el nombre de esta funci�n en el TADCola e invocando a la funci�n Final que retorna una
posicion y devolviendo en nuestra funci�n el elemento que tiene la posicion.
*/
elemento Final_Element(cola * c)
{
	return Final(c)->e;
}

/*
int Size(cola * c);
Descripci�n: Recibe una cola y devuelve el n�mero de elemento que se encuentran en esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: int (Tama�o de la cola)
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta
*No se modifica el TAD

NOTA: Esta funci�n ya existe en el TADLista siendo as� identica a la funci�n del TAD Cola
siendo as� solo necesario modificar el header del TADCola
*/
/**int Size(cola * c)
{
	return c->num_elem;
}**/

/*
void Destroy(cola * c);
Descripci�n: Recibe una cola y la libera completamente.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: La cola se destruye y se inicializa.

NOTA: Esta funci�n ya existe en el TADLista siendo as� identica a la funci�n del TAD Cola
siendo as� solo necesario modificar el header del TADCola

*/
/**void Destroy(cola * c)
{
	nodo * aux;	//Apuntador auxiliar a elemento

	//Mientras el apuntador del frente de la cola no sea NULL
	while(c->frente != NULL)
	{
		//Guardar la referencia al frente
		aux = c->frente;

		//El nuevo frente es el siguiente
		c->frente = c->frente->siguiente;

		//Liberar el antiguo frente de memoria
		free(aux);
	}

	//El n�mero de elementos en la cola es 0
	c->num_elem=0;

	//Colocar el frente (ya quedo en NULL seg�n como se fue destruyendo) y final inicializado
	c->final = NULL;
}**/
