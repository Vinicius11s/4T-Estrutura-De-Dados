#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da lista duplamente encadeada
struct Pessoa {
    int id;
    char nome[50];
    int idade;
    char sexo[20];
    struct Pessoa* prox;
    struct Pessoa* ant;
};

// Função para criar uma nova pessoa
struct Pessoa* criarPessoa(int id, char* nome, int idade, char* sexo) {
    struct Pessoa* novaPessoa = (struct Pessoa*)malloc(sizeof(struct Pessoa));
    if (novaPessoa == NULL) {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }
    novaPessoa->id = id;
    strcpy(novaPessoa->nome, nome);
    novaPessoa->idade = idade;
    strcpy(novaPessoa->sexo, sexo);
    novaPessoa->prox = NULL;
    novaPessoa->ant = NULL;
    return novaPessoa;
}

// Função para recuperar registros de um arquivo
void recuperar_arquivo(struct Pessoa** head) {
    FILE *arq;
    printf("<< Lendo Arquivo de Registros >>\n\n");
    arq = fopen("pessoa.bin", "rb");
    
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!!!\n");
        return;
    }
    
    struct Pessoa tempPessoa; // Variável temporária para ler os dados
    while (fread(&tempPessoa, sizeof(struct Pessoa), 1, arq) > 0) {
        struct Pessoa* novaPessoa = criarPessoa(tempPessoa.id, tempPessoa.nome, tempPessoa.idade, tempPessoa.sexo);
        if (novaPessoa != NULL) {
            inserirPessoaOrdenada(head, novaPessoa);
        }
    }
    
    fclose(arq);
    printf("Dados carregados com sucesso!\n");
    system("pause");
}

// Função para inserir uma pessoa de forma ordenada (por idade)

void inserirPessoaOrdenada(struct Pessoa** head, struct Pessoa* novaPessoa) {
    if (novaPessoa == NULL) {
        printf("Erro: Pessoa inválida\n");
        return;
    }

    // Caso a lista esteja vazia
    if (*head == NULL) {
        *head = novaPessoa;
        printf("Pessoa inserida na lista.\n");
        return;
    }

    struct Pessoa* atual = *head;

    // Inserção no início, caso seja mais jovem que o primeiro
    if (novaPessoa->idade < atual->idade) {
        novaPessoa->prox = atual;
        atual->ant = novaPessoa;
        *head = novaPessoa;
        printf("Pessoa inserida no início da lista.\n");
        return;
    }

    // Percorrer a lista para encontrar a posição correta
    while (atual->prox != NULL && atual->prox->idade < novaPessoa->idade) {
        atual = atual->prox;
    }

    // Inserção no meio ou no final da lista
    novaPessoa->prox = atual->prox;
    if (atual->prox != NULL) {
        atual->prox->ant = novaPessoa;
    }
    atual->prox = novaPessoa;
    novaPessoa->ant = atual;

    printf("Pessoa inserida na lista de forma ordenada.\n");
    system("pause");
}

// Função para listar cadastros em ordem crescente (por idade)
void listarCrescente(struct Pessoa* head) {
    if (head == NULL) {
        printf("Nenhum cadastro encontrado.\n");
        return;
    }

    printf("\nLista de cadastros em ordem crescente de idade:\n");
    struct Pessoa* atual = head;

    while (atual != NULL) {
        printf("ID: %d, Nome: %s, Idade: %d, Sexo: %s\n", atual->id, atual->nome, atual->idade, atual->sexo);
        atual = atual->prox;
    }
    system("pause");
}

// Função para listar cadastros em ordem decrescente (por idade)
void listarDecrescente(struct Pessoa* head) {
    if (head == NULL) {
        printf("Nenhum cadastro encontrado.\n");
        return;
    }

    // Encontra o último nó da lista
    struct Pessoa* atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    printf("\nLista de cadastros em ordem decrescente de idade:\n");
    while (atual != NULL) {
        printf("ID: %d, Nome: %s, Idade: %d, Sexo: %s\n", atual->id, atual->nome, atual->idade, atual->sexo);
        atual = atual->ant;
    }
    system("pause");
}

// Função para remover uma pessoa pelo ID
void removerPessoa(struct Pessoa** head, int id) {
    printf("<<<[REMOVENDO PESSOA]>>>\n");
    if (*head == NULL) {
        printf("Lista vazia. Nenhuma pessoa para remover.\n");
        return;
    }

    struct Pessoa* atual = *head;

    // Encontrar a pessoa com o ID especificado
    while (atual != NULL && atual->id != id) {
        atual = atual->prox;
    }

    // Caso a pessoa com o ID não seja encontrada
    if (atual == NULL) {
        printf("Pessoa com ID %d não encontrada.\n", id);
        return;
    }

    // Caso a pessoa a ser removida seja a primeira da lista
    if (atual == *head) {
        *head = atual->prox;
        if (*head != NULL) {
            (*head)->ant = NULL;
        }
    } else {
        if (atual->prox != NULL) {
            atual->prox->ant = atual->ant;
        }
        if (atual->ant != NULL) {
            atual->ant->prox = atual->prox;
        }
    }

    free(atual);
    printf("Pessoa com ID %d removida com sucesso.\n", id);
    system("pause");
}

