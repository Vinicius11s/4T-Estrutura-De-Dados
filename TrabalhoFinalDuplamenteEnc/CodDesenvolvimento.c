#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

struct Ap {
    int id;
    char nome[100];
    char cidade[150];
    float m2;
    float valor;
    struct Ap* proximo; 
    struct Ap* anterior; 
};

typedef struct Ap Lista;

void limpaTela() {
    system("cls");
}

void pularLinha() {
    printf("\n");
}

int listaVazia(Lista *lista) {
    if (lista == NULL){
    	return 0;
	}
    return 1;
}

void imprimirLista(Lista* lista) {
    if (listaVazia(lista)) {
        printf("\nLista vazia");
    } else {
        Lista* pont;
        printf("\nLista Atual:\n");
        
        // Imprimindo da cabeça até a cauda
        for (pont = lista; pont != NULL; pont = pont->proximo) {
            printf("ID: %d, Nome: %s <-> ", pont->id, pont->nome);
        }

        printf("NULL\n");
    }
}

Lista* carregarCampos(int *contador) {
    Lista* novoNo = (Lista*)malloc(sizeof(Lista)); 
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }
    
     if (*contador == 0) {
        novoNo->id = 0; // Primeiro registro recebe id = 0
    } else {
        novoNo->id = *contador; // Incrementa o contador para o próximo ID
    }
    (*contador)++;
	
	
    printf("\n\nInforme o nome de identificação para o Apartamento: ");
    fflush(stdin);
    gets(novoNo->nome);
    
    printf("\nInforme a cidade do Apartamento: ");
    fflush(stdin);
    gets(novoNo->cidade);
    
    printf("\nInforme o tamanho do Apartamento em metros quadrados: ");
    scanf("%f", &novoNo->m2);
    
    printf("\nInforme o valor: ");
    scanf("%f", &novoNo->valor);
    
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    return novoNo;
}

Lista* inserirNoOrdenado(Lista* lista, Lista* novoNo) {
    // Se a lista estiver vazia, insira no início
    if (lista == NULL) {
        return novoNo; // Novo nó será o primeiro e único nó
    }

    // Se o novo nó deve ser o primeiro nó (maior valor)
    if (novoNo->valor > lista->valor) {
        novoNo->proximo = lista;
        lista->anterior = novoNo;
        return novoNo; // O novo nó é o novo head
    }

    // Percorre a lista para encontrar a posição correta de inserção
    Lista* atual = lista;
    while (atual->proximo != NULL && atual->proximo->valor >= novoNo->valor) {
        atual = atual->proximo; // Continua até encontrar a posição correta
    }

    // Insere o novo nó na posição encontrada
    novoNo->proximo = atual->proximo; // Aponta para o próximo nó
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novoNo; // Ajusta o anterior do próximo nó
    }
    atual->proximo = novoNo; // O nó atual agora aponta para o novo nó
    novoNo->anterior = atual; // O novo nó aponta para o nó atual

    return lista; // Retorna a lista (não mudou o head)
}

void menu() {
    limpaTela();    
    Lista* lista1 = NULL; // Declaração da lista
    int opcao = -1, contador = 0;
    
    setlocale(LC_ALL, "Portuguese");
    
    char username[100];
    DWORD username_len = sizeof(username);
    GetUserName(username, &username_len);
    
    while(opcao != 0) {
        limpaTela();
        printf("\t<<<Este Algoritmo torna possível realizar a manipulação de dados em uma Lista Duplamente Encadeada>>>");
        printf("\n\n\tOlá %s O que Deseja Fazer...?", username);
        
        printf("\n\nMenu de Opções:");
        printf("\n1- Adicionar um ou mais cadastros de maneira ordenada..");
        printf("\n0- Sair");

        printf("\n\nEscolha um número e pressione ENTER: ");
        scanf("%d", &opcao);
    
        switch(opcao) {
            case 1: {
                limpaTela();
                printf("\t<<<Adicionar um ou mais cadastros de maneira ordenada.>>>");

                int continuar = 1;
                while (continuar) {
                    Lista* novoNo = carregarCampos(&contador);
                    if (novoNo != NULL) {
                        lista1 = inserirNoOrdenado(lista1, novoNo); // Insere de forma ordenada
                    }
                    printf("Deseja adicionar outro apartamento? (1 - Sim, 0 - Não): ");
                    scanf("%d", &continuar);
                }
                imprimirLista(lista1); // Exibe a lista após a inserção
                system("pause");
                break;
            }
            case 0:
                break;
            default:
                pularLinha();
                printf("Opção Inválida.");
                pularLinha();
                system("pause");
        }        
    }
}

int main(int argc, char *argv[]) {
    menu();
    return 0;
}


