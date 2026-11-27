#include "utils.h"
#include <stdio.h>
#include <limits.h>

void gerar_relatorio(vetor_dinamico *arr){
    int total = arr->tamanho;
    int soma = 1;
    
    if (total == 0) {
    printf("Nenhum livro cadastrado para gerar estatisticas.\n");
    return;
    }
    
    mergesort(arr, 2);
    int menor = arr->v[0].ano;
    int maior = arr->v[0].ano;
    for(int i = 1; i < total; i++){
        if(strcmp(arr->v[i].categoria, arr->v[i-1].categoria) == 0){
            soma++;
        }
        else{
            printf("%d Livros na Categoria %s\n", soma, arr->v[i-1].categoria);
            soma = 1;
        }

        if(arr->v[i].ano<menor){
            menor = arr->v[i-1].ano;
        }
        if(arr->v[i].ano > maior){
            maior = arr->v[i-1].ano;
        }

    }
    printf("%d livro(s) na categoria %s\n", soma, arr->v[total - 1].categoria);
    printf("Ano mais antigo: %d | Ano mais recente: %d\n", menor, maior);
}
