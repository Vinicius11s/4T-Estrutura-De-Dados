#include <conio.h>
#include<stdio.h>
#include<locale.h>
#define TF 3
//4.	Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.

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
	
	printf("<<<Programa que permite somar elementos de um Vetor de 3 posições>>>");
	
	for(i=0; i<TF; i++){
		printf("\nInforme Vetor da posição %d: ", i);
		scanf("%f", &vet[i]);	
	}
	
	somatoria = somatoria_vet(vet);
	
	printf("\nA Somatória dos números informados é igual a : %0.2f", somatoria);		
}
