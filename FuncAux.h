#ifndef FUNCAUX_HEADER
#define FUNCAUX_HEADER

int indicePalabraReservada(char * palabra);
int indiceOperadorRelacional(char * palabra);
int str2ascii(char * str);
int str2int(char * str);

void agregaAtomo(FILE * cadenaAtomos, char * atomo);
void agregaAtomoPalRes(FILE * cadenaAtomos, int index);
void agregaAtomoOpRel(FILE * cadenaAtomos, int index);

#endif
