#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

struct no{
	int id;
	char nome[50];
	char cidadeTime[50];
	int anoCriacao;
	int qtdeLibertadores;
	int qtdeCopaDoBrasil;
	
	struct no *prox;
	struct no *ante;
};

typedef struct no Lista;

void limpaTela(){
	system("cls");
}
void pularLinha(){
	printf("\n");
}
int listaVazia(Lista *lista) {
    if (lista == NULL)
        return 1;

    return 0;
}

void Menu(){
	Lista *lista1 = NULL;  // Inicializa a lista como vazia
		
	setlocale(LC_ALL,"portuguese");
	
	char username[100];
	DWORD username_len = sizeof(username);
	GetUserName(username, &username_len);
	
	int opcao=-1;
		while(opcao != 0){
		limpaTela();
		printf("\t<<<Este Algoritmo torna possível realizar a manipulação de dados em uma Lista Duplamente Encadeada>>>");
		printf("\n\n\tOlá %s Oque Deseja Fazer...?", username);
		
		printf("\n\nMenu de Opções:");
		printf("\n1- Adicionar um novo cadastro de maneira ordenada.");
		printf("\n2- Excluir um cadastro definitivamente.");
		printf("\n0- Encerrar o Programa.");
	
		printf("\n\nEscolha um número e pressione ENTER: ");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1:
				limpaTela();
				printf("\t<<<Opcão escolhida: Adicionar um novo cadastro de maneira ordenada. >>>");
				lista1 = carregaNovoCadastro(lista1);
				break;
			case 2:
				limpaTela();
				printf("\t<<<Opcão escolhida: Excluir um cadastro definitivamente. >>>");
				exibirCadastros(lista1);
				system("pause");
				break;
			case 0:
				break;
			default:
				pularLinha();
				printf("Opção Inválida.");
				pularLinha();
				system("pause");
		}		
	}
	
}


int main(int argc, char *argv[]) {
	Menu();
	return 0;
}
