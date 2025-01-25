#include <stdio.h>
#define tamanhomaxnome 100
#define tamanhomaxcor 100
#define MAXTAM 5
#define maxentrada 3
#define INICIO 0

typedef struct {
    char nome[tamanhomaxnome];
}entradaminerais;

typedef struct {
    entradaminerais item_e[MAXTAM];
    int primeiroe;
    int ultimoe;
}L_entrada;



entradaminerais InicializarMinerale(entradaminerais* entradam, char* nome);
void setNomee(entradaminerais* entradam, char* nome);

int LEhVazia_e(L_entrada* lista_m);
void FLvazia_e(L_entrada* lista_e);
int LInsere_e(L_entrada* lista_e, entradaminerais y);
void LImprime_e(L_entrada* lista_e);
int Lretira_e(L_entrada* lista_e);