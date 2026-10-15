
#include <stdio.h>
#include <string.h>

#define BRANCO "\033[0;37m"
#define VERDE  "\033[1;32m"
#define AZUL   "\033[1;34m"
#define VERMELHO "\033[1;31m"
#define RESET  "\033[0m"

int main() {
    float numero1 = 0, numero2 = 0, resultado = 0;
    int opcao;
    int continuar = 0;
    char historico[100][100];
    int qtdHistorico = 0;

    do {
        printf(BRANCO);
        printf("╔═══════════════════════════════╗\n");
        printf("║          CALCULADORA          ║\n");
        printf("╠═══════════════════════════════╣\n");
        printf("║ 1 - Soma +                    ║\n");
        printf("║ 2 - Subtração -               ║\n");
        printf("║ 3 - Multiplicação *           ║\n");
        printf("║ 4 - Divisão /                 ║\n");
        printf("║ 5 - Ver Histórico             ║\n");
        printf("║ 6 - Limpar Histórico          ║\n");
        printf("║ 0 - Sair                      ║\n");
        printf("╚═══════════════════════════════╝\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf(RESET);

        if (opcao >= 1 && opcao <= 4) {
            if (continuar == 1) {
                printf(BRANCO);
                printf("Digite o próximo número: ");
                scanf("%f", &numero2);
                printf(RESET);
            } else {
                printf(BRANCO);
                printf("Digite um número: ");
                scanf("%f", &numero1);

                printf("Digite outro número: ");
                scanf("%f", &numero2);
                printf(RESET);
            }
        }

        switch (opcao) {
            case 1:
                resultado = numero1 + numero2;
                break;

            case 2:
                resultado = numero1 - numero2;
                break;

            case 3:
                resultado = numero1 * numero2;
                break;

            case 4:
                if (numero2 == 0) {
                    printf(VERMELHO);
                    printf("Erro: divisão por zero!\n");
                    printf(RESET);
                    break;
                }
                resultado = numero1 / numero2;
                break;

            case 5:
                if (qtdHistorico == 0) {
                    printf(BRANCO);
                    printf("O histórico está vazio!\n");
                    printf(RESET);
                } else {
                    printf(BRANCO);
                    printf("\n");
                    printf("╔═══════════════════════════════╗\n");
                    printf("║           HISTÓRICO           ║\n");
                    printf("╚═══════════════════════════════╝\n");

                    for (int i = 0; i < qtdHistorico; i++) {
                        printf(AZUL);
                        printf("%d) %s\n", i + 1, historico[i]);
                    }
                    printf(RESET);
                }
                break;

            case 6:
                qtdHistorico = 0;
                numero1 = 0;
                numero2 = 0;
                resultado = 0;
                continuar = 2;

                printf(BRANCO);
                printf("Histórico apagado!\n");
                printf(RESET);
                break;

            case 0:
                printf(BRANCO);
                printf("Saindo...\n");
                printf(RESET);
                break;

            default:
                printf(VERMELHO);
                printf("Opção inválida!\n");
                printf(RESET);
                break;
        }

        if (opcao >= 1 && opcao <= 4 &&
            !(opcao == 4 && numero2 == 0)) {

            printf("\n");
            printf(VERDE);
            printf("┌───────────────────────────────┐\n");
            printf(" Resultado: %.2f\n", resultado);
            printf("└───────────────────────────────┘\n");
            printf(RESET);

            if (qtdHistorico < 100) {
                char operador;

                switch (opcao) {
                    case 1: operador = '+'; break;
                    case 2: operador = '-'; break;
                    case 3: operador = '*'; break;
                    default: operador = '/'; break;
                }

                sprintf(historico[qtdHistorico],
                        "%.2f %c %.2f = %.2f",
                        numero1, operador, numero2, resultado);

                qtdHistorico++;
            } else {
                printf(VERMELHO);
                printf("Limite do histórico atingido!\n");
                printf(RESET);
            }

            do {
                printf("\n");
                printf(BRANCO);
                printf("╔═══════════════════════════════╗\n");
                printf("║ 1 - Continuar com resultado   ║\n");
                printf("║ 2 - Novo cálculo              ║\n");
                printf("║ 0 - Voltar ao menu principal  ║\n");
                printf("╚═══════════════════════════════╝\n");
                printf("Escolha uma opção: ");
                scanf("%d", &continuar);
                printf(RESET);

                if (continuar < 0 || continuar > 2) {
                    printf(VERMELHO);
                    printf("Opção inválida!\n");
                    printf(RESET);
                }
            } while (continuar < 0 || continuar > 2);

            if (continuar == 1) {
                numero1 = resultado;
            } else if (continuar == 2) {
                numero1 = 0;
                numero2 = 0;
                resultado = 0;
            }
        }

    } while (opcao != 0);

    return 0;
}

        } while (opcao != 0);
        return 0;
    }

