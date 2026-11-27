#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"
#include "livro.h"

void vetor_dinamico_incializar(vetor_dinamico **arr) {
    /*** Utilizamos uma capacidade de 10 por padrão na criação
     * do vetor dinâmico
     */
    (*arr) = malloc(sizeof(vetor_dinamico));
    (*arr)->capacidade = 10;
    (*arr)->tamanho = 0;
    (*arr)->v = malloc(sizeof(Livro) * 10);
}

void vetor_dinamico_dobra_capacidade(vetor_dinamico *arr) {
    arr->capacidade *= 2;
    arr->v = realloc(arr->v, sizeof(Livro) * arr->capacidade);
}

void vetor_dinamico_metade_capacidade(vetor_dinamico *arr) {
    arr->capacidade /= 2;
    arr->v = realloc(arr->v, sizeof(Livro) * arr->capacidade);
}

void vetor_dinamico_adicionar(vetor_dinamico *arr, Livro x) {
    /*** o tamanho do vetor dinâmico seja igual a sua capaciade,
     * duplicamos a capacidade e realocamos o tamanho do vetor.
     ***/
    if (arr->tamanho == arr->capacidade) {
        vetor_dinamico_dobra_capacidade(arr);
    }
    /***
     * O elemento é inserido ao final.
     */
    arr->v[arr->tamanho] = x;
    arr->tamanho++;
}

void vetor_dinamico_remover(vetor_dinamico *arr) {
    /*** Removemos o último elemento do vetor. Para isto só é necessário
     * decrementar o seu tamanho.
     * Caso o tamanho atual esteja à 1/4 da capacidade máxima do vetor,
     * o vetor é redimensionado para metade do seu tamanho.
     * Nunca redimensionamos a capacidade  para abaixo de 4.
     */
    if (arr->tamanho == arr->capacidade / 4 && arr->capacidade > 4) {
        vetor_dinamico_metade_capacidade(arr);
    }
    arr->tamanho--;
}

void vetor_dinamico_delete(vetor_dinamico **arr) {
    /***
     * Para deletar completamente o vetor dinãmico, basta remover
     * a área apontada por v e a área apontada pelo próprio vetor dinâmico
     */
    free((*arr)->v);
    free(*arr);
    *arr = NULL;
}

Livro vetor_dinamico_back(vetor_dinamico *arr) {
    return arr->v[arr->tamanho - 1];
}

Livro vetor_dinamico_front(vetor_dinamico *arr) {
    return arr->v[0];
}

int vetor_dinamico_tamanho(vetor_dinamico *arr) {
    return arr->tamanho;
}

int vetor_dinamico_capacidade(vetor_dinamico *arr) {
    return arr->capacidade;
}

int compara(Livro *livro_a, Livro *livro_b, int escolha){
    if (escolha == 1){
        return strcmp(livro_a->titulo, livro_b ->titulo) <=0;
    }
    else if (escolha == 2){
        return strcmp(livro_a->categoria, livro_b ->categoria) <=0;
    }
    return livro_a->ano <= livro_b->ano;
}

void merge(Livro *v, Livro *v1, Livro *v2, int size, int escolha)
{
    int i, j = 0, k = 0;
    int mid = size / 2;
    int size2 = size - mid;

    for (i = 0; j < mid && k < size2; i++)
    {
        if (compara(&v1[j], &v2[k], escolha))
        {
            v[i] = v1[j++];
        }
        else
        {
            v[i] = v2[k++];
        }
    }
    while (j < mid)
    {
        v[i++] = v1[j++];
    }
    while (k < size2)
    {
        v[i++] = v2[k++];
    }
}

void mergesort_interno(Livro *v, int size, int escolha)
{
    if (size > 1)
    {
        int mid = size / 2;
        int size2 = size - mid;
        int i;

        Livro *v1 = (Livro *)malloc(mid * sizeof(Livro));
        Livro *v2 = (Livro *)malloc(size2 * sizeof(Livro));

        for (i = 0; i < mid; i++)
        {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++)
        {
            v2[i - mid] = v[i];
        }

        // As chamadas recursivas processam os sub-vetores v1 e v2
        mergesort_interno(v1, mid, escolha);
        mergesort_interno(v2, size2, escolha);
        
        // Intercala v1 e v2 de volta para v
        merge(v, v1, v2, size, escolha);

        free(v1);
        free(v2);
    }
}


void mergesort(vetor_dinamico *arr, int escolha)
{
    
    if (arr != NULL && arr->tamanho > 1) 
    {
        mergesort_interno(arr->v, arr->tamanho, escolha);
    }
}