#include <stdio.h>
#include <string.h>

#define BUFFER 100

/* Implementação do procedimento MostraLamberta */


void
MostraLamberta(int *tabuleiro, int n) {
	printf("%d\n", tabuleiro[n - 1]);
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
