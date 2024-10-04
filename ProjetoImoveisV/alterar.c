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
	printf("\t<<<Alterar um Registro de Im�vel existente>>>");		
	printf("\n\n[Dados Atuais] Im�vel %d: ", imovel_escohido + 1);
	
	if(reg_imovel[imovel_escohido].tipo == 1){
		printf("\n\nIm�vel do Tipo: Casa");
	}
	else if(reg_imovel[imovel_escohido].tipo == 2){
			printf("\n\nIm�vel do Tipo: Apartamento");
	}
	else if(reg_imovel[imovel_escohido].tipo == 3){
			printf("\n\nIm�vel do Tipo: Terreno");
	}				
					
	printf("\nNome: %s", reg_imovel[imovel_escohido].nome);
	printf("\n�rea do Imovel %0.2f m�", reg_imovel[imovel_escohido].area_m2);
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

			printf("\n\n[Altera��o] Im�vel %d: ", i+1);

			printf("\n\n1-Casa ; 2-Apartamento ; 3-Terreno.");
			printf("\nInforme o Tipo do Im�vel: ");
			scanf("%d", &reg_imovel[i].tipo);
			
			if(reg_imovel[i].tipo != 1 && reg_imovel[i].tipo != 2 && reg_imovel[i].tipo != 3){
				printf("\n\tInforme um valor v�ldo para Tipo do Im�vel !!");
				printf("\n");
				system("pause");	
				limpaTela();
			}
		}	
		printf("\nInforme o Nome do Im�vel: ");
		fflush(stdin);
		gets(reg_imovel[i].nome);

		printf("\nInforme a �rea do Im�vel em metros quadrados: ");
		scanf("%f", &reg_imovel[i].area_m2);			

		printf("\nInforme a quantidade de quartos: ");
		scanf("%d", &reg_imovel[i].qtde_quartos);				
		
		printf("\nInforme a quantidade de vagas de garagem do Im�vel: ");
		scanf("%d", &reg_imovel[i].vagas_garagem);
		
		printf("\nInforme a quantidade de banheiros do Im�vel: ");
		scanf("%d", &reg_imovel[i].qtde_banheiros);
		
		printf("\nInforme o Valor do Im�vel: ");
		scanf("%f", &reg_imovel[i].valor);
		
		printf("\nInforme a data de Cadastro.");
		printf("\ndd/mm/yyyy: ");
		fflush(stdin);
		gets(reg_imovel[i].dataCadastro);
			
		printf("\n\n\tAltera��o conclu�da com Sucesso!!");	
		pularLinha();
		system("pause");
		
}

void listar_alterar(int contCadastro, struct imoveis reg_imovel[TF]){
	int i=0, opcao = -1, imovel_escohido;

	while(opcao != 0){
		limpaTela();
		printf("\t<<<Alterar um Registro de Im�vel existente>>>");
		
		printf("\n\n\tIm�veis Cadastrados:");
		
		for(i=0; i<contCadastro; i++){
			printf("\nImovel %d: %s", i+1, reg_imovel[i].nome);
		}
		printf("\n0-Sair");
	
		printf("\n");
		printf("\nInforme o n�mero do Im�vel que deseja alterar: ");
		scanf("%d", &opcao);
				
		if(opcao >0 && opcao <= contCadastro){
			imovel_escohido = opcao - 1;
			exibir_imovel_alterar(imovel_escohido, reg_imovel);
			alterar_registro(imovel_escohido, reg_imovel);
		}	
		else{
			if(opcao != 0){
				printf("O Im�vel escolhido n�o existe.");
				system("pause");			
			}
		}
	}
}
