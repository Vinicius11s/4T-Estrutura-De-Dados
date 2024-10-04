#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>


#define TF 10

struct imoveis{
	int tipo;
	char nome[100];
	float area_m2;
	int qtde_quartos;
	int vagas_garagem;
	int qtde_banheiros;
	float valor;
	char dataCadastro[11];
	bool status;
};


void exibir_imovel_alterar(int imovel_escohido, struct imoveis reg_imovel[TF]){
	limpaTela();
	int i=0;
	printf("\t<<<Alterar um Registro de Imóvel existente>>>");		
	printf("\n\n[Dados Atuais] Imóvel %d: ", imovel_escohido + 1);
	
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
	printf("\nÁrea do Imovel %0.2f m²", reg_imovel[imovel_escohido].area_m2);
	printf("\nQuantidade de Quartos: %d", reg_imovel[imovel_escohido].qtde_quartos);
	printf("\nVagas de Garagem: %d", reg_imovel[imovel_escohido].vagas_garagem);	
	printf("\nQuantidade de Banheiros: %d", reg_imovel[imovel_escohido].qtde_banheiros);
	printf("\nValor: %0.2f", reg_imovel[imovel_escohido].valor);
	printf("\nData de Cadastro: %s", reg_imovel[imovel_escohido].dataCadastro);
	pularLinha();
	pularLinha();
	system("pause");
}


void alterar_registro(int imovel_escohido, struct imoveis reg_imovel[TF]){
		int i = imovel_escohido;
		
		reg_imovel[i].tipo = 0;
		while(reg_imovel[i].tipo != 1 && reg_imovel[i].tipo != 2 && reg_imovel[i].tipo != 3 ){

			printf("\n\n[Alteração] Imóvel %d: ", i+1);

			printf("\n\n1-Casa ; 2-Apartamento ; 3-Terreno.");
			printf("\nInforme o Tipo do Imóvel: ");
			scanf("%d", &reg_imovel[i].tipo);
			
			if(reg_imovel[i].tipo != 1 && reg_imovel[i].tipo != 2 && reg_imovel[i].tipo != 3){
				printf("\n\tInforme um valor váldo para Tipo do Imóvel !!");
				printf("\n");
				system("pause");	
				limpaTela();
			}
		}	
		printf("\nInforme o Nome do Imóvel: ");
		fflush(stdin);
		gets(reg_imovel[i].nome);

		printf("\nInforme a Área do Imóvel em metros quadrados: ");
		scanf("%f", &reg_imovel[i].area_m2);			

		printf("\nInforme a quantidade de quartos: ");
		scanf("%d", &reg_imovel[i].qtde_quartos);				
		
		printf("\nInforme a quantidade de vagas de garagem do Imóvel: ");
		scanf("%d", &reg_imovel[i].vagas_garagem);
		
		printf("\nInforme a quantidade de banheiros do Imóvel: ");
		scanf("%d", &reg_imovel[i].qtde_banheiros);
		
		printf("\nInforme o Valor do Imóvel: ");
		scanf("%f", &reg_imovel[i].valor);
		
		printf("\nInforme a data de Cadastro.");
		printf("\ndd/mm/yyyy: ");
		fflush(stdin);
		gets(reg_imovel[i].dataCadastro);
			
		printf("\n\n\tAlteração concluída com Sucesso!!");	
		pularLinha();
		system("pause");
		
}

void listar_alterar(int contCadastro, struct imoveis reg_imovel[TF]){
	int i=0, opcao = -1, imovel_escohido;

	while(opcao != 0){
		limpaTela();
		printf("\t<<<Alterar um Registro de Imóvel existente>>>");
		
		printf("\n\n\tImóveis Cadastrados:");
		
		for(i=0; i<contCadastro; i++){
			printf("\nImovel %d: %s", i+1, reg_imovel[i].nome);
		}
		printf("\n0-Sair");
	
		printf("\n");
		printf("\nInforme o número do Imóvel que deseja alterar: ");
		scanf("%d", &opcao);
				
		if(opcao >0 && opcao <= contCadastro){
			imovel_escohido = opcao - 1;
			exibir_imovel_alterar(imovel_escohido, reg_imovel);
			alterar_registro(imovel_escohido, reg_imovel);
		}	
		else{
			if(opcao != 0){
				printf("O Imóvel escolhido não existe.");
				system("pause");			
			}
		}
	}
}
