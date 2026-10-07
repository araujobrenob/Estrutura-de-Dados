#include <stdio.h>
#include <stdlib.h>

struct elem {
    int valor;
    Elem* prox;

}

typedef struct elem Elem;

struct lista {
    int qtd;
    Elem* inicio;
};

typedef struct lista* Lista;

Lista* criar_lista(){
    Lista li = malloc(sizeof(struct lista));
    if(li !=NULL){
        li->qtd = 0;
        li->inicio = NULL;
    }
    return li;
    

}

int inserir_inicio(Lista li , int valor_inserido){
    Elem* no = malloc(sizeof(Elem));
    if( no != NULL){
        no->valor = valor_inserido;
        no->prox = li->inicio;
        li->inicio = no;
        li->qtd++;
        return 1;

    }
    return 0;


}

int inserir_final(Lista li , int valor_inserido){
     Elem* no = malloc(sizeof(Elem));
     if(no !=NULL){
        no->valor = valor_inserido;
        no->prox = NULL;
        Elem* aux = li->inicio;
        while(aux->prox !=NULL){
            aux = aux->prox;
        }

     }

void imprimir_lista(Lista li){
    if(quantidadeDaLista(li) == 0){
        return;
    }
    Elem* aux = acessar_inicio(li);
    

    

}
}