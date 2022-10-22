// Práctica 1 Listas circulares Juan Bauza
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nodo
{
int valor;
struct nodo*sig;
}nodo;
nodo* primerN = NULL;
nodo* ultimoN = NULL;
void Insertarnodo();
void Buscarnodo();
void Eliminarnodo();
void Desplegarcola();

int main ()
{
int opcionMenu = 0;
do
    {
        printf("\n|-------------------------------------|");
        printf("\n|               * COLA *              |");
        printf("\n|-------------------|-----------------|");
        printf("\n| 1. Insertar       | 4. Desplegar    |");
        printf("\n| 2. Buscar         | 5. Salir        |");
        printf("\n| 3. Eliminar       |                 |");
        printf("\n|-------------------|-----------------|");
        printf("\n Inserte una Opcion: ");
        scanf("%d", &opcionMenu);

        switch(opcionMenu)
        {

case 1:
system("CLS");
printf("\n Inserte un nodo \n");
Insertarnodo();
break;

case 2:
system("CLS");
printf("\n Busque un nodo \n");
Buscarnodo();
break;

case 3:
system("CLS");
printf("\n Elimine un nodo\n");
Eliminarnodo();
break;

case 4:
printf("\n Desplegar cola \n");
Desplegarcola();
break;

case 5:
system("CLS");
printf("\n  El Programa ha concluido \n");
break;

default:

printf("\n La opcion no es valida, inserte otro numero \n");
}

}while(opcionMenu != 5);
return 0;
}

void Insertarnodo()
{

nodo* nuevo = (nodo*) malloc(sizeof(nodo));
printf("Inserte el valor que tendra el nuevo Nodo: ");
scanf("%d", &nuevo ->valor);
if(primerN==NULL)
{
primerN = nuevo;
primerN ->sig = NULL;
ultimoN = nuevo;
}else
{

ultimoN ->sig = nuevo;
nuevo ->sig = NULL;
ultimoN = nuevo;
}
printf("\n El Nodo ha sido insertado \n");
}

void Buscarnodo()
{
nodo* actualN = (nodo*) malloc(sizeof(nodo));
actualN = primerN;
int Nbuscado=0, encontradoN=0;
printf("Inserte el valor del Nodo que desea encontrar: ");
scanf("%d", &Nbuscado);
if(primerN != NULL)
{
while(actualN != NULL && encontradoN !=1)
{

if(actualN ->valor == encontradoN)
{

printf("\nNodo con el valor (%d) encontrado\n", Nbuscado);
encontradoN = 1;
}
actualN = actualN ->sig;
}
if(encontradoN == 0)
{
printf("\nEl nodo no fue encontrado, inserte otro valor \n");
}

}else
{
printf("\n La Cola esta vacia \n");
}

}
void Eliminarnodo()
{

nodo* actualN = (nodo*) malloc(sizeof(nodo));
actualN = primerN;
nodo* anteriorN = (nodo*) malloc(sizeof(nodo));
anteriorN = NULL;
int Nbuscado=0, encontradoN=0;
printf("Inserte el valor del nodo que desea eliminar: ");
scanf("%d", &Nbuscado);
if(primerN != NULL)
{

while(actualN != NULL && encontradoN != 1){
if(actualN ->valor == encontradoN){
if(actualN == primerN){

primerN = primerN->sig;
}else if(actualN == ultimoN){

anteriorN ->sig = NULL;
ultimoN = anteriorN;
}else{

anteriorN ->sig = actualN ->sig;
}
printf("\n El nodo ha sido eliminado \n");
encontradoN = 1;
}
anteriorN = actualN;
actualN	 = actualN ->sig;
}
if(encontradoN = 0){

printf("\n El nodo no ha sido encontrado \n");
}else{

free(anteriorN);
}
}else{

printf("\n La Cola esta vacia \n");
}
}

void Desplegarcola()
{

nodo* actualN = (nodo*) malloc(sizeof(nodo));
actualN = primerN;
if(primerN != NULL)
{

while(actualN != NULL)
{

printf("\n %d", actualN ->valor);
actualN = actualN -> sig;
}
}else
{

printf("\n La Cola esta vacia \n");
}
}
