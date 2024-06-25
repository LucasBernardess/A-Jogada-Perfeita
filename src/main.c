#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include "../include/file_io.h"
#include "../include/dp_solution.h"
#include "../include/alternative_solution.h"
#include "../include/time_utils.h"

int main(int argc, char *argv[]) {
    struct timeval start, end;
    struct rusage usageStart, usageEnd;
    char *inputFileName = NULL, *outputFileName = NULL;
    char strategy;
    int opt;

    // Processamento dos argumentos da linha de comando
    while ((opt = getopt(argc, argv, "i:o:s:")) != -1) {
        switch (opt) {
            case 'i': inputFileName = optarg; break;
            case 'o': outputFileName = optarg; break;
            case 's': strategy = optarg[0]; break;
            default:
                fprintf(stderr, "Uso: %s -i <arquivo de entrada> -o <arquivo de saída> -s <estratégia>\n", argv[0]);
                return EXIT_FAILURE;
        }
    }

    // Validação dos argumentos de entrada e saída
    if (!inputFileName || !outputFileName || (strategy != 'D' && strategy != 'A')) {
        fprintf(stderr, "Arquivos de entrada e/ou saída ou estratégia não especificados!\n");
        return EXIT_FAILURE;
    }

    // Início da medição do tempo de execução do programa
    gettimeofday(&start, NULL);
    getrusage(RUSAGE_SELF, &usageStart);

    // Processamento do arquivo de entrada e geração do arquivo de saída
    if (!processInputOutput(inputFileName, outputFileName, strategy)) {
        fprintf(stderr, "Falha no processamento dos arquivos.\n");
        return EXIT_FAILURE;
    }

    // Fim da medição do tempo e cálculo do tempo de execução
    gettimeofday(&end, NULL);
    getrusage(RUSAGE_SELF, &usageEnd);
    calculateExecutionTime(start, end, usageStart, usageEnd);
    
    return EXIT_SUCCESS;
}
