#include <conio.h>
#include<stdio.h>
#include<locale.h>
#define TF 10

/*5.Crie um programa em C que receba um vetor de n�meros reais com 10 elementos.
Escreva uma fun��o recursiva que inverta ordem dos elementos presentes no vetor.*/

int inverter_valores(int vet[TF]){
	int inv[TF], i=0;
	for(i=0; i<TF; i++){
		inv[TF-1-i] = vet[i];
	}
	
	printf("\n\nValor Informado na posi��o: ");
	
	for(i=0; i<TF; i++){
	printf("\n%d: %d",i, vet[i]);
	}
	
	printf("\n\nValores Invertidos: ");
	
	for(i=0; i<TF; i++){
	printf("\n%d: %d",i, inv[i]);
	}
}


void main(){
	setlocale(LC_ALL,"portuguese");
	
	int vet[TF], i, inv[TF];
	
	printf("<<<Este Programa inverte a ordem dos numeros informado em 10 posi��es>>>\n");
	
	for(i=0; i<TF; i++){
		printf("Informe o valor da posi��o %d: ", i);
		scanf("%d", &vet[i]);
	}
	inverter_valores(vet);

}
