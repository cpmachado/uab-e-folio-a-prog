/*
 * Programa: 2200909A
 * Descrição: |
 *   Programa que lê um tabuleiro de Lamberta em binário, e imprime o
 *   tabuleiro correspondente.
 *
 *   Mapa de tradução de estados:
 *   | binário | Estado |
 *   | 0       | O      |
 *   | 1       | X      |
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

/*
 * Nome: CaracterParaLambertaEstado
 * Descrição: |
 *   Função que traduz representação de carácter para estado de Lamberta
 * Input:
 *   - caracter(char) representação em carácter
 * Retorna:
 *   - (enum lamberta_estados): Estado associado
 */
enum lamberta_estados
CaracterParaLambertaEstado(char caracter) {
	switch (caracter) {
	case '0':
		return LAMBERTA_O;
	case '1':
		return LAMBERTA_X;
	default:
		return LAMBERTA_DESCONHECIDO;
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
	char str[BUFFER];
	int i, tamanho, tabuleiro[BUFFER];

	scanf("%s", str);
	tamanho = strlen(str);

	for(i = 0; i < tamanho; i++) {
		tabuleiro[i] = CaracterParaLambertaEstado(str[i]);
	}

	MostraLamberta(tabuleiro, tamanho);

	return 0;
}
