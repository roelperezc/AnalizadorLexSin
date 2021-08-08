#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnalizadorSintactico.h"

FILE * cadenaAtomos = NULL;
char * atomosDin;
char ch;
int n_avance = 1;
int errorSint = 0;

//  <Programa> Simbolo inicial de la gramatica, un programa del lenguaje propuesto.
void analisisSintactico(FILE * atomosArchivo, char * atomosMemoria){
	cadenaAtomos = atomosArchivo;
	atomosDin = atomosMemoria;
	ch = getc(cadenaAtomos);
	U();
	UP();
	if(ch == EOF){
		printf("\nAnalisis sintactico exitoso. Se reconoce como parte de la gramatica.\n");
	}
	else{
		errorSintactico("<fin de cadena>");
	}
}

// <Funcion> Estructura de una funcion
void U(){
	if(ch == 'r' || ch == 'e' || ch == 'v'){
		Y();
		avanza('a');
		avanza('(');
		avanza(')');
		avanza('{');
		D();
		S();
		avanza('}');
	}
	else{
		errorSintactico("DEC ENT VAC");
	}
}

// <unTipo> Un tipo de dato que puede ser ENT/REAL o VAC
void Y(){
	if(ch == 'r' || ch == 'e'){
		YP();
	}
	else if(ch = 'v'){
		avanza('v');
	}
	else{
		errorSintactico("DEC ENT");
	}
}

// <Declaracion> Declaraciones y su generacion recursiva
void D(){
	if(ch == 'm' || ch == 'p' || ch == 's' || ch == 'a' || ch == '['){
		
	}
	else if(ch == 'r' || ch == 'e'){
		DP(cadenaAtomos, ch);
		D(cadenaAtomos, ch);
	}
	else{
		errorSintactico("MIENTRAS PARA SI <ident> [");
	}
}

// <otraFuncion> Otras funciones y su generacion recursiva
void UP(){
	if(ch == EOF){
		
	}
	else if(ch == 'r' || ch == 'e' || ch == 'v' ){
		U();
		UP();
	}
	else{
		errorSintactico("DEC ENT VAC");
	}
}

// <unaDeclara> Una declaracion de datos de tipo DEC/ENT
void DP(){
	if(ch == 'r' || ch == 'e'){
		YP();
		L();
	}
	else{
		errorSintactico("DEC ENT");
	}
}

// <Tipo> El tipo DEC o ENT
void YP(){
	if(ch == 'r'){
		avanza('r');
	}
	else if(ch == 'e'){
		avanza('e');
	}
	else{
		errorSintactico("DEC ENT");
	}
}

// <LV> Lista de variables al ser declaradas
void L(){
	if(ch == 'a'){
		avanza('a');
		Z();
		V();
	}
	else{
		errorSintactico("<ident>");
	}
}

// <VEC> Indicador de que una variable es un vector
void Z(){
	if(ch == ',' || ch == ';' || ch == '*' || ch == '/' || ch == '+' || ch == '-' ||
	   ch == ']' || ch == '#' || ch == 'g' || ch == '>' || ch == 'y' || ch == '<' ||
	   ch == 'l' || ch == ')'){
		
	}
	else if(ch == '['){
		avanza('[');
		avanza('i');
		avanza(']');
	}
	else{
		errorSintactico(", ; * / + - ] # == > >= < <= )");
	}
}

// <MasVar> Variables adicionales y su generacion recursiva
void V(){
	if(ch == ','){
		avanza(',');
		avanza('a');
		Z();
		V();
	}
	else if(ch == ';'){
		avanza(';');
	}
	else{
		errorSintactico(", ;");
	}
}

// <Asigna> Sentencias de asignacion
void A(){
	if(ch == 'a'){
		avanza('a');
		avanza('=');
		AP();
		O();
	}
	else{
		errorSintactico("<ident>");
	}
}

// <masAsigna> Sentencias de asignacion de varias variables al mismo tiempo
void AP(){
	if(ch == 'a'){
		avanza('a');
		avanza('=');
		AP();
	}
	else if(ch == '[' || ch == 'c'){
		
	}
	else{
		errorSintactico("<ident> [ <cadena>");
	}
}

// <aritOcadena> Generacion de una expresion aritmetica o una cadena
void O(){
	if(ch == '['){
		avanza('[');
		E();
		avanza(']');
		
	}
	else if(ch == 'c'){
		avanza('c');
		avanza(';');
	}
	else{
		errorSintactico("[ <cadena>");
	}
}

// <MIENTRAS> Sentencia de un ciclo while
void M(){
	if(ch == 'm'){
		avanza('m');
		avanza('(');
		X();
		avanza(')');
		avanza('{');
		S();
		avanza('}');
	}
	else{
		errorSintactico("MIENTRAS");
	}
}

// <expresion> Expresion booleana
void X(){
	if(ch == '(' || ch == 'a' || ch == 'i' || ch == 'd'){
		E();
		R();
		E();
	}
	else{
		errorSintactico("( <ident> <cte ent> <cte dec>");
	}
}

// <op.relacional> Operadores relacionales
void R(){
	if(ch == '#'){
		avanza('#');
	}
	else if(ch == 'g'){
		avanza('g');
	}
	else if(ch == '>'){
		avanza('>');
	}
	else if(ch == 'y'){
		avanza('y');
	}
	else if(ch == '<'){
		avanza('<');
	}
	else if(ch == 'l'){
		avanza('l');
	}
	else{
		errorSintactico("# == > >= < <=");
	}
}

