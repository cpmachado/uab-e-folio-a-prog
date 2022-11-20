/*
 * Programa: 2200909B
 * Descrição: |
 *   Programa que lê a dimensão do tabuleiro, e um certo número de "saltos"
 *   para discartar valores da função randaux.
 *   Imprime o tabuleiro gerado a partir da função PreencheLamberta.
 */
/* CABEÇALHOS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CONSTANTES */
/* Enumeração para os estados diferentes de uma célula de Lamberta */
enum lamberta_estados {
	LAMBERTA_O = 0,
	LAMBERTA_X = 1,
	LAMBERTA_DESCONHECIDO = 2
};

/* TIPOS */
/* Lamberta: Tipo Abstracto de Dado para representação do tabuleiro */
typedef struct Lamberta {
	int *tabuleiro;
	int tamanho;
	int jogada;
	int segmento_maximo;
} *Lamberta;


/* OPERAÇÕES SOBRE LAMBERTA */
/*
 * Nome: LambertaCria
 * Descrição: Cria instância que contém o estado do jogo, numa dada jogada
 * Input:
 *    - tamanho(int): tamanho do tabuleiro de jogo
 * Retorna: (Lamberta) Cria um tabuleiro
 */
Lamberta
LambertaCriar(int tamanho) {
	Lamberta tabuleiro = (Lamberta) malloc(sizeof(struct Lamberta));

	if(!tabuleiro
	   || !(tabuleiro->tabuleiro =
		(int *)malloc(sizeof(int) * tamanho))) {
		free(tabuleiro);
		fprintf(stderr, "LambertaCriar: Falhou a alocação\n");
		return NULL;
	}

	tabuleiro->tamanho = tamanho;
	tabuleiro->jogada = 1;
	tabuleiro->segmento_maximo = tamanho - 1;

	return tabuleiro;
}


/*
 * Nome: LambertaLibertar
 * Descrição: Liberta memória de uma instância Lamberta
 * Input:
 *    - tabuleiro(Lamberta): tabuleiro de jogo
 * Retorna: (void) Liberta a memória associada a um tabuleiro
 */
void
LambertaLibertar(Lamberta tabuleiro) {
	if(tabuleiro) {
		free(tabuleiro->tabuleiro);
	}
	free(tabuleiro);
}


/*
 * Nome: LambertaTamanho
 * Descrição: Retorna o tamanho associado a um tabuleiro Lamberta
 * Input:
 *    - tabuleiro(Lamberta): tabuleiro de jogo
 * Retorna: (int) Tamanho do tabuleiro
 */
int
LambertaTamanho(Lamberta tabuleiro) {
	return tabuleiro->tamanho;
}


/*
 * Nome: LambertaJogada
 * Descrição: Retorna a jogada associada a um tabuleiro Lamberta
 * Input:
 *    - tabuleiro(Lamberta): tabuleiro de jogo
 * Retorna: (int) Jogada do tabuleiro
 */
int
LambertaJogada(Lamberta tabuleiro) {
	return tabuleiro->jogada;
}


/*
 * Nome: LambertaCasaInserir
 * Descrição: Altera o valor de uma célula do tabuleiro Lamberta
 * Input:
 *    - tabuleiro(Lamberta): tabuleiro de jogo
 *    - index(int): índice da célula 1 .. N
 *    - estado(int): estado associado
 * Retorna: (void) Altera a célula no caso do indíce e o estado ser válido
 */
void
LambertaCasaInserir(Lamberta tabuleiro, int index, int estado) {
	if(index < 1 || index > tabuleiro->tamanho
	   || (estado != LAMBERTA_X && estado != LAMBERTA_O)) {
		fprintf(stderr,
			"LambertaCasaInserir:  Posição inválida ou estado inválido\n");
		return;
	}

	tabuleiro->tabuleiro[index - 1] = estado;
}


/*
 * Nome: LambertaCasa
 * Descrição: Retorna o valor de uma casa do tabuleiro
 * Input:
 *    - tabuleiro(Lamberta): tabuleiro de jogo
 *    - index(int): índice da célula 1 .. N
 * Retorna: (int) retorna a célula no caso do indíce ser válido
 */
int
LambertaCasa(Lamberta tabuleiro, int index) {
	if(index < 1 || index > tabuleiro->tamanho) {
		fprintf(stderr,
			"LambertaCasa: Acesso a posição invalida\n");
		return LAMBERTA_DESCONHECIDO;
	}
	return tabuleiro->tabuleiro[index - 1];
}


/*
 * Nome: LambertaInverteCasa
 * Descrição: Inverte o valor de uma célula do tabuleiro de X - O , ou O - X
 * Input:
 *    - tabuleiro(Lamberta): tabuleiro de jogo
 *    - index(int): índice da célula 1 .. N
 * Retorna: (void) retorna a célula no caso do indíce ser válido
 */
void
LambertaInverteCasa(Lamberta tabuleiro, int index) {
	if(index < 1 || index > tabuleiro->tamanho) {
		fprintf(stderr,
			"LambertaInverteCasa: Acesso a posição invalida\n");
		return;
	}
	if(tabuleiro->tabuleiro[index - 1] == LAMBERTA_X) {
		tabuleiro->tabuleiro[index - 1] = LAMBERTA_O;
	} else {
		tabuleiro->tabuleiro[index - 1] = LAMBERTA_X;
	}
}


/*
 * Nome: LambertaJogadaValida
 * Descrição: Verifica se um dado segmento é uma jogada válida
 * Input:
 *    - tabuleiro(Lamberta): tabuleiro de jogo
 *    - index(int): índice da célula base do segmento, 1 .. N
 *    - tamanho(int): tamanho do segmento
 * Retorna: (int) Retorna 1 no caso de ser válida, 0 caso contrário
 */
