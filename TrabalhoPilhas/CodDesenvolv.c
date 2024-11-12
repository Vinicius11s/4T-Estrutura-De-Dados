#include <stdio.h>   
#include <stdlib.h>    
#include <string.h>    
#include <locale.h>    

typedef struct Time {
    int id;                
    char nome[50];         
    int fundacao;          
    struct Time* prox; 
} Time;

typedef struct Pilha {
    Time* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));  // Aloca memória para a pilha.
    p->topo = NULL;                            // Inicializa a pilha vazia (topo = NULL).
    return p;                                  // Retorna o ponteiro para a pilha criada.
}

int pilhaVazia(Pilha* p) {
    return p->topo == NULL;
}

// Função para adicionar um time à pilha.
void push(Pilha* p, int id, char* nome, int fundacao) {
    Time* novo = (Time*)malloc(sizeof(Time));  // Cria um novo nó (Time) para a pilha.
    novo->id = id;                            
    strcpy(novo->nome, nome);                 
    novo->fundacao = fundacao;                
    novo->prox = p->topo;                    
    p->topo = novo;                           
    printf("Time '%s' adicionado à pilha.\n", nome); 
	printf("\n");
	system("pause"); 
}

void pop(Pilha* p) {
    if (pilhaVazia(p)) {  
        printf("Pilha vazia, nada a remover.\n");
        return;
    }
    Time* temp = p->topo;           // Armazena o time do topo em uma variável temporária.
    p->topo = p->topo->prox;        // Atualiza o topo para o próximo time na pilha.
    printf("Time '%s' removido da pilha.\n", temp->nome);  
    free(temp);
    printf("\n");
	system("pause"); 
}

void listarTimes(Pilha* p) {
    if (pilhaVazia(p)) {  
        printf("Pilha vazia, nada a listar.\n");  
        return;
    }
    Time* atual = p->topo;  // Começa do topo da pilha.
    printf("Times na pilha:\n");
    while (atual != NULL) {  // Enquanto houver um time para mostrar.
        printf("ID: %d, Nome: %s, Fundação: %d\n", atual->id, atual->nome, atual->fundacao);
        atual = atual->prox;  // Vai para o próximo time da pilha.
    }
    printf("\n");
	system("pause"); 
}

void atualizarTime(Pilha* p, int id, char* novoNome, int novaFundacao) {
    if (pilhaVazia(p)) {  
        printf("Pilha vazia, nada a atualizar.\n"); 
        return;
    }
    Time* atual = p->topo;  // Começa do topo da pilha.
    while (atual != NULL) {  // Enquanto houver um time para verificar.
        if (atual->id == id) {  // Se encontrar o time com o ID informado.
            strcpy(atual->nome, novoNome);  
            atual->fundacao = novaFundacao;  
            printf("Time com ID %d atualizado.\n", id);
            printf("\n");
			system("pause"); 
            return; 
        }
        atual = atual->prox;
    }
    printf("Time com ID %d não encontrado.\n", id);
    printf("\n");
	system("pause"); 
}

void liberarPilha(Pilha* p) {
    while (!pilhaVazia(p)) {  // Enquanto a pilha não estiver vazia,
        pop(p);  // Remove os times um por um até a pilha ficar vazia.
    }
    free(p);
}

int pilha() {
    setlocale(LC_ALL, "portuguese"); 
	
    Pilha* pilha = criarPilha(); 
    
    int opcao, id, fundacao;
    char nome[50];

    do {
    	system("cls");
		printf("\nMenu:\n");
        printf("1. Adicionar Time\n");
        printf("2. Remover Time\n");
        printf("3. Listar Times\n");
        printf("4. Atualizar Time\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); 

        switch (opcao) {  
            case 1:  // Adicionar Time.
                printf("\n\nDigite o ID do time: ");
                scanf("%d", &id);  
                printf("Digite o nome do time: ");
                scanf(" %[^\n]", nome);  
                printf("Digite o ano de fundação: ");
                scanf("%d", &fundacao); 
                push(pilha, id, nome, fundacao);  // Adiciona o time à pilha.
                break;
            case 2:  // Remover Time.
                pop(pilha);  // Remove o time do topo da pilha.
                break;
            case 3:  // Listar Times.
                listarTimes(pilha); 
                break;
            case 4: 
                printf("Digite o ID do time para atualizar: ");
                scanf("%d", &id); 
                printf("Digite o novo nome do time: ");
                scanf(" %[^\n]", nome); 
                printf("Digite o novo ano de fundação: ");
                scanf("%d", &fundacao); 
                atualizarTime(pilha, id, nome, fundacao);  // Atualiza o time na pilha.
                break;
            case 5:  // Sair.
                liberarPilha(pilha);  // Libera a memória da pilha.
                printf("Encerrando...\n"); 
                break;
            default:
                printf("Opção inválida!\n");  
                break;
        }
    } while (opcao != 5); 
}

void main(){
	pilha();
}


