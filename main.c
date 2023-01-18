#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <Windows.h>

char usuarioNome[100][1];
char usuarioSobrenome[100][1];
int usuarioIdade[100];
float valorCheioIngresso = 550.50;
static int linha = 0;
char tipoCliente;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    tela();

    return 0;
}

void tela(){
    system("cls");
    printf("\nPrograma de vendas de ingresso de Show \n");
    printf("----------------------------------------\n");
    printf("\nMenu inicial\n");
    printf("\nDigite um dos números abaixo para abrir suas respectivas telas \n");
    printf("\n[0] - Cadastre-se e compre um ingresso\n\n");
    printf("\n[1] - Relatório de vendas\n\n");

    char numeroSelecionado;
    scanf("%c", &numeroSelecionado);
    int isNumber = isdigit(numeroSelecionado); //checa se o usuario digitou um caractere numerico

    if(numeroSelecionado == '0' && isNumber > 0){
        telaCadastro();
    } else if(numeroSelecionado == '1' && isNumber > 0){
        if(usuarioNome[0][0] == NULL){
            system("cls");
            printf("\nÉ necessário haver clientes cadastrados para acessar esta tela.");
            Sleep(2000);
            main();
        }
        telaRelatorio();

    } else{
        system("cls");
        printf("\nDigite um dos números corretamente\n");
        main(); //reinicia o programa
    }
}

void telaCadastro(){
        system("cls");
        printf("Digite o nome do cliente: ");
        scanf("%s", &usuarioNome[linha]);
        printf("\nDigite o sobrenome do cliente: ");
        scanf("%s", &usuarioSobrenome[linha]);
        printf("\nDigite a idade do cliente: ");
        scanf("%d", &usuarioIdade[linha]);
        printf("\nCliente %s cadastrado com sucesso!\n", usuarioNome[linha]);
        fflush(stdin);
        linha++;
        Sleep(1500);
        infoCliente();
}

