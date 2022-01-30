#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int id;
    struct vertice * dir;
    struct vertice * esq;
    
}VERTICE;

VERTICE * raiz = NULL;
int tam=0;


VERTICE* buscar(int x, VERTICE *aux){
    if(aux == NULL){
        return NULL;
    }else if(x == aux->id){
        return aux;
    }else if(x < aux->id){ //entra no lado esquerdo
        if(aux ->esq == NULL){
            return aux;
        }else{
            return buscar(x, aux->esq);
        }
    }else{  //entra no lado direito
        if(aux ->dir == NULL){
            return aux; //se encontrar o elemento retorna ele,
            //senão, retorna o pai dele
        }else{
            return buscar(x, aux->dir);
        }
    }
}

void buscar_na_arvore(int id){
    VERTICE* aux = buscar(id, raiz);
    if(aux==NULL){
        printf("Arvore vazia");
    }else if(aux ->id == id){
        printf("Elemento encontrado");
    }else{
        printf("Elemento nao foi encontrado");
    }
}


void adicionar(int id){ 
    VERTICE* aux = buscar(id, raiz);
    if(aux != NULL && aux ->id == id){
        printf("Chave já existe, inserção inválida");
    }else{
        VERTICE* novo=malloc(sizeof(VERTICE));
        novo ->id = id;
        novo ->esq = NULL;
        novo -> dir = NULL;
        if(aux == NULL){ // vazia
            raiz = novo;
        }else if(id < aux->id){ //adicionar no lado esquerdo
            aux ->esq = novo;
        }else{ //adidionar no lado direito
            aux ->dir = novo;
        }
    }
}
VERTICE* remover(VERTICE *raiz, int valor){
    if(raiz==NULL){
        printf("\nA arvore esta vazia!!! %d");
        return raiz;
    }else if(valor < raiz->id){
        raiz->esq = remover(raiz->esq, valor);
    }else if(valor > raiz->id){
        raiz->dir = remover(raiz->dir, valor);
    }else{
        if(raiz->dir == NULL && raiz->esq == NULL){
            free(raiz);
            raiz=NULL;
            printf("\nIremos remover a folha %d",valor);
        }else if(raiz->esq == NULL){
            VERTICE*aux = raiz;
            raiz = raiz->dir;
            free(aux);
            printf("\nEncontramos aqui o filho %d, logo, removemos o vertice do lado esquerdo. \n",valor);
        }else if(raiz->dir == NULL){
            VERTICE*aux = raiz;
            raiz = raiz->esq;
            free(aux);
            printf("\nEncontramos Aqui o filho %d, logo removemos o vertice do lado direito.\n",valor);
        }else{
            VERTICE*aux = raiz->dir;
            raiz->id=aux->id;
            raiz->dir = remover(raiz->dir,aux->id);
            printf("\nIremover remover vertice com dois filhos %d\n",valor);
            }
        }
    return raiz;
}

void in_ordem(VERTICE *aux){
    if(aux ->esq != NULL){
        in_ordem(aux ->esq);
    }
    printf("%d", aux ->id);       
    if(aux ->dir!= NULL){
        in_ordem(aux ->dir);
    }
}


int main(){
    adicionar(8);
    adicionar(5);
    adicionar(2);
    adicionar(1);
    adicionar(6);
    adicionar(7);
    adicionar(4);
    adicionar(3);
    adicionar(9);
    adicionar(13);
    adicionar(76);
    adicionar(32);
    adicionar(21);
    adicionar(12);
    adicionar(17);
    adicionar(19);
    adicionar(16);
    adicionar(35);
    adicionar(18);
    adicionar(23);

    printf("Imprimindo arvore... \n");
    in_ordem(raiz);

    printf("\n");
    
    printf("\nBuscando elemento...\n");
    buscar_na_arvore(2);

    printf("\nRemovendo elemento...\n");
    remover(raiz, 6);
    remover(raiz, 1);
    remover(raiz, 5);
    remover(raiz, 7);
    remover(raiz, 19);
    remover(raiz, 21);
    remover(raiz, 3);
    remover(raiz, 8);
    remover(raiz, 17);
    remover(raiz, 9);

    in_ordem(raiz);
    return 0;
}

