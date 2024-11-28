#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"
#include "tabela_hash.c"

void menu() {
    printf("\n--- MENU ---\n");
    printf("1. Inserir Pokemon\n");
    printf("2. Buscar Pokemon\n");
    printf("3. Remover Pokemon\n");
    printf("4. Imprimir Tabela Hash\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    TabelaHash* pokedex = criar_tabela();
    int opcao, numero;
    char nome[50], natureza[50];

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero do Pokemon: ");
                scanf("%d", &numero);
                printf("Digite o nome do Pokemon: ");
                scanf(" %[^\n]s", nome);
                printf("Digite a natureza do Pokemon: ");
                scanf(" %[^\n]s", natureza);
                inserir_pokemon(pokedex, numero, nome, natureza);
                break;

            case 2:
                printf("Digite o numero do Pokemon que quer buscar: ");
                scanf("%d", &numero);
                Pokemon* encontrado = buscar_pokemon(pokedex, numero);
                if (encontrado) {
                    printf("Pokemon encontrado: Numero: %d, Nome: %s, Natureza: %s\n",
                           encontrado->numero_pokedex, encontrado->nome, encontrado->natureza);
                } else {
                    printf("Pokemon ainda nao registrado na pokedex.\n");
                }
                break;

            case 3:
                printf("Digite o numero do Pokemon que quer remover: ");
                scanf("%d", &numero);
                remover_pokemon(pokedex, numero);
                break;

            case 4:
                printf("Conteudo da Tabela Hash:\n");
                imprimir_tabela(pokedex);
                break;

            case 5:
                printf("Saindo\n");
                liberar_tabela(pokedex);
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}
