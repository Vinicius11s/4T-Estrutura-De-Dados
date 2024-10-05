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
	char endereco[200];
	float area_m2;
	int qtde_quartos;
	int vagas_garagem;
	int qtde_banheiros;
	float valor;
	char dataCadastro[11];
	bool status;
};


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
		
		printf("\nInforme o endere�o do Im�vel: ");
		fflush(stdin);
		gets(reg_imovel[i].endereco);
		
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
}

void exibir_imovel_alterar(int imovel_escohido, struct imoveis reg_imovel[TF]){
	int i = imovel_escohido, campo = 0;
	limpaTela();
	
	printf("\t<<<Alterar um Registro de Im�vel existente>>>");		
	printf("\n\n[Dados Atuais] Im�vel %d: ", imovel_escohido + 1);
	
	if(reg_imovel[imovel_escohido].tipo == 1){
		printf("\n\n[1]- Im�vel do Tipo: Casa");
	}
	else if(reg_imovel[imovel_escohido].tipo == 2){
			printf("\n\n[1]- Im�vel do Tipo: Apartamento");
	}
	else if(reg_imovel[imovel_escohido].tipo == 3){
			printf("\n\n[1]- Im�vel do Tipo: Terreno");
	}				
					
	printf("\n[2]- Nome: %s", reg_imovel[imovel_escohido].nome);
	printf("\n[3]- Endere�o: %s", reg_imovel[imovel_escohido].endereco);
	printf("\n[4]- �rea do Imovel %0.2f m�", reg_imovel[imovel_escohido].area_m2);
	printf("\n[5]- Quantidade de Quartos: %d", reg_imovel[imovel_escohido].qtde_quartos);
	printf("\n[6]- Vagas de Garagem: %d", reg_imovel[imovel_escohido].vagas_garagem);	
	printf("\n[7]- Quantidade de Banheiros: %d", reg_imovel[imovel_escohido].qtde_banheiros);
	printf("\n[8]- Valor: %0.2f", reg_imovel[imovel_escohido].valor);
	printf("\n[9]- Data de Cadastro: %s", reg_imovel[imovel_escohido].dataCadastro);
	
	printf("\n\n[10]- Alterar Todos campos.");
	printf("\n\nEscolha qual campo voc� deseja alterar...");
	printf("\nDigite um n�mero e pressione ENTER: ");
	scanf("%d", &campo);
	
	if(campo > 0 && campo <11){
		printf("\n\n[Altera��o] [Im�vel: %s] [Campo %d]",reg_imovel[imovel_escohido].nome, campo);
		
		switch(campo){
			case 1:
				reg_imovel[i].tipo = 0;
				while(reg_imovel[i].tipo != 1 && reg_imovel[i].tipo != 2 && reg_imovel[i].tipo != 3 ){	
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
			break;
		case 2:
			printf("\nInforme o Nome do Im�vel: ");
			fflush(stdin);
			gets(reg_imovel[i].nome);
			break;
		case 3:	
			printf("\nInforme o endere�o do Im�vel: ");
			fflush(stdin);
			gets(reg_imovel[i].endereco);			
			break;			
		case 4:
			printf("\nInforme a �rea do Im�vel em metros quadrados: ");
			scanf("%f", &reg_imovel[i].area_m2);			
			break;			
		case 5:	
			printf("\nInforme a quantidade de quartos: ");
			scanf("%d", &reg_imovel[i].qtde_quartos);		
			break;			
		case 6:			
			printf("\nInforme a quantidade de vagas de garagem do Im�vel: ");
			scanf("%d", &reg_imovel[i].vagas_garagem);	
			break;
		case 7:		
			printf("\nInforme a quantidade de banheiros do Im�vel: ");
			scanf("%d", &reg_imovel[i].qtde_banheiros);			
			break;		
		case 8:			
			printf("\nInforme o Valor do Im�vel: ");
			scanf("%f", &reg_imovel[i].valor);		
			break;	
		case 9:
			printf("\nInforme a data de Cadastro.");
			printf("\ndd/mm/yyyy: ");
			fflush(stdin);
			gets(reg_imovel[i].dataCadastro);		
			break;
		case 10:
			alterar_registro(imovel_escohido, reg_imovel);
			break;	
		}	
	}
	else{
		printf("O campo escolhido n�o existe.");
		Sleep(2000);		
	}
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
	        if(reg_imovel[i].status ==  true){
				printf("\nImovel %d: %s", i+1, reg_imovel[i].nome);
			}
		}
		printf("\n0-Sair");
	
		printf("\n");
		printf("\nInforme o n�mero do Im�vel que deseja alterar: ");
		scanf("%d", &opcao);
				
		if(opcao >0 && opcao <= contCadastro){
			imovel_escohido = opcao - 1;
		    if(reg_imovel[imovel_escohido].status ==  true){
				exibir_imovel_alterar(imovel_escohido, reg_imovel);
			}
			else{
				printf("\nO Im�vel escolhido se encontra inativo.");
				Sleep(2000);
			}
		}	
		else{
			if(opcao != 0){
				printf("\nO Im�vel escolhido n�o existe.");
				Sleep(2000);			
			}
		}
	}
}
