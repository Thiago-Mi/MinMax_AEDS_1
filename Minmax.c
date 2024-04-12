#include <stdio.h>
#include <string.h>
#include <time.h>


int* criarListaAleatoria(int x) {

    int* lista = (int *) malloc(x * sizeof(int));
    // Preencher a lista com 1/3 de 1 e 2/3 de 0 aleatoriamente

    srand(42);

    for (int i = 0; i < x; i++) {
        int j = rand() % 1000;
        lista[i] = j;
    }

    return lista;
}

int* ordenarLista(int* lista){
    

    return lista;
}


void MaxMin1(int* A, int* maxmin){
    maxmin[0] = A[0];
    maxmin[1] = A[0];
    int i=0;
    while (A[i]!= NULL){
        if (A[i] > maxmin[0]){
            maxmin[0] = A[i];
        }
        if (A[i] < maxmin[1]){
            maxmin[1] = A[i];
        }
    }  
}

void MaxMin2(int* A, int* maxmin){
    maxmin[0] = A[0];
    maxmin[1] = A[0];
    int i=0;
    while (A[i]!= NULL){
        if (A[i] > maxmin[0])
        {
            maxmin[0] = A[i];
        }
        else if (A[i] < maxmin[1])
        {
            maxmin[1] = A[i];
        } 
    }  
}

void MaxMin3(int* A, int* maxmin){
  
}

int main(){
    clock_t* tempo = (clock_t *) malloc(3 * sizeof(clock_t));
    int* A = criarListaAleatoria(100);
    int* maxmin = (int *) malloc(2 * sizeof(int));;
    tempo[0] = clock();
    MaxMin1(A, &maxmin);
    tempo[0] = ((double)(clock() - tempo[0]))/((CLOCKS_PER_SEC/1000));
    tempo[1] = clock();
    MaxMin2(A, &maxmin);
    tempo[1] = ((double)(clock() - tempo[1]))/((CLOCKS_PER_SEC/1000));
    tempo[2] = clock();
    MaxMin3(A, &maxmin);
    tempo[2] = ((double)(clock() - tempo[2]))/((CLOCKS_PER_SEC/1000));

}