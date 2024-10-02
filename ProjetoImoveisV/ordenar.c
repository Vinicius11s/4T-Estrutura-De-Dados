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

void bubbleSort(struct imoveis reg_imovel[TF], int contCadastro, int campoEscolhido) {
    int houveTroca, i;
    struct imoveis elemento;

    do {
        houveTroca = 0;
        for (i = 0; i < contCadastro - 1; i++) {
            if (campoEscolhido == 1) {
                if (reg_imovel[i].vagas_garagem > reg_imovel[i + 1].vagas_garagem) {
                    elemento = reg_imovel[i];
                    reg_imovel[i] = reg_imovel[i + 1];
                    reg_imovel[i + 1] = elemento;
                    houveTroca = 1;
                }
            } else if (campoEscolhido == 2) {
                if (reg_imovel[i].qtde_banheiros > reg_imovel[i + 1].qtde_banheiros) {
                    elemento = reg_imovel[i];
                    reg_imovel[i] = reg_imovel[i + 1];
                    reg_imovel[i + 1] = elemento;
                    houveTroca = 1;
                }
            }
        }
    } while (houveTroca == 1);
}


void exibir_campos(int contCadastro, struct imoveis reg_imovel[TF]){
	int i;
	int campoEscolhido = -1;

	while(campoEscolhido != 0){
		system("cls");
		printf("\t<<<Ordenar dados de um vetor>>>");
		
		printf("\n\n1- Quantidade de vagas de garagem: ");
		printf("\n2- Quantidade de banheiros: ");	
		printf("\n0- Sair");
		printf("\nOrdenar Imóveis por: ");
		scanf("%d", &campoEscolhido);
		
		 if(campoEscolhido == 1 || campoEscolhido == 2) {
			bubbleSort(reg_imovel, contCadastro, campoEscolhido);
            printf("\nImóveis ordenados com sucesso!\n");
            
            for (i = 0; i < contCadastro; i++) {
                printf("\nImóvel %d: %s", i + 1, reg_imovel[i].nome);
                printf("\nVagas de garagem: %d", reg_imovel[i].vagas_garagem);
                printf("\nQuantidade de banheiros: %d\n", reg_imovel[i].qtde_banheiros);
            }
        }
		else{
		 	if (campoEscolhido != 0) {
            printf("\nOpção inválida.\n");			
			}
		}system("pause");
	}
}	                
