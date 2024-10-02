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


void ler_arquivo(struct imoveis reg_imovel[TF]){
	int i;
	FILE *arq;
	printf("<<Lendo Arquivo de Registros>>\n\n");
	arq = fopen("imoveis.bin", "rb");
	if (arq ==NULL){
		printf("Erro ao abrir o arquivo!!!");
	}
	else{
		i = 0;
		while(fread(&reg_imovel[i], sizeof(struct imoveis), 1, arq) > 0){
			i++;
		}
		fclose(arq);
		printf("Registros Lidos com Sucesso!!!");
		system("pause");
	}
}
