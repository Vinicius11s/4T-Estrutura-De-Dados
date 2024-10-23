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
        
        // Imprimindo da cabe�a at� a cauda
        for (pont = lista; pont != NULL; pont = pont->proximo) {
            printf("ID: %d, Nome: %s <-> ", pont->id, pont->nome);
        }

        printf("NULL\n");
    }
}

Lista* carregarCampos(int *contador) {
    Lista* novoNo = (Lista*)malloc(sizeof(Lista)); 
    if (novoNo == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return NULL;
    }
    
     if (*contador == 0) {
        novoNo->id = 0; // Primeiro registro recebe id = 0
    } else {
        novoNo->id = *contador; // Incrementa o contador para o pr�ximo ID
    }
    (*contador)++;
	
	
    printf("\n\nInforme o nome de identifica��o para o Apartamento: ");
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
    // Se a lista estiver vazia, insira no in�cio
    if (lista == NULL) {
        return novoNo; // Novo n� ser� o primeiro e �nico n�
    }

    // Se o novo n� deve ser o primeiro n� (maior valor)
    if (novoNo->valor > lista->valor) {
        novoNo->proximo = lista;
        lista->anterior = novoNo;
        return novoNo; // O novo n� � o novo head
    }

    // Percorre a lista para encontrar a posi��o correta de inser��o
    Lista* atual = lista;
    while (atual->proximo != NULL && atual->proximo->valor >= novoNo->valor) {
        atual = atual->proximo; // Continua at� encontrar a posi��o correta
    }

    // Insere o novo n� na posi��o encontrada
    novoNo->proximo = atual->proximo; // Aponta para o pr�ximo n�
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novoNo; // Ajusta o anterior do pr�ximo n�
    }
    atual->proximo = novoNo; // O n� atual agora aponta para o novo n�
    novoNo->anterior = atual; // O novo n� aponta para o n� atual

    return lista; // Retorna a lista (n�o mudou o head)
}

void menu() {
    limpaTela();    
    Lista* lista1 = NULL; // Declara��o da lista
    int opcao = -1, contador = 0;
    
    setlocale(LC_ALL, "Portuguese");
    
    char username[100];
    DWORD username_len = sizeof(username);
    GetUserName(username, &username_len);
    
    while(opcao != 0) {
        limpaTela();
        printf("\t<<<Este Algoritmo torna poss�vel realizar a manipula��o de dados em uma Lista Duplamente Encadeada>>>");
        printf("\n\n\tOl� %s O que Deseja Fazer...?", username);
        
        printf("\n\nMenu de Op��es:");
        printf("\n1- Adicionar um ou mais cadastros de maneira ordenada..");
        printf("\n0- Sair");

        printf("\n\nEscolha um n�mero e pressione ENTER: ");
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
                    printf("Deseja adicionar outro apartamento? (1 - Sim, 0 - N�o): ");
                    scanf("%d", &continuar);
                }
                imprimirLista(lista1); // Exibe a lista ap�s a inser��o
                system("pause");
                break;
            }
            case 0:
                break;
            default:
                pularLinha();
                printf("Op��o Inv�lida.");
                pularLinha();
                system("pause");
        }        
    }
}

int main(int argc, char *argv[]) {
    menu();
    return 0;
}


