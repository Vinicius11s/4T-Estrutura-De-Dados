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
	int cont = 0, i, opcao = -1, imovel_escohido;
	int outroRegistro = - 1;
	
	while(opcao != 0 && outroRegistro != 0){
		limpaTela();
		printf("\t<<<Ativar Registro de um Imóvel Inativo>>>");
		printf("\n\n\tImóveis Inativos:");
		
			for(i=0; i<contCadastro; i++){
				if(reg_imovel[i].status == false){
					printf("\nImovel %d: %s", i+1, reg_imovel[i].nome);
					cont++;
				}
			}
			printf("\n0- Sair");
			printf("\n");
			printf("\nInforme o número do Imóvel que deseja Ativar: ");
			scanf("%d", &opcao);			
			imovel_escohido = opcao - 1;
						
		if(opcao > contCadastro){
			printf("\nOpção Inexistente...");
			Sleep(2000);
		}
		else{
			if(opcao != 0){
				if(reg_imovel[imovel_escohido].status == true){
					printf("\t<<<Ativar Registro de um Imóvel Inativo>>>");
					printf("\n\nO Cadastro já esta Ativo.");
					Sleep(2000);
				}
				else{
					reg_imovel[imovel_escohido].status = true;
					printf("\nCadastro %d Ativo com sucesso!", imovel_escohido+1);
					pularLinha();
					pularLinha();			
					system("pause");
					cont--;				
				
					printf("\n\n0-Não ; 1-Sim");
					printf("\nDeseja ativar outro Registro ?");
					scanf("%d",&outroRegistro);		
				}
				if(outroRegistro == 1 && cont == 0){
					limpaTela();
					printf("Todos os Cadastros foram ativos");
					pularLinha();
					pularLinha();
					system("pause");
					break;
				}
			}
		}
	}
}


