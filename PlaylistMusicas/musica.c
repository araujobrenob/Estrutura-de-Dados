#include "musica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct musica {
    char titulo[100];
    char artista[100];
    int duracao;
};

Musica cria_musica(char *titulo , char *artista , int duracao){
    if (titulo == NULL || artista == NULL || duracao < 0) return NULL;

    Musica m = malloc(sizeof(struct musica));
    if (m == NULL) return NULL;

    strcpy(m->titulo , titulo);
    strcpy(m->artista , artista);
    m->duracao = duracao;

    return m;
}
char *consulta_titulo(Musica m){
    if (m == NULL) return NULL;
    return m->titulo;
}
char *consulta_artista(Musica m){
    if (m == NULL) return NULL;
    return m->artista;
}
int consulta_duracao(Musica m){
    if (m == NULL) return -1;
    return m->duracao;
}

void imprime_musica(Musica m){
    if (m == NULL) return;
    printf("Titulo : %s Artista : %s  Duracao : %d:%02d\n", m->titulo , m->artista , m->duracao / 60 , m->duracao % 60);


}
void libera_musica(Musica m){
    free(m);
}

