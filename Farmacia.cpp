#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//declaracao de registros
typedef struct Login{
	char login[10];
	int senha;
}Login;

typedef struct Funcionario{
	char nome[10];
	int matricula;
	Login login;
}Funcionario;

typedef struct Remedio{
	char nome[10];
	char validade[12];
	float valor;
	int quantidade;
}Remedio;

//declaracao de variaveis globais
Funcionario vetfunc[2];
Remedio vetremedio[2];

//declaracao dos procedimentos
void Logar();
void MenuAdm();
void MenuFunc();
void CadastrarFuncionario();
void CadastrarRemedio();
void RealizarVenda();
void RelatorioEstoque();
main(){
 Logar();
}//fim main


void Logar(){
Login aux,adm;
int op,achou;

//inicializar administrador
strcpy(adm.login,"adm");
adm.senha=123;

		do{
		achou=0;
		system("cls");
		printf("Login: ");
		fflush(stdin);
		gets(aux.login);
		printf("Senha: ");
		scanf("%i",&aux.senha);
			
		//realizar login	
		if(strcmp(adm.login,aux.login)==0 && adm.senha==aux.senha ){
			achou=1;
			MenuAdm();		
		}//fim comparacao do perfil adm	
		
		for(int i=0;i<2;i++){
			if(strcmp(vetfunc[i].login.login,aux.login)==0 && vetfunc[i].login.senha==aux.senha){
				achou=1;
				MenuFunc();			
			}//fim if comparacao do funcionario	
		}//fim for comparacao funcionario	
			
			
			
			
		if(achou==0){
		printf("\nLogin/senha invalido\n\n");	
		}	
		printf("Desejar continuar no sistema\n");
		printf("1-SIM\n");
		printf("0-NAO\n");
		scanf("%i",&op);	
		if(op==0){
			exit(0);
		}
		}while(op!=0);
	
}//fim login 


void MenuAdm(){
int op;

	do{
		system("cls");
		printf("1-Cadastrar Funcionario\n");
		printf("2-Cadastrar Remedio\n");
		printf("3-Realizar Venda\n");
		printf("4-Relatorio estoque\n");
		printf("0-Sair\n");
		scanf("%i",&op);
		switch(op){
			case 1:
			CadastrarFuncionario();	
				break;
			case 2:
			CadastrarRemedio();
				break;
			case 3:
			RealizarVenda();
				break;
			case 4:
			RelatorioEstoque();	
				break;
			case 0:
				break;
			default:
			printf("Opcao invalida\n");					
		}
		system("pause");
	}while(op!=0);	
	
}//fim menu adm

void MenuFunc(){
int op;

	do{
		system("cls");
		printf("1-Realizar Venda\n");
		printf("0-Sair\n");
		scanf("%i",&op);
		switch(op){
			case 1:
				RealizarVenda();
				break;
			case 0:
				break;
			default:
			printf("Opcao invalida\n");					
		}
		system("pause");
	}while(op!=0);	
	
}//fim menu adm

void CadastrarFuncionario(){
	for(int i=0;i<2;i++){
	printf("Nome: ");
	fflush(stdin);
	gets(vetfunc[i].nome);
	printf("\nMatricula: ");
	scanf("%i",&vetfunc[i].matricula);
	printf("\nLogin: ");
	fflush(stdin);
	gets(vetfunc[i].login.login);
	printf("\nSenha: ");
	scanf("%i",&vetfunc[i].login.senha);
	}//fim for
	
}//fim cadastro funcionario

void CadastrarRemedio(){
	for(int i=0;i<2;i++){
	printf("Nome: ");
	fflush(stdin);
	gets(vetremedio[i].nome);
	printf("\nValor: ");
	scanf("%f",&vetremedio[i].valor);
	printf("\nValidade: ");
	fflush(stdin);
	gets(vetremedio[i].validade);
	printf("\nQuantidade: ");
	scanf("%i",&vetremedio[i].quantidade);
	}//fim for cadastro	
}//fim cadastrar remedio

void RealizarVenda(){
char nomepesq[10];
int qntpesq;
float total,valorpago,valortroco;
	//entrada de dados para remedio
	printf("Nome: ");
	fflush(stdin);
	gets(nomepesq);
	//pesquisando nome do remedio no vetor
	for(int i=0;i<2;i++){
		if(strcmp(vetremedio[i].nome,nomepesq)==0){
		printf("Nome:%s\t- Preco:%.2f \n ",vetremedio[i].nome,vetremedio[i].valor);
		printf("\nDeseja quantas unidades: ");
		scanf("%i",&qntpesq);
		if(qntpesq<=vetremedio[i].quantidade){
		total= qntpesq*vetremedio[i].valor;
		printf("Total:%.2f \n",total);
		printf("\nValor pago: ");
		scanf("%f",&valorpago);
		valortroco= valorpago-total;
		printf("Troco:%.2f\n",valortroco);
		vetremedio[i].quantidade=vetremedio[i].quantidade-qntpesq; 	
		}//fim if quantidade no estoque	
		}//fim if comparacao nome remedio
	}//fim for para pesquisa remedio
		
	
}//fim venda


void RelatorioEstoque(){

	for(int i=0;i<2;i++){
printf("\nNome:%s\tValidade:%s\tQnt:%i\n",vetremedio[i].nome,vetremedio[i].validade,vetremedio[i].quantidade);		
	}//fim for	
	
}//fim relatorio estoque










