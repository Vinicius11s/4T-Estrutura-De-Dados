#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>


struct no{
	int valor;
	struct no *prox;

};

typedef struct no Lista;

void limpaTela(){
	system("cls");
}

void pularLinha(){
	printf("\n");
}

int pesquisarElemento(Lista *lista, int valor) {

    if (listaVazia(lista))
        return 0;
    else {

        Lista* pont;
        for (pont = lista; pont != NULL; pont = pont->prox) {
            if (pont->valor == valor)
                return 1;
        }

        return 0; //se não achar
    }

}

int carregaInserir(int elementoInserir){
	printf("\n\nInforme o Elemento que deseja adicionar a Lista: ");
	scanf("%d", &elementoInserir);
	return elementoInserir;
}

Lista* criarLista() {
    return NULL;
}

int listaVazia(Lista *lista) {
    if (lista == NULL)
        return 1;

    return 0;
}

void localizarElementoEscolhido(Lista *lista){
	int elemento, pont;
	int i=0;
	printf("\n\nInforme o elemento que você deseja Localizar na Lista: ");
	scanf("%d", &elemento);
	
	if(pesquisarElemento(lista, elemento) == 1){
		printf("\nO elemento foi Localizado com sucesso!\n");
		Lista *pont;
		
        for (pont = lista; pont != NULL; pont = pont->prox){
        	if(pont->valor == elemento){
        		printf("[%d] -> ", pont->valor);	
			}
			else{
				printf("%d -> ", pont->valor);	
			}
			i++;
		}
		printf("\n\nElemento encontrado na posição: %d", i);
		pularLinha();
		pularLinha();
		system("pause"); 
	}
	else{
		printf("\nO elemento informado não existe na Lista.");
		pularLinha();
		pularLinha();
		system("pause"); 
	}
}

void exibirLista(Lista *lista) {

    if (listaVazia(lista))
        printf("Lista vazia");
    else {
        Lista *pont;
        printf("\nLista Atual:\n");
        for (pont = lista; pont != NULL; pont = pont->prox)
            printf("%d -> ", pont->valor);
    }

    printf("\n");
}

Lista* removerFinalLista(Lista *lista) {
	Lista *no;
	
    if (!listaVazia(lista)) {
        if (lista->prox == NULL) { //verifica se existe só 1 nó {
            free(lista);
            lista = NULL;
        }
        else {
           for (no = lista; no != NULL; no = no->prox) {
               if (no->prox->prox == NULL) { //identifica penúlt. nó
                    Lista *removeNo = no->prox;
                    no->prox = NULL;
                    free(removeNo);
                    break;
                }
            }
        }
    }
    return lista;
}

Lista* removerInicioLista(Lista *lista) {

    if (listaVazia(lista))
        return NULL;
    else {
        Lista *removerNo = lista;

        if (lista->prox != NULL) //tem pelo menos 2 nós
            lista = lista->prox;
        else  //tem apenas um nós
            lista = NULL;

        free(removerNo);

        return lista;
    }
}

Lista* removerQualquerNo (Lista *lista, int valor) {
    Lista *no_atual, *no_anterior;
    for (no_atual=lista; no_atual != NULL; no_atual=no_atual->prox) {
        if (no_atual->valor == valor) {
            if (no_atual == lista) {
                //nó encontrado está no início da lista
                lista = removerInicioLista(lista);
                break;
            }
                if (no_atual->prox == NULL) {
                //nó encontrado está no fim da lista
                removerFinalLista(lista);
                break;
            }
            //nó encontrado está no meio da lista
            no_anterior ->prox = no_atual->prox;
            free(no_atual);
            break;
        }
        else
            no_anterior = no_atual;
    }
    return lista;
}

Lista* excluirElemento(Lista *lista, int caso){
	int valorExcluido;
	pularLinha();
	exibirLista(lista);
	
	if(caso == 2){
		printf("\nInforme o elemento que deseja alterar na Lista: ");
		scanf("%d", &valorExcluido);
		
			if(pesquisarElemento(lista, valorExcluido) == 1){
				lista = removerQualquerNo(lista, valorExcluido);
				pularLinha();
				return lista;
		}
		else{
			printf("O valor informardo não existe na Lista.");
		}
		return lista;		
	}
	else{
		printf("\nInforme o elemento que deseja excluir da Lista: ");
		scanf("%d", &valorExcluido);
	
		if(pesquisarElemento(lista, valorExcluido) == 1){
			lista = removerQualquerNo(lista, valorExcluido);
			pularLinha();
			return lista;
	}
	else{
		printf("O valor informardo não existe na Lista.");
	}
	return lista;
	}
}

Lista* inserirNoInicioLista(Lista *lista, int valor) {
    //reserva memória para o novo nó
    Lista* novoNo = (Lista*) malloc(sizeof(Lista));
    novoNo->valor = valor;
    novoNo->prox = lista;

    return novoNo;
}

Lista* inserirNoFinalLista (Lista* lista, int valor) {

    Lista* novoNo = (Lista*)malloc(sizeof(Lista));
    novoNo->prox = NULL;
    novoNo->valor = valor;

    if (listaVazia(lista))
        lista = novoNo;
    else {
        Lista *pont;
        for (pont = lista; pont != NULL; pont = pont->prox) {
            if (pont->prox == NULL) { //encontrou o último
                pont->prox = novoNo;
                break;
            }
        }
    }

    return lista;
}

