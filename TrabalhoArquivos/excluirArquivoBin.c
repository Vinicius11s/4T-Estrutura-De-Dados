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
    printf("\n\nEste processo é Irreversível.");
    printf("\n\n1-Sim ; 2-Não");
    printf("\nVocê Deseja excluir Todos Registros do Arquivo ?: ");
    scanf("%d", &opcao);
    
    if(opcao == 1){
		arq = fopen("imoveis.bin", "wb");
	    if (arq == NULL) {
	        printf("Erro ao abrir o arquivo para exclusão!!!\n");
	    }
		else{
			limpaTela();
	    	fclose(arq);
	        printf("\nRegistros Excluídos com Sucesso!!!\n");
	    }
		printf("\nO programa será encerrado para efetivar a exclusão dos Registros.");
		pularLinha();
		pularLinha();
		system("pause");
		exit(0); 	   	
	}
	else{
		if(opcao == 2){
			printf("\nA Exclusão foi cancelada.");
			pularLinha();
			pularLinha();
			system("pause");
		}
		else{
		    printf("\nOpção inválida! Por favor, escolha 1 ou 2.\n");
		    pularLinha();
		    pularLinha();
        	system("pause");		
		}
	}	
}




