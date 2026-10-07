#include <stdlib.h>
#include "lista.h"

struct elem{
    Musica musica;
    struct elem* prox;
};
typedef struct elem Elem;

struct lista {
    int qtd;
    Elem* inicio;
};

Lista cria_lista(){
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->qtd = 0;
    li->inicio = NULL;
    return li;

}
int insere_inicio(Lista li , Musica m){
    if(li == NULL || m == NULL) return 0;
    Elem* novo = malloc(sizeof(Elem));
    if(novo == NULL) return 0;
    novo->musica = m;
    novo->prox = li->inicio;
    li->inicio = novo;
    li->qtd++;
    return 1;
}
int insere_posicao(Lista li , int pos , Musica m){
    if(li == NULL || m == NULL || pos < 0 || pos >li->qtd) return 0;
    if(pos == 0) return insere_inicio(li,m);

    Elem* ant = li->inicio;
    for(int i = 0 ; i < pos-1 ; i++)
        ant = ant->prox;

    Elem* novo = malloc(sizeof(Elem));
    if(novo == NULL) return 0;
    novo->musica = m;
    novo->prox =  ant->prox;
    ant->prox = novo;
    li->qtd++;
    return 1;
}
int insere_final(Lista li , Musica m){
    if(li == NULL) return 0;
    return insere_posicao(li ,li->qtd , m);
}
Musica remove_posicao(Lista li , int pos){
    if(li == NULL || pos < 0 || pos >= li->qtd) return NULL;

    Elem* removido;
    if (pos == 0){
        removido = li->inicio;
        li->inicio = removido->prox;
    }else{
        Elem* ant = li->inicio;
        for(int i = 0 ; i<pos -1 ; i++)
             ant = ant->prox;
             removido = ant->prox;
             ant->prox = removido->prox;
    }
    Musica m = removido->musica;
    free(removido);
    li->qtd--;
    return m;
}
Musica remove_primeira(Lista li){
    return remove_posicao(li , 0);
}
Musica remove_ultima(Lista li){
    if(li == NULL) return NULL;
    return remove_posicao(li , li->qtd -1);
}
Musica consulta_posicao(Lista li , int pos){
    if(li == NULL || pos < 0 || pos >= li ->qtd) return NULL;
    Elem* p = li->inicio;
    for(int i = 0 ; i < pos ; i++)
        p = p->prox;
    
    return p->musica;

    }
Musica consulta_primeira(Lista li){
    return consulta_posicao(li , 0);
}
int consulta_quantidade(Lista li){
    if(li == NULL) return 0;
    return li->qtd;
}

void libera_lista(Lista li){
    if(li == NULL) return;
    Elem* p = li->inicio;
    while (p != NULL){
        Elem* prox = p->prox;
        libera_musica(p->musica);
        free(p);
        p = prox;
    }
    free(li);
}



