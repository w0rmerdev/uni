#include "stackar.h"
#include "fatal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )


struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};



Stack CreateStack( int MaxElements )
{

    Stack S;	

	if( MaxElements < MinStackSize )
		Error( "Stack size is too small" );

	S = malloc( sizeof( struct StackRecord ) );
	if( S == NULL )
		FatalError( "Out of space!!!" );

	S->Array = malloc( sizeof( ElementType ) * MaxElements );
	if( S->Array == NULL )
		FatalError( "Out of space!!!" );

	S->Capacity = MaxElements;
	MakeEmpty( S );

	return S;
}



void DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}


int IsEmpty( Stack S )
{
	// verificar se o top é igual a -1
	return S->TopOfStack == EmptyTOS; // if(S->TopOfStack == -1(EmptyTOS)) { return 1; } else{ return 0; }
}


int IsFull( Stack S )
{
	// verificar se o top é igual a capicity -1
	return S->TopOfStack == S->Capacity - 1;
}


void MakeEmpty( Stack S )
{
	// esvaziar o stack e top = -1
	S->TopOfStack = EmptyTOS;
}


void Push( ElementType X, Stack S )
{
	// adicionar um elemento
	if(IsFull(S))
		Error("Stack is full."); // se o stack estiver cheio dá erro
	S->Array[++S->TopOfStack] = X; // incrementar o Top por 1 e adicionar 
								   // o elemento o elemento X ao topo do stack
}


ElementType Top( Stack S )
{
	// mostrar o último elemento sem o remover
	if(IsEmpty(S))
		Error("Stack is empty.");
	return S->Array[S->TopOfStack];
}


ElementType Pop( Stack S )
{
	// remover o último elemento
	if(IsEmpty(S))
		Error("Stack is empty.");
	return S->Array[S->TopOfStack--];
}

char* arrayFilter(char *c, int sz) {
   char* result;
   int j = 0;
   for(int i = 0; i < sz; i++) {
      if(c[i] == '(' || c[i] == ')' || c[i] == '[' || c[i] == ']' || c[i] == '{' || c[i] == '}') {
         result[j] == c[i];
         j++;
      }
   }

   return result;
}

int isOpenParen(char c){
	if(c == '(' || c == '[' || c == '{'){ return 1; } else { return 0; }
}

int isClosedParen(char c){
	if(c == ')' || c == ']' || c == '}'){ return 1; } else { return 0; }
}

int match(char ch1, char ch2){
	if(ch1 == '(' && ch2 == ')'){
		return 1;
	} else if(ch1 == '[' && ch2 == ']'){
		return 1;
	} else if(ch1 == '{' && ch2 == '}'){
		return 1;
	} else{
		return 0;
	}
}

int ParenthesisMatch( char *s ) {
	Stack S = CreateStack(100);
   int sz = 0;
   char* cleanArray = arrayFilter(s, sz);

   for(int i = 0; s[i] != '\0'; i++) {
      sz++;
   }
   printf("size: %d \n", sz);

	int flag = 2;
	char cha;

	for(int i = 0; i < sz; i++) {
		if(isOpenParen(s[i])) {
			Push(s[i], S);
		} else {
			if(isClosedParen(s[i]) && S->TopOfStack != -1) {
				cha = Pop( S );
				if(match(cha, s[i])) {
					printf("'%c' matches with '%c'\n", cha, s[i]);
				} else {
					printf("'%c' does not match with '%c'\n", cha, s[i]);
					flag = -1;
				}
			} else {
				flag = -1;
			}
		}
	}

	if(flag == -1){return 0;} else {return 1;}
}

int q1(long n) {
   long c = n;
   Stack S = CreateStack(20);
   
   while(n>0) {
      Push(n%10, S);
      n /= 10;
   }

   while(!IsEmpty(S)){
      if(Pop(S) != c%10)
         return 0;
      c /= 10;
   }

   return 1;
}

// 2.
//int main(){
   //Stack S = CreateStack(100);

// 	// 2.a) 23 56- 3* 1 3 4 / + /
// 	// 2.b) 2 4 7 32 / + 7 5 - 3 *- -
// 	// 2.c) 2 6 + 4 7 * 5 - / 6 9 / * 4 9 * 5 3 / + -

