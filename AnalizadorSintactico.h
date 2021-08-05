#ifndef ANASINT_HEADER
#define ANASINT_HEADER

void analisisSintactico(FILE * cadenaAtomos);
char U(FILE * cadenaAtomos, char ch);
char Y(FILE * cadenaAtomos, char ch);
char D(FILE * cadenaAtomos, char ch);
char UP(FILE * cadenaAtomos, char ch);
char DP(FILE * cadenaAtomos, char ch);
char YP(FILE * cadenaAtomos, char ch);
char L(FILE * cadenaAtomos, char ch);
char Z(FILE * cadenaAtomos, char ch);
char V(FILE * cadenaAtomos, char ch);
char A(FILE * cadenaAtomos, char ch);
char AP(FILE * cadenaAtomos, char ch);
char O(FILE * cadenaAtomos, char ch);
char M(FILE * cadenaAtomos, char ch);
char X(FILE * cadenaAtomos, char ch);
char R(FILE * cadenaAtomos, char ch);
char P(FILE * cadenaAtomos, char ch);
char I(FILE * cadenaAtomos, char ch);
char S(FILE * cadenaAtomos, char ch);
char SP(FILE * cadenaAtomos, char ch);
char SPP(FILE * cadenaAtomos, char ch);
char E(FILE * cadenaAtomos, char ch);
char EP(FILE * cadenaAtomos, char ch);
char T(FILE * cadenaAtomos, char ch);
char TP(FILE * cadenaAtomos, char ch);
char F(FILE * cadenaAtomos, char ch);

char avanza(FILE * cadenaAtomos, char ch, char tokenEsperado);
void errorSintactico();

#endif 