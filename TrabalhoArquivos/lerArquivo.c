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

void ler_arquivo(struct imoveis reg_imovel[TF], int *contCadastro) {
    int i = 0;
    FILE *arq;
    limpaTela();
    printf("\t<<Lendo Arquivo de Registros...>>");
    arq = fopen("imoveis.bin", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!!!");
    } else {
        while(fread(&reg_imovel[i], sizeof(struct imoveis), 1, arq) > 0) {
            i++;
        }
        *contCadastro = i; 
        fclose(arq);
        printf("\n\nRegistros Lidos com Sucesso!!!");
        pularLinha();
        pularLinha();
        system("pause");
    }
}
