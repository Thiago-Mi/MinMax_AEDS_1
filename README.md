# Teste de Identificação de Maior e Menor Número em um Vetor

Este programa em C foi desenvolvido para testar três implementações diferentes para identificar o maior e o menor número em um vetor de inteiros. As implementações são denominadas `MaxMin1`, `MaxMin2` e `MaxMin3`.

## Como Executar

1. Compile o programa utilizando um compilador C. Por exemplo, com o GCC:

   ```bash
   gcc -o identificar_max_min identificar_max_min.c
   Execute o programa: 
   ./identificar_max_min

Implementações
MaxMin1

    Descrição: Percorre o vetor uma vez para encontrar o maior e o menor número.
    

MaxMin2

    Descrição: Percorre o vetor uma vez, utilizando um if e else if para encontrar o maior e o menor número.
    

MaxMin3

    Descrição: Divide o vetor em pares, comparando o maior e o menor de cada par, e depois compara com os valores globais.
    

Detalhes da Implementação

    As funções MaxMin1 e MaxMin2 recebem o tamanho do vetor como parâmetro para realizar a iteração corretamente.
    A função MaxMin3 recebe o vetor, o tamanho e um array para armazenar o máximo e o mínimo encontrados.
    Para cada implementação, são realizados 10 testes com vetores de tamanhos diferentes (1000, 10000, 100000, 500000) para avaliar o desempenho em diferentes cenários.
    Os tempos de execução são armazenados em um array tridimensional tempo_exec e são escritos em um arquivo de saída tempos.txt.
