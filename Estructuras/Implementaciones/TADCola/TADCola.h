/*
LIBRERIA: Cabecera de el TAD COLA DIN�MICA
AUTOR: Edgardo Adri�n Franco Mart�nez (C) Septiembre 2016
VERSI�N: 1.5

DESCRIPCI�N: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos din�mica
cuando se le asigna memoria a medida que es necesitada,
durante la ejecuci�n del programa.

NOTA: No es necesario crear un struct para la cola y de igual
manera un struct para el elemento ya que est�n impl�citos en
el TAD Lista
*/

//Renombramos el TAD Lista como cola por dar m�s �rden
typedef lista cola;
//DECLARACI�N DE FUNCIONES
void Initialize(cola * c);			//Inicializar cola (Initialize): Recibe una cola y la inicializa para su trabajo normal.
void Queue(cola * c, elemento e);	//Encolar (Queue): Recibe una cola y agrega un elemento al final de ella.
elemento Dequeue(cola * c);			//Desencolar (Dequeue): Recibe una cola y remueve el elemento del frente retorn�ndolo.
boolean Empty(cola * c);			//Es vac�a (Empty): Recibe la cola y devuelve verdadero si esta esta vac�a.
elemento Front(cola * c);			//Frente (Front): Recibe una cola y retorna el elemento del frente.
elemento Final_Element( cola * c);	//Final (Final_Element): Recibe una cola y retorna el elemento del final.
int Size(cola *c);					//Tama�o (Size): Retorna el tama�o de la cola
void Destroy(cola * c);				//Eliminar cola (Destroy): Recibe una cola y la libera completamente.