Lista* inserirNoOrdenado(Lista *lista, int valor, int caso) {
    int opcao = 0;

    while (opcao != 2) {
        if (lista == NULL) {
            lista = inserirNoInicioLista(lista, valor);
        } else if (lista->prox == NULL) {
            if (lista->valor < valor)
                lista = inserirNoFinalLista(lista, valor);
            else
                lista = inserirNoInicioLista(lista, valor);
        } else {
            Lista *no_atual, *no_anterior = NULL;
            int inserido = 0;

            for (no_atual = lista; no_atual != NULL; no_anterior = no_atual, no_atual = no_atual->prox) {
                if (no_atual->valor > valor) {
                    if (no_atual == lista) {
                        lista = inserirNoInicioLista(lista, valor);
                    } else {
                        Lista *novo_no = (Lista*)malloc(sizeof(Lista));
                        novo_no->valor = valor;
                        novo_no->prox = no_atual;
                        no_anterior->prox = novo_no;
                    }
                    inserido = 1;
                    break;
                }
            }
            if (!inserido) {
                lista = inserirNoFinalLista(lista, valor);
            }
        }
        if(caso == 1){
        	printf("\nElemento adicionado com Sucesso!");
        	exibirLista(lista);
        	pularLinha();
        	pularLinha();
        	system("pause");
        	printf("\nVocê deseja inserir mais elementos à lista?");
        	printf("\n1- Sim");
        	printf("\n2- Não");
        	printf("\nEscolha um número e digite ENTER: ");
        	scanf("%d", &opcao);

        	if (opcao == 1){
        		limpaTela();
        		printf("\t<<<Inserir elemento de forma ordenada.>>>");
            	printf("\n\nInforme o valor que deseja inserir: ");
            	scanf("%d", &valor);
        	}       	
		}
		else if(caso == 2){
			printf("\nAlteração Concluída com sucesso!");
        	exibirLista(lista);
        	pularLinha();
        	pularLinha();
        	system("pause");	
			return lista;			
		}
    }
    return lista;
}

Lista* leNovoValor(Lista *lista){
	int valorNovo;
	
	if(excluirElemento(lista, 2)){
		printf("Informe o novo valor que deseja adicionar a Lista: ");
		scanf("%d", &valorNovo);
		lista = inserirNoOrdenado(lista, valorNovo,2);
	}
	else{
		printf("Não foi possível excluir o valor.\n");
		sleep(2);
	}
	return lista;
}

int totalElementosLista(Lista *lista) {
    if (listaVazia(lista))
        return 0;
    else {

        Lista *pont;
        int totalElementos = 0;
        for (pont = lista; pont != NULL; pont = pont->prox)
            totalElementos++;

        return totalElementos;
    }
}

Lista* QtdeElementos(Lista *lista){
	int totalelementos = 0;
	totalelementos = totalElementosLista(lista);
	if (listaVazia(lista))
        printf("Lista vazia");
    else {
        Lista *pont;
        printf("\nLista Atual:\n");
        for (pont = lista; pont != NULL; pont = pont->prox)
            printf("[%d] -> ", pont->valor);
    }
	
	printf("\n\nA Lista atual contém: %d Elementos\n", totalelementos);
	pularLinha();
	pularLinha();
	system("pause");
}

void menu(){
	limpaTela();
	Lista *lista1 = criarLista();

	int opcao = -1, elementoInserir;
	setlocale(LC_ALL,"portuguese");
	
	
	char username[100];
	DWORD username_len = sizeof(username);
	GetUserName(username, &username_len);
	
	while(opcao != 0){
		limpaTela();
		printf("\t<<<Este Algoritmo torna possível realizar a manipulação de métodos em uma Lista Encadeada>>>");
		printf("\n\n\tOlá %s Oque Deseja Fazer...?", username);
		
		printf("\n\nMenu de Opções:");
		printf("\n1- Inserir elemento de forma ordenada.");
		printf("\n2- Alterar Elemento.");
		printf("\n3- Excluir Elemento.");
		printf("\n4- Localizar Elemento.");
		printf("\n5- Exibir quantidade de elementos da lista.");
		printf("\n0- Encerrar o Programa.");
	
		printf("\n\nEscolha um número e pressione ENTER: ");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1:
				limpaTela();
				printf("\t<<<Opcão escolhida: Inserir elemento de forma ordenada.>>>");
				elementoInserir = carregaInserir(elementoInserir);
				lista1 = inserirNoOrdenado(lista1, elementoInserir,1);
				break;
			case 2:
				limpaTela();
				printf("\t<<<Opcão escolhida: Alterar Elemento>>>");
				leNovoValor(lista1);		
			break;
			case 3:
				limpaTela();
				printf("\t<<<Opcão escolhida: Excluir Elemento>>>");
				excluirElemento(lista1,3);
				limpaTela();
			break;
			case 4:
				limpaTela();
				printf("\t<<<Opcão escolhida: Localizar Elemento>>>");
				localizarElementoEscolhido(lista1);
				break;
			case 5:
				limpaTela();
				printf("\t<<<Opcão escolhida: Exibir quantidade de elementos da lista>>>");
				QtdeElementos(lista1);				
				break;
			case 0:
				break;
			default:
				limpaTela();
				printf("Opção Inválida !!");
				pularLinha();
				pularLinha();
				system("pause");
		}		
	}
}

int main(int argc, char *argv[]) {
	menu();
	return 0;
}
