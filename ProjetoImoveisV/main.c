#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

#define TF 3

struct imoveis{
	int tipo;
	char nome[100];
	int vagas_garagem;
	int qtde_banheiros;
	float valor;
	bool status;
};

void limpaTela(){
	system("cls");
}

void consultaRegistgros(int *aux, int opcao, struct imoveis reg_imovel[TF]){
	switch(opcao){
		case 2:
			if(*aux == 0){
				limpaTela();					
				printf("\t<<<Consulta de Imóveis Cadastrados>>>");
				printf("\n\nNenhum Imóvel foi Cadastrado.");
				printf("\n");
				printf("\n");
				system("pause");
			}
			else
				listar_imoveis(reg_imovel);	
		break;
		case 3:
			if(*aux == 0){
				limpaTela();				
				printf("\t<<<Alterar um Imóvel existente>>>");
				printf("\n\nNenhum Imóvel foi Cadastrado.");
				printf("\n");
				printf("\n");
				system("pause");
			}
			else{
				listar_imoveis(reg_imovel);	
				listar_alterar(reg_imovel);
			}
		break;
		case 4:
			if(*aux == 0){
				limpaTela();				
				printf("\t<<<Excluir Registro de um Imóvel>>>");
				printf("\n\nNenhum Imóvel foi Cadastrado.");
				printf("\n");
				printf("\n");
				system("pause");
			}
			else{
				listar_imoveis_excluir(reg_imovel);	
				listar_alterar(reg_imovel);
			}			
	}

}

void menu(struct imoveis reg_imovel[TF]) {
	limpaTela();
	setlocale(LC_ALL,"portuguese");
	
	int aux = 0, opcao = -1; 
	char username[100];
	DWORD username_len = sizeof(username);
	GetUserName(username, &username_len);
	
	while(opcao != 0){
		limpaTela();
		printf("\t<<< Programa Imóveis >>>");
		printf("\n\n\tOlá %s Oque Deseja Fazer...?", username);
		
		printf("\n\nMenu de Opções:");
		printf("\n1- Cadastro de um Novo Imóvel.");
		printf("\n2- Consulta de Imóveis Cadastrados.");
		printf("\n3- Alterar um Registro de Imóvel existente.");
		printf("\n4- Excluir Registro de um Imóvel.");

		printf("\n0- Encerrar o Programa.");
	
		printf("\n\nEscolha um número e pressione ENTER: ");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1:
				carregar_registro(reg_imovel);
				aux++;
			break;
			case 2:
				consultaRegistgros(&aux, opcao, reg_imovel);
			break;
			case 3:
				consultaRegistgros(&aux, opcao, reg_imovel);
			break;
			case 4:
				consultaRegistgros(&aux, opcao, reg_imovel);	
			break;
			case 0:
				printf("\nFim!\n");
			break;
			
			default:
				limpaTela();
				printf("Opção Inválida !!");
				printf("\n");
				printf("\n");
				system("pause");
		}		
	}
}
	
	
void main() {
	setlocale(LC_ALL,"portuguese");
	struct imoveis reg_imovel[TF];
	
	menu(reg_imovel);
}
