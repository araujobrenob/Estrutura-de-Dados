struct elem{
    int valor;
    struct elem* prox;
};

typedef struct elem Elem;

struct lista{
    int qtd;
    Elem* final;
};

typedef struct lista* Lista;


Lista criar_lista(){
    Lista li = malloc(sizeof(struct lista));
    if(li !=NULL){
        li->qtd = 0;
        Elem* final = NULL;
    }
    return li;
}

acessar_final(Lista li, int valor){
    if(li == NULL){
        return;
    }
    return li->final;

}

acessar_inicio(Lista li , int valor){
    if(li == NULL){
        return;
    }
    return li->final->prox;
}
inserir_inicio(Lista li , int valor){
    Elem* no = malloc (sizeof(struct lista));
    no =
    li->final->prox = no->prox;
    li->final->prox = no;
}