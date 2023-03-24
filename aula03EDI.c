#include <stdio.h>
#include <stdlib.h>

struct no{
    int val;
    struct no *prox;
};

struct no* inserePrim (struct no *lista, int valor){
    struct no *aux = (struct no*) malloc(sizeof(struct no));
    aux->val = valor;
    aux->prox = NULL;
    lista=aux;

    return lista;
}

struct no* insereInicio (struct no *lista, int valor){
    struct no *aux = (struct no*) malloc(sizeof(struct no));
    aux = inserePrim(aux, valor);
    aux->prox = lista;

    return aux;
}

/* ESTÁ ERRADA, INSERE APÓS PRIMEIRO ELEMENTO
struct no* insereFim (struct no *lista, int valor){
    struct no *aux = (struct no*) malloc(sizeof(struct no));
    aux = inserePrim(aux, valor);
    lista->prox = aux;

    return lista;
}

INCLUIR ALGO DESSE ESTILO NO PROGRAMA PARA FUNCIONAR
for(aux2 = lista; aux2->prox != NULL; aux2=aux2->prox){
            if(aux2->prox == NULL)
                maior = aux2;
        }
        maior->prox = aux;
        aux->prox = NULL;
*/

int contaNo (struct no *lista){
    int cont;
    struct no *aux = (struct no*) malloc(sizeof(struct no));
    aux = lista;
    while (aux != NULL){
        cont++;
        aux = aux->prox;
    }
    
    return cont;
}

struct no* insereMeio (struct no *no1, struct no* no3, int valor){
    struct no* no2 = insereInicio (no3, valor);
    no1->prox = no2;
    
    return no2;
}

void imprimeLista (struct no *lista){
    struct no *aux = (struct no*) malloc(sizeof(struct no));
    aux = lista;
    printf("\n\n================================\n")
    while (aux!= NULL){
        printf("%d ", aux->val);
        aux = aux->prox;
    }
    printf("\n\n================================\n");
}

int main(){
    int n;
    int valor;
    struct no *lista = (struct no*) malloc(sizeof(struct no));
    printf("Escolha uma das opções:\n\n");
    printf("1 - Inserir nó no início da lista\n");
    printf("2 - Inserir nó no meio da lista\n");
    printf("3 - Inserir nó no fim da lista\n");
    printf("4 - Imprimir lista\n");
    
    switch (n){
    case 1:
        printf("Digite o valor a ser inserido na lista: ");
        scanf("%d", &valor);

        if (contaNo(lista)<1)
            lista = inserePrim(lista, valor);
        else
            lista = insereInicio(lista, valor);
        break;

    case 2:
        printf("Digite o valor a ser inserido na lista: ");
        scanf("%d", &valor);

    default:
        break;
    }
}