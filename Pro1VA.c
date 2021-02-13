#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main() {
    int memoria[25] = {};
    int A = 0, B = 0, C = 0, D = 0;
    char leituraDeDados[29];

    //Introdu��o
    printf("** Bem vindo ao Simulador Assembly em Linguagem C **\n");
    while (1) {
        printf("Banco de registradores: A:%i B:%i C:%i D:%i", A, B, C, D);
        printf("\nMemoria de dados:");
        for (int i = 0; i < 25; i++) {
            printf(" %i ", memoria[i]);
        }
        printf("\n");
        gets(leituraDeDados);
        char * instrucao, * parametro1, * parametro2;
        instrucao = strtok(leituraDeDados, " ");
        parametro1 = strtok(NULL, ",");
        parametro2 = strtok(NULL, " ");

        if (strcmp(instrucao, "HLT") == 0) {
            break;

        } else if (strcmp(instrucao, "MOV") == 0) {
            if (parametro1[0] == 'A') {
                if (parametro2[0] == 'B') {
                    A = B;
                } else if (parametro2[0] == 'C') {
                    A = C;
                } else if (parametro2[0] == 'D') {
                    A = D;
                } else if (parametro2[0] == '[') {
                    char posicaodamemoria[] = "";
                    int indice = 1;
                    while (parametro2[indice] != ']') {
                        char temp[2] = {
                            parametro2[indice]};
                        strcat(posicaodamemoria, temp);
                        indice++;
                    }
                    int indicePosicaoDaMemoria = atoi(posicaodamemoria);
                    A = memoria[indicePosicaoDaMemoria];
                } else {
                    A = atoi(parametro2);
                }
            } else if (parametro1[0] == 'B') {
                if (parametro2[0] == 'A') {
                    B = A;
                } else if (parametro2[0] == 'C') {
                    B = C;
                } else if (parametro2[0] == 'D') {
                    B = D;
                } else if (parametro2[0] == '[') {
                    char posicaodamemoria[] = "";
                    int indice = 1;
                    while (parametro2[indice] != ']') {
                        char temp[2] = {
                            parametro2[indice]};
                        strcat(posicaodamemoria, temp);
                        indice++;
                    }
                    int indicePosicaoDaMemoria = atoi(posicaodamemoria);
                    B = memoria[indicePosicaoDaMemoria];
                } else {
                    B = atoi(parametro2);
                }
            } else if (parametro1[0] == 'C') {
                if (parametro2[0] == 'A') {
                    C = A;
                } else if (parametro2[0] == 'B') {
                    C = B;
                } else if (parametro2[0] == 'D') {
                    C = D;
                } else if (parametro2[0] == '[') {
                    char posicaodamemoria[] = "";
                    int indice = 1;
                    while (parametro2[indice] != ']') {
                        char temp[2] = {parametro2[indice]};
                        strcat(posicaodamemoria, temp);
                        indice++;
                    }
                    int indicePosicaoDaMemoria = atoi(posicaodamemoria);
                    C = memoria[indicePosicaoDaMemoria];
                } else {
                    C = atoi(parametro2);
                }
            } else if (parametro1[0] == 'D') {
                if (parametro2[0] == 'A') {
                    D = A;
                } else if (parametro2[0] == 'B') {
                    D = B;
                } else if (parametro2[0] == 'C') {
                    D = C;
                } else if (parametro2[0] == '[') {
                    char posicaodamemoria[] = "";
                    int indice = 1;
                    while (parametro2[indice] != ']') {
                        char temp[2] = {
                            parametro2[indice]};
                        strcat(posicaodamemoria, temp);
                        indice++;

                    }
                    int indicePosicaoDaMemoria = atoi(posicaodamemoria);
                    D = memoria[indicePosicaoDaMemoria];
                } else {
                    D = atoi(parametro2);
                }
            } else if (parametro1[0] == '[') {
                char posicaodamemoria[] = "";
                int indice = 1;
                while (parametro1[indice] != ']') {
                    char temp[2] = {
                        parametro1[indice]};
                    strcat(posicaodamemoria, temp);
                    indice++;
                }
                int indicePosicaoDaMemoria = atoi(posicaodamemoria); //MOV endere�o da mem�ria, constante
                if (parametro2[0] == 'A') {
                    memoria[indicePosicaoDaMemoria] = A;
                } else if (parametro2[0] == 'B') {
                    memoria[indicePosicaoDaMemoria] = B;
                } else if (parametro2[0] == 'C') {
                    memoria[indicePosicaoDaMemoria] = C;
                } else if (parametro2[0] == 'D') {
                    memoria[indicePosicaoDaMemoria] = D;
                } else {
                    memoria[indicePosicaoDaMemoria] = atoi(parametro2);
                }
            }
        } else if (strcmp(instrucao, "ADD") == 0)
            if (parametro1[0] == 'A') {
                if (parametro2[0] == 'B') {
                    A = A + B;
                } else if (parametro2[0] == 'C') {
                    A = A + C;
                } else if (parametro2[0] == 'D') {
                    A = A + D;
                } else {
                    A = atoi(parametro2) + A;
                }
            } else if (parametro1[0] == 'B') {
            if (parametro2[0] == 'A') {
                B = B + A;
            } else if (parametro2[0] == 'C') {
                B = B + C;
            } else if (parametro2[0] == 'D') {
                B = B + D;
            } else {
                B = atoi(parametro2) + B;
            }
        } else if (parametro1[0] == 'C') {
            if (parametro2[0] == 'A') {
                C = C + A;
            } else if (parametro2[0] == 'B') {
                C = C + B;
            } else if (parametro2[0] == 'D') {
                C = C + D;
            } else {
                C = atoi(parametro2) + C;
            }
        } else if (parametro1[0] == 'D') {
            if (parametro2[0] == 'A') {
                D = D + A;
            } else if (parametro2[0] == 'B') {
                D = D + B;
            } else if (parametro2[0] == 'C') {
                D = D + C;
            } else {
                D = atoi(parametro2) + D;
            }
        }
    } //comentario teste
    return 0;
}
