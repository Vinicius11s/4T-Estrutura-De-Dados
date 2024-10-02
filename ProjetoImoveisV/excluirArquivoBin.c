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

void excluirArquivo() {
    FILE *arq;
    
    system("cls");
    printf("<<Excluindo Registros do Arquivo>>\n\n");
    arq = fopen("imoveis.bin", "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para exclusão!!!\n");
    } else {
        fclose(arq);
        printf("Registros Excluídos com Sucesso!!!\n");
    }
    system("pause");
}




