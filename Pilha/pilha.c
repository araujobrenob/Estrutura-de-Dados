#include<stdlib.h>
#include"pilha.h"

struct pilha{ // stack
    int dados[MAX];
    int topo;
};

Pilha criar(){
    Pilha p = malloc(sizeof(struct pilha));
    if(p != NULL){
        p->topo = 0;
    }
    return p;
}

// push
int empilhar(Pilha p, int valor){
    if(p->topo < MAX){
        p->dados[p->topo] = valor;
        p->topo++;
        return 1;
    }
    return 0;
} 
//peek
int acessar_topo(Pilha p){
    if(p->topo == 0) // piha vazia
        return 0;
    return p->dados[p->topo - 1];
}
// pop
int desempilhar(Pilha p){
    if(p->topo == 0) // piha vazia
        return 0;
    p->topo--;
    return 1;
} 

Pilha copiar_pilha(Pilha p) {
    Pilha p_aux = criar();

    while(acessar_topo(p)){
        int valor = acessar_topo(p);
        desempilhar(p);
        empilhar(p_aux, valor);
    }
   
// free
void destruir(Pilha p) {
    if(p != NULL)
        free(p);
}