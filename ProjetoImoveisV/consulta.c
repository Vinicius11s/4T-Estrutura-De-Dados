#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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
	
void exibir_imovel(int imovel_escohido, struct imoveis reg_imovel[TF]){
	system("cls");
	int i=0;
	printf("\n\nRegistro de Imóvel %d", imovel_escohido + 1);
	
	if(reg_imovel[imovel_escohido].tipo == 1){
		printf("\n\nImóvel do Tipo: Casa");
	}
	else if(reg_imovel[imovel_escohido].tipo == 2){
			printf("\n\nImóvel do Tipo: Apartamento");
	}
	else if(reg_imovel[imovel_escohido].tipo == 3){
			printf("\n\nImóvel do Tipo: Terreno");
	}				
					
	printf("\nNome: %s", reg_imovel[imovel_escohido].nome);
	printf("\nVagas de Garagem: %d", reg_imovel[imovel_escohido].vagas_garagem);	
	printf("\nQuantidade de Banheiros: %d", reg_imovel[imovel_escohido].qtde_banheiros);
	printf("\nValor: %0.2f", reg_imovel[imovel_escohido].valor);
	printf("\n");
	printf("\n");
	system("pause");
}

void listar_imoveis(int contCadastro, struct imoveis reg_imovel[TF]){
	int opcao = -1, imovel_escohido;
	int i=0;
	while(opcao != 0){
		system("cls");
		printf("\t<<<Consultar Imóveis>>>");
		printf("\n\n\tImóveis Cadastrados:");
		
		for(i=0; i<contCadastro ; i++){
			if(reg_imovel[i].status ==  true){
				printf("\nImovel %d: %s", i+1, reg_imovel[i].nome);		
			}
		}
		printf("\n0-Sair");
	
		printf("\n");
		printf("\nInforme o número do Imóvel que deseja consultar: ");
		scanf("%d", &opcao);
				
		if(opcao >0 && opcao <= TF){
			imovel_escohido = opcao - 1;
			exibir_imovel(imovel_escohido, reg_imovel);
		}	
		else{
			printf("O Imóvel escolhido não existe.");
		}
	}
}

