#include <stdio.h>
#include <windows.h> //Permite usar funções do Windows no programa.
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    //Cabeçalho
    SetConsoleOutputCP(65001); //Ativa UTF-8 no Windows
    printf("    /_________\\ \n");
    printf("   /===========\\ \n");
    printf("  / ____________\\ \n");
    printf("  | ___________ | \n");
    printf("  | | -       | | \n");
    printf("  | |         | | \033[1;34mPraticando Linguagem C\033[0m \033[1;37m- Tailane Brito.\033[0m\n");
    printf("  | |_________| |________________________________________\n");
    printf("  \\=____________/   Bem vindo(a) ao jogo de advinhação!\n");
    printf("  / \"\"\"\"\"\"\"\"\"\"\" \\\n");
    printf(" / ::::::::::::: \\  \n");
    printf("(_________________) \n");
    //Referência: ASCII Art - brian macdonald 

    //Gerando um número aleatório e definindo um intervalo de 0 a 99.
    srand(time(0));
    int num_secreto = rand() % 100;

    //Declaração de variáveis
    int chute;
    int nivel;
    int tentativas = 0; 
    int totaldetentativas;
    double pontos = 1000; 

    //Definindo nível de dificuldade
    while (1) {
        printf("\033[33mDefina o nível de dificuldade:\033[0m\n");
        printf("\033[1;37m(1) Fácil (2)Médio (3)Difícil\033[0m\n");
        printf("\033[33mDigite sua opção (somente números):\033[0m ");
        if(scanf("%d", &nivel) != 1) {
            printf("\033[1;31mDigite um número válido. \033[0m\n");
            while (getchar() != '\n'); //Limpa o buffer
            continue; 
        }
        switch (nivel) {
            case 1:
                totaldetentativas = 15;
                printf("\033[1;34mPreparado? Você possui %d chances. Boa sorte!\033[0m\n", totaldetentativas);
                break;
            case 2:
                totaldetentativas = 10;
                printf("\033[1;34mPreparado? Você possui %d chances. Boa sorte!\033[0m\n", totaldetentativas);
                break;
            case 3: 
                totaldetentativas = 5; 
                printf("\033[1;34mPreparado? Você possui %d chances. Boa sorte!\033[0m\n", totaldetentativas);
                break;
            default:
                printf("\033[1;31mOpção inválida. Siga as instruções \033[0m\n");
                continue;
        } 
        break;
    }

    //Interação com o usuário
    for(int i = 1; i <= totaldetentativas; i++) { 
        printf("%dº Tentativa. \033[1;90mTente um número:\033[0m ", i);
        if (scanf("%d", &chute) != 1) {
            printf("\033[1;31mDigite um número válido.\033[0m\n\n");
            while (getchar() != '\n'); // Limpa o buffer
            i--; // Não conta como tentativa
            continue;
        } 

        //Condições
        if(chute < 0){
            printf("\033[1;31mVocê não pode chutar números negativos.\033[0m\n");
            i--; 
            continue; 
        }
        tentativas++; 

        if (chute == num_secreto) {
            printf("\033[1;32mParabéns! Você acertou em %d tentativas.\033[0m\n", tentativas);
            break; 
        } else if (chute > num_secreto) {
            printf("\033[1;34mTente um número menor.\033[0m\n");
        } else {
            printf("\033[1;34mTente um número maior.\033[0m\n");
        }

        //Definindo pontuação do usuário
        double pontos_perdidos = fabs(chute - num_secreto) / 2.0;
        pontos = pontos - pontos_perdidos; 
    } 

    // Mensagem de derrota
    if (chute != num_secreto) {
        printf("\033[1;31mVocê perdeu! O número secreto era %d. Tente novamente!\033[0m\n", num_secreto);
    }

    //Mensagem final ao usuário
    printf("Fim de jogo! Você fez um total de %.2f pontos. \n", pontos);

    return 0;
}
