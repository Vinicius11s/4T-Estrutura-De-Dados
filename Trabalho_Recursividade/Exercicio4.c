#include <conio.h>
#include<stdio.h>
#include<locale.h>
#define TF 3
//4.	Fa�a uma fun��o recursiva que permita somar os elementos de um vetor de inteiros.

float somatoria_vet(float vet[TF]){
	int i=0;
	float somatoria=0;
	
	if(vet[0] == 1){
		return (1);
	}
	else{
		for(i=0; i<TF; i++)
			somatoria += vet[i];
	}

	return (somatoria);	
}
		


void main(){
	float somatoria, vet[TF];
	int i=0;
	
	setlocale(LC_ALL,"portuguese");
	
	printf("<<<Programa que permite somar elementos de um Vetor de 3 posi��es>>>");
	
	for(i=0; i<TF; i++){
		printf("\nInforme Vetor da posi��o %d: ", i);
		scanf("%f", &vet[i]);	
	}
	
	somatoria = somatoria_vet(vet);
	
	printf("\nA Somat�ria dos n�meros informados � igual a : %0.2f", somatoria);		
}
