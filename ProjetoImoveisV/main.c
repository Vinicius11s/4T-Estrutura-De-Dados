#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

#define TF 5

struct imoveis{
	int tipo;
	char nome[100];
	int vagas_garagem;
	int qtde_banheiros;
	float valor;
	bool status;
};

struct imoveisOff{
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


void menu(struct imoveis reg_imovel[TF]){
	limpaTela();
	int tamanhoVetor = 0;
	setlocale(LC_ALL,"portuguese");
	
	int opcao = -1, contCadastro = 0;
	char username[100];
	DWORD username_len = sizeof(username);
	GetUserName(username, &username_len);
	
	while(opcao != 0){
		limpaTela();
		printf("\t<<< Programa Im�veis >>>");
		printf("\n\n\tOl� %s Oque Deseja Fazer...?", username);
		
		printf("\n\nMenu de Op��es:");
		printf("\n1- Cadastro de um Novo Im�vel.");
		printf("\n2- Consulta de Im�veis Cadastrados.");
		printf("\n3- Alterar um Registro de Im�vel existente.");
		printf("\n4- Excluir Registro de um Im�vel.");
		printf("\n5- Ativar Registro de um Im�vel Exclu�do.");
		printf("\n6- Ordenar dados de um vetor.");
		printf("\n7- Gravar Dados em Arquivo.");
		printf("\n8- Recuperar Dados da �ltima execu��o.");
		printf("\n9- Excluir Arquivo imoveis.bin. por completo");

		printf("\n0- Encerrar o Programa.");
	
		printf("\n\nEscolha um n�mero e pressione ENTER: ");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1:
				carregar_registro(reg_imovel, &contCadastro);
				break;
			case 2:
				if(contCadastro == 0){
					limpaTela();
					printf("\t<<<Consulta de Im�veis Cadastrados>>>\n");
					printf("\nNenhum Im�vel foi Cadastrado.");
					printf("\n");
					printf("\n");
					system("pause");
				}
				else{
					listar_imoveis(contCadastro, reg_imovel);
				}
				break;
			case 3:
				listar_alterar(contCadastro, reg_imovel);
				break;
			case 4:
				listar_excluir(contCadastro, reg_imovel);	
				break;
			case 5:
				listar_ativar(contCadastro, reg_imovel);
				break;
			case 6:
				exibir_campos(contCadastro, reg_imovel);
				break;	
			case 7:
				gravar_arquivo(reg_imovel);
				break;
			case 8:
				ler_arquivo(reg_imovel);
				break;
			case 9:
				excluirArquivo(reg_imovel);
				break;
			case 0:
				printf("\nFim!\n");
				break;
			default:
				limpaTela();
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