// 	// 2.a) 23 56- 3* 1 3 4 / + /
// 	float a,b;
// 	Push(23, S);
// 	Push(56, S);
// 	b = Pop( S );
// 	a = Pop ( S );
// 	Push(a-b, S);
// 	Push(3, S);
// 	b = Pop( S );
// 	a = Pop( S );
// 	Push(a*b, S);
// 	Push(1, S);
// 	Push(3, S);
// 	Push(4, S);
// 	b = Pop( S );
// 	a = Pop( S );
// 	Push(a/b, S);
// 	b = Pop( S );
// 	a = Pop( S );
// 	Push(a+b, S);
// 	b = Pop( S );
// 	a = Pop( S);
// 	Push(a/b, S);
// 	printf("%f popped \n", Pop(S));
	
// 	// 2.b) 2 4 7 32 / + 7 5 - 3 *- -
// 	float c, d;
// 	Push(2, S);
// 	Push(4, S);
// 	Push(7, S);
// 	Push(32, S);
// 	d = Pop( S );
// 	c = Pop( S );
// 	Push(c / d, S);
// 	d = Pop( S );
// 	c = Pop( S );
// 	Push(c + d, S);
// 	Push(7, S);
// 	Push(5, S);
// 	d = Pop( S );
// 	c = Pop( S );
// 	Push(c - d, S);
// 	Push(3, S);
// 	d = Pop( S );
// 	c = Pop( S );
// 	Push(c * d, S);
// 	d = Pop( S );
// 	c = Pop( S );
// 	Push(c - d, S);
// 	d = Pop( S );
// 	c = Pop( S );
// 	Push(c - d, S);
// 	printf("%f popped \n", Pop(S));

// 	// 2.c) 2 6 + 4 7 * 5 - / 6 9 / * 4 9 * 5 3 / + -
// 	float e, f;
// 	Push(2, S);
// 	Push(6, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e + f, S);
// 	Push(4, S);
// 	Push(7, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e * f, S);
// 	Push(5, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e - f, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e / f, S);
// 	Push(6, S);
// 	Push(9, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e / f, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e * f, S);
// 	Push(4, S);
// 	Push(9, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e * f, S);
// 	Push(5, S);
// 	Push(3, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e / f, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e + f, S);
// 	f = Pop( S );
// 	e = Pop( S );
// 	Push(e - f, S);
// 	printf("Resultado = %f \n", Top( S ));
// 	Pop( S );
//}


// 3.

// int main(){
// 	Stack S = CreateStack(100);
// 	char c1[] = {'{','[', '(', ')', ']', '}'};
// 	char c2[] = {')', '(', '('};
// 	int sz1 = 6, sz2 = 3;
// 	char cha;
// 	int flag = 2;
// 	int flag2 = 2;

// 	for(int i = 0; i < sz1; i++){
// 		if(isOpenParen(c1[i])){
// 			Push(c1[i], S);
// 		} else{
// 			if(isClosedParen(c1[i]) && S->TopOfStack != -1){
// 				cha = Pop( S );
// 				if(match(cha, c1[i])){
// 					printf("'%c' matches with '%c'\n", cha, c1[i]);
// 				} else{
// 					printf("'%c' does not match with '%c'\n", cha, c1[i]);
// 					flag = -1;
// 				}
// 			} else {
// 				flag = -1;
// 			}
// 		}
// 	}

// 	if(flag == -1){ printf("not balanced\n"); } else { printf("balanced\n"); }

// 	MakeEmpty( S );

// 	for(int j = 0; j < sz2; j++){
// 		if(isOpenParen(c2[j])){
// 			Push(c2[j], S);
// 		} else{
// 			if(isClosedParen(c2[j]) && S->TopOfStack != -1){
// 				cha = Pop( S );
// 				if(match(cha, c2[j])){
// 					printf("'%c' matches with '%c'\n", cha, c2[j]);
// 				} else{
// 					printf("'%c' does not match with '%c'\n", cha, c2[j]);
// 					flag2 = -1;
// 				}
// 			} else {
// 				flag2 = -1;
// 			}
// 		}
// 	}

// 	if(flag2 == -1){ printf("not balanced\n"); } else { printf("balanced\n"); }
	
// 	printf("Teste: \n");

// 	int x = ParenthesisMatch(c1);
// 	int y = ParenthesisMatch(c2);

// 	if(x == 0){ printf("not balanced\n"); } else { printf("balanced\n"); }
// 	if(y == 0){ printf("not balanced\n"); } else { printf("balanced\n"); }

// }


// ( AX + ( B * C ) )
// AX B C * +

// ( ( AX + ( B * CY ) ) / ( D ­- E ) )
// AX B CY * + D E - /

// ( ( A + B ) * ( C + E ) )
// A B + C E + *

// ( AX * ( BX * ( ( ( CY + AY ) + BY ) * CX ) ) )
// AX BX CY AY + BY + CX * * *

// ( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J )
// H A B C + D * + F * G * E * * J +
