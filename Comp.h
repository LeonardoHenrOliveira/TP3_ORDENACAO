#include <stdio.h>
#include <stdlib.h>
#include "Rochas.h"
#define InicioArranjo 0
#define MaxTam 1000

typedef struct {
 Trocha* Item;
 int Primeiro, Ultimo;
} TLista;


void FLVazia(TLista* pLista, int n);
int LEhVazia(TLista* pLista);
int LInsere(TLista* pLista, Trocha x);
int LRetira(TLista* pLista, int p, Trocha *pX);
void LImprime(TLista* pLista);

void Particao(int Esq, int Dir, int *i, int *j, TLista *A, int* comparacoes, int* movimentacoes);
void Ordena(int Esq, int Dir, TLista *A, int* comparacoes, int* movimentacoes);
void QuickSort(TLista *A, int n, int* comparacoes, int* movimentacoes);
void Bolha(TLista *v, int n, int* comparacoes, int* movimentacoes);
