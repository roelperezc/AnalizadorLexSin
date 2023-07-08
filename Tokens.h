#ifndef TOKENS_HEADER
#define TOKENS_HEADER

typedef struct nodoToken NodoToken;

typedef struct listaToken ListaToken;

ListaToken * crearListaToken();

void agregarToken(ListaToken * lista, int clase, int valor);
void imprimirAArchivoListaToken(ListaToken * lista, FILE * salida);
void mostrarListaToken(ListaToken * lista);
void eliminarListaToken(ListaToken * lista);

#endif
