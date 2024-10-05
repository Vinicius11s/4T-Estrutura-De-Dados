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

void bubbleSort(struct imoveis reg_imovel[TF], int contCadastro, int campoEscolhido) {
    int houveTroca, i;
    struct imoveis elemento;

    do {
        houveTroca = 0;
        for (i = 0; i < contCadastro - 1; i++) {
            if (campoEscolhido == 1) {
                if (reg_imovel[i].area_m2 > reg_imovel[i + 1].area_m2) {
                    elemento = reg_imovel[i];
                    reg_imovel[i] = reg_imovel[i + 1];
                    reg_imovel[i + 1] = elemento;
                    houveTroca = 1;
                }
            } else if (campoEscolhido == 2) {
                if (reg_imovel[i].vagas_garagem > reg_imovel[i + 1].vagas_garagem) {
                    elemento = reg_imovel[i];
                    reg_imovel[i] = reg_imovel[i + 1];
                    reg_imovel[i + 1] = elemento;
                    houveTroca = 1;
                }
                else if (campoEscolhido == 3){
	                if (reg_imovel[i].qtde_banheiros > reg_imovel[i + 1].qtde_banheiros) {
	                    elemento = reg_imovel[i];
	                    reg_imovel[i] = reg_imovel[i + 1];
	                    reg_imovel[i + 1] = elemento;
	                    houveTroca = 1;
	                }	
	                else if (campoEscolhido == 4){
	                	if (reg_imovel[i].valor > reg_imovel[i + 1].valor) {
	                    	elemento = reg_imovel[i];
	                   	 	reg_imovel[i] = reg_imovel[i + 1];
	                    	reg_imovel[i + 1] = elemento;
	                    	houveTroca = 1;
	                	}
	                }
				}
            }
        }
    } while (houveTroca == 1);
}


void exibir_campos(int contCadastro, struct imoveis reg_imovel[TF]){
	int i;
	int campoEscolhido = -1;

	while(campoEscolhido != 0){
		limpaTela();
		printf("\t<<<Ordenar dados de um vetor>>>");

		printf("\n\n\nOrdenar Imóveis por: ");		
		printf("\n1- Metros Quadrados.");
		printf("\n2- Quantidade de vagas de garagem.");
		printf("\n3- Quantidade de banheiros.");
		printf("\n4- Valor do Imóvel.");	
		printf("\n0- Sair");
		
		printf("\n\nEscolha um número e pressione ENTER: ");
		scanf("%d", &campoEscolhido);
		
		 if(campoEscolhido > 0 || campoEscolhido < 5) {
			bubbleSort(reg_imovel, contCadastro, campoEscolhido);
			
			limpaTela();
            printf("\nImóveis ordenados com sucesso!\n");
            
            switch(campoEscolhido){
            	case 1:
            		for (i = 0; i < contCadastro; i++) {
            			if(reg_imovel[i].status ==  true){
	                		printf("\n\nImóvel %d: %s", i + 1, reg_imovel[i].nome);
	                		printf("\nÁrea do Imóvel: %0.2f m²", reg_imovel[i].area_m2);
 						}
					}
            		pularLinha();
            		pularLinha();
            		system("pause");	
            		break;
            	case 2:
            		for (i = 0; i < contCadastro; i++) {
            			if(reg_imovel[i].status ==  true){
                			printf("\n\nImóvel %d: %s", i + 1, reg_imovel[i].nome);
                			printf("\nQuantidade de vagas de garagem: %d", reg_imovel[i].vagas_garagem);
            			}
					}
            		pularLinha();
            		pularLinha();
            		system("pause");            		
            		break;           	
            	case 3:
             		for (i = 0; i < contCadastro; i++) {
             		    if(reg_imovel[i].status ==  true){
                			printf("\n\nImóvel %d: %s", i + 1, reg_imovel[i].nome);
                			printf("\nQuantidade de banheiros: %d", reg_imovel[i].qtde_banheiros);
                		}
            		}
            		pularLinha();
            		pularLinha();
            		system("pause");           		
            		break;            	
            	case 4:
            		for (i = 0; i < contCadastro; i++) {
            			if(reg_imovel[i].status ==  true){
                			printf("\n\nImóvel %d: %s", i + 1, reg_imovel[i].nome);
                			printf("\nValor do Imóvel: %0.2f", reg_imovel[i].valor);
                		}
            		}
            		pularLinha();
            		pularLinha();
            		system("pause");            		
            		break;            	         	
			}
        }
		else{
		 	if (campoEscolhido != 0) {
            printf("\nOpção inválida.\n");			
			}
		}
	}
}	                