// <PARA> Sentencia de un ciclo for
void P(){
	if(ch == 'p'){
		avanza('p');
		avanza('(');
		avanza('a');
		avanza('=');
		avanza('i');
		avanza(';');
		X();
		avanza(';');
		avanza('a');
		avanza('=');
		avanza('a');
		avanza('+');
		avanza('i');
		avanza(')');
		avanza('{');
		S();
		avanza('}');
	}
	else{
		errorSintactico("PARA");
	}
}

// <SI> Sentencia de una condicional if-else
void I(){
	if(ch == 's'){
		avanza('s');
		avanza('(');
		X();
		avanza(')');
		avanza('{');
		S();
		avanza('}');
		avanza('n');
		avanza('{');
		S();
		avanza('}');
	}
	else{
		errorSintactico("SI");
	}
}

// <Sentencias> Generacion de sentencias recursivamente
void S(){
	if(ch == 'm' || ch == 'p' || ch == 's' || ch == 'a' || ch == '['){
		SP();
		SPP();
	}
	else{
		errorSintactico("MIENTRAS PARA SI <ident> [");
	}
}

// <unaSent> Sentencias while, for, if, asignacion y llamadas a funciones
void SP(){
	if(ch == 'm'){
		M();
	}
	else if(ch == 'p'){
		P();
	}
	else if(ch == 's'){
		I();
	}
	else if(ch == 'a'){
		A();
	}
	else if(ch == '['){
		avanza('[');
		avanza('a');
		avanza('(');
		avanza(')');
		avanza(']');
	}
	else{
		errorSintactico("MIENTRAS PARA SI <ident> [");
	}
}

// <otraSent> Generacion recursiva de sentencias
void SPP(){
	if(ch == 'm' || ch == 'p' || ch == 's' || ch == 'a' || ch == '['){
		SP();
		SPP();
	}
	else if (ch == '}'){
		
	}
	else{
		errorSintactico("MIENTRAS PARA SI <ident> [");
	}
}

// <expr.arit> Expresiones aritmeticas
void E(){
	if(ch == '(' || ch == 'a' || ch == 'i' || ch == 'd' ){
		T();
		EP();
	}
	else{
		errorSintactico("( <ident> <cte ent> <cte dec>");
	}
}

// Generacion de sumas y restas
void EP(){
	if(ch == '+' ){
		avanza('+');
		T();
		EP();
	}
	else if(ch == '-' ){
		avanza('-');
		T();
		EP();
	}
	else if(ch == ']' || ch == '#' || ch == 'g' || ch == '>' || ch == 'y' || ch == '<' ||
	   		ch == 'l' || ch == ')' || ch == ';' ){
		
	}
	else{
		errorSintactico("+ - ] # == > >= < <= ) ;");
	}
}

// Generacion de expresiones aritmeticas
void T(){
	if(ch == '(' || ch == 'a' || ch == 'i' || ch == 'd' ){
		F();
		TP();
	}
	else{
		errorSintactico("( <ident> <cte ent> <cte dec>");
	}
}

// Generacion de multiplicaciones y divisiones
void TP(){
	if(ch == '*' ){
		avanza('*');
		F();
		TP();
	}
	else if(ch == '/' ){
		avanza('/');
		F();
		TP();
	}
	else if(ch == ']' || ch == '#' || ch == 'g' || ch == '>' || ch == 'y' || ch == '<' ||
	   		ch == 'l' || ch == ')' || ch == ';' || ch == '+' || ch == '-' ){
		
	}
	else{
		errorSintactico("* / ] # == > >= < <= ) ; + -");
	}
}

// Generacion de los oepradores como variables o constantes
void F(){
	if(ch == '(' ){
		avanza('(');
		E();
		avanza(')');
	}
	else if(ch == 'a' ){
		avanza('a');
		Z();
	}
	else if(ch == 'i' ){
		avanza('i');
	}
	else if(ch == 'd' ){
		avanza('d');
	}
	else{
		errorSintactico("( <ident> <cte ent> <cte dec>");
	}
}

// Atomos y los tokens que representan
char atomosTokens[14][2][10] ={{"r", "DEC"},
							   {"e", "ENT"},
							   {"m", "MIENTRAS"},
							   {"p", "PARA"},
							   {"s", "SI"},
							   {"n", "SINO"},
							   {"v", "VAC"},
							   {"a", "<ident>"},
							   {"c", "<cadena>"},
							   {"g", "=="},
							   {"y", ">="},
							   {"l", "<="},
							   {"i", "<cte ent>"},
							   {"d", "<cte dec>"}
								};

// Atomo que es su propio token, global
char atomoToken[2] = {'\0','\0'};

// Metodo que devuelve cual es el token de un atomo 
char * atomosATokens(char atomo){
	for(int i = 0; i < 14; i++){
		if(atomo == atomosTokens[i][0][0]){
			return atomosTokens[i][1]; 
		}
	}
	atomoToken[0] = atomo;
	return atomoToken;
}

// Metodo para avanzar un token en la cadena si es el esperado o en caso contrario
// mandar error sintactico. 
void avanza(char tokenEsperado){
	if(!(ch == tokenEsperado)){
		errorSintactico(atomosATokens(tokenEsperado));
	}
	ch = getc(cadenaAtomos);
	n_avance++;
}

// Metodo para terminar el programa en caso de error sintactico. 
void errorSintactico(char * tokensEsperados){
	printf("\nError sintactico en token %d\n", n_avance);
	printf("%.*s\n", n_avance, atomosDin);
	printf("Se esperaba alguno de los siguientes tokens: %s\n", tokensEsperados);
	remove("atomos_temp.txt");
	exit(0);
}