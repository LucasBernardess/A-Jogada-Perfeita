#include <stdio.h>
#include <stdlib.h>
#include "../include/file_io.h"
#include "../include/dp_solution.h"
#include "../include/alternative_solution.h"

int processInputOutput(const char *inputFileName, char strategy) {
    // Abre o arquivo de entrada para leitura
    FILE *inputFile = fopen(inputFileName, "r");
    if (!inputFile) {
        perror("Erro ao abrir o arquivo de entrada");
        return 0;
    }

    int n;
    if (fscanf(inputFile, "%d", &n) != 1) {
        fprintf(stderr, "Formato de arquivo de entrada inválido.\n");
        fclose(inputFile);
        return 0;
    }

    unsigned long int *sequence = (unsigned long int *)malloc(n * sizeof(unsigned long int));
    for (int i = 0; i < n; i++) {
        if (fscanf(inputFile, "%lu", &sequence[i]) != 1) {
            fprintf(stderr, "Erro ao ler os dados da sequência.\n");
            fclose(inputFile);
            free(sequence);
            return 0;
        }
    }
    fclose(inputFile);

    unsigned long int result;
    if (strategy == 'D') {
        result = maxPointsDP(sequence, n);
    } else {
        result = maxPointsBruteForce(sequence, n, 0);
    }

    // Abre o arquivo de saída para escrita
    FILE *outputFile = fopen("saida.txt", "w");
    if (!outputFile) {
        perror("Erro ao abrir o arquivo de saída");
        free(sequence);
        return 0;
    }
    fprintf(outputFile, "%lu\n", result);
    fclose(outputFile);

    free(sequence);
    return 1; // Indica sucesso
}