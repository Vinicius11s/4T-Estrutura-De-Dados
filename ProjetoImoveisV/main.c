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
		printf("\t<<< Programa Im�veis >>>");
		printf("\n\n\tOl� %s Oque Deseja Fazer...?", username);
		
		printf("\n\nMenu de Op��es:");
		printf("\n1-Cadastro de Novo Im�vel.");
		printf("\n2-Consulta de Im�veis Cadastrados.");
		printf("\n3-Alterar um Im�vel existente.");
		printf("\n0-Encerrar o Programa.");
	
		printf("\n\nEscolha uma Op��o: ");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1:
				carregar_registro(reg_imovel);
				aux++;
			break;
			
			
			case 2:
				if(aux == 0){
					system("cls");					
					printf("\t<<<Consultar Im�veis>>>");
					printf("\n\nNenhum Im�vel foi Cadastrado.");
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
				printf("Op��o Inv�lida !!");
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
