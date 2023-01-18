// SISTEMA DE VENDA DE INGRESSOS PARA TEATRO
//_____________________________________________________________________________________// Início do programa. // Inclusão de biliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <windows.h>
#include <time.h>//biblioteca hora
//_____________________________________________________________________________________// Declaração de Variáveis
int poltrona_escolhida;
int idade;
int prof, estudante, crianca_carente_t,crianca_carente_q, crianca_ate12, acima_60, pg_integral;
int desconto_percentual;
char tecla_inicio;
char id_peca, id_secao;
char Ds;
int edipo_rei;
int peca;
float total_pago; // Valor pago em cada tiket
float preco_peca = 125.50;
float valor_total;
float desconto;
float caixa_total;
float total_arrecadado;
int quat_vendidos;
// Declaração de matrizes / vetores
int co[9];
int co1[9];
char cliente[40]= "";
char secao_escolhida[40]= "";
FILE* arq;//variavel arq armazeza e grava dados do arquivo tiket.txt
char str1[] = "tikets/1_terca/01.txt";//gera nome do arquivo para tiket txt
char str2[] = "tikets/1_terca/02.txt";
char str3[] = "tikets/1_terca/03.txt";
18char str4[] = "tikets/1_terca/04.txt";
char str5[] = "tikets/1_terca/05.txt";
char str6[] = "tikets/1_terca/06.txt";
char str7[] = "tikets/1_terca/07.txt";
char str8[] = "tikets/1_terca/08.txt";
char str9[] = "tikets/1_terca/09.txt";
char str10[] = "tikets/1_terca/10.txt";
char str11[] = "tikets/2_quinta/01.txt";
char str12[] = "tikets/2_quinta/02.txt";
char str13[] = "tikets/2_quinta/03.txt";
char str14[] = "tikets/2_quinta/04.txt";
char str15[] = "tikets/2_quinta/05.txt";
char str16[] = "tikets/2_quinta/06.txt";
char str17[] = "tikets/2_quinta/07.txt";
char str18[] = "tikets/2_quinta/08.txt";
char str19[] = "tikets/2_quinta/09.txt";
char str20[] = "tikets/2_quinta/10.txt";
//_____________________________________________________________________________________// Declaração de Funções
void escolhe_peca(void);
void escolhe_secao(void);
void escolhe_assento(void);
void perfil_cliente(void);
void sem_desconto(void);
void desconto_meia(void);
void data_hora(void);
void desconto_er(void);
void desconto_preco_peca(void);
void desconto_ac(void);
void limpa_historico(void);
void desconto_carente(void);
void poltrona_disponivel();
void desconto_cliente(void);
void grava_tiket(void);
void fluxo_de_caixa(void);
19//_____________________________________________________________________________________// Rotina principal
int main() {
setlocale(LC_ALL, "Portuguese"); //habilita a acentuação para o português
system("cls");
printf(" ____________________________________________ \n");
printf(" | |\n");
printf(" | BEM VINDO! |\n");
printf(" | |\n");
printf(" | SISTEMA DE VENDA DE INGRESSOS |\n");
printf(" | PARA TEATRO |\n");
printf(" | |\n");
printf(" |____________________________________________|\n");
printf(" ____________________________________________ \n");
printf(" | |\n");
printf(" | [1] = SISTEMA DE VENDAS |\n");
printf(" | [2] = FLUXO DE CAIXA |\n");
printf(" | [3] = LIMPAR HISTORICO DE VENDAS |\n");
printf(" |____________________________________________|\n");
//tecla_inicio = getchar();
//rotina sistema de escolha vendas fluxo caixa e limpar historico
scanf("%s",&tecla_inicio);
if(tecla_inicio == '1'){
escolhe_secao();
}else
if(tecla_inicio == '2'){
fluxo_de_caixa();
}else
if(tecla_inicio == '3'){
limpa_historico();
}else
main();// Volta ao inicio do programa
20main(); // volta ao inicio do programa
getchar();
return(0);
} // fim da rotina principal
//_____________________________________________________________________________________// Função que trata da escolha do horário de apresentação da peça
void escolhe_secao(void){
system("cls"); // Limpa a tela
printf("\n");
printf(" ____________________________________________ \n");
printf(" | |\n");
printf(" | PEÇA EM CARTAZ |\n");
printf(" | ROMEU E JULIETA R$.%.2f |\n",preco_peca);
printf(" |____________________________________________|\n");
printf("\n");
printf("\n"); // Pula linha
printf("\n ESCOLHA UMA DAS SESSÕES DISPONÍVEIS ABAIXO");
printf("\n");
printf("\n ");
printf("\n [1] = TERÇA FEIRA 18:30H ÁS 20:00H ");
printf("\n ");
printf("\n [2] = QUINTA FEIRA 18:30H ÁS 20:00H ");
printf("\n ");
printf("\n");
scanf("%s",&id_secao); // Ler a tecla digitada e armazena na variável id_sessão
switch(id_secao){ // Inicia um teste de caso com a variável id_secao
case '1':{ // Caso a variável id_secao contenha o caracter '1' strcpy (secao_escolhida, "TERÇA FEIRA 18:30H ÁS 20:00H");
break;
}
case '2':{ // Caso a variável id_secao contenha o caracter 2
21strcpy (secao_escolhida, "QUINTA FEIRA 18:30H ÁS 20:00H");
break;
}
default: { // Caso não seja nenhuma das opções acima
printf("\n");
printf(" OPÇÃO INVÁLIDA");
Sleep(100);
printf(".");
Sleep(100);
printf(".");
Sleep(100);
printf(".");
escolhe_secao(); // Chama a função escolhe_secao
break;
}
}
printf("\n");
printf(" VOCÊ ESCOLHEU A SEÇÃO DE %s",secao_escolhida);
//Sleep(2000);
escolhe_assento(); // Chama a função escolhe_secao
}
// Função que trata da escolha do assento/poltrona
void escolhe_assento(void){
int i;
int j = 5;
system("cls"); // Limpa a tela
if(id_secao == '1'){
printf("\n\n\n");
printf(" SEÇÃO DE TERÇA FEIRA\n");
printf(" ESCOLHA UMA CADEIRA ABAIXO\n");
printf(" 0= LIVRE 1= OCUPADA\n\n\n");
printf(" CADEIRA 01 CADEIRA 02 CADEIRA 03 CADEIRA 04 CADEIRA05\n");
printf(" [%d] [%d] [%d] [%d]
[%d]\n\n\n\n\n",co[0],co[1],co[2],co[3],co[4]);
printf(" CADEIRA 06 CADEIRA 07 CADEIRA 08 CADEIRA 09 CADEIRA10\n");
printf(" [%d] [%d] [%d] [%d] [%d]",co[5],co[6],co[7],co[8],co[9]);
}else if(id_secao == '2'){
printf("\n\n\n");
22printf(" SEÇÃO DE QUINTA FEIRA\n");
printf(" ESCOLHA UMA CADEIRA ABAIXO\n");
printf(" 0= LIVRE 1= OCUPADA\n\n\n");
printf(" CADEIRA 01 CADEIRA 02 CADEIRA 03 CADEIRA 04 CADEIRA05\n");
printf(" [%d] [%d] [%d] [%d]
[%d]\n\n\n\n\n",co1[0],co1[1],co1[2],co1[3],co1[4]);
printf(" CADEIRA 06 CADEIRA 07 CADEIRA 08 CADEIRA 09 CADEIRA10\n");
printf(" [%d] [%d] [%d] [%d]
[%d]",co1[5],co1[6],co1[7],co1[8],co1[9]);
}
printf("\n\n\n\n");
scanf("%d",&poltrona_escolhida);
if(id_secao == '1'){
if(poltrona_escolhida == co[0] || poltrona_escolhida == co[1] ||
poltrona_escolhida == co[2] || poltrona_escolhida == co[3] ||
poltrona_escolhida == co[4] || poltrona_escolhida == co[5] ||
poltrona_escolhida == co[6] || poltrona_escolhida == co[7] ||
poltrona_escolhida == co[8] || poltrona_escolhida == co[9]){
printf(" A CADEIRA QUE VOÇÊ ESCOLHEUNÃOESTÁDISPONÍVEL\n");
printf(" FAVOR ESCOLHA UMA CADEIRADISPONÍVEL\n");
Sleep(3000);
escolhe_assento(); // Chama a função escolhe assento novamente
}
}
if(id_secao == '2'){
if(poltrona_escolhida == co1[0] || poltrona_escolhida == co1[1] ||
poltrona_escolhida == co1[2] || poltrona_escolhida == co1[3] ||
poltrona_escolhida == co1[4] || poltrona_escolhida == co1[5] ||
poltrona_escolhida == co1[6] || poltrona_escolhida == co1[7] ||
poltrona_escolhida == co1[8] || poltrona_escolhida == co1[9]){
printf(" A CADEIRA QUE VOÇÊ ESCOLHEUNÃOESTÁDISPONÍVEL\n");
printf(" FAVOR ESCOLHA UMA CADEIRADISPONÍVEL\n");
Sleep(3000);
escolhe_assento(); // Chama a função escolhe assento novamente
23}
}
if(poltrona_escolhida < 11){
printf("VOÇÊ ESCOLHEU A POLTRONA: %d",poltrona_escolhida);
}
else{
printf("\n");//escolheu opção invalida
printf(" POR FAVOR ");
Sleep(100);
printf("ESCOLHA ");
Sleep(100);
printf("UMA POLTRONA DE ");
Sleep(100);
printf("1 A 10");
Sleep(100);
printf("!");
Sleep(2000);
escolhe_assento();
}
Sleep(100); // Atraso de 2 seg no programa
perfil_cliente(); // chama a função perfil do cliente
}
// Função que verifica perfil do cliente
void perfil_cliente(void){
system("cls"); // Limpa a tela
printf("\n\n");
printf(" SELECIONE A ALTERNATIVAABAIXO QUE CORRESPONDE COMO CLIENTE\n");
printf("\n");
printf(" 1 = É PROFESSOR DA REDE PÚBLICA?\n");
printf(" 2 = ESTUDANTE?\n");
printf(" 3 = CRIANÇA CARENTE DA REDE PÚBLICA?\n");
printf(" 4 = TEM ENTRE 2 E 12 ANOS?\n");
printf(" 5 = TEM ACIMA DE 60 ANOS?\n");
printf(" 6 = PAGAMENTO INTEIRO\n");
printf("\n\n");
scanf("%s",&Ds);
Sleep(100);
24system("cls");
desconto_cliente();
}
// pega a data e hora atual e imprime na tela
void data_hora(void)
{
char data_atual[9];
char time_atual[9];
// Apresenta a data atual _strdate( data_atual);
printf( "Data %s ", data_atual);
// Apresenta a hora atual _strtime( time_atual);
printf( "Hora %s ", time_atual);
Sleep(100);
}
void desconto_cliente(void){
switch(Ds){ // case desconto_meia e para crianças carentes, professores e idosos
case '1':{ //caso seja professor
strcpy (cliente, "PROFESSOR DA REDE PÚBLICA");
prof++;
desconto = preco_peca/2;
desconto_percentual = ((desconto/preco_peca)* 100);
total_pago = preco_peca - desconto;
break;
}
case '2':{
strcpy (cliente, "ESTUDANTE");
estudante++;
desconto = preco_peca/2;
desconto_percentual = ((desconto/preco_peca)* 100);
total_pago = preco_peca - desconto;
break;
}
case '3':{
strcpy (cliente, "CRIANÇA CARENTE DA REDE PÚBLICA");
if (id_secao == '2'){
crianca_carente_q++; desconto = preco_peca/2;
25desconto_percentual = ((desconto/preco_peca)* 100);
total_pago = preco_peca - desconto;
}else{
crianca_carente_t++;
desconto = preco_peca;
desconto_percentual = ((desconto/preco_peca)* 100);
total_pago = preco_peca - desconto;
}
break;
}
case '4':{
strcpy (cliente, "TEM ENTRE 2 E 12 ANOS");
crianca_ate12++;
desconto = preco_peca/2;
desconto_percentual = ((desconto/preco_peca)* 100);
total_pago = preco_peca - desconto;
break;
}
case '5':{
strcpy (cliente, "TEM ACIMA DE 60 ANOS");
acima_60++;
desconto = preco_peca/2;
desconto_percentual = ((desconto/preco_peca)* 100);
total_pago = preco_peca - desconto;
break;
}
case '6':{
strcpy (cliente, "PAGAMENTO INTEIRO");
pg_integral++;
desconto = 0;
desconto_percentual = ((desconto/preco_peca)* 100);
total_pago = preco_peca - desconto;
break;
}
default: { // Caso não seja nenhuma das opções acima
printf("\n");
printf(" OPÇÃO INVÁLIDA");
Sleep(100);
26printf(".");
Sleep(100);
printf(".");
Sleep(100);
printf(".");
desconto_cliente(); // Chama a função desconto
break;
}
}
system("cls");
printf(" \n");
printf("--------------------------------------------\n");
data_hora();
printf("N. Poltrona %d\n", poltrona_escolhida);
printf("--------------------------------------------\n");
printf(" Ingresso Peça teatral\n\n");
printf(" ROMEU E JULIETA\n");
printf(" %s\n\n",secao_escolhida);
printf("Foi concedido %d%% de desconto neste tiket\n\n*********",desconto_percentual);
printf(" %s ********\n\n\nValor inteiro---------------------R$ %.2f\n",cliente,preco_peca);
printf("Desconto--------------------------R$ %.2f\nTotal pago------------------------R$
%.2f",desconto,total_pago);
printf("\n");
grava_tiket();//chama a funçao GRAVA TIKET no sistema
}
void limpa_historico(void){//funcao limpa historico de vendas
printf("APAGANDO HISTORICO DE VENDAS");
prof =0;
estudante =0 ;
crianca_carente_q=0;
crianca_carente_t=0;
crianca_ate12=0;
acima_60=0;
pg_integral=0;
Sleep(2000);
system("cls");
remove("tikets/1_terca/01.txt");
remove("tikets/1_terca/02.txt");
27remove("tikets/1_terca/03.txt");
remove("tikets/1_terca/04.txt");
remove("tikets/1_terca/05.txt");
remove("tikets/1_terca/06.txt");
remove("tikets/1_terca/07.txt");
remove("tikets/1_terca/08.txt");
remove("tikets/1_terca/09.txt");
remove("tikets/1_terca/10.txt");
remove("tikets/2_quinta/01.txt");
remove("tikets/2_quinta/02.txt");
remove("tikets/2_quinta/03.txt");
remove("tikets/2_quinta/04.txt");
remove("tikets/2_quinta/05.txt");
remove("tikets/2_quinta/06.txt");
remove("tikets/2_quinta/07.txt");
remove("tikets/2_quinta/08.txt");
remove("tikets/2_quinta/09.txt");
remove("tikets/2_quinta/10.txt");
printf("TODO O HISTORICO FOI APAGADO COM SUCESSO!");
Sleep(2000);
}
//função gera arquivos txt historico de vendas
void grava_tiket(void){
char data_atual[9];
char time_atual[9];
//gera_arquivos();
switch(poltrona_escolhida){
case 1:{ // Caso a variável id_secao contenha o caracter '1' if(id_secao == '1'){
arq = fopen(str1,"w");
co [0] = 1; //coloca valor 1 na posição 0,0 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str11,"w");
co1 [0] = 1; //coloca valor 1 na posição 1,0 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
}
28break;
}
case 2:{ // Caso a variável id_secao contenha o caracter '2' if(id_secao == '1'){
arq = fopen(str2,"w");
co[1] = 1; //coloca valor 1 na posição 0,1 do vetor para cadeira ocupada
printf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str12,"w");
co1[1] = 1; //coloca valor 1 na posição 1,1 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
}
break;
case 3:{ // Caso a variável id_secao contenha o caracter '3' if(id_secao == '1'){
arq = fopen(str3,"w");
co[2] = 1; //coloca valor 1 na posição 0,2 do vetor para cadeira ocupada
printf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str13,"w");
co1[2] = 1; //coloca valor 1 na posição 1,2 do vetor para cadeira ocupada
printf("\n Tiket gerado com sucesso!");
}
break;
}
case 4:{ // Caso a variável id_secao contenha o caracter '4' if(id_secao == '1'){
arq = fopen(str4,"w");
co[3] = 1; //coloca valor 1 na posição 0,3 do vetor para cadeira ocupada
printf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str14,"w");
co1[3] = 1; //coloca valor 1 na posição 1,3 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
}
29break;
}
case 5:{ // Caso a variável id_secao contenha o caracter '5' if(id_secao == '1'){
arq = fopen(str5,"w");
co[4] = 1; //coloca valor 1 na posição 0,4 do vetor para cadeira ocupada
printf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str15,"w");
co1[4] = 1; //coloca valor 1 na posição 1,4 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
}
break;
}
case 6:{ // Caso a variável id_secao contenha o caracter '6' if(id_secao == '1'){
arq = fopen(str6,"w");
co[5] = 1; //coloca valor 1 na posição 0,5 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str16,"w");
co1[5] = 1; //coloca valor 1 na posição 1,5 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
}
break;
}
case 7:{ // Caso a variável id_secao contenha o caracter '7' if(id_secao == '1'){
arq = fopen(str7,"w");
co[6] = 1; //coloca valor 1 na posição 0,6 do vetor para cadeira ocupada
printf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str17,"w");
co1[6] = 1; //coloca valor 1 na posição 1,6 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
30}
break;
}
case 8:{ // Caso a variável id_secao contenha o caracter '8' if(id_secao == '1'){
arq = fopen(str8,"w");
co[7] = 1; //coloca valor 1 na posição 0,7 do vetor para cadeira ocupada
printf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str18,"w");
co1[7] = 1; //coloca valor 1 na posição 1,7 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
}
break;
}
case 9:{ // Caso a variável id_secao contenha o caracter '9' if(id_secao == '1'){
arq = fopen(str9,"w");
co[8] = 1; //coloca valor 1 na posição 0,8 do vetor para cadeira ocupada
printf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str19,"w");
co1[8] = 1; //coloca valor 1 na posição 1,8 do vetor para cadeira ocupadaprintf("\n Tiket gerado com sucesso!");
}
break;
}
case 10:{ // Caso a variável id_secao contenha o caracter '10' if(id_secao == '1'){
arq = fopen(str10,"w");
co[9] = 1; //coloca valor 1 na posição 0,9 do vetor para cadeira ocupada
printf("\n Tiket gerado com sucesso!");
} else
if(id_secao == '2'){
arq = fopen(str20,"w");
co1[9] = 1; //coloca valor 1 na posição 1,9 do vetor para cadeira ocupada
31printf("\n Tiket gerado com sucesso!");
}
break;
}
}
default:{
printf("nao gravou ");
break;
}
}_strdate( data_atual); _strtime( time_atual);
fprintf(arq,"\n--------------------------------------------\n");
fprintf(arq, "Data %s Hora %s N. Poltrona %d\n", data_atual, time_atual, poltrona_escolhida);
fprintf(arq,"--------------------------------------------\n");
fprintf(arq," Ingresso Peça teatral\n\n ROMEU E JULIETA\n",secao_escolhida);
fprintf(arq,"Foi concedido %d%% de desconto neste tiket\n\n*********",desconto_percentual);
fprintf(arq," %s ********\n\n\nValor inteiro---------------------R$ %.2f\n",cliente,preco_peca);
fprintf(arq,"Desconto--------------------------R$ %.2f\nTotal pago------------------------R$
%.2f",desconto,total_pago);
fclose(arq);
printf("\n\n [I]= VOLTAAO INÍCIO");
printf("\n\n");
if('s' == getchar()) {escolhe_secao();}
else if('i' == getchar()) {main();}
}
// Função fluxo de caixa
void fluxo_de_caixa(void){
float meia_entrada = preco_peca/2;
total_arrecadado = ((prof * meia_entrada )+ (estudante * meia_entrada )+ (crianca_carente_q * meia_entrada )+ (acima_60 * meia_entrada )+ (crianca_ate12*meia_entrada)+ (preco_peca*pg_integral));
quat_vendidos = (prof + estudante + crianca_carente_q +
acima_60 + crianca_ate12 + pg_integral);
system("cls"); // Limpa a tela
printf("\n");
printf(" RELATÓRIO DE CAIXA\n\n");
32printf(" QUANTIDADE DE INGRESSOS VENDIDOS PROFESSOR DA REDE PUBLICA:----------- %d\n",prof);
printf(" QUANTIDADE DE INGESSOS VENDIDOS ESTUDANTE:----------------------------%d\n", estudante);
printf(" QUANTIDADE DE INGRESSOS VENDIDOS CRIANÇA CARENTE QUINTAFEIRA:-------- %d\n", crianca_carente_q);
printf(" QUANTIDADE DE INGRESSOS VENDIDOS CRIANÇA CARENTE TERÇAFEIRA:--------- %d\n", crianca_carente_t);
printf(" QUANTIDADE DE INGRESSOS VENDIDOS IDOSO ACIMA DE 60 ANOS:--------------%d\n", acima_60);
printf(" QUANTIDADE DE INGRESSOS VENDIDOS CRIANÇAS ENTRE 2 E 12 ANOS:---------- %d\n",crianca_ate12);
printf(" QUANTIDADE DE INGRESSOS VENDIDOS VALOR INTEGRAL:---------------------- %d\n",pg_integral);
printf("\n");
printf(" QUANTIDADE TOTAL VENDIDOS:---------------------------------------N. %d\n",quat_vendidos);
printf(" TOTAL:-----------------------------------------------------------R$ %.2f\n",total_arrecadado);
// Sleep(1000);
printf("\n\n\n PARA VOLTAR PRECIONE [I] \n");
// scanf("%s",esc);
if('i' == getchar()) {main();}
else {fluxo_de_caixa();}
}
