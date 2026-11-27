/*main.c // interação com o usuário e menu 
livro.c / livro.h // manipulação de structs e operações sobre livros 
vetor.c / vetor.h // vetor dinâmico, adicionar, remover, ordenar 
arquivo.c / arquivo.h // leitura/escrita em arquivos 
utils.c / utils.h // funções auxiliares (limpar buffer etc.)
*/

#include <stdio.h>

void menu(){
    printf("1.Cadastrar livro");
    printf("2.Listar todos os livros");
    printf("3.Buscar livros");
    printf("4.Remover livro por ID");
    printf("5.Salvar dados em arquivo texto");
    printf("6.Salvar dados em arquivo binário");
    printf("7.Carregar dados de arquivo ao iniciar");
    printf("8.Gerar relatórios");
    printf("9.Sair");
}

int main(){
    while(1){
        menu();
        int escolha;
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                    
            case 2:

            case 3:

            case 4:

            case 5:

            case 6:

            case 7:

            case 8:

            case 9:

            default:
            printf("Escolha inválida!\n");
            break;    
        }
    }
}