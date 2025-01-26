#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Comp.h"

int main(){
    clock_t start, stop;
    int comparacoes = 0;
    int movimentacao = 0;

    FILE *arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; 
    }

    int quantidade_rochas;
    if (fscanf(arquivo, "%d", &quantidade_rochas) != 1) {
        printf("Erro ao ler a quantidade de sondas.\n");
        fclose(arquivo);
        return 1;
    }
    TLista comp;
    FLVazia(&comp, quantidade_rochas);

    for (int i = 0; i < quantidade_rochas; i++) {
        int l = 0;
        float latitude, longitude;
        float peso;

        if (fscanf(arquivo, "%f %f %f", &latitude, &longitude, &peso) != 3) {
            printf("Erro ao ler dados da rocha (latitude, longitude, peso).\n");
            break;
            }
            fgetc(arquivo); 

            char minerais_entrada[255];
            if (fgets(minerais_entrada, sizeof(minerais_entrada), arquivo) == NULL) {
                printf("Erro ao ler os minerais da rocha.\n");
                break;
            }
            fgetc(arquivo); 

            minerais_entrada[strcspn(minerais_entrada, "\r\n")] = '\0'; 

            char *token = strtok(minerais_entrada, " ");
            Trocha rnova;
            Trocha rocha;
            L_entrada lista_e;
            FLvazia_e(&lista_e);
            while (token != NULL) {
                if (strlen(token) > 0) {
                    entradaminerais entradam;
                    entradaminerais m1 = InicializarMinerale(&entradam, token);
                    LInsere_e(&lista_e, m1); 
                    l++; 
                }
                token = strtok(NULL, " "); 
            }
            classifica_categoria(&lista_e, &rnova, l); 
            rocha = InicializaRocha(&rnova, i, peso, latitude, longitude);
            Lretira_e(&lista_e);
            LInsere(&comp, rocha); 
    }    
    fclose(arquivo);
    printf("\n=========================================\n");

    int tipo;
    printf("\n0- Bublle / 1- Quick: ");
    scanf("%d:",&tipo);
    if (tipo == 0){
        start = clock();
        Bolha(&comp, quantidade_rochas, &comparacoes, &movimentacao);
        stop = clock();

        double timep = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("tempo gasto %.5lfs\n",timep);
    }else if(tipo==1){
        start = clock();
        QuickSort(&comp, quantidade_rochas, &comparacoes, &movimentacao);
 
    }else {
        printf("valor errado!!");
    }
    LImprime(&comp);

    printf("=========================================");
    printf("\nMovimentacoes totais: %d", movimentacao);
    printf("\nComparcoes totais: %d", comparacoes);
    stop = clock();
    double timep = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\ntempo gasto %.4lfs\n",timep);
    printf("=========================================\n");

}