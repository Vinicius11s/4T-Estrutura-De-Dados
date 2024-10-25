#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

// Estrutura da lista duplamente encadeada
struct Pessoa {
    int id;
    char nome[50];
    int idade;
    char sexo[20];
    struct Pessoa* prox;
    struct Pessoa* ant;
};

// Função para inserir uma pessoa de forma ordenada (sem mensagens)
void inserirPessoaSilenciosa(struct Pessoa** head, struct Pessoa* novaPessoa) {
    if (novaPessoa == NULL) {
        return; // Se a nova pessoa é inválida, não faz nada
    }

    // Caso a lista esteja vazia
    if (*head == NULL) {
        *head = novaPessoa;
        return; // Retorna sem mensagem
    }

    struct Pessoa* atual = *head;

    // Inserção no início, caso a pessoa seja mais jovem que o primeiro da lista
    if (novaPessoa->idade < atual->idade) {
        novaPessoa->prox = atual;
        atual->ant = novaPessoa;
        *head = novaPessoa;
        return; // Retorna sem mensagem
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
}


// Função para validar se o ID já existe na lista
bool validarId(struct Pessoa** head, int id) {
    struct Pessoa* atual = *head;

    while (atual != NULL) {
        if (atual->id == id) {
            printf("Erro: Pessoa com ID %d já existe na lista.\n", id);
            sleep(3);
            return true; // Não insere se o ID já existe
        }
        atual = atual->prox;
    }
    return false;
}

// Função para pular linha
void pularLinha() {
    printf("\n");
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
        printf("\n%s cadastrado com sucesso!", novaPessoa->nome);
        pularLinha();
        system("pause");
        return;
    }

    struct Pessoa* atual = *head;

    // Inserção no início, caso a pessoa seja mais jovem que o primeiro da lista
    if (novaPessoa->idade < atual->idade) {
        novaPessoa->prox = atual;
        atual->ant = novaPessoa;
        *head = novaPessoa;
        printf("\n%s cadastrado com sucesso!", novaPessoa->nome);
        pularLinha();
        system("pause");
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
    
    printf("\n%s cadastrado com sucesso!", novaPessoa->nome);
    pularLinha();
    system("pause");

}

// Função para limpar a tela
void limpaTela() {
    system("cls");
}

// Função para criar uma nova pessoa
struct Pessoa* criarPessoa(int id, char* nome, int idade, char* sexo) {
    struct Pessoa* novaPessoa = (struct Pessoa*)malloc(sizeof(struct Pessoa));
    if (novaPessoa == NULL) {
        printf("Erro ao alocar memória.\n");
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
            // Chama a função de inserção, mas não exibe a mensagem de sucesso
             inserirPessoaSilenciosa(head, novaPessoa);
        }
    }

    fclose(arq);
    printf("Dados carregados com sucesso!\n");
    system("pause");
}


// Função para listar cadastros em ordem crescente (por idade)
void listarCrescente(struct Pessoa* head) {
    if (head == NULL) {
        printf("Nenhum cadastro encontrado.\n");
        pularLinha();
        system("pause");
        return;
    }

    printf("\nLista de cadastros em ordem crescente de idade:\n");
    struct Pessoa* atual = head;

    while (atual != NULL) {
        printf("ID: %d, Nome: %s, Idade: %d, Sexo: %s\n", atual->id, atual->nome, atual->idade, atual->sexo);
        atual = atual->prox;
    }
    pularLinha();
    system("pause");
}

// Função para listar cadastros em ordem decrescente (por idade)
void listarDecrescente(struct Pessoa* head) {
    if (head == NULL) {
        printf("Nenhum cadastro encontrado.\n");
        pularLinha();
        system("pause");
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
    pularLinha();
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
        pularLinha();
        system("pause");
        return;
    }

    struct Pessoa* atual = *head;

    // Encontrar a pessoa com o ID especificado
    while (atual != NULL && atual->id != id) {
        atual = atual->prox;
    }

    // Caso a pessoa com o ID não seja encontrada
    if (atual == NULL) {
        printf("\nPessoa com ID %d não encontrada.\n", id);
        pularLinha();
        system("pause");
        return;
    }
    limpaTela();
    printf("<<<\tOpcão escolhida: Buscar cadastro>>>\n");    
    // Exibe informações da pessoa encontrada
    printf("\nPessoa encontrada:\n");
    printf("ID: %d, \nNome: %s, \nIdade: %d, \nSexo: %s\n", atual->id, atual->nome, atual->idade, atual->sexo);
    
    // Editar a pessoa
    editarPessoa(atual);
}

void gravar_arquivo(struct Pessoa* head) {
    FILE* arquivo = fopen("pessoa.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }

    struct Pessoa* atual = head;

    // Percorrer toda a lista e escrever cada pessoa no arquivo
    while (atual != NULL) {
        fwrite(atual, sizeof(struct Pessoa), 1, arquivo);
        atual = atual->prox;
    }

    fclose(arquivo);
    printf("Dados gravados com sucesso.\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Pessoa* head = NULL;

    recuperar_arquivo(&head);  // Carregar pessoas do arquivo

    int opcao, id, idade;
    char nome[50], sexo[20];

    while (1) {
        limpaTela();
        
    	char username[100];
		DWORD username_len = sizeof(username);
		GetUserName(username, &username_len);
		limpaTela();
		printf("\t<<<Este Algoritmo torna possível realizar a manipulação de métodos em uma Lista Encadeada>>>");
		printf("\n\n\tOlá %s Oque Deseja Fazer...?", username);
    	
        printf("\n\n<<<<<  [ MENU ]  >>>>>>\n");
        printf("\n1. Inserir Pessoa\n");
        printf("2. Listar Pessoas (Crescente)\n");
        printf("3. Listar Pessoas (Decrescente)\n");
        printf("4. Remover Pessoa\n");
        printf("5. Localizar e Editar Pessoa\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o ID: ");
                scanf("%d", &id);
                if (validarId(&head, id)) {
                    break;
                }
                printf("Digite o nome: ");
                getchar();  // Consumir o '\n'
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';  // Remover o '\n' do final

                printf("Digite a idade: ");
                scanf("%d", &idade);

                printf("Digite o sexo: ");
                getchar();  // Consumir o '\n'
                fgets(sexo, sizeof(sexo), stdin);
                sexo[strcspn(sexo, "\n")] = '\0';  // Remover o '\n' do final

                struct Pessoa* novaPessoa = criarPessoa(id, nome, idade, sexo);
                inserirPessoaOrdenada(&head, novaPessoa);
                break;

            case 2:
                listarCrescente(head);
                break;

            case 3:
                listarDecrescente(head);
                break;

            case 4:
                printf("Digite o ID da pessoa a ser removida: ");
                scanf("%d", &id);
                removerPessoa(&head, id);
                break;

            case 5:
                printf("Digite o ID da pessoa a ser localizada: ");
                scanf("%d", &id);
                localizarPessoa(&head, id);
                break;

            case 0:
                printf("Saindo do programa...\n");
                gravar_arquivo(head);

                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

