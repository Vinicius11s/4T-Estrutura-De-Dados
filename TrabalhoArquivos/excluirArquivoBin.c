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

void excluirArquivo() {
	int opcao = 0;
    FILE *arq;
    
    
    system("cls");
    printf("<<Excluindo Registros do Arquivo>>");
    printf("\n\nEste processo � Irrevers�vel.");
    printf("\n\n1-Sim ; 2-N�o");
    printf("\nVoc� Deseja excluir Todos Registros do Arquivo ?: ");
    scanf("%d", &opcao);
    
    if(opcao == 1){
		arq = fopen("imoveis.bin", "wb");
	    if (arq == NULL) {
	        printf("Erro ao abrir o arquivo para exclus�o!!!\n");
	    }
		else{
			limpaTela();
	    	fclose(arq);
	        printf("\nRegistros Exclu�dos com Sucesso!!!\n");
	    }
		printf("\nO programa ser� encerrado para efetivar a exclus�o dos Registros.");
		pularLinha();
		pularLinha();
		system("pause");
		exit(0); 	   	
	}
	else{
		if(opcao == 2){
			printf("\nA Exclus�o foi cancelada.");
			pularLinha();
			pularLinha();
			system("pause");
		}
		else{
		    printf("\nOp��o inv�lida! Por favor, escolha 1 ou 2.\n");
		    pularLinha();
		    pularLinha();
        	system("pause");		
		}
	}	
}




