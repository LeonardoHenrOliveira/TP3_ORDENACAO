#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compartimento.h"

int main(){
    printf("11111111111111");
    compartimento comp;
    FLvazia(&comp);
    FILE *arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; 
    }

    int Rochas;
    if (fscanf(arquivo, "%d", &Rochas) != 1) {
        printf("Erro ao ler a quantidade de sondas.\n");
        fclose(arquivo);
        return 1;
    }
    fgetc(arquivo); 
    
for (int i = 0; i < Rochas; i++) {
        printf("%d\n", Rochas);
        int l = 0;
            float latitude, longitude;
            int peso;

            if (fscanf(arquivo, "%f %f %d", &latitude, &longitude, &peso) != 3) {
                printf("Erro ao ler dados da rocha (latitude, longitude, peso).\n");
                break;
            }
            fgetc(arquivo); 

            char minerais_entrada[255];
            if (fgets(minerais_entrada, sizeof(minerais_entrada), arquivo) == NULL) {
                printf("Erro ao ler os minerais da rocha.\n");
                break;
            }
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
            rocha = InicializaRocha(&rnova, 1, peso, latitude, longitude);
            Lretira_e(&lista_e);
            printf("Rocha inserida na sonda.\n");
            LInsere(&comp, rocha);
    fclose(arquivo);
}

}