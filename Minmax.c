#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Função que cria uma lista de tamanho especificado preenchida com valores aleatórios.
 *
 * @param tamanho Tamanho da lista a ser criada.
 * @return Ponteiro para a lista criada.
 */
int* criarListaAleatoria(int tamanho) {

    int* lista = (int *) malloc(tamanho * sizeof(int));
    // Preencher a lista com 1/3 de 1 e 2/3 de 0 aleatoriamente

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        int j = rand() % tamanho;
        lista[i] = j;
    }

    return lista;
}

/**
 * Função que ordena uma lista de inteiros em ordem crescente.
 *
 * @param lista Ponteiro para a lista a ser ordenada.
 * @param tamanho Tamanho da lista.
 * @return Ponteiro para a lista ordenada.
 */
int* ordenarCrescente(int* lista, int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (lista[i] > lista[j]) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
    return lista;
}

/**
 * Função que ordena uma lista de inteiros em ordem decrescente.
 *
 * @param lista Ponteiro para a lista a ser ordenada.
 * @param tamanho Tamanho da lista.
 * @return Ponteiro para a lista ordenada.
 */
int* ordenarDecrescente(int* lista, int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (lista[i] < lista[j]) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
    return lista;
}

/**
 * Função que encontra o máximo e o mínimo de uma lista de inteiros.
 *
 * @param A Ponteiro para a lista de inteiros.
 * @param maxmin Array de dois elementos para armazenar o máximo e o mínimo encontrados.
 * @param tamanho Tamanho da lista.
 */
void MaxMin1(int* A, int* maxmin, int tamanho){
    maxmin[0] = A[0];
    maxmin[1] = A[0];
    int i=0;
    while (i < tamanho){
        if (A[i] > maxmin[0]){
            maxmin[0] = A[i];
        }
        if (A[i] < maxmin[1]){
            maxmin[1] = A[i];
        }
        i++;
    }  
}

/**
 * Função que encontra o máximo e o mínimo de uma lista de inteiros.
 *
 * @param A Ponteiro para a lista de inteiros.
 * @param maxmin Array de dois elementos para armazenar o máximo e o mínimo encontrados.
 * @param tamanho Tamanho da lista.
 */
void MaxMin2(int* A, int* maxmin, int tamanho){
    maxmin[0] = A[0];
    maxmin[1] = A[0];
    int i=0;
    while (i < tamanho){
        if (A[i] > maxmin[0])
        {
            maxmin[0] = A[i];
        }
        else if (A[i] < maxmin[1])
        {
            maxmin[1] = A[i];
        } 
        i++;
    }  
}

/**
 * Função que encontra o máximo e o mínimo de uma lista de inteiros.
 *
 * @param A Ponteiro para a lista de inteiros.
 * @param n Tamanho da lista.
 * @param maxmin Array de dois elementos para armazenar o máximo e o mínimo encontrados.
 */
void MaxMin3(int* A, int n, int* maxmin){
    int i, FimDoAnel;

    if (n % 2 > 0) {
        A[n + 1] = A[n];
        FimDoAnel = n;
    } else {
        FimDoAnel = n - 1;
    }

    if (A[0] > A[1]) {
        maxmin[0] = A[0];
        maxmin[1] = A[1];
    } else {
        maxmin[0] = A[1];
        maxmin[1] = A[0];
    }

    i = 2;
    while (i <= FimDoAnel) {
        if (A[i] > A[i + 1]) {
            if (A[i] > maxmin[0]) {
                maxmin[0] = A[i];
            }
            if (A[i + 1] < maxmin[1]) {
                maxmin[1] = A[i + 1];
            }
        } else {
            if (A[i + 1] > maxmin[0]) {
                maxmin[0] = A[i + 1];
            }
            if (A[i] < maxmin[1]) {
                maxmin[1] = A[i];
            }
        }
        i = i + 2;
    }
}

/**
 * Função que imprime os tempos de execução dos métodos em um arquivo.
 *
 * @param tempo_exec Array tridimensional contendo os tempos de execução.
 * @param nomeArquivo Nome do arquivo onde os tempos serão escritos.
 */
