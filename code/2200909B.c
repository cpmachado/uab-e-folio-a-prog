/*
 * Programa: 2200909B
 * Descrição: |
 *   Programa que lê a dimensão do tabuleiro, e um certo número de "saltos"
 *   para discartar valores da função randaux.
 *   Imprime o tabuleiro gerado a partir da função PreencheLamberta.
 */
/* CABEÇALHOS */
#include <stdio.h>
#include <string.h>


/* CONSTANTES */
#define BUFFER 100


/* Enumeração para os estados diferentes de uma célula de Lamberta */
enum lamberta_estados {
	LAMBERTA_O = 0,
	LAMBERTA_X = 1,
	LAMBERTA_DESCONHECIDO = 2
};

/* FUNÇÕES */

/* -- Mapeadores -- */

/*
 * Nome: LambertaEstadoParaCaracter
 * Descrição: |
 *   Função que traduz representação de estado de Lamberta para carácter
 * Input:
 *   - estado(enum lamberta_estados): Estado associado
 * Retorna:
 *   - (char) representação em carácter
 */
char
LambertaEstadoParaCaracter(enum lamberta_estados estado) {
	switch (estado) {
	case LAMBERTA_O:
		return 'O';
	case LAMBERTA_X:
		return 'X';
	default:
		return 'U';
	}
}

/* -- UTILITÁRIOS -- */

/*
 * Nome: randaux
 * Descrição: |
 *   Função retorna números pseudo-aleatórios
 * Input: (void)
 * Retorna:
 *   - (unsigned int) número pseudo-aleatório
 */
unsigned int
randaux(void) {
	static long seed = 1;
	return (((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}


/*
 * Nome: PreencheLamberta
 * Descrição: Preenche o tabuleiro com recurso à função randaux
 * Input:
 *   - tabuleiro(int): Tabuleiro que contém as posições
 *   - n(int): Dimensão do tabuleiro
 * Retorna: (void) Altera o parâmetro tabuleiro
 */
void
PreencheLamberta(int *tabuleiro, int n) {
	int i;

	for(i = 0; i < n; i++) {
		if(randaux() % 2 == 1) {
			tabuleiro[i] = LAMBERTA_X;
		} else {
			tabuleiro[i] = LAMBERTA_O;
		}
	}
}

/* -- I/O -- */

/*
 * Nome: MostraLamberta
 * Descrição: Função que imprime o tabuleiro de Lamberta
 * Input:
 *   - tabuleiro(int): Tabuleiro que contém as posições
 *   - n(int): Dimensão do tabuleiro
 * Retorna: (void)
 */
void
MostraLamberta(int *tabuleiro, int n) {
	int i;

	for(i = 0; i < n; i++) {
		printf("%c", LambertaEstadoParaCaracter(tabuleiro[i]));
	}
	printf("\n");
}


int
main(void) {
	int i, saltos, tamanho, tabuleiro[BUFFER];

	scanf("%d %d", &tamanho, &saltos);

	for(i = 0; i < saltos; i++) {
		randaux();
	}

	PreencheLamberta(tabuleiro, tamanho);
	MostraLamberta(tabuleiro, tamanho);

	return 0;
}
