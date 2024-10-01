#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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

struct imoveisCopia{
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



void listar_excluir(int contCadastro, struct imoveis reg_imovel[TF]){
	struct imoveisCopia reg_imovel[TF];
	struct imoveisOff reg_imovel[TF];

	int i, opcao = -1, imovel_escohido;

	while(opcao != 0){
		system("cls");
		printf("\t<<<Excluir Registro de um Imóvel>>>");
		printf("\n\n\tImóveis Ativos:");
		
			for(i=0; i<contCadastro; i++){
				printf("\nImovel %d: %s", i+1, reg_imovel[i].nome);
			}
			printf("\n0-Sair");
		
			printf("\n");
			printf("\nInforme o número do Imóvel que deseja excluir: ");
			scanf("%d", &opcao);			
		

				
		if(opcao >0 && opcao <= contCadastro){
			imovel_escohido = opcao - 1;
			imoveisCopia reg_imovel = imoveis reg_imovel;
						
		}	
		else{
			printf("O Imóvel escolhido não existe.");
		}
	}
}


