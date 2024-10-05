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

void listar_ativar(int contCadastro, struct imoveis reg_imovel[TF]) {
    int i, opcao = -1, imovel_escolhido;
    int outroRegistro = -1;
    int cont = 0;

    for (i = 0; i < contCadastro; i++) {
        if (reg_imovel[i].status == false) {
            cont++;
        }
    }
	if (cont == 0) {
        limpaTela();
        printf("\t<<<Ativar Registro de um Im�vel>>>");
        printf("\n\nN�o h� im�veis inativos para ativar.");
        pularLinha();
        pularLinha();
        system("pause");
        return;
    }

    while (opcao != 0 && outroRegistro != 0 && cont > 0) {
        limpaTela();
        printf("\t<<<Ativar Registro de um Im�vel>>>");
        printf("\n\n\tIm�veis Inativos:");
        
        for (i = 0; i < contCadastro; i++) {
            if (reg_imovel[i].status == false) {
                printf("\nImovel %d: %s", i + 1, reg_imovel[i].nome);
            }
        }
        printf("\n0- Sair");
        
        
        printf("\n\nInforme o n�mero do Im�vel que deseja ativar: ");
        scanf("%d", &opcao);            
        imovel_escolhido = opcao - 1;

        if (opcao > contCadastro) {
            printf("\nOp��o Inexistente...");
            Sleep(2000);
        } else {
            if (opcao != 0) {
                if (reg_imovel[imovel_escolhido].status == true) {
                    limpaTela();
                    printf("\t<<<Ativar Registro de um Im�vel>>>");
                    printf("\n\nO Cadastro j� est� Ativo.");
                    Sleep(2000);
                } else {
                    reg_imovel[imovel_escolhido].status = true;
                    printf("\nCadastro %d Ativo com sucesso!", imovel_escolhido + 1);
                    pularLinha();
                    pularLinha();            
                    system("pause");
                    cont--;

                    if (cont == 0) {
                        limpaTela();
		                printf("\t<<<Ativar Registro de um Im�vel>>>");
                        printf("\n\nTodos os Cadastros foram ativados.");
                        pularLinha();
                        pularLinha();
                        system("pause");
                        break;
                    }
                }

                if (cont > 0) {
                    printf("\n\n0-N�o ; 1-Sim");
                    printf("\nDeseja ativar outro Registro?");
                    scanf("%d", &outroRegistro);
                }
            }
        }
    }
}


