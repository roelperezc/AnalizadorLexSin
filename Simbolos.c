#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Simbolos.h"

// Estructura del simbolo
struct nodoSimbolo {
	int posicion; // Posicion
	char * nombre; // Nombre
	int tipo; // Tipo
	struct nodoSimbolo * next; // Siguiente simbolo
};

// Lista de simbolos
struct listaSimbolo {
	NodoSimbolo * head; // Primer elemento
	NodoSimbolo * tail; // Ultimo elemento
};

// Método para crear un nodo de simbolo
NodoSimbolo * crearSimbolo(int posicion, char * nombre);

NodoSimbolo * crearSimbolo(int posicion, char * nombre){
	NodoSimbolo * nuevoNodo = malloc(sizeof(NodoSimbolo));
	if (!nuevoNodo) {
		return NULL;
	}
	
	char * nombreCopia = (char *) malloc(strlen(nombre)+1);
	strcpy(nombreCopia,nombre);
	
	nuevoNodo->posicion = posicion;
	nuevoNodo->nombre = nombreCopia;
	nuevoNodo->tipo = -1;
	nuevoNodo->next = NULL;
	return nuevoNodo;
}

// Metodo para crear una lista de simbolos
ListaSimbolo * crearListaSimbolo();

ListaSimbolo * crearListaSimbolo(){
	ListaSimbolo * lista = malloc(sizeof(ListaSimbolo));
	if (!lista) {
		return NULL;
	}
	lista->head = NULL;
	lista->tail = NULL;
	return lista;
}

// Metodo para mostrar el contenido de una lista de simbolos
void mostrarListaSimbolo(ListaSimbolo * lista) {
	NodoSimbolo * current = lista->head;
	if(lista->head == NULL) 
		return;
	printf("Pos\t\tNom\t\tTipo\n");
  	for(; current != NULL; current = current->next)  {
		printf("%d\t\t%s\t\t%d\n", current->posicion,current->nombre,current->tipo);
	}
}

// Metodo para imprimir a un archivo una lista de simbolos
void imprimirAArchivoListaSimbolo(ListaSimbolo * lista, FILE * salida) {
	NodoSimbolo * current = lista->head;
	if(lista->head == NULL) 
		return;
	fprintf(salida,"Pos\t\tNom\t\tTipo\n");
  	for(; current != NULL; current = current->next)  {
		fprintf(salida, "%d\t\t%s\t\t%d\n", current->posicion,current->nombre,current->tipo);
	}
}

// Metodo para agregar una literal a la lista
void agregarSimbolo(ListaSimbolo * lista, int posicion, char * nombre){
	NodoSimbolo * current = NULL;
	if(lista->head == NULL){
		lista->head = crearSimbolo(posicion,nombre);
		lista->tail = lista->head;
	}
	else {
		current = lista->tail;
		current->next = crearSimbolo(posicion,nombre);
		lista->tail = current->next;
	}
}

// Metodo para buscar una un simbolo en la tabla de simbolos
int estaEnLaLista(ListaSimbolo * lista, char * nombre){
	NodoSimbolo * current = lista->head;
	if(lista->head == NULL)
		return -1;
	for(; current != NULL; current = current -> next) {
		if(!strcmp(current->nombre, nombre))
			return current->posicion;
	}
	return -1;
}

// Metodo para eliminar la lista de simbolos
void eliminarListaSimbolo(ListaSimbolo * lista){
	NodoSimbolo * current = lista->head;
	NodoSimbolo * next = current;
	while(current != NULL){
		next = current->next;
		free(current->nombre);
		free(current);
		current = next;
	}
	free(lista);
}