void imprimirTempos(int tempo_exec[3][3][4], char* nomeArquivo) {
    char *metodos[3] = {"MaxMin1", "MaxMin2", "MaxMin3"};
    char *ordenacoes[3] = {"Aleatoria", "Crescente", "Decrescente"};
    int entradas[4] = {1000, 10000, 100000, 500000};

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Tempo de execucao em milissegundos:\n");
    for (int k = 0; k < 4; k++) {
        fprintf(arquivo, "Entrada: %d\n", entradas[k]);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                fprintf(arquivo, "%s %s: %dms\n", metodos[i], ordenacoes[j], tempo_exec[i][j][k]/10);
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

/**
 * Função principal que executa os métodos e registra os tempos de execução.
 */
int main(){
    clock_t* tempo = (clock_t *) malloc(3 * sizeof(clock_t));
    int* maxmin = (int *) malloc(2 * sizeof(int));
    int entradas[4] = {1000, 10000, 100000, 500000};
    int tempo_exec[3][3][4];
    for(int i =0; i<4; i++){
        for(int j=0; j<10; j++){
            int* A = criarListaAleatoria(entradas[i]);
            maxmin = (int *) malloc(2 * sizeof(int));
            tempo[0] = clock();
            MaxMin1(A, maxmin, entradas[i]);
            tempo[0] = ((double)(clock() - tempo[0]))/((CLOCKS_PER_SEC/1000));
            tempo_exec[0][0][i] = tempo[0];
            maxmin = (int *) malloc(2 * sizeof(int));
            tempo[1] = clock();
            MaxMin2(A, maxmin, entradas[i]);
            tempo[1] = ((double)(clock() - tempo[1]))/((CLOCKS_PER_SEC/1000));
            tempo_exec[0][1][i] = tempo[1];
            maxmin = (int *) malloc(2 * sizeof(int));
            tempo[2] = clock();
            MaxMin3(A, i, maxmin);
            tempo[2] = ((double)(clock() - tempo[2]))/((CLOCKS_PER_SEC/1000));
            tempo_exec[0][2][i] += tempo[2];
        }
    }
    for(int i =0; i<4; i++){
        for(int j=0; j<10; j++){
            int* A = criarListaAleatoria(entradas[i]);
            A = ordenarCrescente(A, entradas[i]);
            maxmin = (int *) malloc(2 * sizeof(int));
            tempo[0] = clock();
            MaxMin1(A, maxmin, entradas[i]);
            tempo[0] = ((double)(clock() - tempo[0]))/((CLOCKS_PER_SEC/1000));
            tempo_exec[0][0][i] = tempo[0];
            maxmin = (int *) malloc(2 * sizeof(int));
            tempo[1] = clock();
            MaxMin2(A, maxmin, entradas[i]);
            tempo[1] = ((double)(clock() - tempo[1]))/((CLOCKS_PER_SEC/1000));
            tempo_exec[0][1][i] = tempo[1];
            maxmin = (int *) malloc(2 * sizeof(int));
            tempo[2] = clock();
            MaxMin3(A, i, maxmin);
            tempo[2] = ((double)(clock() - tempo[2]))/((CLOCKS_PER_SEC/1000));
            tempo_exec[0][2][i] += tempo[2];
        }
    }
    printf("comecou 3");
    for(int i =0; i<4; i++){
        for(int j=0; j<10; j++){
            int* A = criarListaAleatoria(entradas[i]);
            A = ordenarDecrescente(A, entradas[i]);
            maxmin = (int *) malloc(2 * sizeof(int));
            tempo[0] = clock();
            MaxMin1(A, maxmin, entradas[i]);
            tempo[0] = ((double)(clock() - tempo[0]))/((CLOCKS_PER_SEC/1000));
            tempo_exec[0][0][i] = tempo[0];
            maxmin = (int *) malloc(2 * sizeof(int));
            tempo[1] = clock();
            MaxMin2(A, maxmin, entradas[i]);
            tempo[1] = ((double)(clock() - tempo[1]))/((CLOCKS_PER_SEC/1000));
            tempo_exec[0][1][i] = tempo[1];
            maxmin = (int *) malloc(2 * sizeof(int));
            tempo[2] = clock();
            MaxMin3(A, i, maxmin);
            tempo[2] = ((double)(clock() - tempo[2]))/((CLOCKS_PER_SEC/1000));
            tempo_exec[0][2][i] += tempo[2];
        }
    }

    imprimirTempos(tempo_exec, "tempos.txt");
}