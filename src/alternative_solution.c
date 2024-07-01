#include "../include/alternative_solution.h"
#include <stdlib.h>

#include <stdio.h>

// Função recursiva de força bruta para encontrar a pontuação máxima
int brute_force_solution(int *sequence, int n) {
    // Caso base: se a sequência estiver vazia
    if (n <= 0) return 0;

    int maxPoints = 0;
    for (int i = 0; i < n; i++) {
        // Ponto atual
        int currentPoints = sequence[i];

        // Subsequências resultantes da remoção de sequence[i] e seus vizinhos
        int leftPoints = brute_force_solution(sequence, i - 1);
        int rightPoints = brute_force_solution(sequence + i + 2, n - i - 2);

        // Pontos totais ao escolher sequence[i]
        int totalPoints = currentPoints + leftPoints + rightPoints;

        // Atualiza a pontuação máxima
        if (totalPoints > maxPoints) {
            maxPoints = totalPoints;
        }
    }

    return maxPoints;
}

// Função principal para chamada da solução de força bruta
int alternative_solution(int *sequence, int n) {
    return brute_force_solution(sequence, n);
}