// Função para editar uma pessoa
void editarPessoa(struct Pessoa* pessoa) {
    printf("<<<[EDITANDO PESSOA COM ID %d]>>>\n", pessoa->id);

    printf("Digite o novo nome: ");
    getchar();  // Consumir o '\n' residual
    fgets(pessoa->nome, sizeof(pessoa->nome), stdin);
    pessoa->nome[strcspn(pessoa->nome, "\n")] = '\0';  // Remover o '\n' do final

    printf("Digite a nova idade: ");
    scanf("%d", &pessoa->idade);
    getchar();  // Consumir o '\n'

    printf("Digite o novo sexo: ");
    fgets(pessoa->sexo, sizeof(pessoa->sexo), stdin);
    pessoa->sexo[strcspn(pessoa->sexo, "\n")] = '\0';  // Remover o '\n' do final

    printf("Pessoa com ID %d editada com sucesso.\n", pessoa->id);
    system("pause");
}

// Função para localizar e editar uma pessoa pelo ID
void localizarPessoa(struct Pessoa** head, int id) {
    if (*head == NULL) {
        printf("\nLista vazia. Nenhuma pessoa para localizar.\n");
        return;
    }

    struct Pessoa* atual = *head;

    // Encontrar a pessoa com o ID especificado
    while (atual != NULL && atual->id != id) {
        atual = atual->prox;
    }

    // Caso a pessoa com o ID não seja encontrada
    if (atual == NULL) {
        printf("Pessoa com ID %d não encontrada.\n", id);
        return;
    }

    // Exibe informações da pessoa encontrada
    printf("Pessoa encontrada:\n");
    printf("ID: %d, Nome: %s, Idade: %d, Sexo: %s\n", atual->id, atual->nome, atual->idade, atual->sexo);
    
    // Opções para editar ou excluir a pessoa
    int opcao;
    printf("\nPara editar o usuario, digite 1.");
    printf("\nPara excluir o usuario, digite 2.");
    printf("\nPara continuar digite 0.\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        editarPessoa(atual);  // Edita a pessoa encontrada
    } else if (opcao == 2) {
        removerPessoa(head, id);  // Remove a pessoa encontrada
    }
    system("pause");
}

// Função para gravar registros em um arquivo
void gravar_arquivo(struct Pessoa* head) {
    FILE *arq;
    struct Pessoa* atual = head;  // Ponteiro para percorrer a lista

    // Limpa a tela
    system("cls");
    printf("<< Gravando Registros no Arquivo >>\n\n");

    // Abre o arquivo para gravação
    arq = fopen("pessoa.bin", "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!!!\n");
        return; // Retorna da função se não conseguir abrir o arquivo
    }

    // Percorre a lista e grava cada registro
    while (atual != NULL) {
        fwrite(atual, sizeof(struct Pessoa), 1, arq); // Grava o nó atual
        atual = atual->prox;  // Avança para o próximo nó
    }

    // Fecha o arquivo
    fclose(arq);
    printf("Registros Gravados com Sucesso!!!\n");

    // Pausa para o usuário
    system("pause");
}

// Função para ver quantas pessoas existem na lista
void totalElementosLista(struct Pessoa* head) {
    if (head == NULL) {  // Verifica se a lista está vazia
        printf("\nLista vazia. Nenhuma pessoa para localizar.\n");
        return;
    }

    struct Pessoa *pont;
    int totalElementos = 0;
    for (pont = head; pont != NULL; pont = pont->prox) {  // Percorre a lista
        totalElementos++;
    }

    printf("\n\nA lista atual contém %d Cadastros.\n", totalElementos);
    pularLinha();
    system("pause");
}

void pularLinha(){
	printf("\n");
}

// Função para exibir o menu
void exibirMenu() {
    system("cls");
    printf("\nMenu:\n");
    printf("1. Inserir novo cadastro (ordenado por idade)\n");
    printf("2. Buscar cadastro\n");
    printf("3. Listar cadastros (ordem crescente)\n");
    printf("4. Listar cadastros (ordem decrescente)\n");
    printf("5. Verificar quantidade de cadastros existem na lista\n");

    printf("0. Sair\n");
}

// Função principal
int main() {
	
    struct Pessoa* head = NULL;  // Cabeça da lista
    int opcao;

    recuperar_arquivo(&head);

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();  // Consome o '\n' deixado pelo scanf

        switch (opcao) {
            case 1: {
                system("cls");
                printf("<<<[INSERINDO PESSOA NOVA]>>>\n");
                // Inserir cadastro
                int id, idade;
                char nome[50], sexo[20];

                printf("\nDigite o ID: ");
                scanf("%d", &id);
                getchar();  // Consome o '\n' deixado pelo scanf

                printf("Digite o nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' do final da string

                printf("Digite a idade: ");
                scanf("%d", &idade);
                getchar();  // Consome o '\n' deixado pelo scanf

                printf("Digite o sexo: ");
                fgets(sexo, sizeof(sexo), stdin);
                sexo[strcspn(sexo, "\n")] = '\0';  // Remove o '\n' do final da string

                struct Pessoa* novaPessoa = criarPessoa(id, nome, idade, sexo);
                inserirPessoaOrdenada(&head, novaPessoa);
                break;
            }
            case 2: {
                system("cls");
                printf("<<<[LOCALIZAR PESSOA]>>>\n");
                int id;
                printf("Digite o ID da pessoa que deseja encontrar: ");
                scanf("%d", &id);
                localizarPessoa(&head, id);
                break;
            }
            case 3:
                system("cls");
                printf("<<<[LISTANDO EM CRESCENTE]>>>\n");
                listarCrescente(head);
                break;
            case 4:
                system("cls");
                // Listar cadastros (ordem decrescente)
                listarDecrescente(head);
                break;
            case 5:
            	system("cls");
            	totalElementosLista(head);
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        
    } while (opcao != 0);
    
    printf("Gravando registro no arquivo...\n");
    gravar_arquivo(head);
    
    return 0;
}

