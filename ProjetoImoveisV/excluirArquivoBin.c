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

void excluirArquivo(reg_imovel) {

    FILE *arq;
	int i;
	
	system("cls");
	printf("<<Gravando Registros no Arquivo>>\n\n");
	arq = fopen("aluno.bin", "wb");
	fclose(arq);
	printf("Registros Gravados com Sucesso!!!");
	system("pause");

    
    
    
}




