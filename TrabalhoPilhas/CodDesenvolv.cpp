#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Time {
    int id;
    char nome[50];
    int fundacao;
    struct Time* prox;
    struct Time* ant;
} Time;

typedef struct Pilha {
    Time* topo;
} Pilha;

// Funções da pilha
Pilha* criarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int pilhaVazia(Pilha* p) {
    return p->topo == NULL;
}

void push(Pilha* p, int id, char* nome, int fundacao) {
    Time* novo = (Time*)malloc(sizeof(Time));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->fundacao = fundacao;
    novo->prox = p->topo;
    novo->ant = NULL;
    if (p->topo != NULL) {
        p->topo->ant = novo;
    }
    p->topo = novo;
    printf("Time '%s' adicionado à pilha.\n", nome);
}

void pop(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia, nada a remover.\n");
        return;
    }
    Time* temp = p->topo;
    p->topo = p->topo->prox;
    if (p->topo != NULL) {
        p->topo->ant = NULL;
    }
    printf("Time '%s' removido da pilha.\n", temp->nome);
    free(temp);
}

void listarTimes(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia, nada a listar.\n");
        return;
    }
    Time* atual = p->topo;
    printf("Times na pilha:\n");
    while (atual != NULL) {
        printf("ID: %d, Nome: %s, Fundação: %d\n", atual->id, atual->nome, atual->fundacao);
        atual = atual->prox;
    }
}

void atualizarTime(Pilha* p, int id, char* novoNome, int novaFundacao) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia, nada a atualizar.\n");
        return;
    }
    Time* atual = p->topo;
    while (atual != NULL) {
        if (atual->id == id) {
            strcpy(atual->nome, novoNome);
            atual->fundacao = novaFundacao;
            printf("Time com ID %d atualizado.\n", id);
            return;
        }
        atual = atual->prox;
    }
    printf("Time com ID %d não encontrado.\n", id);
}

void liberarPilha(Pilha* p) {
    while (!pilhaVazia(p)) {
        pop(p);
    }
    free(p);
}

int main() {
    Pilha* pilha = criarPilha();
    int opcao, id, fundacao;
    char nome[50];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Time\n");
        printf("2. Remover Time\n");
        printf("3. Listar Times\n");
        printf("4. Atualizar Time\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o ID do time: ");
                scanf("%d", &id);
                printf("Digite o nome do time: ");
                scanf(" %[^\n]", nome);
                printf("Digite o ano de fundação: ");
                scanf("%d", &fundacao);
                push(pilha, id, nome, fundacao);
                break;
            case 2:
                pop(pilha);
                break;
            case 3:
                listarTimes(pilha);
                break;
            case 4:
                printf("Digite o ID do time para atualizar: ");
                scanf("%d", &id);
                printf("Digite o novo nome do time: ");
                scanf(" %[^\n]", nome);
                printf("Digite o novo ano de fundação: ");
                scanf("%d", &fundacao);
                atualizarTime(pilha, id, nome, fundacao);
                break;
            case 5:
                liberarPilha(pilha);
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}

