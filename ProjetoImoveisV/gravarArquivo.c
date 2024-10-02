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


void gravar_arquivo(struct imoveis reg_imovel[], int contCadastro) {
    FILE *arq;
    system("cls");
    printf("<<Gravando Registros no Arquivo>>\n\n");
    arq = fopen("imoveis.bin", "wb");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!!!");
    } else {
        fwrite(reg_imovel, sizeof(struct imoveis), contCadastro, arq);
        fclose(arq);
        printf("Registros Gravados com Sucesso!!!");
    }
    system("pause");
}
