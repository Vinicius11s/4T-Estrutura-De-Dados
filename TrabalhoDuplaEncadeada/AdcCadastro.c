#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

struct no{
	int id;
	char nome[50];
	char cidadeTime[50];
	int anoCriacao;
	int qtdeLibertadores;
	int qtdeCopaDoBrasil;
	
	struct no *prox;
	struct no *ante;

};

typedef struct no Lista;

void exibirCadastros(Lista *lista) {
    if (lista == NULL) {
        printf("A lista est� vazia.\n");
        return;
    }

    Lista *aux = lista;  // Ponteiro auxiliar para percorrer a lista

    printf("\n\nExibindo a lista de clubes ordenada pelo ano de cria��o:\n\n");

    while (aux != NULL) {
        printf("Id: %d\n", aux->id);
        printf("Nome do Clube: %s\n", aux->nome);
        printf("Cidade do Clube: %s\n", aux->cidadeTime);
        printf("Ano de Cria��o: %d\n", aux->anoCriacao);
        printf("Quantidade de Libertadores: %d\n", aux->qtdeLibertadores);
        printf("Quantidade de Copas do Brasil: %d\n", aux->qtdeCopaDoBrasil);
        printf("----------------------------------------\n");

        aux = aux->prox;  // Avan�a para o pr�ximo n�
    }
}

int gerarNovoId(Lista *lista) {
    int id = 1;  // Inicia o ID a partir de 1
    Lista *aux = lista;

    // Percorre a lista para encontrar o maior ID
    while (aux != NULL) {
        if (aux->id >= id) {
            id = aux->id + 1;  // Incrementa o ID se for igual ou maior que o atual
        }
        aux = aux->prox;
    }

    return id;  // Retorna o pr�ximo ID dispon�vel
}

Lista* inserirOrdenadoPorAno(Lista *lista, Lista *novo) {
    if (lista == NULL) {
        // Lista vazia, insere como o primeiro n�
        novo->prox = NULL;
        novo->ante = NULL;
        return novo;
    }
    
    Lista *atual = lista;
    Lista *anterior = NULL;
    
    // Percorre a lista at� encontrar a posi��o correta
    while (atual != NULL && atual->anoCriacao < novo->anoCriacao) {
        anterior = atual;
        atual = atual->prox;
    }
    
    if (anterior == NULL) {
        // Inserir no in�cio da lista
        novo->prox = lista;
        lista->ante = novo;
        return novo;
    } else {
        // Inserir no meio ou final da lista
        novo->prox = atual;
        novo->ante = anterior;
        anterior->prox = novo;
        
        if (atual != NULL) {
            atual->ante = novo;
        }
        return lista;
    }
}

Lista* carregaNovoCadastro(Lista *lista){
	
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return NULL;
    }
    
    novo->id = gerarNovoId(lista); 
    
    printf("\n\nInforme o nome do time: ");
    fflush(stdin);
    gets(novo->nome);
    
    printf("\nInforme a cidade do time: ");
    fflush(stdin);
    gets(novo->cidadeTime);
    
    printf("\nInforme o ano de cria��o do time: ");
    scanf("%d", &novo->anoCriacao);
    
    printf("\nInforme a quantidade de t�tulos da Libertadores: ");
    scanf("%d", &novo->qtdeLibertadores);
    
    printf("\nInforme a quantidade de t�tulos da Copa do Brasil: ");
    scanf("%d", &novo->qtdeCopaDoBrasil);

    lista = inserirOrdenadoPorAno(lista, novo);
    
    return lista;		
}
