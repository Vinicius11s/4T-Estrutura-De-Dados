#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
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

void carregar_registro(struct imoveis reg_imovel[TF]){
	int opcao = -1;
	int i = 0;
	do{

		system("cls");
	    reg_imovel[i].tipo = 0;
	    
		while(reg_imovel[i].tipo != 1 && reg_imovel[i].tipo != 2 && reg_imovel[i].tipo != 3 ){
			printf("\t<<<Cadastro de um Novo Im�vel>>>");

			printf("\n\nRegistro Im�vel: %d", i+1);

			printf("\n\n1-Casa ; 2-Apartamento ; 3-Terreno.");
			printf("\nInforme um n�mero para Tipo do Im�vel: ");
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
		
		reg_imovel[i].status = true;
		i++;
		
		printf("\n1-Sim ; 2-N�o.");
		printf("\nDeseja cadastrar um novo Im�vel ? ");
		scanf("%d", &opcao);

		

	}while(opcao != 2);
}
