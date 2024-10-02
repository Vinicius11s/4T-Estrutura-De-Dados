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

void listar_ativar(int contCadastro, struct imoveis reg_imovel[TF]){

	int i, opcao = -1, imovel_escohido;

	while(opcao != 2){
		system("cls");
		printf("\t<<<Ativar Registro de um Imóvel Excluído>>>");
		printf("\n\n\tImóveis Inativos:");
		
			for(i=0; i<contCadastro+1; i++){
				if(reg_imovel[i].status == false){
					printf("\nImovel %d: %s", i+1, reg_imovel[i].nome);
				}
			}
		
			printf("\n");
			printf("\nInforme o número do Imóvel que deseja ativar: ");
			scanf("%d", &imovel_escohido);			
		

				
		if(imovel_escohido >0 && imovel_escohido <= contCadastro){
			imovel_escohido = imovel_escohido - 1;
			
				reg_imovel[imovel_escohido].status = true;
				printf("\nCadastro %d Ativado com sucesso!", imovel_escohido+1);
				system("pause");
			
			printf("\n\n1-Sim ; 2-Não");
			printf("\nDeseja ativar outro Registro ?");
			scanf("%d",&opcao);
		}
		else{
			printf("\nOpção Inexistente...");
		}
	}
}

