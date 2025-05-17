#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int fatorial(int num) {
    int resultado = 1;
    for (int i = 1; i <= num; i++) {
        resultado *= i;
    }
    return resultado;
}

int eh_palindromo(char palavra[]) {
    int inicio = 0;
    int fim = strlen(palavra) - 1;

    while (inicio < fim) {
        if (tolower(palavra[inicio]) != tolower(palavra[fim])) {
            return 0;
        }
        inicio++;
        fim--;
    }
    return 1;
}

int contem_substring(char str1[], char str2[]) {
    if (strstr(str1, str2) != NULL) {
        return 1;
    }
    return 0;
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
            char palavra[101];

            printf("Digite uma palavra (sem espacos, ate 100 caracteres): ");
            fgets(palavra, sizeof(palavra), stdin);
            palavra[strcspn(palavra, "\n")] = '\0';

            if (eh_palindromo(palavra)) {
                printf("A palavra '%s' e um palindromo.\n", palavra);
            } else {
                printf("A palavra '%s' nao e um palindromo.\n", palavra);
            }
            break;
        }

        case 4: {
            char str1[101], str2[101];

            printf("Digite a primeira string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';

            printf("Digite a segunda string: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';

            if (contem_substring(str1, str2)) {
                printf("A segunda string esta contida na primeira.\n");
            } else {
                printf("A segunda string nao esta contida na primeira.\n");
            }
            break;
        }

        default:
            printf("\nVoce digitou um numero inexistente na tabela.\n");
    }

    return 0;
}
