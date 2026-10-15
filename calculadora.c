#include<stdio.h>
#include<string.h>

int main(){

    float numero1, numero2, resultado;
    int opcao;
    int continuar = 0;
    char historico [100][100];
    int qtdHistorico = 0;

    do
    {
        printf("\033[1;32m");
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
        printf("\033[1;32m");
        printf("Escolha uma opção:");
        scanf("%d", &opcao);
        printf("\033[0m");
    
    if (opcao >= 1 && opcao <= 4){

    if (continuar == 1){
        printf("\033[1;32m");
        printf("Digite um número: ");
        printf("\033[1;32m");
        scanf("%f", &numero2);
    } else {
        printf("\033[1;32m");
        printf("Digite um número: ");
        printf("\033[1;32m");
        scanf("%f", &numero1);
   
        printf("\033[1;32m");
        printf("Digite um número: ");
        printf("\033[1;32m");
        scanf("%f", &numero2);
    }
}
            
    switch (opcao){
    case 1:
        resultado = numero1 + numero2;
        printf("\n");
        printf("\033[1;31m");
        printf("┌───────────────────────────────┐\n");
        printf(" Resultado: %.2f\n", resultado);
        printf("└───────────────────────────────┘\n");
        printf("\033[0m");
        sprintf(historico[qtdHistorico],
            "%.2f + %.2f = %.2f",
            numero1, numero2, resultado);
        qtdHistorico++;
        break;
    case 2:
            resultado = numero1 - numero2;
        printf("\n");
        printf("\033[1;31m");
        printf("┌───────────────────────────────┐\n");
        printf(" Resultado: %.2f\n", resultado);
        printf("└───────────────────────────────┘\n");
        printf("\033[0m");
        sprintf(historico[qtdHistorico],
            "%.2f - %.2f = %.2f",
            numero1, numero2, resultado);
        qtdHistorico++;
        break;
    case 3:
        resultado = numero1 * numero2;
        printf("\n");
        printf("\033[1;31m");
        printf("┌───────────────────────────────┐\n");
        printf(" Resultado: %.2f\n", resultado);
        printf("└───────────────────────────────┘\n");
        printf("\033[0m");
        sprintf(historico[qtdHistorico],
            "%.2f * %.2f = %.2f",
            numero1, numero2, resultado);
        qtdHistorico++;
        break;
    case 4:
    if (numero2 != 0){
        resultado = numero1 / numero2;
        printf("\n");
        printf("\033[1;31m");
        printf("┌───────────────────────────────┐\n");
        printf(" Resultado: %.2f\n", resultado);
        printf("└───────────────────────────────┘\n");
        printf("\033[0m");
        sprintf(historico[qtdHistorico],
        "%.2f / %.2f = %.2f",
        numero1, numero2, resultado);

        qtdHistorico++;
    } else {
        printf("\033[1;31m");
        printf("Erro: divisão por zero!\n");
        printf("\033[0m");
    }
        break;
    case 5:
    if (qtdHistorico == 0){
        printf("\033[1;31m");
        printf("O Histórico está zerado!\n");
        printf("\033[0m");
    }else{
        printf("\n");
        printf("\033[1;32m");
        printf("╔═══════════════════════════════╗\n");
        printf("║           HISTÓRICO           ║\n");
        printf("╚═══════════════════════════════╝\n");
        printf("\033[1;32m");

    for (int i = 0; i < qtdHistorico; i++)
        {
        printf("%d) %s\n", i + 1, historico[i]);
        }
        
    }
        break;        
    case 6:
        qtdHistorico = 0;
        numero1 = 0;
        numero2 = 0;
        resultado = 0;

        continuar =2;
    
        printf("\033[1;31m");
        printf("Histórico apagado!\n");
        printf("\033[0m");
        break;
        case 0:
        printf("\033[1;31m");
        printf("Saindo...\n");
        printf("\033[0m");

        continuar = 0;
            
        break;
        
        default:
        printf("\033[1;31m");
        printf("Opção inválida!\n");
        printf("\033[0m");
        break;
        } 
        if (opcao >= 1 && opcao <= 4){

    do {
        printf("\n");
        printf("\033[1;32m");
        printf("╔═══════════════════════════════╗\n");
        printf("║ 1 - Continuar com o resultado.║\n");
        printf("║ 2 - Novo calculo.             ║\n");
        printf("║ 0 - Voltar ao menu principal. ║\n");
        printf("╚═══════════════════════════════╝\n");
        printf("\033[1;32m");
        printf("Escolha uma opção:");
        scanf("%d", &continuar);
        printf("\033[0m");
    

        if (continuar < 0 || continuar > 2){
        printf("\033[1;31m");
        printf("Opção inválida!\n");
        printf("\033[0m");
        }

    }   while (continuar < 0 || continuar > 2);

        if (continuar == 1){
        numero1 = resultado;
    }   else if (continuar == 2){
        numero1 = 0;
        numero2 = 0;
        resultado = 0;
    }
        }
        } while (opcao != 0);
        return 0;
    }

