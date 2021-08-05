#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnalizadorSintactico.h"

void analisisSintactico(FILE * cadenaAtomos){
	char ch = getc(cadenaAtomos);
	ch = U(cadenaAtomos, ch);
	ch = UP(cadenaAtomos, ch);
	if(ch == EOF){
		printf("Se acepta como parte de la gramatica.");
	}
	else{
		errorSintactico();
	}
		   
}

char U(FILE * cadenaAtomos, char ch){
	if(ch == 'r' || ch == 'e' || ch == 'v'){
		ch = Y(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch,'a');
		ch = avanza(cadenaAtomos, ch,'(');
		ch = avanza(cadenaAtomos, ch,')');
		ch = avanza(cadenaAtomos, ch,'{');
		ch = D(cadenaAtomos, ch);
		ch = S(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch,'}');
	}
	else{
		errorSintactico();
	}
	return ch;
}

char Y(FILE * cadenaAtomos, char ch){
	if(ch == 'r' || ch == 'e'){
		ch = YP(cadenaAtomos, ch);
	}
	else if(ch = 'v'){
		ch = avanza(cadenaAtomos, ch,'v');
	}
	else{
		errorSintactico();
	}
	return ch;
}

char D(FILE * cadenaAtomos, char ch){
	if(ch == 'm' || ch == 'p' || ch == 's' || ch == 'a' || ch == '['){
		
	}
	else if(ch == 'r' || ch == 'e'){
		ch = DP(cadenaAtomos, ch);
		ch = D(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
	return ch;
}

char UP(FILE * cadenaAtomos, char ch){
	if(ch == EOF){
		
	}
	else if(ch == 'r' || ch == 'e' || ch == 'v' ){
		ch = U(cadenaAtomos, ch);
		ch = UP(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
	return ch;
}

char DP(FILE * cadenaAtomos, char ch){
	if(ch == 'r' || ch == 'e' || ch == 'v'){
		ch = YP(cadenaAtomos, ch);
		ch = L(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
	return ch;
}

char YP(FILE * cadenaAtomos, char ch){
	if(ch == 'r'){
		ch = avanza(cadenaAtomos, ch, 'r');
	}
	else if(ch == 'e'){
		ch = avanza(cadenaAtomos, ch, 'e');
	}
	else{
		errorSintactico();
	}
	return ch;
}

char L(FILE * cadenaAtomos, char ch){
	if(ch == 'a'){
		ch = avanza(cadenaAtomos, ch,'a');
		ch = Z(cadenaAtomos, ch);
		ch = V(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
	return ch;
}

char Z(FILE * cadenaAtomos, char ch){
	if(ch == ',' || ch == ';' || ch == '*' || ch == '/' || ch == '+' || ch == '-' ||
	   ch == ']' || ch == '#' || ch == ']' || ch == '#' || ch == 'g' || ch == '>' ||
	   ch == 'y' || ch == '<' || ch == 'l'){
		
	}
	else if(ch == '['){
		ch = avanza(cadenaAtomos, ch, '[');
	}
	else{
		errorSintactico();
	}
	return ch;
}

char V(FILE * cadenaAtomos, char ch){
	if(ch == ','){
		ch = avanza(cadenaAtomos, ch, ',');
		ch = avanza(cadenaAtomos, ch, 'a');
		ch = Z(cadenaAtomos, ch);
		ch = V(cadenaAtomos, ch);
	}
	else if(ch == ';'){
		ch = avanza(cadenaAtomos, ch, ';');
	}
	else{
		errorSintactico();
	}
	return ch;
}

char A(FILE * cadenaAtomos, char ch){
	if(ch == 'a'){
		ch = avanza(cadenaAtomos, ch, 'a');
		ch = avanza(cadenaAtomos, ch, '=');
		ch = AP(cadenaAtomos, ch);
		ch = O(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
	return ch;
}

char AP(FILE * cadenaAtomos, char ch){
	if(ch == 'a'){
		ch = avanza(cadenaAtomos, ch, 'a');
		ch = avanza(cadenaAtomos, ch, '=');
		ch = AP(cadenaAtomos, ch);
	}
	else if(ch == '[' || ch == 'c'){
		
	}
	else{
		errorSintactico();
	}
	return ch;
}

char O(FILE * cadenaAtomos, char ch){
	if(ch == '['){
		ch = avanza(cadenaAtomos, ch, '[');
		ch = E(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch, ']');
		
	}
	else if(ch == 'c'){
		ch = avanza(cadenaAtomos, ch, 'c');
		ch = avanza(cadenaAtomos, ch, ';');
	}
	else{
		errorSintactico();
	}
	return ch;
}

char M(FILE * cadenaAtomos, char ch){
	if(ch == 'm'){
		ch = avanza(cadenaAtomos, ch, 'm');
		ch = avanza(cadenaAtomos, ch, '(');
		ch = X(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch, ')');
		ch = avanza(cadenaAtomos, ch, '{');
		ch = S(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch, '}');
	}
	else{
		errorSintactico();
	}
	return ch;
}

char X(FILE * cadenaAtomos, char ch){
	if(ch == '(' || ch == 'a' || ch == 'i' || ch == 'd'){
		ch = E(cadenaAtomos, ch);
		ch = R(cadenaAtomos, ch);
		ch = E(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
	return ch;
}
	
char R(FILE * cadenaAtomos, char ch){
	if(ch == '#'){
		ch = avanza(cadenaAtomos, ch, '#');
	}
	else if(ch == 'g'){
		ch = avanza(cadenaAtomos, ch, 'g');
	}
	else if(ch == '>'){
		ch = avanza(cadenaAtomos, ch, '>');
	}
	else if(ch == 'y'){
		ch = avanza(cadenaAtomos, ch, 'y');
	}
	else if(ch == '<'){
		ch = avanza(cadenaAtomos, ch, '<');
	}
	else if(ch == 'l'){
		ch = avanza(cadenaAtomos, ch, 'l');
	}
	else{
		errorSintactico();
	}
	return ch;
}

char P(FILE * cadenaAtomos, char ch){
	if(ch == 'p'){
		ch = avanza(cadenaAtomos, ch, 'p');
		ch = avanza(cadenaAtomos, ch, '(');
		ch = avanza(cadenaAtomos, ch, 'a');
		ch = avanza(cadenaAtomos, ch, '=');
		ch = avanza(cadenaAtomos, ch, 'i');
		ch = avanza(cadenaAtomos, ch, ';');
		ch = X(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch, ';');
		ch = avanza(cadenaAtomos, ch, 'a');
		ch = avanza(cadenaAtomos, ch, '=');
		ch = avanza(cadenaAtomos, ch, 'a');
		ch = avanza(cadenaAtomos, ch, '+');
		ch = avanza(cadenaAtomos, ch, 'i');
		ch = avanza(cadenaAtomos, ch, ')');
		ch = avanza(cadenaAtomos, ch, '{');
		ch = S(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch, '}');
	}
	else{
		errorSintactico();
	}
	return ch;
}


char I(FILE * cadenaAtomos, char ch){
	if(ch == 's'){
		ch = avanza(cadenaAtomos, ch, 's');
		ch = avanza(cadenaAtomos, ch, '(');
		ch = X(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch, ')');
		ch = avanza(cadenaAtomos, ch, '{');
		ch = S(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch, '}');
		ch = avanza(cadenaAtomos, ch, 'n');
		ch = avanza(cadenaAtomos, ch, '{');
		ch = S(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch, '}');
	}
	else{
		errorSintactico();
	}
	return ch;
}

char S(FILE * cadenaAtomos, char ch){
	if(ch == 'm' || ch == 'p' || ch == 's' || ch == 'a' || ch == '['){
		ch = SP(cadenaAtomos, ch);
		ch = SPP(cadenaAtomos, ch);

	}
	else{
		errorSintactico();
	}
	return ch;
}

char SP(FILE * cadenaAtomos, char ch){
	if(ch == 'm'){
		ch = M(cadenaAtomos, ch);
	}
	else if(ch == 'p'){
		ch = P(cadenaAtomos, ch);
	}
	else if(ch == 's'){
		ch = P(cadenaAtomos, ch);
	}
	else if(ch == 'a'){
		ch = I(cadenaAtomos, ch);
	}
	else if(ch == '['){
		ch = A(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
	return ch;
}

char SPP(FILE * cadenaAtomos, char ch){
	if(ch == 'm' || ch == 'p' || ch == 's' || ch == 'a' || ch == '['){
		ch = SP(cadenaAtomos, ch);
		ch = SPP(cadenaAtomos, ch);
	}
	else if (ch == '}'){
		
	}
	else{
		errorSintactico();
	}
	return ch;
}

char E(FILE * cadenaAtomos, char ch){
	if(ch == '(' || ch == 'a' || ch == 'i' || ch == 'd' ){
		ch = T(cadenaAtomos, ch);
		ch = EP(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
	return ch;
}

char EP(FILE * cadenaAtomos, char ch){
	if(ch == '+' ){
		ch = avanza(cadenaAtomos, ch, '+');
		ch = T(cadenaAtomos, ch);
		ch = EP(cadenaAtomos, ch);
	}
	else if(ch == '-' ){
		ch = avanza(cadenaAtomos, ch, '-');
		ch = T(cadenaAtomos, ch);
		ch = EP(cadenaAtomos, ch);
	}
	else if(ch == ']' || ch == '#' || ch == 'g' || ch == '>' || ch == 'y' || ch == '<' ||
	   		ch == ')' || ch == 'l' ){
		
	}
	else{
		errorSintactico();
	}
	return ch;
}

char T(FILE * cadenaAtomos, char ch){
	if(ch == '(' || ch == 'a' || ch == 'i' || ch == 'd' ){
		ch = F(cadenaAtomos, ch);
		ch = TP(cadenaAtomos, ch);
	}
	else{
		errorSintactico();
	}
	return ch;
}

char TP(FILE * cadenaAtomos, char ch){
	if(ch == '*' ){
		ch = avanza(cadenaAtomos, ch, '*');
		ch = F(cadenaAtomos, ch);
		ch = TP(cadenaAtomos, ch);
	}
	else if(ch == '/' ){
		ch = avanza(cadenaAtomos, ch, '/');
		ch = F(cadenaAtomos, ch);
		ch = TP(cadenaAtomos, ch);
	}
	else if(ch == ']' || ch == '#' || ch == 'g' || ch == '>' || ch == 'y' || ch == '<' ||
	   		ch == 'l' || ch == ')' || ch == ';' ){
		
	}
	else{
		errorSintactico();
	}
	return ch;
}

char F(FILE * cadenaAtomos, char ch){
	if(ch == '(' ){
		ch = avanza(cadenaAtomos, ch, '(');
		ch = E(cadenaAtomos, ch);
		ch = avanza(cadenaAtomos, ch, ')');
	}
	else if(ch == 'a' ){
		ch = avanza(cadenaAtomos, ch, 'a');
		ch = Z(cadenaAtomos, ch);
	}
	else if(ch == 'i' ){
		ch = avanza(cadenaAtomos, ch, 'i');
	}
	else if(ch == 'd' ){
		ch = avanza(cadenaAtomos, ch, 'd');
	}
	else{
		errorSintactico();
	}
	return ch;
}


char avanza(FILE * cadenaAtomos, char ch, char tokenEsperado){
	if(!(ch == tokenEsperado)){
		errorSintactico();
	}
	return getc(cadenaAtomos);
}

void errorSintactico(){
	printf("Error sintactico");
	exit(0);
}