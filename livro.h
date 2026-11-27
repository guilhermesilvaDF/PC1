#ifndef LIVRO_H
#define LIVRO_H
#include "vetor.h"

typedef struct{
    int id;
    char titulo[100];
    char autor[100];
    int ano;
    char categoria[50];
}Livro;

void cadastrar_livro(vetor_dinamico *arr);
void listar_livros(vetor_dinamico *arr);
void buscar_livro(vetor_dinamico *arr, int opcao, char *string);
void buscar_livro_substring(vetor_dinamico *arr, char *string);
void remover_livro(vetor_dinamico *arr, int alvo);
void imprime_livro(Livro livro);

#endif