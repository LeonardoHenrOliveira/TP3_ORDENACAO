#include <stdio.h>
#include "Compartimento.h"


void FLvazia(compartimento* lista){
    lista->primeiro = INICIO;
    lista->ultimo = lista->primeiro;
};

int LEhVazia(compartimento* lista){
    return(lista->primeiro == lista->ultimo);
};

int LInsere(compartimento* lista, Trocha x){
    if(lista->ultimo == MAXTAM)
        return 0;
    lista->item[lista->ultimo++] = x;
    return 1;
};

int Lretira(compartimento* lista, int p, Trocha *px){
    int cont;
    if(LEhVazia(lista) || p >= lista->ultimo || p < 0)
        return 0;
    
    *px = lista->item[p];
    for(cont = p+1; cont <= lista->ultimo; cont++){
        lista->item[cont - 1] = lista->item[cont];
    }
    return 1;
};

void LImprime(compartimento* lista){
    int i;
    for (i = lista->primeiro; i < lista->ultimo; i++){
        printf("\n%s\n", lista->item[i].latitude);
        printf("%.2f\n", lista->item[i].latitude);
        printf("%.2f\n", lista->item[i].categoria);
        printf("%s\n", lista->item[i].peso);
    }
};