#ifndef VETOR_H
#define VETOR_H

#include <stdlib.h>
#include "livro.h"

typedef struct {
    Livro *v;          // vetor dinâmico
    int capacidade; // capacidade do vetor dinãmico
    int tamanho;     // tamanho do vetor dinâmico
} vetor_dinamico;

void mergesort(vetor_dinamico *arr, int escolha);

void vetor_dinamico_incializar(vetor_dinamico **arr);
void vetor_dinamico_delete(vetor_dinamico **arr);
void vetor_dinamico_adicionar(vetor_dinamico *arr, Livro x);
void vetor_dinamico_remover(vetor_dinamico *arr);

Livro vetor_dinamico_back(vetor_dinamico *arr);
Livro vetor_dinamico_front(vetor_dinamico *arr);
int vetor_dinamico_capacidade(vetor_dinamico *arr);
int vetor_dinamico_tamanho(vetor_dinamico *arr);


#endif