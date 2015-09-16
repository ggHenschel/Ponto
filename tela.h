/* tela.h */

#ifndef TELA_H
#define TELA_H

#define ALTURA 20
#define LARGURA 50

#define PONTO '.'
#define ESPACO ' '
#define TETO_E_CHAO '-'
#define PAREDE '0'

typedef enum direcao {
    NORTE,
    SUL,
    OESTE,
    LESTE
} Direcao;

typedef struct ponto {
  int x, y;
  Direcao d;
} Ponto;

void inicializa (char tela[ALTURA][LARGURA], Ponto* p);
void desenha (char tela[ALTURA][LARGURA]);
void mover (char tela[ALTURA][LARGURA], Ponto* p);
void norte (char tela[ALTURA][LARGURA], Ponto* p);
void sul (char tela[ALTURA][LARGURA], Ponto* p);
void oeste (char tela[ALTURA][LARGURA], Ponto* p);
void leste (char tela[ALTURA][LARGURA], Ponto* p);
void muda_direcao (Ponto* p, int d);

#endif