void infoCliente(){
    system("cls");
        printf("\nSELECIONE A ALTERNATIVA ABAIXO QUE CORRESPONDE COM O CLIENTE\n");
        printf("\n");
        printf(" 1 = PROFESSOR DA REDE PÚBLICA?\n");
        printf(" 2 = ESTUDANTE?\n");
        printf(" 3 = PORTADOR DE NECESSIDADES ESPECIAIS?\n");
        printf(" 4 = NENHUMA DAS OPÇÕES ACIMA (VALOR CHEIO)\n");
        fflush(stdin); //limpa o buffer para evitar bugs com scanf
        scanf("%c", &tipoCliente);

    switch(tipoCliente){
       case '1': {
            int verificacao = 0;
            do{
                float descontoIngresso = 0.5 * valorCheioIngresso; //50% de desconto
                printf("\n50porcento1 de 500 é %0.2f", descontoIngresso);
                system("cls");
                printf("\nIngresso de %s %s\n", usuarioNome, usuarioSobrenome);
                printf("\nTela vendas\n");
                printf("\n--------------------------------------------\n");
                printf("Data do show: 20/02/2023 \n");
                printf("--------------------------------------------\n");
                printf("Foi concedido 50 por cento de desconto neste ingresso pois é professor de rede pública.\n\n");
                printf("O valor do ingresso é %.2f\n", valorCheioIngresso - descontoIngresso);
                printf("Ingresso de Show\n\n*Snoop Dogg e Eminem*\n");
                printf("\n\nValor inteiro---------------------R$ %.2f\n", valorCheioIngresso - descontoIngresso);
                printf("\n\nIngresso salvo com sucesso!\n");
                printf("\nPressione E para voltar ao menu.\n");
                fflush(stdin);
                scanf("%c", &verificacao);
            } while(verificacao == 1);

            tela();
       } break;

       case '2': {
            int verificacao = 0;
            do {
                float descontoIngresso = 0.5 * valorCheioIngresso; //50% de desconto
                printf("\n50porcento1 de 500 é %0.2f", descontoIngresso);
                system("cls");
                printf("\nIngresso de %s %s\n", usuarioNome, usuarioSobrenome);
                printf("\nTela vendas\n");
                printf("\n--------------------------------------------\n");
                printf("Data do show: 20/02/2023 \n");
                printf("--------------------------------------------\n");
                printf("Foi concedido 50 por cento de desconto neste ingresso pois é estudante.\n\n");
                printf("O valor do ingresso é %.2f\n", valorCheioIngresso - descontoIngresso);
                printf("Ingresso de Show\n\n*Snoop Dogg e Eminem*\n");
                printf("\n\nValor inteiro---------------------R$ %0.2f\n", valorCheioIngresso - descontoIngresso);
                printf("\n\nIngresso salvo com sucesso!\n");
                printf("\nPressione E para voltar ao menu.\n");
                fflush(stdin);
                scanf("%c", &verificacao);
            } while(verificacao == 1);

            tela();
       } break;

       case '3': {
           int verificacao = 0;
           do{
                float descontoIngresso = 0.5 * valorCheioIngresso; //50% de desconto
                printf("\n50porcento1 de 500 é %0.2f", descontoIngresso);
                system("cls");
                printf("\nIngresso de %s %s\n", usuarioNome, usuarioSobrenome);
                printf("\nTela vendas\n");
                printf("\n--------------------------------------------\n");
                printf("Data do show: Data 20/02/2023 \n");
                printf("--------------------------------------------\n");
                printf("Foi concedido 50 por cento de desconto neste ingresso pois é portador de necessidades especiais.\n\n");
                printf("O valor do ingresso é %.2f\n", valorCheioIngresso - descontoIngresso);
                printf("Ingresso de Show\n\n*Snoop Dogg e Eminem*\n");
                printf("\n\nValor inteiro---------------------R$ %0.2f\n", valorCheioIngresso - descontoIngresso);
                printf("\n\nIngresso salvo com sucesso!\n");
                printf("\nPressione E para voltar ao menu.\n");
                fflush(stdin);
                scanf("%c", &verificacao);
           } while(verificacao == 1);

           tela();

       } break;

       case '4': {
            int verificacao = 0;
            do{
                printf("\nNão foi concedido desconto no ingresso.");
                system("cls");
                printf("\nIngresso de %s %s\n", usuarioNome, usuarioSobrenome);
                printf("\nTela vendas\n");
                printf("\n--------------------------------------------\n");
                printf("Data do show: 20/02/2023 \n");
                printf("--------------------------------------------\n");
                printf("Não foi concedido desconto no ingresso.\n\n");
                printf("O valor do ingresso é R$ 500,50\n");
                printf("Ingresso de Show\n\n Snoop Dogg e Eminem\n");
                printf("\n\nValor inteiro---------------------R$ 500,50\n");
                printf("\n\nIngresso salvo com sucesso!\n");
                printf("\nPressione E para voltar ao menu.\n");
                fflush(stdin);
                scanf("%c", &verificacao);
           } while(verificacao == 1);
           tela();
       } break;
        default: telaCadastro(); break;
    }
}


void telaRelatorio(){
    system("cls");
    printf("\nClientes que possuem ingresso: \n\n");

    for(int i = 0; i < linha; i++){
        if(tipoCliente == '1'){
            printf("\nCLIENTES COM DESCONTO DE PROFESSORES DE REDE PUBLICA\n");
            printf("%s %s, %i anos\n", usuarioNome[i], usuarioSobrenome[i], usuarioIdade[i]);
            printf("\n\n ------------------------------- \n\n");
        }
        if(tipoCliente == '2'){
            printf("\nCLIENTES COM DESCONTO DE ESTUDANTE\n");
            printf("%s %s, %i anos\n", usuarioNome[i], usuarioSobrenome[i], usuarioIdade[i]);
            printf("\n\n ------------------------------- \n\n");
        }
        if(tipoCliente == '3'){
            printf("\nCLIENTES COM DESCONTO DE NECESSIDADES ESPECIAIS\n");
            printf("%s %s, %i anos\n", usuarioNome[i], usuarioSobrenome[i], usuarioIdade[i]);
            printf("\n\n ------------------------------- \n\n");
        }
        if(tipoCliente == '4'){
            printf("\nCLIENTES SEM DESCONTO\n");
            printf("%s %s, %i anos\n", usuarioNome[i], usuarioSobrenome[i], usuarioIdade[i]);
            printf("\n\n ------------------------------- \n\n");
        }
    }
}


