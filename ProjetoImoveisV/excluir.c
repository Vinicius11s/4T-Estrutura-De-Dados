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


void listar_excluir(int contCadastro, struct imoveis reg_imovel[TF]){
	int cont = 0, i, opcao = -1, imovel_escohido;
	int outroRegistro = - 1;
	
	while(opcao != 0 && outroRegistro != 0){
		limpaTela();
		printf("\t<<<Excluir Registro de um Imóvel>>>");
		printf("\n\n\tImóveis Ativos:");
		
			for(i=0; i<contCadastro; i++){
				if(reg_imovel[i].status == true){
					printf("\nImovel %d: %s", i+1, reg_imovel[i].nome);
					cont++;
				}
			}
			printf("\n0- Sair");
			printf("\n");
			printf("\nInforme o número do Imóvel que deseja excluir: ");
			scanf("%d", &opcao);			
			imovel_escohido = opcao - 1;
						
		if(opcao > contCadastro){
			printf("\nOpção Inexistente...");
			Sleep(2000);
		}
		else{
			if(opcao != 0){
				if(reg_imovel[imovel_escohido].status == false){
					printf("\t<<<Excluir Registro de um Imóvel>>>");
					printf("\n\nO Cadastro já esta Inativo.");
					Sleep(2000);
				}
				else{
					reg_imovel[imovel_escohido].status = false;
					printf("\nCadastro %d Excluído com sucesso!", imovel_escohido+1);
					pularLinha();
					pularLinha();			
					system("pause");
					cont--;				
				
					printf("\n\n0-Não ; 1-Sim");
					printf("\nDeseja excluir outro Registro ?");
					scanf("%d",&outroRegistro);		
				}
				if(outroRegistro == 1 && cont == 0){
					limpaTela();
					printf("Todos os Cadastros foram excluídos");
					pularLinha();
					pularLinha();
					system("pause");
					break;
				}
			}
		}
	}
}


