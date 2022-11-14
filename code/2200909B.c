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
enum estados_lamberta {
	O = 0,
	X = 1
};


/* FUNÇÕES */

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
		tabuleiro[i] = randaux() % 2;
	}
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
