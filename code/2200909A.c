/* HEADERS */
#include <stdio.h>
#include <string.h>


/* CONSTANTES */
#define BUFFER 100

enum estados_lamberta {
	O = 0,
	X = 1
};


/* FUNÇÕES */

char
EstadoParaCaracter(enum estados_lamberta estado) {
	static char representacoes[] = {
		[O] = 'O',
		[X] = 'X'
	};
	return representacoes[estado];
}

/* Implementação do procedimento MostraLamberta */
void
MostraLamberta(int *tabuleiro, int n) {
	int i;

	for(i = 0; i < n; i++) {
		printf("%c", EstadoParaCaracter(tabuleiro[i]));
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
