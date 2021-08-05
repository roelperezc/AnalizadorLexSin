#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Literales.h"

// Estructura de la literal
struct nodoLiteral {
	int posicion; // Posicion
	char * dato; // Cadena
	struct nodoLiteral * next; // Siguiente literal
};

// Lista de literales
struct listaLiteral {
	NodoLiteral * head; // Primer elemento
	NodoLiteral * tail; // Ultimo elemento
};

// Método para crear un nodo de literal
NodoLiteral * crearLiteral(int posicion, char * dato);

NodoLiteral * crearLiteral(int posicion, char * dato){
	NodoLiteral * nuevoNodo = malloc(sizeof(NodoLiteral));
	if (!nuevoNodo) {
		return NULL;
	}
	
	char * datoCopia = (char *) malloc(strlen(dato)+1);
	strcpy(datoCopia,dato);
	
	nuevoNodo->posicion = posicion;
	nuevoNodo->dato = datoCopia;
	nuevoNodo->next = NULL;
	return nuevoNodo;
}

// Metodo para crear una lista de literales
ListaLiteral * crearListaLiteral();

ListaLiteral * crearListaLiteral(){
	ListaLiteral * lista = malloc(sizeof(ListaLiteral));
	if (!lista) {
		return NULL;
	}
	lista->head = NULL;
	lista->tail = NULL;
	return lista;
}

// Metodo para mostrar el contenido de una lista de literales
void mostrarListaLiteral(ListaLiteral * lista) {
	NodoLiteral * current = lista->head;
	if(lista->head == NULL) 
		return;
	printf("Pos\t\tDato\n");
  	for(; current != NULL; current = current->next) {
		printf("%d\t\t%s\n", current->posicion,current->dato);
	}
}

// Metodo para imprimir a un archivo el contenido de una lista de literales
void imprimirAArchivoListaLiteral(ListaLiteral * lista, FILE * salida) {
	NodoLiteral * current = lista->head;
	if(lista->head == NULL) 
		return;
	fprintf(salida,"Pos\t\tDato\n");
  	for(; current != NULL; current = current->next) {
		fprintf(salida,"%d\t\t%s\n", current->posicion,current->dato);
	}
}

// Metodo para agregar una literal a la lista
void agregarLiteral(ListaLiteral * lista, int posicion, char * dato){
	NodoLiteral * current = NULL;
	if(lista->head == NULL){
		lista->head = crearLiteral(posicion,dato);
		lista->tail = lista->head;
	}
	else {
		current = lista->tail;
		current->next = crearLiteral(posicion,dato);
		lista->tail = current->next;
	}
}

// Metodo para eliminar la lista de literales
void eliminarListaLiteral(ListaLiteral * lista){
	NodoLiteral * current = lista->head;
	NodoLiteral * next = current;
	while(current != NULL){
		next = current->next;
		free(current->dato);
		free(current);
		current = next;
	}
	free(lista);
}
