#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int fatorial(int num) {
    // Gabrielly Sousa Lorentz
    int resultado = 1;
    for (int i = 1; i <= num; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    printf("===== MENU DE EXERCICIOS =====");
    printf("\n\n1 - Sequencia de Fibonacci\n2 - Fatoriais\n3 - Verificar Palindromo\n4 - Verificar Substring.");
    printf("\n\nDigite o numero da tarefa desejada: ");
 
    int opcao;
    scanf("%d", &opcao);
 
    getchar();
 
    switch (opcao) {
        case 1: {
            // Heitor Fernandes Barbosa
            int elementos_fibonacci;
            printf("\nSequencia de Fibonacci:");
            printf("\nDigite a quantidade de elementos que voce deseja: ");
            scanf("%d", &elementos_fibonacci);
 
            getchar();
 
            if (elementos_fibonacci <= 0) {
                printf("A quantidade de elementos desejados deve ser maior que 0.\n");
                break;
            }
 
            int fibonacci[elementos_fibonacci];
            int i = 0;
 
            while (i < elementos_fibonacci) {
                if (i == 0)
                    fibonacci[i] = 0;
                else if (i == 1)
                    fibonacci[i] = 1;
                else
                    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
                i++;
            }
 
            printf("Sequencia correspondente:\n");
            for (int o = 0; o < elementos_fibonacci; o++) {
                printf("%d,", fibonacci[o]);
            }
            printf("\n");
            break;
        }
 
        case 2: {
            // Gabrielly Sousa Lorentz
            int N;
 
            do {
                printf("Digite um numero inteiro N (entre 1 e 20): ");
                scanf("%d", &N);
            } while (N < 1 || N > 20);
 
            int* fatoriais = (int*)malloc(N * sizeof(int));
 
            if (fatoriais == NULL) {
                printf("Erro ao alocar memória para os fatoriais.\n");
                return 1;
            }
 
            for (int i = 1; i <= N; i++) {
                fatoriais[i-1] = fatorial(i);
            }
 
            for (int i = 1; i <= N; i++) {
                printf("%d! = %d\n", i, fatoriais[i-1]);
            }
 
            free(fatoriais);
            break;
        }
 
        case 3: {

        }
 
        case 4: {

        }
 
        default:
            printf("\nVoce digitou um numero inexistente na tabela.\n");
    }
 
    return 0;
}
