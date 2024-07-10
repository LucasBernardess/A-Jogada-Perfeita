#include <stdio.h>
#include <stdlib.h>
#include "../include/file_io.h"
#include "../include/dp_solution.h"
#include "../include/alternative_solution.h"

// Função para processar a entrada e saída conforme estratégia escolhida
int processInputOutput(const char *inputFileName, char strategy) {
    // Abre o arquivo de entrada para leitura
    FILE *inputFile = fopen(inputFileName, "r");
    if (!inputFile) {
        perror("Erro ao abrir o arquivo de entrada");
        return 0;
    }

    int quantity;

    // Verificações para prosseguir com a execução
    if (fscanf(inputFile, "%d", &quantity) != 1) {
        fprintf(stderr, "Formato de arquivo de entrada inválido.\n");
        fclose(inputFile);
        return 0;
    }

    if (quantity < 0 || quantity > 100000) {
        fprintf(stderr, "Valor fora do intervalo permitido: %d\n", quantity);
        fclose(inputFile);
        return 0;
    }

    // Aloca memória para a sequência
    unsigned long int *sequence = (unsigned long int *)malloc(quantity * sizeof(unsigned long int));
    for (int i = 0; i < quantity; i++) {
        if (fscanf(inputFile, "%lu", &sequence[i]) != 1) {
            fprintf(stderr, "Erro ao ler os dados da sequência.\n");
            fclose(inputFile);
            free(sequence);
            return 0;
        }
    }
    fclose(inputFile);

    unsigned long int result;
    // Escolhe a estratégia escolhida
    if (strategy == 'D') {
        result = maxPointsDP(sequence, quantity); // Solução Dinâmica
    } else {
        result = maxPointsBruteForce(sequence, quantity, 0); // Solução com força bruta
    }

    // Abre o arquivo de saída para escrita
    FILE *outputFile = fopen("saida.txt", "w");
    if (!outputFile) {
        perror("Erro ao abrir o arquivo de saída");
        free(sequence);
        return 0;
    }

    // Escreve o resultado no arquivo de saída
    fprintf(outputFile, "%lu\n", result);
    fclose(outputFile);

    free(sequence);
    return 1;
}