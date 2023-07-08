#ifndef ANASINT_HEADER
#define ANASINT_HEADER

void analisisSintactico(FILE * cadenaAtomos, char * atomosMemoria);
void U();
void Y();
void D();
void UP();
void DP();
void YP();
void L();
void Z();
void V();
void A();
void AP();
void O();
void M();
void X();
void R();
void P();
void I();
void S();
void SP();
void SPP();
void E();
void EP();
void T();
void TP();
void F();

void avanza(char tokenEsperado);
void errorSintactico();

#endif 