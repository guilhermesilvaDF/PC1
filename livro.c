#include "vetor.h"
#include "livro.h"
#include <stdio.h>
#include <string.h>

void cadastrar_livro(vetor_dinamico *arr){
    static int id_atual = 1;
    Livro livro;
    livro.id = id_atual;
    id_atual++;
    
    printf("Insira, respectivamente, o titulo, autor, e categoria do livro");
    fgets(livro.titulo, 101, stdin);
    fgets(livro.autor, 101, stdin);
    fgets(livro.categoria, 51, stdin);
    
    // Remove o '\n' do final
    livro.titulo[strcspn(livro.titulo, "\n")] = '\0'; 
    livro.autor[strcspn(livro.autor, "\n")] = '\0';
    livro.categoria[strcspn(livro.categoria, "\n")] = '\0';

    printf("Qual o ano desse livro?\n");
    scanf("%d", &livro.ano);
    getchar();

    vetor_dinamico_adicionar(arr, livro);
    printf("Livro '%s' cadastrado! \n", livro.titulo);
    return;
}

void listar_livros(vetor_dinamico *arr){
    int tam = vetor_dinamico_tamanho(arr);

    for(int i = 0; i<tam; i++){
        imprime_livro(arr->v[i]);
    }
}

void buscar_livro_substring(vetor_dinamico *arr, char *string){
    int tam = vetor_dinamico_tamanho(arr), found = 0;
    
    // Essencial: remover o '\n' do final do termo digitado pelo usuário, 
    // senão o strstr vai procurar pela quebra de linha também!
    string[strcspn(string, "\n")] = '\0';
    for(int i = 0; i<tam; i++){
        Livro livro = arr->v[i];
        if (strstr(livro.titulo, string) != NULL) {
            imprime_livro(livro);
            found = 1;
        }
    }
    if(!found){
        printf("Nenhum livro com esse termo encontrado\n");
    }
}

void buscar_livro(vetor_dinamico *arr, int opcao, char *string){
    int tam = vetor_dinamico_tamanho(arr), found = 0;
    string[strcspn(string, "\n")] = '\0';

    if(opcao == 2){
        for(int i = 0; i<tam; i++){
        Livro livro = arr->v[i];
        if (strcmp(livro.titulo, string) == 0) {
            imprime_livro(livro);
            found = 1;
            }
        }
    }
    else{
        for(int i = 0; i<tam; i++){
        Livro livro = arr->v[i];
        if (strcmp(livro.categoria, string) == 0) {
            imprime_livro(livro);
            found = 1;
            }
        }
    }
    if(!found){
        printf("Nenhum livro com esse termo encontrado\n");
    }
}
        

void remover_livro(vetor_dinamico *arr, int alvo){
    int tam = vetor_dinamico_tamanho(arr);

    for(int i = 0; i<tam; i++){
        Livro livro = arr->v[i];
        if(livro.id == alvo){
            for(int j = i; j < tam - 1; j++){
                arr->v[j] = arr->v[j+1];
            }
            vetor_dinamico_remover(arr);
            return;
        }
    }
    printf("Nenhum livro com o ID informado foi encontrado\n");
}

void imprime_livro(Livro livro){
    printf("ID:%d\nTitulo:%s\nAutor:%s\nCategoria:%s\nAno:%d\n", livro.id, livro.autor, livro.categoria, 
        livro.ano);
    return;
}