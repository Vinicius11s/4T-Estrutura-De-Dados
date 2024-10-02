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


void gravar_arquivo(struct imoveis reg_imovel[TF]){
	FILE *arq;
	int i;
	system("cls");
	printf("<<Gravando Registros no Arquivo>>\n\n");
	arq = fopen("imoveis.bin", "wb");
	if(arq == NULL){
		printf("Erro ao abrir o arquivo!!!");
	}
	else{
		for(i=0; i<TF; i++){
			fwrite(&reg_imovel[i], sizeof(struct imoveis), 1, arq);
		}
		fclose(arq);
		printf("Registros Gravados com Sucesso!!!");
	}
	system("pause");
}
