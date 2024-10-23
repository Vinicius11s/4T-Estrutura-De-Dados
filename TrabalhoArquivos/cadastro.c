#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TF 10

struct imoveis{
	int tipo;
	char nome[100];
	char endereco[200];
	float area_m2;
	int qtde_quartos;
	int vagas_garagem;
	int qtde_banheiros;
	float valor;
	char dataCadastro[11];
	bool status;
};
void carregar_registro(struct imoveis reg_imovel[TF], int *contCadastro){
	int opcao = -1;
	int i;
	do{
		i = *contCadastro;
		limpaTela();
	    reg_imovel[i].tipo = 0;
	    
		while(reg_imovel[i].tipo != 1 && reg_imovel[i].tipo != 2 && reg_imovel[i].tipo != 3 ){
			printf("\t<<<Cadastro de um Novo Im�vel>>>");

			printf("\n\nRegistro Im�vel: %d", i+1);

			printf("\n\n1-Casa ; 2-Apartamento ; 3-Terreno.");
			printf("\nInforme um n�mero para Tipo do Im�vel: ");
			scanf("%d", &reg_imovel[i].tipo);			
			if(reg_imovel[i].tipo != 1 && reg_imovel[i].tipo != 2 && reg_imovel[i].tipo != 3){
				printf("\n\tInforme um valor v�ldo para Tipo do Im�vel !!");
				pularLinha();
				pularLinha();
				system("pause");	
				limpaTela();
			}
		}
					
		printf("\nInforme o Nome do Im�vel: ");
		fflush(stdin);
		gets(reg_imovel[i].nome);
		
		printf("\nInforme o endere�o do Im�vel: ");
		fflush(stdin);
		gets(reg_imovel[i].endereco);	
		
		printf("\nInforme a �rea do Im�vel em metros quadrados: ");
		scanf("%f", &reg_imovel[i].area_m2);			

		printf("\nInforme a quantidade de quartos: ");
		scanf("%d", &reg_imovel[i].qtde_quartos);		
		
		printf("\nInforme a quantidade de vagas de garagem: ");
		scanf("%d", &reg_imovel[i].vagas_garagem);
		
		printf("\nInforme a quantidade de banheiros: ");
		scanf("%d", &reg_imovel[i].qtde_banheiros);
		
		printf("\nInforme o Valor: ");
		scanf("%f", &reg_imovel[i].valor);

		printf("\nInforme a data de Cadastro.");
		printf("\ndd/mm/yyyy: ");
		fflush(stdin);
		gets(reg_imovel[i].dataCadastro);
			
		printf("\n\n\tIm�vel %s Cadastrado com Sucesso!!", reg_imovel[i].nome);	
		pularLinha();
		
		reg_imovel[i].status = true;
		*contCadastro = *contCadastro + 1;

		printf("\n1-Sim ; 2-N�o.");
		printf("\nDeseja cadastrar um novo Im�vel ? ");
		scanf("%d", &opcao);
		
	}while(opcao != 2);
}
