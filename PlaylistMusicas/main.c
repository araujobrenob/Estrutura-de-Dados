#include <stdio.h>
#include "lista.h"

void adiciona_musica(Lista playlist , Musica m){
    if(insere_final(playlist,m))
        printf("Adicionada ao final : %s\n" ,consulta_titulo(m));
    else
        printf("erro ao adicionar musica.\n");
}

void adiciona_musica_posicao(Lista playlist , Musica m , int pos , int *proxima){
    if(insere_posicao(playlist , pos , m)){
        if(pos < *proxima){
            (*proxima)++;
        }
            
    }   else{
            printf("posicao %d invalida para adicionar" , pos);
    }
}

void remove_musica(Lista playlist ,int pos , int *proxima){
    Musica m = remove_posicao(playlist , pos);
    if(m == NULL){
        printf("posicao %d invalida para remover" , pos);
        return;
    }
    if(pos < *proxima){
        (*proxima)--;
    }      
     printf("removida da posicao %d : %s\n" , pos ,consulta_titulo(m));
        libera_musica(m);
}

int tempo_restante(Lista playlist , int proxima){
    int total = 0;
    for(int i = proxima ; i < consulta_quantidade(playlist) ; i++){
        total += consulta_duracao(consulta_posicao(playlist , i));
    }
    printf("tempo restante : %d:%02d\n" , total / 60 , total % 60);
    return total;   
}
void play(Lista playlist , int *proxima){
    Musica m = consulta_posicao(playlist , *proxima);
    if(m == NULL) {
        printf("fim da playlist ");
        return;
    }
    printf("tocando (posicao : %d)" , *proxima);
    imprime_musica(m);
    (*proxima)++;
}

int musicas_reproduzidas(int proxima){
    printf("musicas reproduzidas : %d\n", proxima);
    return proxima;
}
int main(){
    Lista playlist = cria_lista();
    int proxima = 0;

    Musica m[10] = {
        cria_musica("Bohemian Rhapsody" , "Queen", 354),
        cria_musica("Imagine" , "John Lennon" , 183),
        cria_musica("Garota de ipanema" , "Tom jobim" , 195),
        cria_musica("Hotel california" , "Eagles" , 391),
        cria_musica("Evidencias" , "Xitaozinho e Xororo" , 250),
        cria_musica("Billie jeans" , "Michael Jackson", 294),
        cria_musica("Aquarela" , "Toquinho", 260),
        cria_musica("You are not alone" , "Michael Jackson" , 346),
        cria_musica("Waka waka" , "Shakira" , 202),
        cria_musica("Veridis quo" , "Daft punk" , 345)

    };

    printf("montando playlist");
    for(int i = 0 ; i < 7 ; i++) {
        adiciona_musica(playlist , m[i]);
    }
    adiciona_musica_posicao(playlist , m[7] , 0 , &proxima);
    adiciona_musica_posicao(playlist , m[8] , 3 , &proxima);
    adiciona_musica_posicao(playlist , m[9] , 5 , &proxima);
    
    printf("musicas na playlist : %d\n" , consulta_quantidade(playlist));
    tempo_restante(playlist , proxima);

    printf("Tocando");
    play(playlist , &proxima);
    play(playlist , &proxima);
    play(playlist , &proxima);
    musicas_reproduzidas(proxima);
    tempo_restante(playlist, proxima);

    printf("alterando a playlist durante a reproducao");
    remove_musica(playlist , 1 , &proxima);
    tempo_restante(playlist , proxima);

    printf(" tocando ate o fim");
    while(proxima < consulta_quantidade(playlist)){
        play(playlist , &proxima);
    }
    play(playlist , &proxima);
    musicas_reproduzidas(proxima);
    tempo_restante(playlist , proxima);

    printf("resumo");
    printf("quantidade de musicas na playlist : %d\n" , consulta_quantidade(playlist));
    printf("posicao da proxima musica a ser tocada : %d\n" , proxima);

    libera_lista(playlist);
    return 0;

}

