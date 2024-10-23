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
	
	if(listaVazia(lista) == 1){
		printf("\n\nA Lista está vazia\n");
		pularLinha();
		system("pause");
	}
	else{
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
}

void exibirLista(Lista *lista) {

    if (listaVazia(lista))
        printf("\nLista vazia");
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
	if(listaVazia(lista) == 1){
		printf("\n\nA Lista está vazia.\n");
		pularLinha();
		system("pause");
		return lista;
	}
	int valorExcluido;
	pularLinha();
	exibirLista(lista);
	int aux = -1;
	
		if(caso == 2){
			do{
				printf("\nInforme o elemento que deseja alterar na Lista: ");
				scanf("%d", &valorExcluido);
				
				if(pesquisarElemento(lista, valorExcluido) == 1){
					lista = removerQualquerNo(lista, valorExcluido);
					pularLinha();
					aux++;
					return lista;
				}
				else{
					printf("\nO valor informardo não existe na Lista.");
					sleep(2);
				}
		}while(aux != 0);		
	}
	else{
		do{
			printf("\nInforme o elemento que deseja excluir da Lista: ");
			scanf("%d", &valorExcluido);
		
			if(pesquisarElemento(lista, valorExcluido) == 1){
				lista = removerQualquerNo(lista, valorExcluido);
				pularLinha();
				printf("Exclusão concluída com sucesso!!");
				sleep(2);
				pularLinha();
				exibirLista(lista);
				pularLinha();
				system("pause");
				aux++;
				return lista;
			}
			else{
				printf("O valor informardo não existe na Lista.");
				sleep(2);
			}
		}while(aux != 0);
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
        pularLinha();
		exibirLista(lista);
        pularLinha();
        system("pause");
        limpaTela();
        do {
            limpaTela();
            printf("\t<<<Opção Escolhida: Inserir elemento de forma ordenada.>>>");
            printf("\n\nVocê deseja inserir mais elementos à lista?");
            printf("\n1- Sim");
            printf("\n2- Não");
            printf("\nEscolha um número e digite ENTER: ");
            scanf("%d", &opcao);

            if (opcao == 1) {
                printf("\nInforme o valor que deseja inserir: ");
                scanf("%d", &valor);
                // Apenas chama a função de inserção sem a recursão
                if(pesquisarElemento(lista, valor) == 0){
					lista = inserirNoOrdenado(lista, valor, 0);
					exibirLista(lista);
               	 	pularLinha();
                	system("pause");
				}
				else{
					printf("\nO Elemento já existe na Lista.");
					sleep(2);
				}
            } else if (opcao != 2) {
                printf("\nInforme uma opção válida.");
                sleep(2);
            }
        } while (opcao != 2);  // Continua até o usuário escolher "Não" (2)
    }
					
		if(caso == 2){
			printf("\nAlteração Concluída com sucesso!");
	        exibirLista(lista);
	        pularLinha();
	        system("pause");	
	        pularLinha();
			return lista;				
		}   	 
	
    return lista;
}

Lista* carregaNovoValor(Lista *lista) {
	if(listaVazia(lista) == 1){
		printf("\n\nA Lista está vazia.\n");
		pularLinha();
		system("pause");
		return lista;
	}
	
    int valorNovo;
    Lista *novaLista = excluirElemento(lista, 2);

    if (novaLista != NULL) {
        printf("Informe o novo valor que deseja adicionar à Lista: ");
        scanf("%d", &valorNovo);
        lista = inserirNoOrdenado(novaLista, valorNovo, 2);
    } else {
        printf("\nNão foi possível excluir o valor.\n");
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

Lista* QtdeElementos(Lista *lista, int caso){
	int totalelementos = 0;
	totalelementos = totalElementosLista(lista);
	if (listaVazia(lista) == 1){
		printf("\n\na Lista está vazia.\n");	
		pularLinha();
		system("pause");
		return lista;
	} 
	Lista *pont;
	if(caso == 5){
   		printf("\n\nLista Atual:\n");
    	for (pont = lista; pont != NULL; pont = pont->prox){
        	printf("%d -> ", pont->valor);
		}		
        pularLinha();
        pularLinha();
        system("pause");		
	}
    else{
  	    printf("\n\nLista Atual:\n");
    	for (pont = lista; pont != NULL; pont = pont->prox){
        	printf("[%d] -> ", pont->valor);
		}
		if(totalelementos == 1){
	   		printf("\n\nA Lista atual contém: %d Elemento\n", totalelementos);
			pularLinha();
			system("pause");  		
		}
		else{
	    	printf("\n\nA Lista atual contém: %d Elementos\n", totalelementos);
			pularLinha();
			system("pause");  			    
   		}  	
	}
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
		printf("\n2- Alterar elemento.");
		printf("\n3- Excluir elemento.");
		printf("\n4- Localizar elemento.");
		printf("\n5- Exibir Todos elementos.");
		printf("\n6- Exibir quantidade de elementos da lista.");
		printf("\n0- Encerrar o Programa.");
	
		printf("\n\nEscolha um número e pressione ENTER: ");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1:
				limpaTela();
				printf("\t<<<Opcão escolhida: Inserir elemento de forma ordenada.>>>");
				elementoInserir = carregaInserir(elementoInserir);
				if(pesquisarElemento(lista1, elementoInserir) == 0){
					lista1 = inserirNoOrdenado(lista1, elementoInserir,1);	
				}
				else{
					printf("\nO Elemento já existe na Lista.");
					sleep(2);
				}
				break;
			case 2:
				limpaTela();
				printf("\t<<<Opcão escolhida: Alterar Elemento>>>");
				lista1 = carregaNovoValor(lista1);		
			break;
			case 3:
				limpaTela();
				printf("\t<<<Opcão escolhida: Excluir Elemento>>>");
				lista1 = excluirElemento(lista1,3);
				limpaTela();
			break;
			case 4:
				limpaTela();
				printf("\t<<<Opcão escolhida: Localizar Elemento>>>");
				localizarElementoEscolhido(lista1);
				break;
			case 5:
				limpaTela();
				printf("\t<<<Opcão escolhida: Exibir Todos elementos>>>");
				QtdeElementos(lista1,5);				
				break;
			case 6:
				limpaTela();
				printf("\t<<<Opcão escolhida: Exibir quantidade de elementos da lista>>>");
				QtdeElementos(lista1,6);				
				break;
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
