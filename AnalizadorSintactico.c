#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnalizadorSintactico.h"

FILE * cadenaAtomos = NULL;
char ch;
long n_avance = 1; 

void analisisSintactico(FILE * atomos_temp){
	cadenaAtomos = atomos_temp;
	ch = getc(cadenaAtomos);
	U();
	UP();
	if(ch == EOF){
		printf("Se acepta como parte de la gramatica.");
	}
	else{
		errorSintactico();
	}	   
}

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
		errorSintactico();
	}
}

void Y(){
	if(ch == 'r' || ch == 'e'){
		YP();
	}
	else if(ch = 'v'){
		avanza('v');
	}
	else{
		errorSintactico();
	}
}

void D(){
	if(ch == 'm' || ch == 'p' || ch == 's' || ch == 'a' || ch == '['){
		
	}
	else if(ch == 'r' || ch == 'e'){
		DP(cadenaAtomos, ch);
		D(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
}

void UP(){
	if(ch == EOF){
		
	}
	else if(ch == 'r' || ch == 'e' || ch == 'v' ){
		U();
		UP();
	}
	else{
		errorSintactico();
	}
}

void DP(){
	if(ch == 'r' || ch == 'e' || ch == 'v'){
		YP();
		L();
	}
	else{
		errorSintactico();
	}
}

void YP(){
	if(ch == 'r'){
		avanza('r');
	}
	else if(ch == 'e'){
		avanza('e');
	}
	else{
		errorSintactico();
	}
}

void L(){
	if(ch == 'a'){
		avanza('a');
		Z();
		V();
	}
	else{
		errorSintactico();
	}
}

void Z(){
	if(ch == ',' || ch == ';' || ch == '*' || ch == '/' || ch == '+' || ch == '-' ||
	   ch == ']' || ch == '#' || ch == ']' || ch == '#' || ch == 'g' || ch == '>' ||
	   ch == 'y' || ch == '<' || ch == 'l'){
		
	}
	else if(ch == '['){
		avanza('[');
	}
	else{
		errorSintactico();
	}
}

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
		errorSintactico();
	}
}

void A(){
	if(ch == 'a'){
		avanza('a');
		avanza('=');
		AP();
		O();
	}
	else{
		errorSintactico();
	}
}

void AP(){
	if(ch == 'a'){
		avanza('a');
		avanza('=');
		AP();
	}
	else if(ch == '[' || ch == 'c'){
		
	}
	else{
		errorSintactico();
	}
}

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
		errorSintactico();
	}
}

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
		errorSintactico();
	}
}

void X(){
	if(ch == '(' || ch == 'a' || ch == 'i' || ch == 'd'){
		E();
		R();
		E();
	}
	else{
		errorSintactico();
	}
}
	
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
		errorSintactico();
	}
}

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
		errorSintactico();
	}
}


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
		errorSintactico();
	}
}

void S(){
	if(ch == 'm' || ch == 'p' || ch == 's' || ch == 'a' || ch == '['){
		SP();
		SPP();
	}
	else{
		errorSintactico();
	}
}

void SP(){
	if(ch == 'm'){
		M();
	}
	else if(ch == 'p'){
		P();
	}
	else if(ch == 's'){
		P();
	}
	else if(ch == 'a'){
		I();
	}
	else if(ch == '['){
		A();
	}
	else{
		errorSintactico();
	}
}

void SPP(){
	if(ch == 'm' || ch == 'p' || ch == 's' || ch == 'a' || ch == '['){
		SP();
		SPP();
	}
	else if (ch == '}'){
		
	}
	else{
		errorSintactico();
	}
}

void E(){
	if(ch == '(' || ch == 'a' || ch == 'i' || ch == 'd' ){
		T();
		EP();
	}
	else{
		errorSintactico();
	}
}

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
	   		ch == ')' || ch == 'l' ){
		
	}
	else{
		errorSintactico();
	}
}

void T(){
	if(ch == '(' || ch == 'a' || ch == 'i' || ch == 'd' ){
		F();
		TP();
	}
	else{
		errorSintactico();
	}
}

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
	   		ch == 'l' || ch == ')' || ch == ';' ){
		
	}
	else{
		errorSintactico();
	}
}

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
		errorSintactico();
	}
}


void avanza(char tokenEsperado){
	if(!(ch == tokenEsperado)){
		errorSintactico();
	}
	ch = getc(cadenaAtomos);
	n_avance++;
}

void errorSintactico(){
	printf("Error sintactico");
	exit(0);
}