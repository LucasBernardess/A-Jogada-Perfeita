#include <stdlib.h>
#include <stdio.h>
#include "../include/alternative_solution.h"

// Função recursiva de força bruta para encontrar a pontuação máxima
int alternative_solution(int *sequence, int n) {
    // Caso base: se a sequência estiver vazia
    if (n <= 0) return 0;

    int maxPoints = 0;
    for (int i = 0; i < n; i++) {
        // Ponto atual
        int currentPoints = sequence[i];

        // Subsequências resultantes da remoção de sequence[i] e seus vizinhos
        int leftPoints = alternative_solution(sequence, i - 1);
        int rightPoints = alternative_solution(sequence + i + 2, n - i - 2);

        // Pontos totais ao escolher sequence[i]
        int totalPoints = currentPoints + leftPoints + rightPoints;

        // Atualiza a pontuação máxima
        if (totalPoints > maxPoints) {
            maxPoints = totalPoints;
        }
    }

    return maxPoints;
}