int
LambertaJogadaValida(Lamberta tabuleiro, int index, int tamanho) {
	int i;

	/* Verificar tamanho */
	if(tamanho < 1 || tamanho > tabuleiro->segmento_maximo) {
		return 0;
	}

	/* Verificar base do segmento */
	if(index < 1 || index > tabuleiro->tamanho) {
		return 0;
	}

	/* Verificar se segmento está dentro do tabuleiro  */
	if(index - 1 + tamanho > tabuleiro->tamanho) {
		return 0;
	}

	/* Verificar se o segmento contém um X  */
	for(i = index; i < index + tamanho; i++) {
		if(tabuleiro->tabuleiro[i - 1] == LAMBERTA_X) {
			return 1;
		}
	}

	return 0;
}


/*
 * Nome: LambertaAplicaJogada
 * Descrição: Aplica a jogada do tabuleiro, e actualiza o seu estado
 * Input:
 *    - tabuleiro(Lamberta): tabuleiro de jogo
 *    - index(int): índice da célula base do segmento, 1 .. N
 *    - tamanho(int): tamanho do segmento
 * Retorna: (void) Actualiza o tabuleiro. Perigoso, uma vez que não verifica
 * que a jogada é válida.
 */
void
LambertaAplicaJogada(Lamberta tabuleiro, int index, int tamanho) {
	int i;

	for(i = index; i < index + tamanho; i++) {
		LambertaInverteCasa(tabuleiro, i);
	}

	tabuleiro->jogada++;
	if(tabuleiro->jogada < tabuleiro->tamanho) {
		tabuleiro->segmento_maximo =
			tabuleiro->tamanho - tabuleiro->jogada;
	}
}



/* FUNÇÕES */

/* -- Mapeadores -- */

/*
 * Nome: LambertaEstadoParaCaracter
 * Descrição: |
 *   Função que traduz representação de estado de Lamberta para carácter
 * Input:
 *   - estado(int): Estado associado
 * Retorna:
 *   - (char) representação em carácter
 */
char
LambertaEstadoParaCaracter(int estado) {
	switch (estado) {
	case LAMBERTA_O:
		return 'O';
	case LAMBERTA_X:
		return 'X';
	default:
		return 'U';
	}
}

/* -- Utilitários -- */

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
PreencheLamberta(Lamberta tabuleiro) {
	int i;
	int tamanho = LambertaTamanho(tabuleiro);

	for(i = 1; i <= tamanho; i++) {
		if(randaux() % 2 == 1) {
			LambertaCasaInserir(tabuleiro, i, LAMBERTA_X);
		} else {
			LambertaCasaInserir(tabuleiro, i, LAMBERTA_O);
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
MostraLamberta(Lamberta tabuleiro) {
	int i;
	int estado;

	if(LambertaTamanho(tabuleiro) >= 10) {
		for(i = 1; i <= LambertaTamanho(tabuleiro) / 10; i++) {
			printf("         %d", i);
		}
		printf("\n");
	}

	for(i = 1; i <= LambertaTamanho(tabuleiro); i++) {
		printf("%d", i % 10);
	}
	printf("\n");

	for(i = 1; i <= LambertaTamanho(tabuleiro); i++) {
		estado = LambertaCasa(tabuleiro, i);
		printf("%c", LambertaEstadoParaCaracter(estado));
	}
	printf("\n");
}


/*
 * Nome: JogadaHumanaLamberta
 * Descrição: Função que imprime campo para preencher os dados de segmento
 * Input:
 *   - jogada(int): Jogada para o qual está a ler o segmento
 *   - base(int*): apontador para inteiro que vai conter o índice da base do
 *     segmento
 *   - tamanho(int*): apontador para inteiro que vai conter o tamanho do
 *     segmento
 * Retorna: (void) Altera a base e tamanho
 */
void
JogadaHumanaLamberta(int jogada, int *base, int *tamanho) {
	printf("Jogada [%d]: ", jogada);
	scanf("%d %d", base, tamanho);
	printf("%d %d\n", *base, *tamanho);
}


/*
 * Nome: JogoLamberta
 * Descrição: Jogo de Lamberta, assume tabuleiro em estado inicial
 * Input:
 *    - tabuleiro(Lamberta): tabuleiro de jogo
 * Retorna: (void) Altera o tabuleiro
 */
void
JogoLamberta(Lamberta tabuleiro) {
	int base, tamanho;

	MostraLamberta(tabuleiro);
	JogadaHumanaLamberta(LambertaJogada(tabuleiro), &base, &tamanho);

	while(LambertaJogadaValida(tabuleiro, base, tamanho)) {
		LambertaAplicaJogada(tabuleiro, base, tamanho);
		MostraLamberta(tabuleiro);
		JogadaHumanaLamberta(LambertaJogada(tabuleiro), &base,
				     &tamanho);
	}

	printf("Jogada inválida, perde jogador %d.\n",
	       1 + !(LambertaJogada(tabuleiro) % 2));
}


int
main(void) {
	int i, saltos, tamanho;
	Lamberta tabuleiro;

	scanf("%d %d", &tamanho, &saltos);

	for(i = 0; i < saltos; i++) {
		randaux();
	}

	if(!(tabuleiro = LambertaCriar(tamanho))) {
		exit(EXIT_FAILURE);
	}

	PreencheLamberta(tabuleiro);
	JogoLamberta(tabuleiro);
	LambertaLibertar(tabuleiro);

	return 0;
}
