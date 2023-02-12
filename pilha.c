/*
 * main.c
 * Classe de implemantação da ED Pilha.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* iniciar() {

	Pilha *p = malloc(sizeof(Pilha));
	p->topo = NULL;
	p->tamanho = 0;

	return p;
}

void push(Pilha *p, char caractere) {

	Elemento *e = malloc(sizeof(Elemento));
	e->valor = caractere;
	e->proximo = p->topo;
	p->topo = e;

	p->tamanho = p->tamanho + 1;
}

char pop(Pilha *p) {

	Elemento *e;
	char c;

	if (!empty(p)) {

		e = p->topo;
		c = e->valor;
		p->topo = p->topo->proximo;

		p->tamanho = p->tamanho - 1;

		free(e);

		return c;
	} else {

		printf("Pilha vazia.\n");
		return '\0';
	}

}

int empty(Pilha *p) {
	return p->tamanho == 0;
}
