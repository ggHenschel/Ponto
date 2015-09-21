/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include "tela.h"
#include "pong_raquete.h"
#include "desenha_menu.h"

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define kbhit _kbhit
#define getch _getch
#define limpa_tela() SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0})
#define dorme(milis) Sleep(milis)
#else
#include <unistd.h>
#include "console.h"
#define limpa_tela() system("clear")
#define dorme(milis) usleep(milis * 1000)
#endif

int main () {
    
    char tela[ALTURA][LARGURA];
	char menu[ALTURA][LARGURA];
    int direcao;
    int reinicia=1;
    Ponto p;
    player player1, player2;
    menuInic(menu);
    while (reinicia>-1) {
        limpa_tela();
        if (reinicia==1) {
            
            menuDesenha(menu);
            while (!(getch() == 13 || getch()==10)){
                ;
            }
            player2.score=0;
            player1.score=0;
            rand_direction(&p);
        }
        inicializa(tela, &p);
        inicializa_player(tela,&player1, 1);
        inicializa_player(tela,&player2, 2);
        reinicia=-1;
        while (1) {
            if (reinicia==4) {while (!(getch()==27)) {
                    ;
                }
                reinicia=-1;
            }
            if (reinicia==2) {
                player1.score+=1;
                p.d=LESTE;
                break;
            }
            if (reinicia==3) {
                player2.score+=1;
                p.d=OESTE;
                break;
            }
            if (player2.score==10||player1.score==10) {
                reinicia=1;
                break;
            }
            
            limpa_tela();
            desenha(tela);
            if (kbhit()) {
                direcao = getch();
                muda_direcao_player2(&player2, direcao);
                muda_direcao_player1(&player1, direcao, &reinicia);
            }
            mover_player(tela, &player1);
            mover_player(tela, &player2);
            mover_bola_novo(tela, &p, &player2,&player1, &reinicia);
            dorme(60);
            }
        
    }
  return 0;
}
