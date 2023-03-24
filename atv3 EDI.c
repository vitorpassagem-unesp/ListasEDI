#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Aluno{
    int n, rank;
};

struct no{
    struct Aluno aluno;
    struct no *prox;
};

int contaNo (struct no *lista){
    int cont = 0;
    struct no *aux = (struct no*) malloc(sizeof(struct no));
    aux = lista;
    while (aux != NULL){
        cont++;
        aux = aux->prox;
    }
    
    return cont;
}

struct no *insereAluno(struct no *lista, int n, int rank){
    struct no *aux = (struct no*) malloc(sizeof(struct no));
    struct no *aux2 = (struct no*) malloc(sizeof(struct no));
    struct no *aux3 = (struct no*) malloc(sizeof(struct no));
    aux->aluno.n = n;
    aux->aluno.rank = rank;
    aux->prox = NULL;
    if(contaNo(lista)==0) //para incluir o primeiro elemento da lista
        lista = aux;
    else{
        int i;
        for(aux2 = lista, i = 0, aux3 = lista; aux2 != NULL; aux2 = aux2->prox, i++){ //percorre elementos da lista
            if (n>=aux2->aluno.n && aux2->prox == NULL){ //insere à direita do PRIMEIRO elemento da lista se for maior que ele
                aux->prox = aux2->prox;
                aux2->prox = aux;
                break;
            }
            else if(aux2->aluno.n == 1){ //se o aluno com n a ser comparado for o numero 1, insere o aluno digitado à direita 
                aux->prox = aux2;
                aux3 = aux;
                lista = aux;
                break;
            }
            else if(n<=aux2->aluno.n){ //se o aluno a ser inserito tiver n menor do que o comparado, o insere à esquerda
                aux->prox = aux2;
                aux3->prox = aux;
                break;
            }
            else if(i!=0) //avança para o elemento da direita a cada loop depois do primeiro (seria equivalente a um i-1 em um vetor)
                aux3 = aux3->prox; 
        }                
    }

return lista;
}

void imprimeLista (struct no *lista){
    struct no *aux = (struct no*) malloc(sizeof(struct no));
    aux = lista;
    printf("\n\n================================\n");
    for(int i=(contaNo(lista)-1), int j=0; j>i; j++){
        printf("No: %d\tClassific.: %d\n", aux->aluno.n, aux->aluno.rank);
        aux = aux->prox;
    }
    printf("\n\n================================\n");
}


int main(){
    int op;
    int valor;
    struct no *lista = NULL;
    do{
        printf("Escolha uma das opções:\n\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Imprimir lista\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        
        switch (op){
        case 1:
            printf("Digite o 'n' do aluno a ser inserido na lista: ");
            int n, rank;
            scanf("%d", &n);
            printf("Digite a classificacao do aluno: ");
            scanf("%d", &rank);
            lista = insereAluno(lista, n, rank);
            break;
        case 2:
            imprimeLista(lista);
            break;
        default:
            printf("\nERROR\n\n\n");
            break;
        }
    }while(op!=0);
}
