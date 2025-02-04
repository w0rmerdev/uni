#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "fatal.h"
#include "../Code_Stacks/stackar.h"
#include "../Code_Stacks/exs_stacks.c"

void Entrada(ElementType carr, Stack q) {
   if(IsFull(q))
      Error("Stack is full.");

   Push(carr, q);
}

void Saida(Stack q) {
   if(IsEmpty(q))
      Error("Stack is empty.");

   Pop(q);
}

void F(Stack q, Stack r) {
   if(IsEmpty(q))
      Error("Stack is empty.");
   if(IsFull(r))
      Error("Stack is full.");

   Push(Pop(q), r);
}

void G(Stack q, Stack r) {
   if(IsEmpty(q))
      Error("Stack is empty.");
   if(IsFull(r))
      Error("Stack is full.");

   Push(Pop(q), r);
}

int main() {
   Stack A = CreateStack(10);   
   Stack B = CreateStack(10);   
   Stack C = CreateStack(10);

   Entrada(1, A);
   Entrada(2, A);
   Entrada(3, A);
   Entrada(4, A);
   F(A, B);
   F(A, B);
   F(A, B);
   F(A, B);
   G(B, C);
   G(B, C);
   G(B, C);
   G(B, C);
   Saida(C);
   Saida(C);
   Saida(C);
   Saida(C);
}
