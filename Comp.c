#include <stdio.h>
#include <stdlib.h>
#include "Comp.h"

void FLVazia(TLista *pLista, int n)
{
    pLista->Item = (Trocha *)malloc(sizeof(Trocha) * n);
    pLista->Primeiro = INICIO;
    pLista->Ultimo = pLista->Primeiro;
}

int LEhVazia(TLista *pLista)
{
    return (pLista->Ultimo == pLista->Primeiro);
}

int LInsere(TLista *pLista, Trocha x)
{
    if (pLista->Ultimo == MaxTam)
        return 0;
    pLista->Item[pLista->Ultimo++] = x;
    return 1;
}

int LRetira(TLista *pLista, int p, Trocha *pX)
{
    int cont;
    if (LEhVazia(pLista) || p >= pLista->Ultimo || p < 0)
    {
        return 0;
    }
    *pX = pLista->Item[p];
    pLista->Ultimo--;
    for (cont = p + 1; cont <= pLista->Ultimo; cont++)
    {
        pLista->Item[cont - 1] = pLista->Item[cont];
    }
    return 1;
}
void LImprime(TLista *pLista)
{
    int i;
    for (i = pLista->Primeiro; i < pLista->Ultimo; i++)
    {
        printf("%s", pLista->Item[i].categoria);
        printf(" %.1f\n", pLista->Item[i].peso);
    }
}

void Particao(int Esq, int Dir, int *i, int *j, TLista *A, int* comparacoes, int* movimentacoes)
{
    Trocha pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = A->Item[(*i + *j) / 2]; /* obtem o pivo x */
    do
    {
        while (pivo.peso > A->Item[*i].peso)
            (*i)++;
        while (pivo.peso < A->Item[*j].peso)
            (*j)--;
        if (*i <= *j)
        {
            aux = A->Item[*i];
            A->Item[*i] = A->Item[*j];
            A->Item[*j] = aux;
            (*i)++;
            (*j)--;
            (*movimentacoes)++;
        }
        (*comparacoes)++;
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, TLista *A, int* comparacoes, int* movimentacoes)
{
    int i, j;
    Particao(Esq, Dir, &i, &j, A, comparacoes, movimentacoes);
    if (Esq < j)
        Ordena(Esq, j, A, comparacoes, movimentacoes);
    if (i < Dir)
        Ordena(i, Dir, A, comparacoes, movimentacoes);
}
void QuickSort(TLista *A, int n, int* comparacoes, int* movimentacoes)
{
    Ordena(0, n - 1, A, comparacoes, movimentacoes);
}

void Bolha(TLista *v, int n, int* comparacoes, int* movimentacoes){
    int i, j;
    Trocha aux;
    for (i = 0; i < n - 1; i++){
        for (j = 1; j < n - i; j++){
            if (v->Item[j].peso <= v->Item[j - 1].peso){
                aux = v->Item[j];
                v->Item[j] = v->Item[j - 1];
                v->Item[j - 1] = aux;
                (*movimentacoes)++;
            } // if
        (*comparacoes)++;
        }
    }
}
