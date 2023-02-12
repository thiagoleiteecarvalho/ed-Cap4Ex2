/*
 * main.c
 * Resposta do exercício 2 do capítulo 4.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pilha.h"

int main(void) {

	Pilha *pilha = iniciar();

	if (!pilha) {

		printf("Sem memória disponivel!\n");
		exit(1);
	} else {

		//Se desejar palavras maiores, aumente aqui o tamanho.
		char palavra[500];

		printf("Digite uma palavra:");
		scanf("%s", palavra);

		//Colocando a palavra na pilha
		int i;
		for(i = 0; i < strlen(palavra); i++) {
			push(pilha, palavra[i]);
		}

		bool palindromo = true;
		int j;
		for(j = 0; j < strlen(palavra); j++) {

			char letra = pop(pilha);

			if (letra != palavra[j]) {
				printf("As letras %c e %c não coindidem. Palavra não é palindromo.", letra, palavra[j]);
				palindromo = false;
				break;
			}
		}

		if (palindromo) {
			printf("A palavra %s é palindromo.", palavra);
		}

		free(pilha);
		pilha = NULL;

		return 0;
	}
}
