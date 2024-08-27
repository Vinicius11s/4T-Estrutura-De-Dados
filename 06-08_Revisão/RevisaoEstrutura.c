#include <stdio.h>
#include <conio.h>


// Exe 1


/*void par_impar(){
	int x;	
	printf("Informe um numero: ");
	scanf("%d", &x);
	
	if(x % 2 == 0){
		printf("Numero par! ");	
	}
	else{
		printf("Numero impar! ");
	}
}
void main(){
	par_impar();	
}


//Exe 2

//2.	Para atingir o índice olímpico, são realizados vários torneios de corridas de 100 metros. Faça um algoritmo que leia o nome
//e o tempo de um atleta e apresente sua pontuação, conforme listado abaixo:
//T < 10 seg: 100 pontos
//T >= 10 e T <=13  seg: 70 pontos
//T > 13 Seg: 40 pontos

/*
void nome_tempo(){
	char nome[50];
	int tempo;
	float pontos;
	
	printf("Informe o seu Nome: ");
	scanf("%s", nome);
	printf("Informe o seu Tempo: ");
	scanf("%d", &tempo);
	
	if(tempo < 10){
		printf("Pontuacao: 100 pontos");
	}
	else{
		if(tempo >= 10 && tempo<= 13){
			printf("Pontuacao: 70 pontos");

		}
		else{
			if(tempo > 13){
				printf("Pontuacao: 40 pontos");
			}
		}
	}
}

void main(){
	nome_tempo();
}
*/

// Exe 4

/*4.	Escreva um programa em C que leia 10 valores inteiros, encontre o maior e o menor deles e mostre o resultado. .*/
	

/*void maior_menor(){
	int i, maior, menor, num;
	printf("<<<Inicio do Exercicio Maior/Menor>>>\n ");

		
	for(i=1; i<=3; i++){
		printf("Informe um Valor: ");
		scanf("%d", &num);
		
		if(i == 1){
			maior = num;
			menor = num;
		}
		else{
			if(num > maior){
			maior = num;
			}
			
			if(num < menor){
			menor = num;
			}
		}
	}
	printf("Maior numero Digitado %d\n", maior);
	printf("Menor numero Digitado %d\n", menor);
}

void main(){
	maior_menor();
}
*/

//Exe 5
#define TF 5

 
void carregar_vetor(int vet[TF]){
	int i;	
	for(i=0; i<TF; i++){
		printf("Informe Vetor[%d]: ", i);
		scanf("%d", &vet[i]);
	}
}


void exibir_vetor(int vet[TF]){
	int i;
	printf("\n");
	
	for(i=0; i<TF; i++){
		printf("Vetor [%d] = %d \n", i, vet[i]);
	}	
}


void main(){
	int vet[TF];	
	carregar_vetor(vet);
	exibir_vetor(vet);
}










