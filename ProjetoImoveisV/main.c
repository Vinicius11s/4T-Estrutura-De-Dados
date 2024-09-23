#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

#define TF 3

struct imoveis{
	int tipo;
	char nome[100];
	int vagas_garagem;
	int qtde_banheiros;
	float valor;
};



void menu(struct imoveis reg_imovel[TF]) {
	system("cls");
	setlocale(LC_ALL,"portuguese");
	
	int aux = 0;
	int opcao = -1; 
	char username[100];
	DWORD username_len = sizeof(username);
	GetUserName(username, &username_len);
	while(opcao != 0){
		system("cls");
		printf("\t<<< Programa Imóveis >>>");
		printf("\n\n\tOlá %s Oque Deseja Fazer...?", username);
		
		printf("\n\nMenu de Opções:");
		printf("\n1-Cadastro de Novo Imóvel.");
		printf("\n2-Consulta de Imóveis Cadastrados.");
		printf("\n3-Alterar um Imóvel existente.");
		printf("\n0-Encerrar o Programa.");
	
		printf("\n\nEscolha uma Opção: ");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1:
				carregar_registro(reg_imovel);
				aux++;
			break;
			
			
			case 2:
				if(aux == 0){
					system("cls");					
					printf("\t<<<Consultar Imóveis>>>");
					printf("\n\nNenhum Imóvel foi Cadastrado.");
					printf("\n");
					printf("\n");
					system("pause");
				}
				else{
					listar_imoveis(reg_imovel);		
				}
			break;
			
			
			case 3:
				listar_alterar(reg_imovel);
			break;
			
			
			case 0:
				printf("\nFim!\n");
			break;
			
			default:
				system("cls");
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
