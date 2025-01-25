#include <stdio.h>
#include <string.h>
#include "L_entradas.h"

entradaminerais InicializarMinerale(entradaminerais* entradam, char* nome){
    setNomee(entradam,nome);
    return *entradam;
}
void setNomee(entradaminerais* entradam, char* nome){
    strcpy(entradam->nome, nome);
};

void FLvazia_e(L_entrada* lista_e){
    lista_e->primeiroe = INICIO;
    lista_e->ultimoe= lista_e->primeiroe;
}
int LInsere_e(L_entrada* lista_e, entradaminerais y){
    if(lista_e->ultimoe==maxentrada){
        return 0;
    }
    lista_e->item_e[lista_e->ultimoe++] = y;
    return 1;
}

void LImprime_e(L_entrada* lista_e){
    int i;
    for (i = lista_e->primeiroe; i < lista_e->ultimoe; i++){
        printf("\n%s\n", lista_e->item_e[i].nome);
    }
}

int LEhVazia_e(L_entrada* lista_m){
    return(lista_m->primeiroe == lista_m->primeiroe);
};
int Lretira_e(L_entrada* lista_e) {
    lista_e->ultimoe=0;
    return 0; 
}
