
typedef struct musica* Musica;

Musica cria_musica(char *titulo , char *artista , int duracao);
char *consulta_titulo(Musica m);
char *consulta_artista(Musica m);
int consulta_duracao(Musica m);
void imprime_musica(Musica m);
void libera_musica(Musica m);


