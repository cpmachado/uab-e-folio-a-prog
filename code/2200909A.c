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
enum estados_lamberta {
	O = 0,
	X = 1
};


/* FUNÇÕES */

/*
 * Nome: EstadoLambertaParaCaracter
 * Descrição: |
 *   Função que traduz representação de estado de Lamberta para carácter
 * Input:
 *   - estado(enum estados_lamberta): Estado associado
 * Retorna:
 *   - (char) representação em carácter
 */
char
EstadoLambertaParaCaracter(enum estados_lamberta estado) {
	static char representacoes[] = {
		[O] = 'O',
		[X] = 'X'
	};
	return representacoes[estado];
}


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
		printf("%c", EstadoLambertaParaCaracter(tabuleiro[i]));
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
		if(str[i] == '0') {
			tabuleiro[i] = 0;
		} else {
			tabuleiro[i] = 1;
		}
	}

	MostraLamberta(tabuleiro, tamanho);

	return 0;
}
