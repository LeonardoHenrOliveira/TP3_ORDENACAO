#include <stdio.h>
#include "Rochas.h"

typedef struct {
    Trocha item[10000];
    int primeiro;
    int ultimo;
}compartimento;

void FLvazia(compartimento* lista);
int LEhVazia(compartimento* lista);
int LInsere(compartimento* lista, Trocha x);
int Lretira(compartimento* lista, int p, Trocha *px);
void LImprime(compartimento* lista);
