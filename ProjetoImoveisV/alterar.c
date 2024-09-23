#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TF 3

struct imoveis{
	int tipo;
	char nome[100];
	int vagas_garagem;
	int qtde_banheiros;
	float valor;
};

void alterar_registro(int imovel_escohido, struct imoveis reg_imovel[TF]){
		int i = imovel_escohido;
		
		reg_imovel[i].tipo = 0;
		while(reg_imovel[i].tipo != 1 && reg_imovel[i].tipo != 2 && reg_imovel[i].tipo != 3 ){

			printf("\n\nRegistro Im�vel: %d", i+1);

			printf("\n\n1-Casa ; 2-Apartamento ; 3-Terreno.");
			printf("\nInforme o Tipo do Im�vel: ");
			scanf("%d", &reg_imovel[i].tipo);
			
			if(reg_imovel[i].tipo != 1 && reg_imovel[i].tipo != 2 && reg_imovel[i].tipo != 3){
				printf("\n\tInforme um valor v�ldo para Tipo do Im�vel !!");
				printf("\n\n");
				system("pause");	
				system("cls");
			}
		}
					
		printf("\nInforme o Nome do Im�vel: ");
		fflush(stdin);
		gets(reg_imovel[i].nome);
		
		
		printf("\nInforme a quantidade de vagas de garagem do Im�vel: ");
		scanf("%d", &reg_imovel[i].vagas_garagem);
		
		printf("\nInforme a quantidade de banheiros do Im�vel: ");
		scanf("%d", &reg_imovel[i].qtde_banheiros);
		
		printf("\nInforme o Valor do Im�vel: ");
		scanf("%f", &reg_imovel[i].valor);
			
		printf("\n\n\tIm�vel %s Cadastrado com Sucesso!!", reg_imovel[i].nome);	
		printf("\n");
		
}

void listar_alterar(struct imoveis reg_imovel[TF]){
	int i, opcao = -1, imovel_escohido;

	while(opcao != 0){
		system("cls");
		printf("\t<<<Alterar Im�veis>>>");
		printf("\n\n\tIm�veis Cadastrados:");
		
		for(i=0; i<TF; i++){
			printf("\nImovel %d: %s", i+1, reg_imovel[i].nome);
		}
		printf("\n0-Sair");
	
		printf("\n");
		printf("\nInforme o n�mero do Im�vel que deseja alterar: ");
		scanf("%d", &opcao);
				
		if(opcao >0 && opcao <= TF){
			imovel_escohido = opcao - 1;
			exibir_imovel(imovel_escohido, reg_imovel);
			alterar_registro(imovel_escohido, reg_imovel);
		}	
		else{
			printf("O Im�vel escolhido n�o existe.");
			system("pause");
		}
	}
}


