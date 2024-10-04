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


void gravar_arquivo(struct imoveis reg_imovel[TF], int contCadastro) {
    FILE *arq;
    limpaTela();
    printf("\t<<Gravando Registros no Arquivo...>>");
    arq = fopen("imoveis.bin", "wb");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!!!");
    } else {
        fwrite(reg_imovel, sizeof(struct imoveis), contCadastro, arq);
        fclose(arq);
        printf("\n\nRegistros Gravados com Sucesso!!!");
    }
    pularLinha();
    pularLinha();
    system("pause");
}

