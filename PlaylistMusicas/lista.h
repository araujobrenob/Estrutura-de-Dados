#include "musica.h"

typedef struct lista* Lista;

Lista cria_lista();
int insere_inicio(Lista li , Musica m);
int insere_final(Lista li , Musica m);
int insere_posicao(Lista li , int pos , Musica m);

Musica remove_primeira(Lista li);
Musica remove_ultima(Lista li);
Musica remove_posicao(Lista li , int pos);

Musica consulta_primeira(Lista li);
Musica consulta_posicao(Lista li , int pos);

int consulta_quantidade(Lista li);

void libera_lista(Lista li);

